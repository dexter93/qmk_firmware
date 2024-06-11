#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"

// clang-format off

const sled1734x_led_t PROGMEM g_sled1734x_leds[SLED1734X_LED_COUNT] = {
/* Refer to SLED1734X manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, CA1_D,    CA3_D,    CA2_D},
    {0, CA1_E,    CA3_E,    CA2_E},
    {0, CA1_F,    CA3_F,    CA2_F},
    {0, CA1_G,    CA3_G,    CA2_G},
    {0, CA1_H,    CA3_H,    CA2_H},
    {0, CA1_I,    CA3_I,    CA2_I},
    {0, CA1_J,    CA3_J,    CA2_J},

    {0, CA4_A,    CA5_A,    CA6_A},
    {0, CA4_B,    CA5_B,    CA6_B},
    {0, CA4_C,    CA5_C,    CA6_C},
    {0, CA4_G,    CA5_G,    CA6_G},
    {0, CA4_H,    CA5_H,    CA6_H},
    {0, CA4_I,    CA5_I,    CA6_I},
    {0, CA4_J,    CA5_J,    CA6_J},
    {0, CA4_K,    CA5_K,    CA6_K},

    {0, CA7_A,    CA8_A,    CA9_A},
    {0, CA7_B,    CA8_B,    CA9_B},
    {0, CA7_C,    CA8_C,    CA9_C},
    {0, CA7_D,    CA8_D,    CA9_D},
    {0, CA7_E,    CA8_E,    CA9_E},
    {0, CA7_F,    CA8_F,    CA9_F},
    {0, CA7_I,    CA8_I,    CA9_I},

    {0, CB1_A,    CB2_A,    CB3_A},
    {0, CB1_B,    CB2_B,    CB3_B},
    {0, CB1_C,    CB2_C,    CB3_C},
    {0, CB1_D,    CB2_D,    CB3_D},
    {0, CB1_E,    CB2_E,    CB3_E},
    {0, CB1_F,    CB2_F,    CB3_F},
    {0, CB1_G,    CB2_G,    CB3_G},

    {0, CB4_A,    CB5_A,    CB6_A},
    {0, CB4_B,    CB5_B,    CB6_B},
    {0, CB4_C,    CB5_C,    CB6_C},
    {0, CB4_D,    CB5_D,    CB6_D},
    {0, CB4_E,    CB5_E,    CB6_E},
    {0, CB4_F,    CB5_F,    CB6_F},
    {0, CB4_G,    CB5_G,    CB6_G},
    {0, CB4_H,    CB5_H,    CB6_H},

    {0, CB4_I,    CB5_I,    CB6_I},
    {0, CB4_J,    CB5_J,    CB6_J},
    {0, CB4_K,    CB5_K,    CB6_K},
    {0, CB4_L,    CB5_L,    CB6_L},
    {0, CB4_O,    CB5_O,    CB6_O},

    {0, CA1_C,    CA2_C,    CA3_C},
    {0, CA1_D,    CA2_D,    CA3_D},
    {0, CA1_E,    CA2_E,    CA3_E},
    {0, CA1_F,    CA2_F,    CA3_F},
    {0, CA1_G,    CA2_G,    CA3_G},
    {0, CA1_H,    CA2_H,    CA3_H},
    {0, CA1_I,    CA2_I,    CA3_I},

    {1, CA1_C,    CA2_C,    CA3_C},
    {1, CA1_D,    CA2_D,    CA3_D},
    {1, CA1_E,    CA2_E,    CA3_E},

    {0, CA1_J,    CA2_J,    CA3_J},
    {0, CA1_K,    CA2_K,    CA3_K},
    {0, CA1_L,    CA2_L,    CA3_L},
    {0, CA1_M,    CA2_M,    CA3_M},
    {0, CA1_N,    CA2_N,    CA3_N},
    {0, CA1_O,    CA2_O,    CA3_O},
    {0, CA1_P,    CA2_P,    CA3_P},

    {1, CA1_F,    CA2_F,    CA3_F},
    {1, CA1_G,    CA2_G,    CA3_G},
    {1, CA1_H,    CA2_H,    CA3_H},
    {1, CA1_I,    CA2_I,    CA3_I},
    {1, CA1_J,    CA2_J,    CA3_J},
    {1, CA1_K,    CA2_K,    CA3_K},
    {1, CA1_L,    CA2_L,    CA3_L},

    {0, CA4_A,    CA5_A,    CA6_A},
    {0, CA4_B,    CA5_B,    CA6_B},
    {0, CA4_C,    CA5_C,    CA6_C},
    {0, CA4_G,    CA5_G,    CA6_G},
    {0, CA4_H,    CA5_H,    CA6_H},
    {0, CA4_I,    CA5_I,    CA6_I},
    {0, CA4_J,    CA5_J,    CA6_J},
    {0, CA4_K,    CA5_K,    CA6_K},

    {1, CA1_J,    CA2_J,    CA3_J},
    {1, CA1_K,    CA2_K,    CA3_K},
    {1, CA1_L,    CA2_L,    CA3_L},
    {1, CA1_J,    CA2_J,    CA3_J},
    {1, CA1_K,    CA2_K,    CA3_K},
    {1, CA1_L,    CA2_L,    CA3_L},

    {0, CA4_L,    CA5_L,    CA6_L},
    {0, CA4_M,    CA5_M,    CA6_M},
    {0, CA4_N,    CA5_N,    CA6_N},
    {0, CA4_O,    CA5_O,    CA6_O},
    {0, CA4_P,    CA5_P,    CA6_P},
    {0, CA8_O,    CA7_O,    CA9_O},
    {0, CA8_A,    CA7_A,    CA9_A},

    {1, CA4_F,    CA5_F,    CA6_F},
    {1, CA4_G,    CA5_G,    CA6_G},
    {1, CA4_H,    CA5_H,    CA6_H},

    {0, CA8_B,    CA7_B,    CA9_B},
    {0, CA8_C,    CA7_C,    CA9_C},
    {0, CA8_D,    CA7_D,    CA9_D},
    {0, CA8_E,    CA7_E,    CA9_E},
    {0, CA8_F,    CA7_F,    CA9_F},
    {0, CA8_J,    CA7_J,    CA9_J},

    {1, CA4_J,    CA5_J,    CA6_J},
    {1, CA4_K,    CA5_K,    CA6_K},
    {1, CA4_L,    CA5_L,    CA6_L},
    {1, CA4_M,    CA5_M,    CA6_M},
    {1, CA4_N,    CA5_N,    CA6_N},

    {0, CA8_K,    CA7_K,    CA9_K},
    {0, CA8_L,    CA7_L,    CA9_L},
    {0, CA8_M,    CA7_M,    CA9_M},
    {0, CA8_N,    CA7_N,    CA9_N},
    {0, CA8_O,    CA7_O,    CA9_O},
    {0, CA8_P,    CA7_P,    CA9_P},

    {1, CA4_O,    CA5_O,    CA6_O},
    {1, CA4_P,    CA5_P,    CA6_P},
//    {1, CA8_A,    CA7_A,    CA9_A},
//    {1, CA8_B,    CA7_B,    CA9_B},
//    {1, CA8_C,    CA7_C,    CA9_C},

};
#endif