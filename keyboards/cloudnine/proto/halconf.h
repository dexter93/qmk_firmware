#pragma once
#define HAL_USE_PAL TRUE
//#define HAL_USE_GPT TRUE
//#define PAL_USE_CALLBACKS TRUE
#define HAL_USE_SERIAL TRUE
//#define SN32_ST_USE_TIMER CT16B1
#define SN32_UART_UART0_IRQ_PRIORITY          2
#define SN32_I2C_I2C0_IRQ_PRIORITY         3

#include_next <halconf.h>