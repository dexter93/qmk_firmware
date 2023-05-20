#pragma once
#define HAL_USE_I2C TRUE
/* I2C fallback driver for RGB and slave matrix */
#define SW_I2C_USE_I2C1 TRUE
#define SW_I2C_USE_I2C2 TRUE
#define SW_I2C_USE_OSAL_DELAY FALSE
#include_next <halconf.h>
