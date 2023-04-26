#include "quantum.h"

/*
Left side is using the ChibiOS fallback i2c driver. This driver does not have provisions for slave mode, but we are using it in master configuration.
Fake mute the slave side calls
*/
#define I2C_SLAVE_REG_COUNT 30

uint8_t i2c_slave_reg[I2C_SLAVE_REG_COUNT];

void i2c_slave_init(uint8_t address){}
void i2c_slave_stop(void){}