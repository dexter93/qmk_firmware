#pragma once
#define HAL_USE_I2C TRUE
#define PAL_USE_WAIT TRUE
#define PAL_USE_CALLBACKS TRUE

/* I2C fallback driver for RGB */
#define SW_I2C_USE_I2C1 TRUE
#define SW_I2C_USE_OSAL_DELAY FALSE
/*
Left side is using the ChibiOS fallback i2c driver. This driver does not have provisions for slave mode, but we are using it in master configuration.
Fake mute the slave side calls
*/
#define I2C_SUPPORTS_SLAVE_MODE TRUE
#define i2c_lld_get_rxbytes(i2cp) 0
#define i2c_lld_match_address(i2cp, i2cadr) MSG_OK
#define i2c_lld_slave_receive_timeout(i2cp, rxbuf, rxbytes,  timeout) MSG_OK
#define i2c_lld_slave_transmit_timeout(i2cp, txbuf, txbytes, timeout) MSG_OK
#include_next <halconf.h>
