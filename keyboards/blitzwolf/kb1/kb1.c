/* Copyright 2019 Stephen Peery
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

#include "kb1.h"
#include "rgb_matrix.h"

// void reset_keyboard_kb(){
// // #ifdef SN32_BOOTLOADER_ADDRESS
//     // enter_bootloader_mode_if_requested();
//     bootloader_jump();
// // #endif
// }

led_config_t g_led_config = { {
  {   0,      1,   2,      3,      4,      5,   6,      7,      8,   9,  10,  11,     12,  13, },
  {  14,     15,  16,     17,     18,     19,  20,     21,     22,  23,  24,  25,     26,  27, },
  {  28,     29,  30,     31,     32,     33,  34,     35,     36,  37,  38,  39, NO_LED,  41, },
  {  42, NO_LED,  44,     45,     46,     47,  48,     49,     50,  51,  52,  53,     54,  55, },
  {  56,     57,  58, NO_LED, NO_LED, NO_LED,  62, NO_LED, NO_LED,  65,  66,  67,     68,  69  }
}, {
    { 1 *12, 0 }, { 2 *12, 0 }, { 3 *12, 0 }, { 4 *12, 0 }, { 5 *12, 0 },  { 6 *12, 0  }, { 7 *12, 0  }, { 8 *12, 0 }, { 9 *12, 0  }, { 10*12, 0 }, { 11*12, 0 }, { 12*12, 0 }, { 13*12, 0 }, { 14*12, 0 },
    { 1 *12, 1 }, { 2 *12, 1 }, { 3 *12, 1 }, { 4 *12, 1 }, { 5 *12, 1 },  { 6 *12, 1  }, { 7 *12, 1  }, { 8 *12, 1 }, { 9 *12, 1  }, { 10*12, 1 }, { 11*12, 1 }, { 12*12, 1 }, { 13*12, 1 }, { 14*12, 1 },
    { 1 *12, 2 }, { 2 *12, 2 }, { 3 *12, 2 }, { 4 *12, 2 }, { 5 *12, 2 },  { 6 *12, 2  }, { 7 *12, 2  }, { 8 *12, 2 }, { 9 *12, 2  }, { 10*12, 2 }, { 11*12, 2 }, { 12*12, 2 }, { 13*12, 2 }, { 14*12, 2 },
    { 1 *12, 3 }, { 2 *12, 3 }, { 3 *12, 3 }, { 4 *12, 3 }, { 5 *12, 3 },  { 6 *12, 3  }, { 7 *12, 3  }, { 8 *12, 3 }, { 9 *12, 3  }, { 10*12, 3 }, { 11*12, 3 }, { 12*12, 3 }, { 13*12, 3 }, { 14*12, 3 },
    { 1 *12, 4 }, { 2 *12, 4 }, { 3 *12, 4 }, { 4 *12, 4 }, { 5 *12, 4 },  { 6 *12, 4  }, { 7 *12, 4  }, { 8 *12, 4 }, { 9 *12, 4  }, { 10*12, 4 }, { 11*12, 4 }, { 12*12, 4 }, { 13*12, 4 }, { 14*12, 4 },
}, {
/* 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14*/
   4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  // 0
   4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  // 1
   4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  0,  4,  // 2
   4,  0,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  // 3
   4,  4,  4,  0,  0,  0,  4,  0,  0,  4,  4,  4,  4,  4,  // 4
} };
