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
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "midi.h"

extern MidiDevice midi_device;

// 1st layer on the cycle
#define LAYER_CYCLE_START 0
// Last layer on the cycle
#define LAYER_CYCLE_END   3

enum custom_keycodes {
    SLCT_A = SAFE_RANGE,
    LAY_UP,
    LAY_DN
};
enum midi_cc_keycodes_LTRM { MIDI_CC1, MIDI_CC2, MIDI_CC3, MIDI_CC4, MIDI_CC5, MIDI_CC6, MIDI_CC7, MIDI_CC8, MIDI_CC9, MIDI_CC10, MIDI_CC11, MIDI_CC12, MIDI_CC13, MIDI_CC14, MIDI_CC15, MIDI_CC16, MIDI_CC17, MIDI_CC18, MIDI_CC19, MIDI_CC20, MIDI_CC21, MIDI_CC22, MIDI_CC23, MIDI_CC24, MIDI_CC25 };
static uint8_t current_MIDI_ccNumber         = 1;
static char    current_MIDI_ccNumber_char[3] = {'0', '1', '\0'};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        GUI_TOG,
        _______, KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_PAUS, KC_HOME,
        SLCT_A,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,           KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC, KC_END,
        KC_COPY, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_PSTE, KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_CUT,  KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        MO(_FN), KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,                                    KC_SPC,           KC_RALT, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT,
                                                                       KC_MUTE
    ),
    [_FN] = LAYOUT(
        _______,
        _______,  QK_BOOT, KC_MSEL, KC_MPLY, KC_MSTP, KC_MPRV,  KC_MNXT, _______,        _______, _______, _______, _______,  _______, _______, KC_SCRL,  KC_INS, _______,
        _______,  _______, _______, _______, _______, _______,  _______, _______,        _______, _______, _______, _______,  _______, _______,          _______, _______,
        _______,  _______, _______, _______, _______, _______,  _______,                 _______, _______, _______, _______,  _______, _______, _______, _______, _______,
        LAY_UP,  _______, _______, _______, _______, _______,  _______,                 _______, _______, _______, _______,  _______, _______,          _______, _______,
        LAY_DN,  _______,          _______, _______, _______,  _______, _______,        _______, _______, _______, _______,  _______,          _______, _______, _______,
        _______,  _______, _______, _______,          _______,                                    _______,          _______,  _______,          _______, _______, _______,
                                                                         _______
    ),
    [_LTRM] = LAYOUT(
        _______,
        _______,   QK_BOOT,   KC_MSEL,   KC_MPLY,   KC_MSTP,   KC_MPRV,   KC_MNXT,   _______,        _______, _______, _______, _______,  _______, _______, KC_SCRL,  KC_INS, _______,
        _______,  MIDI_CC1,  MIDI_CC2,  MIDI_CC3,  MIDI_CC4,  MIDI_CC5,  MIDI_CC6,  MIDI_CC7,        _______, _______, _______, _______,  _______, _______,          _______, _______,
        _______,  MIDI_CC8,  MIDI_CC9, MIDI_CC10, MIDI_CC11, MIDI_CC12, MIDI_CC13,                   _______, _______, _______, _______,  _______, _______, _______, _______, _______,
        _______, MIDI_CC14, MIDI_CC15, MIDI_CC16, MIDI_CC17, MIDI_CC18, MIDI_CC19,                   _______, _______, _______, _______,  _______, _______,          _______, _______,
        _______, MIDI_CC20,            MIDI_CC21, MIDI_CC22, MIDI_CC23, MIDI_CC24, MIDI_CC25,        _______, _______, _______, _______,  _______,          _______, _______, _______,
        _______,   _______, _______, _______,          _______,                                               _______,          _______,  _______,          _______, _______, _______,
                                                                         _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SLCT_A:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_DELAY(5) "a"));
        return false;
      }
      break;
    case LAY_UP: {
          // Our logic will happen on presses, nothing is done on releases
          if (!record->event.pressed) {
            // We've already handled the keycode (doing nothing), let QMK know so no further code is run unnecessarily
            return false;
          }

          uint8_t current_layer = get_highest_layer(layer_state);

          // Check if we are within the range, if not quit
          if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
            return false;
          }

          uint8_t next_layer = current_layer + 1;
          if (next_layer > LAYER_CYCLE_END) {
              next_layer = LAYER_CYCLE_START;
          }
          layer_move(next_layer);
          return false;
      }
      break;
      case LAY_DN: {
            // Our logic will happen on presses, nothing is done on releases
            if (!record->event.pressed) {
              // We've already handled the keycode (doing nothing), let QMK know so no further code is run unnecessarily
              return false;
            }

            uint8_t current_layer = get_highest_layer(layer_state);

            // Check if we are within the range, if not quit
            if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
              return false;
            }

            uint8_t next_layer = current_layer - 1;
            if (next_layer > LAYER_CYCLE_END) {
                next_layer = LAYER_CYCLE_START;
            }
            layer_move(next_layer);
            return false;
        }
        break;
        case MIDI_CC1:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 1;
                current_MIDI_ccNumber_char[0] = '0';
                current_MIDI_ccNumber_char[1] = '1';
            } else {
            }
            return false;
            break;
        case MIDI_CC2:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 2;
                current_MIDI_ccNumber_char[0] = '0';
                current_MIDI_ccNumber_char[1] = '2';
            } else {
            }
            return false;
            break;
        case MIDI_CC3:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 3;
                current_MIDI_ccNumber_char[0] = '0';
                current_MIDI_ccNumber_char[1] = '3';
            } else {
            }
            return false;
            break;
        case MIDI_CC4:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 4;
                current_MIDI_ccNumber_char[0] = '0';
                current_MIDI_ccNumber_char[1] = '4';
            } else {
            }
            return false;
            break;
        case MIDI_CC5:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 5;
                current_MIDI_ccNumber_char[0] = '0';
                current_MIDI_ccNumber_char[1] = '5';
            } else {
            }
            return false;
            break;
        case MIDI_CC6:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 6;
                current_MIDI_ccNumber_char[0] = '0';
                current_MIDI_ccNumber_char[1] = '6';
            } else {
            }
            return false;
            break;
        case MIDI_CC7:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 7;
                current_MIDI_ccNumber_char[0] = '0';
                current_MIDI_ccNumber_char[1] = '7';
            } else {
            }
            return false;
            break;
        case MIDI_CC8:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 8;
                current_MIDI_ccNumber_char[0] = '0';
                current_MIDI_ccNumber_char[1] = '8';
            } else {
            }
            return false;
            break;
        case MIDI_CC9:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 9;
                current_MIDI_ccNumber_char[0] = '0';
                current_MIDI_ccNumber_char[1] = '9';
            } else {
            }
            return false;
            break;
        case MIDI_CC10:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 10;
                current_MIDI_ccNumber_char[0] = '1';
                current_MIDI_ccNumber_char[1] = '0';
            } else {
            }
            return false;
            break;
        case MIDI_CC11:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 11;
                current_MIDI_ccNumber_char[0] = '1';
                current_MIDI_ccNumber_char[1] = '1';
            } else {
            }
            return false;
            break;
        case MIDI_CC12:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 12;
                current_MIDI_ccNumber_char[0] = '1';
                current_MIDI_ccNumber_char[1] = '2';
            } else {
            }
            return false;
            break;
        case MIDI_CC13:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 13;
                current_MIDI_ccNumber_char[0] = '1';
                current_MIDI_ccNumber_char[1] = '3';
            } else {
            }
            return false;
            break;
        case MIDI_CC14:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 14;
                current_MIDI_ccNumber_char[0] = '1';
                current_MIDI_ccNumber_char[1] = '4';
            } else {
            }
            return false;
            break;
        case MIDI_CC15:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 15;
                current_MIDI_ccNumber_char[0] = '1';
                current_MIDI_ccNumber_char[1] = '5';
            } else {
            }
            return false;
            break;
        case MIDI_CC16:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 16;
                current_MIDI_ccNumber_char[0] = '1';
                current_MIDI_ccNumber_char[1] = '6';
            } else {
            }
            return false;
            break;
        case MIDI_CC17:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 17;
                current_MIDI_ccNumber_char[0] = '1';
                current_MIDI_ccNumber_char[1] = '7';
            } else {
            }
            return false;
            break;
        case MIDI_CC18:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 18;
                current_MIDI_ccNumber_char[0] = '1';
                current_MIDI_ccNumber_char[1] = '8';
            } else {
            }
            return false;
            break;
        case MIDI_CC19:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 19;
                current_MIDI_ccNumber_char[0] = '1';
                current_MIDI_ccNumber_char[1] = '9';
            } else {
            }
            return false;
            break;
        case MIDI_CC20:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 20;
                current_MIDI_ccNumber_char[0] = '2';
                current_MIDI_ccNumber_char[1] = '0';
            } else {
            }
            return false;
            break;
        case MIDI_CC21:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 21;
                current_MIDI_ccNumber_char[0] = '2';
                current_MIDI_ccNumber_char[1] = '1';
            } else {
            }
            return false;
            break;
        case MIDI_CC22:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 22;
                current_MIDI_ccNumber_char[0] = '2';
                current_MIDI_ccNumber_char[1] = '2';
            } else {
            }
            return false;
            break;
        case MIDI_CC23:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 23;
                current_MIDI_ccNumber_char[0] = '2';
                current_MIDI_ccNumber_char[1] = '3';
            } else {
            }
            return false;
            break;
        case MIDI_CC24:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 24;
                current_MIDI_ccNumber_char[0] = '2';
                current_MIDI_ccNumber_char[1] = '4';
            } else {
            }
            return false;
            break;
        case MIDI_CC25:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 25;
                current_MIDI_ccNumber_char[0] = '2';
                current_MIDI_ccNumber_char[1] = '5';
            } else {
            }
            return false;
            break;
  }
  return true;
}

#if defined(RGB_MATRIX_ENABLE)
bool rgb_matrix_indicators_user(void) {
    // Set encoder color per layer.
    uint8_t led_min = 89;
    uint8_t led_max = 92;
   // RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i <= led_max; i++) {
        //RGB_MATRIX_TEST_LED_FLAGS();
        //if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            if(layer_state_is( _BASE)) rgb_matrix_set_color(i, RGB_WHITE);
            if(layer_state_is( _FN)) rgb_matrix_set_color(i, RGB_OFF);
            if(layer_state_is( _LTRM)) rgb_matrix_set_color(i, RGB_BLUE);
            if(layer_state_is( 3)) rgb_matrix_set_color(i, RGB_GREEN);
       // }
    }
    return led_max < RGB_MATRIX_LED_COUNT;
}
#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN]   = {ENCODER_CCW_CW(KC_CYCLE_DOWN, KC_CYCLE_UP) },
};
#endif
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state)) {
        case _LTRM:
            if (clockwise) {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 65);
                } else {
                midi_send_cc(&midi_device, 0, current_MIDI_ccNumber, 63);
                }
            break;
        default:
            break;
    }
    return true;
}


