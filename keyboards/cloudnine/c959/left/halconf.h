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

#define HAL_USE_GPT TRUE
#define SN32_GPT_USE_CT16B1 TRUE
#define HAL_USE_I2C TRUE
/* I2C fallback driver for RGB and slave matrix */
#define SW_I2C_USE_I2C1 TRUE
#define SW_I2C_USE_I2C2 TRUE
#define SW_I2C_USE_OSAL_DELAY FALSE
#include_next <halconf.h>
#undef HAL_USE_PWM
#define HAL_USE_PWM FALSE
