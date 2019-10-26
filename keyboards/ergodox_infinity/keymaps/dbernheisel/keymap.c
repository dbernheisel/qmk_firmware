#include QMK_KEYBOARD_H
#include "layers.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_ergodox_pretty(
    KC_EQL,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5, KC_ESC,     KC_ESC,  KC_6, KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,
    KC_GRV,  KC_Q,    KC_W,   KC_E,    KC_R,    KC_T, MO(_RAISE), KC_LBRC, KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    KC_RBRC,
    KC_TAB,  KC_A,    KC_S,   KC_D,    KC_F,    KC_G,                      KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B, KC_LEAD,    KC_BSLS, KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_GRV, KC_BSLS, KC_LGUI,                                  KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_RGUI,
             KC_INS,  KC_PSCR,                                    KC_RALT, KC_RCTL,
                      KC_HOME,                                    KC_PGUP,
    KC_BSPC, KC_DEL,  KC_END,                                     KC_PGDN, KC_ENT, KC_SPC),

	[_COLEMAK] = LAYOUT_ergodox_pretty(
    KC_EQL,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_ESC,     KC_ESC,  KC_6, KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,
    KC_GRV,  KC_Q, KC_W, KC_F, KC_P, KC_G, MO(_RAISE), KC_LBRC, KC_J, KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_RBRC,
    KC_TAB,  KC_A, KC_R, KC_S, KC_T, KC_D,                      KC_H, KC_N,    KC_E,    KC_I,   KC_O,    KC_QUOT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LEAD,    KC_BSLS, KC_K, KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_GRV, KC_BSLS, KC_LGUI,                      KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_RGUI,
             KC_INS, KC_PSCR,                          KC_RALT, KC_RCTL,
                     KC_HOME,                          KC_PGUP,
    KC_BSPC, KC_DEL, KC_END,                           KC_PGDN, KC_ENT, KC_SPC),

	[_RAISE] = LAYOUT_ergodox_pretty(
    BL_TOGG, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F11,     KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_MUTE,
    BL_INC,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_VOLU,
    BL_DEC,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_MRWD, KC_MPRV, KC_MNXT, KC_MFFD, KC_NO,  KC_VOLD,
    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,                                      KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
             KC_NO, RESET,                                  KC_NO, KC_NO,
                    KC_NO,                                  KC_NO,
    KC_NO,   KC_NO, KC_NO,                                  KC_NO, KC_NO, KC_MPLY),

	[_NUM] = LAYOUT_ergodox_pretty(
    KC_EQL, KC_1, KC_2,  KC_3,  KC_4,  KC_5,  KC_ESC,       KC_NO, KC_NO, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_P4, KC_P5,   KC_P6,   KC_PCMM, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEAD,      KC_NO, KC_NO, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                    KC_P0,   KC_P0,   KC_PDOT, KC_PENT, KC_NO,
           KC_NO, KC_NO,                                    KC_NO, KC_NO,
                  KC_NO,                                    KC_NO,
    KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_PENT, KC_NO)
};


LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    // Replace the sequences below with your own sequences.
    SEQ_ONE_KEY(KC_1) {
      // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
      set_single_persistent_default_layer(_QWERTY);
    }
    SEQ_ONE_KEY(KC_2) {
      // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
      set_single_persistent_default_layer(_COLEMAK);
    }
    SEQ_ONE_KEY(KC_3) {
      // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
      set_single_persistent_default_layer(_NUM);
    }
  }
}

void matrix_init_user() {
  backlight_enable();
  backlight_level(BACKLIGHT_LEVELS);
}
