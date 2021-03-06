/* Copyright 2019 MechMerlin
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

#define _QWERTY 0
#define _NAV 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,      KC_PGDN,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,              KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,        KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI,   KC_LALT,                       KC_SPC,                              NAV,   KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_NAV] = LAYOUT_65_ansi_blocker(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_VOLU,
        _______,     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,      KC_VOLD,
        _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,
        _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        KC_MPLY, _______,
        _______,   _______,   _______,                      _______,                              _______,   _______,        KC_MPRV, _______, KC_MNXT
    ),

};

const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {2, 2, 2, 2};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
        rgblight_enable();
        rgblight_mode(2);
        rgblight_sethsv(132, 255, 100);
      } else {
        layer_off(_NAV);
        rgblight_mode(1);
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}
