// Copyright 2025 Dimitris Mantzouranis <d3xter93@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#define SN32_SERIAL_USE_UART0 TRUE
#define SN32_I2C_USE_I2C0 TRUE
#define SN32_GPT_USE_CT16B0 TRUE
#define SN32_ST_USE_TIMER SN32_TIM_CT16B1
#include_next <mcuconf.h>
