/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#define CTLALT LCTL(KC_LALT)

enum layers  {
    _BASE,
    _SYMBOL,
    _CURSOR, 
    _NUM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   ESC  |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   TAB  |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |Enter |  ESC |  |ADJUST|Space |   N  |   M  |  ,/; | ./:  |   -  | RShift |
 * `----------------------+------+------+------+      +------|  |------+      +------+------+------+----------------------'
 *                        | LAlt | LCTR |SYMBOL|      | GUI  |  | NUM  |      |CURSOR|CTLALT|LEADER|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
      KC_ESC  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , SE_ARNG,
      LT(_NUM,KC_TAB), KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                              KC_H,   KC_J ,  KC_K ,   KC_L ,SE_ODIA, SE_ADIA,
      KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , XXXXXXX, KC_ESC , XXXXXXX, XXXXXXX, KC_N,  KC_M ,KC_COMM, KC_DOT ,KC_SLSH, RSFT_T(KC_DEL),
                                 KC_LALT, KC_LCTL, MO(_SYMBOL), KC_ENT ,KC_LGUI, KC_BSPC, KC_SPC, MO(_CURSOR), CTLALT, QK_LEAD
    ),

/*
 * Symbol Layer
 */
    [_SYMBOL] = LAYOUT(
      _______, SE_QUOT,  SE_LABK , SE_RABK, SE_DQUO , KC_DOT,                                     SE_AMPR, SE_SCLN, SE_LBRC, SE_RBRC,SE_PERC,_______,
      _______, SE_EXLM, KC_SLSH, SE_PLUS, SE_EQL , SE_HASH,                                     SE_PIPE, SE_COLN, SE_LPRN, SE_RPRN, SE_QUES, KC_DEL,
      _______, SE_CIRC, SE_SLSH, SE_ASTR, SE_BSLS, _______, XXXXXXX, _______, _______, XXXXXXX, SE_TILD, SE_DLR, SE_LCBR, SE_RCBR, SE_AT, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Cursor Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |WheelU|      |      |                              |      |PrvWord| Up |NxtWord|      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |       | LCTL |WheelD|LSFT | Bksp |                              | Bksp | Left | Down |Right | Del  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | Undo | Cut  | Copy |Paste |      |      |      |  |      |      |      | Home |      | End  |      |        |
 * `----------------------+------+------+------+      +------|  |------+      +------+------+------+----------------------'
 *                        |      |      |      |      |Space |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_CURSOR] = LAYOUT(
      _______, KC_INS, KC_PSCR, KC_APP, _______, _______,                                     KC_PGUP, PRVWD, KC_UP, NXTWD, DLINE, KC_BSPC,
      _______, KC_LALT, KC_LCTL, KC_LSFT, REDO, KC_CAPS,                                     KC_PGDN, KC_LEFT, KC_DOWN,KC_RIGHT, KC_BSPC, KC_DEL,
      _______,  UNDO  ,   CUT  ,  COPY  , PASTE  , _______, XXXXXXX, _______, _______, XXXXXXX, _______, KC_HOME, _______, KC_END , _______, _______,
                                 _______, _______, _______, _______, KC_SPC , _______, _______, _______, _______, _______
    ),

/*
 * Num Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  1 ! |  2 @ |  3 # |  4 $ |  5 % |                              |  /   |  7 & |  8 * |  9 ( |  -   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |                              |  *   |  4 $ |  5 % |  6 ^ |  +   | Space  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |  0 ) |  1 ! |  2 @ |  3 # |  =   | Enter  |
 * `----------------------+------+------+------+      +------|  |------+      +------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |  ,   |  .   |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      QK_BOOT,  _______  ,  _______  ,  _______  ,  _______  ,  _______  ,                       XXXXXXX,  KC_7  ,  KC_8  ,  KC_9  , SE_ASTR, _______,
      _______,  _______  ,  _______  ,  _______  ,  _______  ,  _______  ,                       XXXXXXX,  KC_4  ,  KC_5  ,  KC_6  , SE_PLUS, KC_SPC ,
      _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX,  KC_0  ,   KC_1  ,  KC_2  ,  KC_3  , SE_EQL, KC_ENT ,
                                 _______, _______, _______, _______, _______, _______, _______, _______, KC_0,  _______
    )
};
