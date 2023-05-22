/* Copyright 2023 Dimitris Mantzouranis <d3xter93@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 #include "i2c_master.h"

/* Master to Slave I2C Connection */
static const I2CConfig slavei2cconfig = {
    0,
    I2C2_SCL_PIN,
    I2C2_SDA_PIN,
    &i2c_sw_delay,
};

/* matrix state(1:on, 0:off) */
extern matrix_row_t raw_matrix[MATRIX_ROWS]; // raw values

static pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;

static pin_t col_pins[MATRIX_COLS]   = MATRIX_COL_PINS;

uint8_t scan_buf[10]= {0};
uint8_t slave_row;
uint8_t slave_col;
bool key_level = false;
bool slave_matrix_scan_update(void) {
    bool update_request = false;
    uint8_t buf[10];
    i2cStart(&I2CD2, &slavei2cconfig);
    i2c_status_t ret = i2cMasterReceiveTimeout(&I2CD2, (SLAVE_I2C_ADDRESS >> 1), buf, sizeof(buf), TIME_MS2I(100));
    if (ret != I2C_STATUS_SUCCESS) {
        i2cStop(&I2CD2);
        return update_request;
    }
    for(int i=0; i < sizeof(buf); i++) {
        if( buf[i] != scan_buf[i]) {
            scan_buf[i]=buf[i];
            update_request = true;
        }
    }
    return update_request;
}

void slave_decode(void) {
    uint8_t scan_row = -1, scan_col = -1;
    for (int i = 0; i < sizeof(scan_buf); i++) {
        if (scan_buf[i] == 0) continue;
        int leftmost_bit_pos = 7;
        while ((scan_buf[i] & (1 << leftmost_bit_pos)) == 0) leftmost_bit_pos--;
        scan_row = leftmost_bit_pos;
        scan_col = i;
        break;
    }
    if( scan_row == 255 || scan_col == 255) {
        key_level = false;
        return; //key released
    }
    if( scan_col <= (MATRIX_COLS / 2)) {
        slave_row = scan_row + 1;
        slave_col = scan_col;
        key_level = true;
        return; //key pressed
    }
    // something went wrong here - unhandled
}


static inline void setPinOutput_writeLow(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinLow(pin);
    }
}

static inline void setPinOutput_writeHigh(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinHigh(pin);
    }
}

static inline void setPinInputHigh_atomic(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinInputHigh(pin);
    }
}

static inline uint8_t readMatrixPin(pin_t pin) {
    if (pin != NO_PIN) {
        return (readPin(pin) == 0) ? 0 : 1;
    } else {
        return 1;
    }
}

static bool select_row(uint8_t row) {
    pin_t pin = row_pins[row];
    if (pin != NO_PIN) {
        setPinOutput_writeLow(pin);
        return true;
    }
    return false;
}

static void unselect_row(uint8_t row) {
    pin_t pin = row_pins[row];
    if (pin != NO_PIN) {
#            ifdef MATRIX_UNSELECT_DRIVE_HIGH
        setPinOutput_writeHigh(pin);
#            else
        setPinInputHigh_atomic(pin);
#            endif
    }
}


static void unselect_rows(void) {
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        unselect_row(x);
    }
}

void matrix_init_custom(void) {
    unselect_rows();
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        if (col_pins[x] != NO_PIN) {
            setPinInputHigh_atomic(col_pins[x]);
        }
    }
}
void matrix_read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Start with a clear matrix row
    matrix_row_t current_row_value = 0;

    if (!select_row(current_row)) { // Select row
        return;                     // skip NO_PIN row
    }
    matrix_output_select_delay();

    // For each col...
    matrix_row_t row_shifter = MATRIX_ROW_SHIFTER;
    for (uint8_t col_index = 0; col_index < (MATRIX_COLS / 2); col_index++, row_shifter <<= 1) {
        uint8_t pin_state = readMatrixPin(col_pins[col_index]);

        // Populate the matrix row with the state of the col pin
        current_row_value |= pin_state ? 0 : row_shifter;
    }

    // Unselect row
    unselect_row(current_row);
    matrix_output_unselect_delay(current_row, current_row_value != 0); // wait for all Col signals to go HIGH

    // Update the matrix
    current_matrix[current_row] = current_row_value;
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    matrix_row_t curr_matrix[MATRIX_ROWS] = {0};
    // Set row, read cols
    for (uint8_t current_row = 1; current_row < (MATRIX_ROWS -1); current_row++) {
        matrix_read_cols_on_row(curr_matrix, current_row);
    }
    // Update the top left direct pins as part of the matrix
    curr_matrix[0] |= readMatrixPin(DIRECT_WIN_LOCK_PIN) ? 0 : MATRIX_ROW_SHIFTER;
    curr_matrix[1] |= readMatrixPin(DIRECT_RGB_TOGG_PIN) ? 0 : MATRIX_ROW_SHIFTER;
    // Update the encoder switch as part of the matrix
    curr_matrix[7] |= readMatrixPin(DIRECT_ENCODER_PUSH_PIN) ? 0 : (MATRIX_ROW_SHIFTER << 7);
    // Check the slave side
    if(slave_matrix_scan_update()) slave_decode();
    curr_matrix[slave_row] |= !key_level ? 0 : (MATRIX_ROW_SHIFTER << ((MATRIX_COLS / 2) + slave_col));

    bool changed = memcmp(raw_matrix, curr_matrix, sizeof(curr_matrix)) != 0;
    if (changed) memcpy(raw_matrix, curr_matrix, sizeof(curr_matrix));

    return changed;
}
