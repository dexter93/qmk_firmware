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

#pragma once

/* Board and GPIO setup */
#ifndef RGB_MATRIX_ENABLE
#define WAIT_US_TIMER GPTD2
#endif
#define MATRIX_UNSELECT_DRIVE_HIGH
#define MATRIX_IO_DELAY 1
#define GPIO_INPUT_PIN_DELAY 0

/* Debug options */
#define DEBUG_MATRIX_SCAN_RATE

/* RGB LED Config */
#define SN32_RGB_MATRIX_ROW_PINS { A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, B0, B1 }
#define SN32_RGB_MATRIX_COL_PINS { B6, B7, B8, B9, B10, B11, B12, B13, B14, B15 }
#define SN32_PWM_OUTPUT_ACTIVE_LEVEL SN32_PWM_OUTPUT_ACTIVE_HIGH
#define SN32_RGB_OUTPUT_ACTIVE_LEVEL SN32_RGB_OUTPUT_ACTIVE_LOW
#define RGB_MATRIX_LED_COUNT (60)

/* Disable RGB lighting when PC is in suspend */
#define RGB_DISABLE_WHEN_USB_SUSPENDED

/* RGB Matrix Effects */
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES