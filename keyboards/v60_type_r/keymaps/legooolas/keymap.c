/* Copyright 2017 REPLACE_WITH_YOUR_NAME
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

/* This is the default ANSI layout provided by the KBP V60 Type R
* as depicted in their manual and on the stock keycaps.
*/
#include QMK_KEYBOARD_H

//#include "config.h"
//#include "v60_type_r.h"

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Default Layer (Qwerty)
   * ,-----------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   Bs  |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-----------------------------------------------------------|
   * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |LShift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Up       |
   * |-----------------------------------------------------------|
   * |Fn0 |Alt |Gui |      Space              |`   |Lef |Dwn|Rig |
   * `-----------------------------------------------------------'
   */
  [0] = LAYOUT_60_ansi(
               KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
               KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
               KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
               KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_UP,   \
               MO(1),   KC_LALT, KC_LGUI,          KC_SPC,                                      KC_GRV,  KC_LEFT, KC_DOWN, KC_RIGHT),

  /* Keymap 1: FN Layer
   * ,-----------------------------------------------------------.
   * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
   * |-----------------------------------------------------------|
   * |     |   |Up |RGB|RD+|GR+|BL+|   |Prt|Scl|Pau|Up|   | Ins  |
   * |-----------------------------------------------------------|
   * |      |Lft|Dwn|Rig|RD-|GR-|BL-|   |Hme|PgU|Lef|Rig|        |
   * |-----------------------------------------------------------|
   * |        |UMD|BLT|BLC|   |VolD|VolU|Mut|End|PgD|Dwn|PgU     |
   * |-----------------------------------------------------------|
   * |    |AltG|    |                        |    |Home|PgDn|End |
   * `-----------------------------------------------------------'
   */
  [1] = LAYOUT_60_ansi(
               _______,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL, \
               _______,   _______,  KC_UP,    RGB_TOG,  RGB_RI ,  RGB_GI ,  RGB_BI ,   _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,    _______, KC_INS, \
               _______,   KC_LEFT,  KC_DOWN,  KC_RIGHT, RGB_RD ,  RGB_GD ,  RGB_BD ,   _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,          _______,\
               _______,   RGB_MOD,  BL_TOGG,  BL_STEP,  _______,  KC_VOLD,  KC_VOLU,   KC_MUTE, KC_END,  KC_PGDN, KC_DOWN,           KC_PGUP,  \
               _______,   KC_RALT,  _______,            _______,                                                  _______,  KC_HOME, KC_PGDN, KC_END),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // output low
        DDRE  |=  (1<<PE6);
        PORTE &= ~(1<<PE6);
    }
    else {
        // Hi-Z
        DDRE  &= ~(1<<PE6);
        PORTE &= ~(1<<PE6);
    }
}
