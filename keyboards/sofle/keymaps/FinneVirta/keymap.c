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


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE, 
    _NUMPAD
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    SOFLE = SAFE_RANGE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  | ,/;  | ./:  |   -  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | CTAL | Del |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_BASE] = LAYOUT(
  SE_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     SE_ARNG,
  LT(_NUMPAD,KC_TAB),   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    SE_ODIA,  SE_ADIA,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     _______,KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTL, MO(_LOWER), KC_ENT,      KC_SPC,  MO(_RAISE), KC_RCTL, KC_RALT, KC_DEL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  '   |  <   |   >  |  "   |  .   |                    |   &  |   ;  |   [  |   ]  |  %   |     |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  !   |  -   |  +   |   =  |  #   |-------.    ,-------|  |   |   :  |   (  |   )  |  ?   |     |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  ^   |  /   |  *   |  \   |     |-------|    |-------|   ~  |   $  |   {  |   }  |   @  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | CTAL | Del |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,  SE_QUOT, SE_LABK, SE_RABK, SE_DQUO, KC_DOT,                          SE_AMPR, SE_SCLN, SE_LBRC, SE_RBRC, SE_PERC, _______,
  _______,  SE_EXLM, KC_SLSH, SE_PLUS, SE_EQL, SE_HASH,                          SE_PIPE, SE_COLN, SE_LPRN, SE_RPRN, SE_QUES, KC_DEL, 
  _______,  SE_CIRC, SE_SLSH, SE_ASTR, SE_BSLS, _______, _______,       _______, SE_TILD, SE_DLR,  SE_LCBR, SE_RCBR, SE_AT, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    | PgUp | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift| Redo | Caps |-------.    ,-------| PgUp | Left | Down | Right| Bspc | Del  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift| Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | CTAL | Del |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,  KC_INS,  KC_PSCR,   KC_APP,  _______, _______,                        KC_PGUP, PRVWD,   KC_UP, NXTWD,DLINE, KC_BSPC,
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  REDO, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_BSPC, KC_DEL,
  _______, UNDO, CUT, COPY, PASTE, _______,  _______,       _______,  _______, KC_HOME, _______, KC_END,   _______, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   QK_BOOT   |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | |    |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | CTAL | Del |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_NUMPAD] = LAYOUT(
  QK_BOOT , _______,  _______ ,  _______ , _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______  , _______, _______ , _______ ,CG_TOGG,_______,                     _______, KC_7, KC_8, KC_9, SE_ASTR, _______,
  _______ , _______,CG_TOGG, _______,    _______,  _______,                     _______, KC_4, KC_5, KC_6, SE_PLUS, _______,
  _______ , _______, _______, _______,    _______,  _______, _______,     _______, _______, KC_1, KC_2, KC_3, SE_EQL, _______,
                   _______, _______, _______, _______, _______,     _______, _______, KC_0, _______, _______
  )
};

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
