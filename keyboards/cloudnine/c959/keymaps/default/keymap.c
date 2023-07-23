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

enum custom_keycodes {
    SLCT_A = SAFE_RANGE,
    PRNT_ID
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        GUI_TOG,
        RGB_MOD, KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_PAUS, KC_HOME,
        SLCT_A,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,           KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC, KC_END,
        KC_COPY, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_PSTE, KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_CUT,  KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        MO(_FN), KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,                                    KC_SPC,           KC_RALT, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT,
                                                                       KC_MUTE
    ),
    [_FN] = LAYOUT(
        _______,
        RGB_TOG,  QK_BOOT, KC_MSEL, KC_MPLY, KC_MSTP, KC_MPRV,  KC_MNXT, _______,        _______, _______, _______, _______,  _______, _______, KC_SCRL,  KC_INS, _______,
        _______,  _______, _______, _______, _______, _______,  _______, _______,        _______, _______, _______, _______,  _______, _______,          _______, _______,
        _______,  _______, _______, _______, _______, _______,  _______,                 _______, _______, _______, _______,  _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,  _______,                 _______, _______, _______, _______,  _______, _______,          _______, _______,
        _______,  _______,          _______, _______, _______,  _______, _______,        _______, _______, _______, _______,  _______,          _______, _______, _______,
        _______,  PRNT_ID, _______, _______,          _______,                                    _______,          _______,  _______,          _______, _______, _______,
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
      case PRNT_ID:
        if (record->event.pressed) {
          uprintf("Device Serial number: %08lx%08lx \n", SN_UC->H4BYTE, SN_UC->L4BYTE);
          uprintf("Device Serial lower 4 bytes: %08lx \n", SN_UC->L4BYTE);
          uprintf("Device Serial higher 4 bytes: %08lx \n", SN_UC->H4BYTE);
          return false;
        }
        break;
  }
  return true;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
};
#endif
