/* Copyright 2015-2021 Jack Humbert
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
#include "sendstring_swedish.h"

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
#define PASTEHIST LGUI(KC_V)
#define SCRSHOT LGUI(LSFT(KC_S))
#define NXTWD LCTL(KC_RIGHT)
#define PRVWD LCTL(KC_LEFT)
#define DLINE LCTL(KC_BSPC)
#define CTLALT LCTL(KC_LALT)


enum custom_keycodes {
  SELLINE = SAFE_RANGE,
  BACKLIT,
  SRCHSEL,
  WEMAIL,
  PEMAIL,
};

enum layers  {
    _BASE,
    _SYMBOL,
    _CURSOR, 
    _NUM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_grid(
    MT(MOD_LGUI,KC_ESC),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SE_ARNG,
    LT(_NUM,KC_TAB),   KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    SE_ODIA, SE_ADIA,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    LED_LEVEL, KC_LCTL, KC_LALT, KC_MEH, MO(_SYMBOL), MT(MOD_LCTL, KC_SPC),  MT(MOD_LCTL, KC_SPC),  MO(_CURSOR), KC_RALT, KC_DOWN, KC_UP,   KC_RGHT
),

[_SYMBOL] = LAYOUT_planck_grid(
    WEMAIL, SE_QUOT, SE_LABK, SE_RABK, SE_DQUO, KC_DOT,    SE_AMPR, SE_SCLN, SE_LBRC, SE_RBRC, SE_PERC, _______,
    PEMAIL, SE_EXLM, KC_SLSH, SE_PLUS, SE_EQL, SE_HASH,    SE_PIPE, SE_COLN, SE_LPRN, SE_RPRN, SE_QUES, KC_DEL, 
    SRCHSEL, SE_CIRC, SE_SLSH, SE_ASTR, SE_BSLS, _______,   SE_TILD, SE_DLR,  SE_LCBR, SE_RCBR, SE_AT,   _______,
    TOGGLE_LAYER_COLOR, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______
),

[_CURSOR] = LAYOUT_planck_grid(
    _______,  KC_INS,  KC_PSCR,  KC_APP,  _______, _______,                     KC_PGUP, PRVWD,   KC_UP,   NXTWD,   DLINE,   KC_BSPC,
    _______, KC_LALT,  SCRSHOT,  KC_LSFT,  REDO, KC_CAPS,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, KC_DEL,
    _______, UNDO,     CUT,      COPY,     PASTE, PASTEHIST,                    _______, KC_HOME, SELLINE, KC_END,   _______, _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______
),

[_NUM] = LAYOUT_planck_grid(
    QK_BOOT, _______, _______, _______, _______, _______,   QK_BOOT, KC_7,    KC_8,    KC_9,    SE_ASTR, _______,
    _______, _______, _______, _______, _______, _______,   _______, KC_4,    KC_5,    KC_6,    SE_PLUS, _______,
    _______, _______, _______, _______, _______, _______,   KC_0,    KC_1,    KC_2,    KC_3,    SE_EQL,  _______,
    CG_TOGG, _______, _______, _______, _______, _______,   _______, KC_0, KC_COMM, KC_DOT, _______, _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SELLINE:  // Selects the current line.
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
      }
      return false;
    case WEMAIL:  // Enters work email.
      if (record->event.pressed) {
        SEND_STRING("daniel.virta@anticimex.se");
      }
      return false;
    case PEMAIL:  // Enters personal email.
      if (record->event.pressed) {
        SEND_STRING("daniel.virta@outlook.com");
      }
      return false;
    case SRCHSEL:  // Searches the current selection in a new tab.
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("ct") SS_DELAY(100) SS_LCTL("v") SS_TAP(X_ENTER));
      }
      return false;
  }
  return true;
};

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = {{42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {32, 255, 234}, {32, 255, 234}, {32, 255, 234}, {32, 255, 234}},

    [1] = {{89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}},

    [2] = {{216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {249, 228, 255}, {249, 228, 255}, {249, 228, 255}, {216, 255, 255}, {216, 255, 255}, {105, 255, 255}, {105, 255, 255}, {105, 255, 255}, {216, 255, 255}, {14, 255, 255}, {216, 255, 255}, {216, 255, 255}, {249, 228, 255}, {249, 228, 255}, {249, 228, 255}, {216, 255, 255}, {216, 255, 255}, {105, 255, 255}, {105, 255, 255}, {105, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}},

};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) {
        return false;
    }
    switch (get_highest_layer(layer_state)) {
        case 1:
            set_layer_color(0);
            break;
        case 2:
            set_layer_color(1);
            break;
        case 3:
            set_layer_color(2);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return false;
}