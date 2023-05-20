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
    {0, CA4_K,    CA5_K,    CA6_K}, //BR
    {0, CA4_L,    CA5_L,    CA6_L}, //TR
    {0, CA4_M,    CA5_M,    CA6_M}, //TL
    {0, CA4_N,    CA5_N,    CA6_N}, //BL
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
        // LED Index to Physical Position
                   { 16,0  }, { 30,0  }, { 43,0  }, { 56,0  }, { 69,0  }, { 82,0  }, { 96,0  },            {119,0  }, {132,0  }, {145,0  }, {158,0  }, {171,0  }, {184,0  }, {198,0  }, {211,0  }, {224,0  }, 
        {  0,15 }, { 16,15 }, { 30,15 }, { 43,15 }, { 56,15 }, { 69,15 }, { 82,15 }, { 96,15 },            {119,15 }, {132,15 }, {145,15 }, {158,15 }, {171,15 }, {184,15 },            {204,15 }, {224,15 }, 
        {  0,27 }, { 20,27 }, { 36,27 }, { 49,27 }, { 63,27 }, { 76,27 }, { 89,27 },                       {112,27 }, {125,27 }, {138,27 }, {152,27 }, {165,27 }, {178,27 }, {191,27 }, {208,27 }, {224,27 }, 
        {  0,40 }, { 21,40 }, { 40,40 }, { 53,40 }, { 66,40 }, { 79,40 }, { 92,40 },                       {115,40 }, {128,40 }, {142,40 }, {155,40 }, {168,40 }, {181,40 },            {203,40 }, {224,40 },
        {  0,52 }, { 25,52 },            { 46,52 }, { 59,52 }, { 72,52 }, { 86,52 }, { 99,52 },            {122,52 }, {135,52 }, {148,52 }, {161,52 }, {175,52 },            {193,52 }, {211,52 }, {224,52 },
        {  0,64 }, { 18,64 }, { 35,64 }, { 51,64 },            { 82,64 },                                             {128,64 },            {160,64 },            {180,64 }, {198,64 }, {211,64 }, {224,64 },
        // encoder
        {  105,64 }, {  105,64 }, {  105,64 }, {  105,64 },
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
    #ifdef LED_FN_PIN
        setPinOutput(LED_FN_PIN);
        writePin(LED_FN_PIN, !LED_PIN_ON_STATE);
    #endif
    #ifdef LED_MACRO_PIN
        setPinOutput(LED_MACRO_PIN);
        writePin(LED_MACRO_PIN, !LED_PIN_ON_STATE);
    #endif
    #ifdef LED_WIN_LOCK_PIN
        setPinOutput(LED_WIN_LOCK_PIN);
        writePin(LED_WIN_LOCK_PIN, !LED_PIN_ON_STATE);
    #endif
    /* Direct Pin Switches */
    setPinInputHigh(DIRECT_WIN_LOCK_PIN);
    setPinInputHigh(DIRECT_RGB_TOGG_PIN);
    setPinInputHigh(DIRECT_ENCODER_PUSH_PIN);
}

bool led_update_user(led_t led_state) {
    keymap_config.raw = eeconfig_read_keymap();

    extended_led_t extended_led_state = {
                .fn_active = led_state.reserved & (1 << 0),
                .macro = led_state.reserved & (1 << 1),
                .gui_lock = led_state.reserved & (1 << 2)
        };
    if(layer_state_is(_FN)) extended_led_state.fn_active = !extended_led_state.fn_active;
    if(keymap_config.no_gui) extended_led_state.gui_lock = !extended_led_state.gui_lock;

    /* Set the reserved bits in led_state */
    led_state.reserved = (extended_led_state.fn_active ? 1 : 0) |
                        (extended_led_state.macro ? 1 : 0) << 1 |
                        (extended_led_state.gui_lock ? 1 : 0) << 2;
    /* Write LED state to hardware */
    writePin(LED_FN_PIN, extended_led_state.fn_active);
    writePin(LED_MACRO_PIN, extended_led_state.macro);
    writePin(LED_WIN_LOCK_PIN, extended_led_state.gui_lock);
    return true;
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
    uint8_t addr = SLAVE_I2C_ADDRESS;
    i2cStart(&I2CD2, &slavei2cconfig);
    i2c_status_t ret = i2cMasterReceiveTimeout(&I2CD2, (addr >> 1), buf, sizeof(buf), TIME_MS2I(100));
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

void shutdown_user(void) {
    // Disable RGB on software shutdown
    SLED1734X_sw_shutdown(DRIVER_ADDR_1);
    SLED1734X_sw_shutdown(DRIVER_ADDR_2);
}