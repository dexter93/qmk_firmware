#include "quantum.h"

/* Custom delay function to achieve Fast Mode I2C */
void sw_i2c_delay(void) {
    for(uint8_t i=0; i<13; i++) __NOP();
}

/* Debug */
void keyboard_post_init_user(void) {
    debug_enable = true;
    debug_keyboard = true;
    debug_matrix=true;
}
