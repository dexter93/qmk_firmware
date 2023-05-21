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
#include "left.h"
#include "i2c_master.h"
#ifdef RGB_MATRIX_ENABLE

// clang-format off

const sled1734x_led PROGMEM g_sled1734x_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to SLED1734X manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, CA3_D,    CA1_D,    CA2_D},
    {0, CA3_E,    CA1_E,    CA2_E},
    {0, CA3_F,    CA1_F,    CA2_F},
    {0, CA3_G,    CA1_G,    CA2_G},
    {0, CA3_H,    CA1_H,    CA2_H},
    {0, CA3_I,    CA1_I,    CA2_I},
    {0, CA3_J,    CA1_J,    CA2_J},

    {1, CA3_C,    CA1_C,    CA2_C},
    {1, CA3_D,    CA1_D,    CA2_D},
    {1, CA3_E,    CA1_E,    CA2_E},
    {1, CA3_F,    CA1_F,    CA2_F},
    {1, CA3_G,    CA1_G,    CA2_G},
    {1, CA3_H,    CA1_H,    CA2_H},
    {1, CA3_I,    CA1_I,    CA2_I},
    {1, CA3_J,    CA1_J,    CA2_J},
    {1, CA3_K,    CA1_K,    CA2_K},

    {0, CA5_A,    CA4_A,    CA6_A},
    {0, CA5_B,    CA4_B,    CA6_B},
    {0, CA5_C,    CA4_C,    CA6_C},
    {0, CA5_F,    CA4_F,    CA6_F},
    {0, CA5_G,    CA4_G,    CA6_G},
    {0, CA5_H,    CA4_H,    CA6_H},
    {0, CA5_I,    CA4_I,    CA6_I},
    {0, CA5_J,    CA4_J,    CA6_J},

    {1, CA5_A,    CA4_A,    CA6_A},
    {1, CA5_B,    CA4_B,    CA6_B},
    {1, CA5_C,    CA4_C,    CA6_C},
    {1, CA5_F,    CA4_F,    CA6_F},
    {1, CA5_G,    CA4_G,    CA6_G},
    {1, CA5_H,    CA4_H,    CA6_H},
    {1, CA5_J,    CA4_J,    CA6_J},
    {1, CA5_K,    CA4_K,    CA6_K},

    {0, CA8_A,    CA7_A,    CA9_A},
    {0, CA8_B,    CA7_B,    CA9_B},
    {0, CA8_C,    CA7_C,    CA9_C},
    {0, CA8_D,    CA7_D,    CA9_D},
    {0, CA8_E,    CA7_E,    CA9_E},
    {0, CA8_F,    CA7_F,    CA9_F},
    {0, CA8_I,    CA7_I,    CA9_I},

    {1, CA8_A,    CA7_A,    CA9_A},
    {1, CA8_B,    CA7_B,    CA9_B},
    {1, CA8_C,    CA7_C,    CA9_C},
    {1, CA8_D,    CA7_D,    CA9_D},
    {1, CA8_E,    CA7_E,    CA9_E},
    {1, CA8_F,    CA7_F,    CA9_F},
    {1, CA8_I,    CA7_I,    CA9_I},
    {1, CA8_J,    CA7_J,    CA9_J},
    {1, CA8_K,    CA7_K,    CA9_K},

    {0, CB2_A,    CB1_A,    CB3_A},
    {0, CB2_B,    CB1_B,    CB3_B},
    {0, CB2_C,    CB1_C,    CB3_C},
    {0, CB2_D,    CB1_D,    CB3_D},
    {0, CB2_E,    CB1_E,    CB3_E},
    {0, CB2_F,    CB1_F,    CB3_F},
    {0, CB2_G,    CB1_G,    CB3_G},

    {1, CB2_A,    CB1_A,    CB3_A},
    {1, CB2_B,    CB1_B,    CB3_B},
    {1, CB2_C,    CB1_C,    CB3_C},
    {1, CB2_D,    CB1_D,    CB3_D},
    {1, CB2_E,    CB1_E,    CB3_E},
    {1, CB2_F,    CB1_F,    CB3_F},
    {1, CB2_H,    CB1_H,    CB3_H},
    {1, CB2_I,    CB1_I,    CB3_I},

    {0, CB5_A,    CB4_A,    CB6_A},
    {0, CB5_B,    CB4_B,    CB6_B},
    {0, CB5_D,    CB4_D,    CB6_D},
    {0, CB5_E,    CB4_E,    CB6_E},
    {0, CB5_F,    CB4_F,    CB6_F},
    {0, CB5_G,    CB4_G,    CB6_G},
    {0, CB5_H,    CB4_H,    CB6_H},

    {1, CB5_A,    CB4_A,    CB6_A},
    {1, CB5_B,    CB4_B,    CB6_B},
    {1, CB5_C,    CB4_C,    CB6_C},
    {1, CB5_D,    CB4_D,    CB6_D},
    {1, CB5_E,    CB4_E,    CB6_E},
    {1, CB5_F,    CB4_F,    CB6_F},
    {1, CB5_G,    CB4_G,    CB6_G},
    {1, CB5_H,    CB4_H,    CB6_H},

    {0, CB5_I,    CB4_I,    CB6_I},
    {0, CB5_J,    CB4_J,    CB6_J},
    {0, CB5_K,    CB4_K,    CB6_K},
    {0, CB5_L,    CB4_L,    CB6_L},
    {0, CB5_O,    CB4_O,    CB6_O},

    {1, CB5_I,    CB4_I,    CB6_I},
    {1, CB5_J,    CB4_J,    CB6_J},
    {1, CB5_K,    CB4_K,    CB6_K},
    {1, CB5_L,    CB4_L,    CB6_L},
    {1, CB5_O,    CB4_O,    CB6_O},
    {1, CB5_P,    CB4_P,    CB6_P},

    //encoder
    {0, CA4_M,    CA5_M,    CA6_M}, //TL
    {0, CA4_L,    CA5_L,    CA6_L}, //TR
    {0, CA4_N,    CA5_N,    CA6_N}, //BL
    {0, CA4_K,    CA5_K,    CA6_K}, //BR

};

#define __ NO_LED

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        { __, __, __, __, __, __, __, __,    __, __, __, __, __, __, __, __, __ },
        { __,  0,  1,  2,  3,  4,  5,  6,     7,  8,  9, 10, 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20, 21, 22, 23,    24, 25, 26, 27, 28, 29, __, 30, 31 },
        { 32, 33, 34, 35, 36, 37, 38, __,    39, 40, 41, 42, 43, 44, 45, 46, 47 },
        { 48, 49, 50, 51, 52, 53, 54, __,    55, 56, 57, 58, 59, 60, __, 61, 62 },
        { 63, 64, __, 65, 66, 67, 68, 69,    70, 71, 72, 73, 74, __, 75, 76, 77 },
        { 78, 79, 80, 81, __, 82, __, __,    __, 83, __, 84, __, 85, 86, 87, 88 },
        // encoder
        { __, __, __, __, 89, 90, 91, 92,    __, __, __, __, __, __, __, __, __ },
    },
    {
                   { 14,0  }, { 26,0  }, { 37,0  }, { 49,0  }, { 60,0  }, { 72,0  }, { 83,0  },     {132,0  }, {144,0  }, {155,0  }, {167,0  }, {178,0  }, {190,0  }, {201,0  }, {213,0  }, {224,0  },
        {  0,11 }, { 14,11 }, { 26,11 }, { 37,11 }, { 49,11 }, { 60,11 }, { 72,11 }, { 83,11 },     {132,11 }, {144,11 }, {155,11 }, {167,11 }, {178,11 }, {190,11 },            {207,11 }, {224,11 },
        {  0,20 }, { 17,20 }, { 32,20 }, { 43,20 }, { 55,20 }, { 66,20 }, { 78,20 },                {126,20 }, {138,20 }, {149,20 }, {161,20 }, {172,20 }, {184,20 }, {195,20 }, {210,20 }, {224,20 },
        {  0,29 }, { 19,29 }, { 34,29 }, { 46,29 }, { 57,29 }, { 69,29 }, { 80,29 },                {129,29 }, {141,29 }, {152,29 }, {164,29 }, {175,29 },            {187,29 }, {205,29 }, {224,29 },
        {  0,38 },            { 22,38 }, { 40,38 }, { 52,38 }, { 63,38 }, { 75,38 }, { 86,38 },     {135,38 }, {146,38 }, {158,38 }, {169,38 }, {181,38 },            {197,38 }, {213,38 }, {224,38 },
        {  0,46 }, { 16,46 }, { 30,46 }, { 45,46 },            { 72,46 },                                      {141,46 },            {168,46 },            {185,46 }, {201,46 }, {213,46 }, {224,46 },
        //encoder
                                                    {101,55 }, {112,55 }, {101,64 }, {112,64 },
    },
    {
        // RGB LED Index to Flag
           1, 1, 1, 1, 1, 1, 1,     1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 4, 4, 4, 4, 4, 4,     4, 4, 4, 4, 4, 4,    1, 1,
        1, 1, 4, 4, 4, 4, 4,        4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 8, 4, 4, 4, 4, 4,        4, 4, 4, 4, 4, 4,    1, 1,
        1, 1,    4, 4, 4, 4, 4,     4, 4, 4, 4,    4, 1, 1, 1,
        1, 1, 1, 1,    4,              4,    1,    1, 1, 1, 1,
        //encoder
        2, 2, 2, 2,
    }
};

#endif // RGB_MATRIX_ENABLE

/* Master to Slave I2C Connection */
static const I2CConfig slavei2cconfig = {
    0,
    I2C2_SCL_PIN,
    I2C2_SDA_PIN,
    &i2c_sw_delay,
};

void keyboard_pre_init_kb(void) {
    /* Init Slave side I2C */
    setPinInput(I2C2_SCL_PIN);
    setPinInput(I2C2_SDA_PIN);
    wait_ms(10);
    setPinOutput(I2C2_SCL_PIN);
    setPinOutput(I2C2_SDA_PIN);

    /* Custom Indicator LEDs */
    setPinOutput(LED_FN_PIN);
    writePin(LED_FN_PIN, !LED_PIN_ON_STATE);
    setPinOutput(LED_MACRO_PIN);
    writePin(LED_MACRO_PIN, !LED_PIN_ON_STATE);
    setPinOutput(LED_WIN_LOCK_PIN);
    writePin(LED_WIN_LOCK_PIN, !LED_PIN_ON_STATE);

    /* Direct Pin Switches */
    setPinInputHigh(DIRECT_WIN_LOCK_PIN);
    setPinInputHigh(DIRECT_RGB_TOGG_PIN);
    setPinInputHigh(DIRECT_ENCODER_PUSH_PIN);
}

void housekeeping_task_kb(void) {
    extended_led_t extended_led_state = {0};
    if(layer_state_is(_FN)) extended_led_state.fn_active = !extended_led_state.fn_active;
    if(keymap_config.no_gui) extended_led_state.gui_lock = !extended_led_state.gui_lock;
    /* Write LED state to hardware */
    writePin(LED_FN_PIN, extended_led_state.fn_active);
    writePin(LED_MACRO_PIN, extended_led_state.macro);
    writePin(LED_WIN_LOCK_PIN, extended_led_state.gui_lock);
}

/* matrix state(1:on, 0:off) */
extern matrix_row_t raw_matrix[MATRIX_ROWS]; // raw values

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

static inline uint8_t readMatrixPin(pin_t pin) {
    if (pin != NO_PIN) {
        return (readPin(pin) == 0) ? 0 : 1;
    } else {
        return 1;
    }
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    matrix_row_t curr_matrix[MATRIX_ROWS] = {0};
    // Set row, read cols
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
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

#ifdef RGB_MATRIX_ENABLE
void shutdown_user(void) {
    // Disable RGB on software shutdown
    SLED1734X_sw_shutdown(DRIVER_ADDR_1);
    SLED1734X_sw_shutdown(DRIVER_ADDR_2);
}
#endif // RGB_MATRIX_ENABLE
