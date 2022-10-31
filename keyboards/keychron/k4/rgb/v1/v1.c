#include "v1.h"

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock)
        RGB_MATRIX_INDICATOR_SET_COLOR(55, 255, 0, 0);
    if (host_keyboard_led_state().num_lock)
        RGB_MATRIX_INDICATOR_SET_COLOR(33, 255, 0, 0);
}
