// Copyright 2023 Dimitris Mantzouranis (@dexter93)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "left.h"
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
    {0, CB5_L,    CB4_L,    CB6_K},
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

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {      0,  1,  2,  3,  4,  5,  6,     7,  8,  9, 10, 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20, 21, 22, 23,    24, 25, 26, 27, 28, 29,     30, 31 },
        { 32, 33, 34, 35, 36, 37, 38,        39, 40, 41, 42, 43, 44, 45, 46, 47 },
        { 48, 49, 50, 51, 52, 53, 54,        55, 56, 57, 58, 59, 60,     61, 62 },
        { 63, 64,     65, 66, 67, 68, 69,    70, 71, 72, 73, 74,     75, 76, 77 },
        { 78, 79, 80, 81,     82,                83,     84,     85, 86, 87, 88 },
    },
    {
        // LED Index to Physical Position
                   { 16,0  }, { 30,0  }, { 43,0  }, { 56,0  }, { 69,0  }, { 82,0  }, { 96,0  },            {119,0  }, {132,0  }, {145,0  }, {158,0  }, {171,0  }, {184,0  }, {198,0  }, {211,0  }, {224,0  }, 
        {  0,15 }, { 16,15 }, { 30,15 }, { 43,15 }, { 56,15 }, { 69,15 }, { 82,15 }, { 96,15 },            {119,15 }, {132,15 }, {145,15 }, {158,15 }, {171,15 }, {184,15 },            {204,15 }, {224,15 }, 
        {  0,27 }, { 20,27 }, { 36,27 }, { 49,27 }, { 63,27 }, { 76,27 }, { 89,27 },                       {112,27 }, {125,27 }, {138,27 }, {152,27 }, {165,27 }, {178,27 }, {191,27 }, {208,27 }, {224,27 }, 
        {  0,40 }, { 21,40 }, { 40,40 }, { 53,40 }, { 66,40 }, { 79,40 }, { 92,40 },                       {115,40 }, {128,40 }, {142,40 }, {155,40 }, {168,40 }, {181,40 },            {203,40 }, {224,40 },
        {  0,52 }, { 25,52 },            { 46,52 }, { 59,52 }, { 72,52 }, { 86,52 }, { 99,52 },            {122,52 }, {135,52 }, {148,52 }, {161,52 }, {175,52 },            {193,52 }, {211,52 }, {224,52 },
        {  0,64 }, { 18,64 }, { 35,64 }, { 51,64 },            { 82,64 },                                             {128,64 },            {160,64 },            {180,64 }, {198,64 }, {211,64 }, {224,64 },
    },
    {
        // RGB LED Index to Flag
           1, 1, 1, 1, 1, 1, 1,     1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 4, 4, 4, 4, 4, 4, 4,     4, 4, 4, 4, 4, 1,    1, 1,
        1, 4, 4, 4, 4, 4, 4,        4, 4, 4, 4, 4, 4, 1, 1, 1,
        1, 4, 4, 4, 4, 4, 4,        4, 4, 4, 4, 1, 1,    1, 1,
        1, 4,    4, 4, 4, 4, 4,     4, 4, 4, 1,    1, 1, 1, 1,
        1, 1, 1, 1,    4,           1,    1,       1, 1, 1, 1,
    }
};

#endif // RGB_MATRIX_ENABLE
