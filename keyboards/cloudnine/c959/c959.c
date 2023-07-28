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
#include "c959.h"
#include "i2c_master.h"
#include "rgb_matrix.h"
#include "debug.h"
#include "wait.h"
#include "gpio.h"

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

void shutdown_user(void) {
    /* Disable RGB on suspend */
    SLED1734X_sw_shutdown(DRIVER_ADDR_1);
    SLED1734X_sw_shutdown(DRIVER_ADDR_2);
}

#endif // RGB_MATRIX_ENABLE

/* Custom delay function to achieve Fast Mode I2C */
void sw_i2c_delay(void) {
    // done.
}
/* Custom init function for I2C */
void i2c_init(void) {
    // done.
}
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

/* Debug */
void keyboard_post_init_kb(void) {
    debug_enable = true;
    debug_keyboard = true;
    debug_matrix=true;
}