/* Copyright 2021 Kyle McCreery
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
 #include "keymap_swedish.h"

#define C_S LCTL_T(KC_S)
#define A_D LALT_T(KC_D)
#define G_F LGUI_T(KC_F)
#define C_J RCTL_T(KC_J)
#define A_K RALT_T(KC_K)
#define G_L RGUI_T(KC_L)
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define NXTWD LCTL(KC_RIGHT)
#define PRVWD LCTL(KC_LEFT)
#define DLINE LCTL(KC_BSPC)

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  WAKA60 = SAFE_RANGE,
};

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _SYMBOL,
    _RAISE,
    _NUMPAD

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
    SE_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SE_ARNG,
    LT(_NUMPAD,KC_TAB),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    SE_ODIA, SE_ADIA,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_MUTE,  KC_N,    KC_M,    KC_COMM,    KC_DOT, KC_SLSH,  KC_RSFT,
    LCA(KC_NO), KC_LGUI, KC_LALT, KC_LCTL,   MO(_SYMBOL),  KC_ENT, KC_DEL,   KC_SPC,   MO(_RAISE),  KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT
    ),
    [_SYMBOL] = LAYOUT(
    SE_PERC, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    SE_AMPR, SE_QUOT, SE_LABK,  SE_RABK, SE_DQUO, KC_DOT,           SE_AMPR, SE_SCLN, SE_LBRC, SE_RBRC, SE_PERC, _______,
    _______, SE_EXLM, KC_SLSH,  SE_PLUS, SE_EQL, SE_HASH,           SE_PIPE, SE_COLN, SE_LPRN, SE_RPRN, SE_QUES, KC_DEL,
    _______, SE_CIRC, SE_SLSH, SE_ASTR, SE_BSLS,  _______, _______, SE_TILD, SE_DLR, SE_LCBR, SE_RCBR, SE_AT, _______,
    _______, _______, _______,  _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, KC_INS, KC_PSCR, KC_APP, _______, _______,          KC_PGUP, PRVWD, KC_UP, NXTWD, DLINE, KC_BSPC,
    _______, KC_LALT, KC_LCTL, KC_LSFT, REDO, KC_CAPS,          KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, KC_DEL,
    _______, UNDO, CUT, COPY, PASTE, _______, _______, _______, KC_HOME, _______, KC_END, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_NUMPAD] = LAYOUT(
    QK_BOOT, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, KC_7, KC_8, KC_9, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, KC_4, KC_5, KC_6, SE_PLUS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, LSFT(KC_DOT), _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_SLSH, KC_COMM, KC_DOT, _______
    )
};

#ifdef ENCODER_MAP_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
        [_BASE] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
        [_SYMBOL]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
        [_RAISE]  = { ENCODER_CCW_CW(_______, _______) },
        [_NUMPAD]  = { ENCODER_CCW_CW(_______, _______) },
    };
#endif
