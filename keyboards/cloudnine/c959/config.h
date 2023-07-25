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
#define WAIT_US_TIMER GPTD2
#define MATRIX_UNSELECT_DRIVE_HIGH
#define MATRIX_IO_DELAY 1
#define GPIO_INPUT_PIN_DELAY 0
/* Debug */
#define DEBUG_MATRIX_SCAN_RATE
/* Master to Slave I2C Connection */
#define I2C2_SCL_PIN C13
#define I2C2_SDA_PIN C12
#define SLAVE_I2C_ADDRESS 0x4f
/* RGB Drivers I2C Connection */
#define I2C1_SCL_PIN C9
#define I2C1_SDA_PIN C10
#define I2C1_SCL_PAL_MODE PAL_MODE_OUTPUT_PUSHPULL
#define I2C1_SDA_PAL_MODE PAL_MODE_OUTPUT_PUSHPULL
#define USE_GPIOV1
/* RGB Matrix Driver Configuration */
#define DRIVER_COUNT 2
#define DRIVER_ADDR_1 0b1110100
#define DRIVER_ADDR_2 0b1110111
#define DRIVER_1_LED_TOTAL (41 + 4)
#define DRIVER_2_LED_TOTAL 48
#define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
/* Direct Pins Configuration */
#define DIRECT_WIN_LOCK_PIN B13
#define DIRECT_RGB_TOGG_PIN B14
#define DIRECT_ENCODER_PUSH_PIN C8
/* Custom Indicators Configuration */
#define LED_FN_PIN B12
#define LED_MACRO_PIN B9
#define LED_WIN_LOCK_PIN B8
/* Enable RGB Framebuffer Effects */
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
/* Enable RGB Reactive Effects */
#define RGB_MATRIX_KEYPRESSES