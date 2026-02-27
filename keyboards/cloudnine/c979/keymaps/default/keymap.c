// Copyright 2025 Dimitris Mantzouranis <d3xter93@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers{
    WIN_BASE,
    WIN_FN,
    MAC_BASE,
    MAC_FN,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define MC_LOCK LCTL(LCMD(KC_Q))
#define PC_LOCK LGUI(KC_L)
#define MC_MODE DF(MAC_BASE)
#define PC_MODE DF(WIN_BASE)

enum custom_keycodes {
    RGB_TEST = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐ ┌───┐   ┌───┬───┬───┬───┐ ┌───┐          ┌───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐            ╭────╮
     * ├───┤ │Esc│   │F1 │F2 │F3 │F4 │ │F5 │          │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PSc│Scr│Pse│            │ENC │
     * └───┘ └───┘   └───┴───┴───┴───┘ └───┘          └───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘            ╰────╯
     * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐          ┌───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
     * │ M1│ │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │          │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │Ins│Hom│PgU│ │Num│ / │ * │ - │
     * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘        ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
     * │ M2│ │ Tab │ Q │ W │ E │ R │ T │          │ Y │ U │ I │ O │ P │ [ │ ] │  \  │ │Del│End│PgD│ │ 7 │ 8 │ 9 │   │
     * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐         └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │
     * │ M3│ │ Caps │ A │ S │ D │ F │ G │          │ H │ J │ K │ L │ ; │ ' │  Enter │               │ 4 │ 5 │ 6 │   │
     * ├───┤ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐        └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤
     * │ M4│ │ Shift  │ Z │ X │ C │ V │ B │          │ N │ M │ , │ . │ / │    Shift │     │ ↑ │     │ 1 │ 2 │ 3 │   │
     * ├───┤ ├────┬───┴┬──┴─┬─┴───┴───┴───┤       ┌──┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤Ent│
     * │ M5│ │Ctrl│GUI │Alt │             │       │             │ Alt│ GUI│Menu│Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │   │
     * └───┘ └────┴────┴────┴─────────────┘       └─────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
     */
    [WIN_BASE] = LAYOUT_fullsize_ansi_split_spc(
        PC_LOCK,
        RM_NEXT,     KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,            KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,     KC_PSCR, KC_SCRL, KC_PAUS,                               KC_MUTE,
        KC_HOME,     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,     KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_END,      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,    KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_COPY,     KC_CAPS,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,                                   KC_P4,   KC_P5,   KC_P6,
        KC_PSTE,     KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT,             KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        MO(WIN_FN),  KC_LCTL,   KC_LWIN, KC_LALT,          KC_SPC,                             KC_SPC,                    KC_RALT, KC_RWIN, MO(WIN_FN), KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT
    ),
    [WIN_FN] = LAYOUT_fullsize_ansi_split_spc(
        _______,
        RM_TOGG,     _______, KC_BRID, KC_BRIU, KC_TASK, KC_FLXP,          MC_MODE,             KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,    _______, _______, _______,                               KC_MUTE,
        _______,     _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,    RM_HUEU, RM_SATU, RM_VALU,    _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______, _______,    RM_HUED, RM_SATD, RM_VALD,    _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,          QK_BOOT,                                  _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,          _______,             RM_SPDU,             _______, _______, _______, _______,
        RGB_TEST,    _______, _______, _______,          _______,                               _______,                   _______, _______, _______, RM_TOGG,    RM_PREV, RM_SPDD, RM_NEXT,    _______,          _______
    ),
    [MAC_BASE] = LAYOUT_fullsize_ansi_split_spc(
        MC_LOCK,
        RM_NEXT,     KC_ESC,    KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD,          KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,     KC_PSCR, KC_SCRL, KC_PAUS,                               KC_MUTE,
        KC_HOME,     KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,     KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_END,      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,    KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_COPY,     KC_CAPS,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,                                   KC_P4,   KC_P5,   KC_P6,
        KC_PSTE,     KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT,             KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        MO(MAC_FN),  KC_LCTL,   KC_LOPT, KC_LCMD,          KC_SPC,                             KC_SPC,                    KC_RCMD, KC_ROPT, MO(MAC_FN), KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT
    ),
    [MAC_FN] = LAYOUT_fullsize_ansi_split_spc(
        _______,

        RM_TOGG,     _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,          PC_MODE,             KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,    _______, _______, _______,                               KC_MUTE,
        _______,     _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,    RM_HUEU, RM_SATU, RM_VALU,    _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______, _______,    RM_HUED, RM_SATD, RM_VALD,    _______, _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,          QK_BOOT,                                  _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,          _______,             RM_SPDU,             _______, _______, _______, _______,
        RGB_TEST,    _______, _______, _______,          _______,                               _______,                   _______, _______, _______, RM_TOGG,    RM_PREV, RM_SPDD, RM_NEXT,    _______,          _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_TEST:
            if (record->event.pressed) {
                uint8_t mods = get_mods() | get_oneshot_mods() | get_weak_mods();
                bool ctrl  = (mods & MOD_MASK_CTRL);
                bool shift = (mods & MOD_MASK_SHIFT);

                if (ctrl && shift) {
                    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
                    rgb_matrix_sethsv_noeeprom(HSV_WHITE);
                }
            }
            return false;
    }
    return true;
}

void keyboard_post_init_user(void) {
    default_layer_set(1UL << MAC_BASE);
    if(!is_keyboard_left()) {
        gpio_set_pin_output(LED_FN_PIN);
        gpio_set_pin_output(LED_MAC_PIN);
        gpio_set_pin_output(LED_PC_PIN);
    }
}

void housekeeping_task_user(void) {
    static layer_state_t last_layer = 0;
    static layer_state_t last_default = 0;

    if (layer_state == last_layer && default_layer_state == last_default) return;

    last_layer = layer_state;
    last_default = default_layer_state;

    layer_state_t combined = layer_state | default_layer_state;
    uint8_t base = get_highest_layer(default_layer_state);

    if (base > MAC_BASE) return;

    layer_state_set_user(combined);

}

layer_state_t layer_state_set_user(layer_state_t state) {
    if(!is_keyboard_left()) {
        bool fn_active = layer_state_cmp(state, WIN_FN) || layer_state_cmp(state, MAC_FN);
        uint8_t base_layer = get_highest_layer(default_layer_state);
        writePin(LED_FN_PIN, fn_active);
        writePin(LED_PC_PIN, base_layer == WIN_BASE);
        writePin(LED_MAC_PIN, base_layer == MAC_BASE);
    }
    return state;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif
