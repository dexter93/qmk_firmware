#include "quantum.h"

/* Custom delay function to achieve Fast Mode I2C */
void sw_i2c_delay(void) {
    for(uint8_t i=0; i<13; i++) __NOP();
}
/* Dummy slave mode */
//#define I2C_SLAVE_REG_COUNT 30

//uint8_t i2c_slave_reg[I2C_SLAVE_REG_COUNT];

//void i2c_slave_init(uint8_t address){}
//void i2c_slave_stop(void){}
/* Debug */
void keyboard_post_init_user(void) {
    debug_enable = true;
    debug_keyboard = true;
    debug_matrix=true;
}
