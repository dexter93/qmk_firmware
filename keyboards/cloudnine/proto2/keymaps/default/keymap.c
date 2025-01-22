// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum custom_keycodes {
    RT_TOGG = SAFE_RANGE,
    RT_RSET,
    RT_PREV,
    RT_NEXT,
    RT_SEND,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(
        QK_BOOT,
        KC_P1,     KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        RT_TOGG,     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        RT_RSET,     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, 
        RT_PREV,     KC_CAPS,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        RT_NEXT,     KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        RT_SEND,     KC_LCTL,   KC_LGUI, KC_LALT,          KC_SPC
    )
};
void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;
    // debug_mouse=true;
}
/*
#if defined(RGB_MATRIX_ENABLE)

#include "sled1734x.h"

static bool    rgb_test_mode   = false;
static uint8_t rgb_led_index   = 0;
static uint8_t rgb_color_index = 0;

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (rgb_test_mode) {
        for (uint8_t i = led_min; i <= led_max; ++i) {
            uint8_t r = 0, g = 0, b = 0;
            if (i == rgb_led_index) {
                r = (rgb_color_index == 0) ? 0xFF : 0;
                g = (rgb_color_index == 1) ? 0xFF : 0;
                b = (rgb_color_index == 2) ? 0xFF : 0;
            }
            rgb_matrix_set_color(i, r, g, b);
        }
    }
    return false;
}

static char send_buf[32];

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        switch (keycode) {
            case RT_TOGG:
                rgb_test_mode = !rgb_test_mode;
                return false;

            case RT_RSET:
                rgb_led_index   = 0;
                rgb_color_index = 0;
                return false;

            case RT_PREV:
                if (rgb_color_index > 0) {
                    rgb_color_index--;
                } else {
                    rgb_color_index = 2;
                    if (rgb_led_index > 0) {
                        rgb_led_index--;
                    } else {
                        rgb_led_index = SLED1734X_LED_COUNT - 1;
                    }
                }
                rgb_matrix_set_color_all(0xFF,0,0);
                return false;

            case RT_NEXT:
                if (++rgb_color_index > 2) {
                    rgb_color_index = 0;
                    if (++rgb_led_index >= SLED1734X_LED_COUNT) {
                        rgb_led_index = 0;
                    }
                }
                rgb_matrix_set_color_all(0,0xFF,0);
                return false;

            case RT_SEND:
                rgb_matrix_set_color_all(0,0,0xFF);
                if (rgb_led_index < SLED1734X_LED_COUNT) {
                    // SLED1734x-specific code
                    sled1734x_led_t led = g_sled1734x_leds[rgb_led_index];

                    // Determine the color register (R, G, B) based on rgb_color_index
                    uint8_t reg = (rgb_color_index == 0) ? led.r : ((rgb_color_index == 1) ? led.g : led.b);

                    // Calculate the driver and register location
                    uint8_t driver = led.driver;

                    uint8_t adjusted_reg = reg - SLED1734X_OFFSET;

                    // Determine the register bank and number, including handling the "B side" locations
                    if (reg >= CA1_A && reg <= CA8_P) {
                        // A side, adjust the bank and register number
                        char bank = 'A';
                        uint8_t reg_number = 1 + (adjusted_reg) / 16;
                        uint8_t reg_letter = 'A' + (adjusted_reg) % 16; // Ensure A-P range

                        // Create the send buffer with proper formatting
                        snprintf(send_buf, sizeof(send_buf), "%d,%c_%d%c", driver, bank, reg_number, reg_letter);  // Added reg_letter
                    }

                    // Handle the fake locations with offsets for the B side
                    if (reg >= CA9_A && reg <= CB7_P) {
                        // Apply the frame offset for the B side locations
                        char bank = 'B';
                        adjusted_reg = reg - SLED1734X_OFFSET + SLED1734X_FRAME_OFFSET;
                        uint8_t reg_number = 1 + (adjusted_reg) / 16;  // Adjust for the 'B' side
                        uint8_t reg_letter = 'A' + (adjusted_reg) % 16; // Ensure A-P range

                        // Create the send buffer with proper formatting
                        snprintf(send_buf, sizeof(send_buf), "%d,%c_%d%c", driver, bank, reg_number, reg_letter);  // Added reg_letter
                    }
                } else {
                    // Handle additional LEDs (beyond total count)
                    static const char colors[3] = {'R', 'G', 'B'};
                    sprintf(send_buf, "+%d,%c", rgb_led_index - SLED1734X_LED_COUNT, colors[rgb_color_index]);
                }

                // Send the buffer
                send_string(send_buf);
                return false;
        }
    }
    return true;
}
#endif
*/