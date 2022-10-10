/* Copyright 2022 Pablo Ramirez <jp.ramangulo@gmail.com>
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

#include "k14.h"

// readability
#define NA NO_LED

// __attribute__ ((weak))
// led_config_t g_led_config = { {
//     {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15 },
//     { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
//     { 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, NA, 44, 45, 46 },
//     { 47, NA, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, NA, 58, 59, 60 },
//     { 61, 62, 63, NA, NA, NA, 64, NA, NA, 65, 66, 67, 68, 69, 70, 71 }
// }, {
//     { 0.00,  0.00 }, { 14.93,  0.00 }, { 29.87,  0.00 }, { 44.80,  0.00 }, { 59.73,  0.00 }, { 74.67,  0.00 }, { 89.60,  0.00 }, { 104.53,  0.00 }, { 119.47,  0.00 }, { 134.40,  0.00 }, { 149.33,  0.00 }, { 164.27,  0.00 }, { 179.20,  0.00 }, { 194.13,  0.00 }, { 209.07,  0.00 }, { 224.00,  0.00 },
//     { 0.00, 16.00 }, { 14.93, 16.00 }, { 29.87, 16.00 }, { 44.80, 16.00 }, { 59.73, 16.00 }, { 74.67, 16.00 }, { 89.60, 16.00 }, { 104.53, 16.00 }, { 119.47, 16.00 }, { 134.40, 16.00 }, { 149.33, 16.00 }, { 164.27, 16.00 }, { 179.20, 16.00 }, { 194.13, 16.00 }, { 209.07, 16.00 }, { 224.00, 16.00 },
//     { 0.00, 32.00 }, { 14.93, 32.00 }, { 29.87, 32.00 }, { 44.80, 32.00 }, { 59.73, 32.00 }, { 74.67, 32.00 }, { 89.60, 32.00 }, { 104.53, 32.00 }, { 119.47, 32.00 }, { 134.40, 32.00 }, { 149.33, 32.00 }, { 164.27, 32.00 },                    { 184.13, 32.00 }, { 209.07, 32.00 }, { 224.00, 32.00 },
//     { 7.50, 48.00 },                   { 29.87, 48.00 }, { 44.80, 48.00 }, { 59.73, 48.00 }, { 74.67, 48.00 }, { 89.60, 48.00 }, { 104.53, 48.00 }, { 119.47, 48.00 }, { 134.40, 48.00 }, { 149.33, 48.00 }, { 164.27, 48.00 },                    { 179.20, 48.00 }, { 209.07, 48.00 }, { 224.00, 48.00 },
//     { 0.00, 64.00 }, { 14.93, 64.00 }, { 29.87, 64.00 },                                                       { 89.60, 64.00 },                                       { 134.40, 64.00 }, { 149.33, 64.00 }, { 164.27, 64.00 }, { 179.20, 64.00 }, { 194.13, 64.00 }, { 209.07, 64.00 }, { 224.00, 64.00 },
// }, {
//     4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
//     4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
//     4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 4, 4,
//     1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 1,    4, 4, 4,
//     1, 1, 1,          4,       1, 1, 1, 1, 4, 4, 4,
// } };

void keyboard_post_init_kb(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
