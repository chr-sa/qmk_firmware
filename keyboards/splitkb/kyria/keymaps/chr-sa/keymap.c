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
#include "keymap_german.h"
#include "oneshot.h"

enum layers {
    _CRTN = 0,
    _QWERTY,
    _NAV,
    _NUM,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SFT = SAFE_RANGE,
    OS_CTL,
    OS_GUI,
    OS_ALT,
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define CRTN     DF(_CRTN)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define NUM      MO(_NUM)
#define SYM_LS   MO(_SYM_LS)
#define NAV_LS   MO(_NAV_LS)
#define NUM_LS   MO(_NUM_LS)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define OSS      OSM(MOD_LSFT)

// clang-format off
#define ALPHA_LAYOUT( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29) \
    LAYOUT( \
      KC_NO, K00, K01, K02, K03, K04,                                      K05, K06, K07, K08, K09, KC_NO, \
      KC_NO, K10, K11, K12, K13, K14,                                      K15, K16, K17, K18, K19, KC_NO, \
      KC_NO, K20, K21, K22, K23, K24, _______,  _______, _______, _______, K25, K26, K27, K28, K29, KC_NO, \
                  ADJUST, KC_LGUI, NUM, KC_SPC, KC_BSPC, SYM, OSS, NAV, KC_RGUI, KC_APP \
    )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // g l d v q f m o u /
    // c r t n b y s e i a
    // z j k h p x w ' , .
    [_CRTN] = ALPHA_LAYOUT(
     DE_G, DE_L, DE_D, DE_V, DE_Q, DE_K, DE_F, DE_O   , DE_U   , DE_QUOT,
     DE_C, DE_R, DE_T, DE_N, DE_P, DE_Y, DE_S, DE_E   , DE_I   , DE_A   ,
     DE_Z, DE_J, DE_M, DE_H, DE_B, DE_X, DE_W, DE_SLSH, DE_COMM, DE_DOT
    ),

    [_QWERTY] = ALPHA_LAYOUT(
     DE_Q, DE_W, DE_E, DE_R, DE_T, DE_Z, DE_U, DE_I   , DE_O  , DE_P   ,
     DE_A, DE_S, DE_D, DE_F, DE_G, DE_H, DE_J, DE_K   , DE_L  , DE_SLSH,
     DE_Y, DE_X, DE_C, DE_V, DE_B, DE_N, DE_M, DE_COMM, DE_DOT, DE_MINS
    ),

    [_NAV] = LAYOUT(
      _______, CW_TOGG, KC_END , KC_UP  , KC_HOME, KC_PGUP,                                     _______, DE_SS  , DE_ODIA, DE_UDIA, _______, _______,
      _______, KC_TAB , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                     _______, OS_CTL , OS_SFT , OS_ALT , OS_GUI , _______,
      _______, KC_DEL , KC_TAB , KC_ESC , KC_BSPC, KC_RGUI, _______, _______, _______, _______, _______, DE_ADIA, _______, _______, _______, _______,
                                  _______, _______, _______, KC_ENT, _______, _______, _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     DE_PLUS, DE_7, DE_8, DE_9, DE_SLSH, _______,
      _______, OS_GUI , OS_ALT , OS_SFT , OS_CTL , _______,                                     DE_MINS, DE_4, DE_5, DE_6, KC_ENT , _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DE_EQL , DE_1, DE_2, DE_3, DE_ASTR, _______,
                                 _______, _______, _______, _______, _______, _______, DE_0, _______, _______, _______
    ),

    [_SYM] = LAYOUT(
     _______ , DE_DEG , DE_PLUS, DE_LCBR, DE_RCBR, DE_AT  ,                                     DE_ACUT, DE_LABK, DE_RABK,   KC_9 ,   KC_0 , _______,
     _______ , DE_CIRC, DE_EQL , DE_LPRN, DE_RPRN, KC_PERC,                                     KC_CIRC, DE_SLSH, DE_BSLS, DE_HASH, DE_DLR , _______,
     _______ , DE_PERC, DE_MINS, DE_LBRC, DE_RBRC, KC_AMPR, _______, _______, _______, _______, DE_GRV , DE_TILD, DE_PIPE, DE_QUES, DE_EXLM, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, OS_CTL , OS_SFT , OS_ALT , OS_GUI , _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
      _______, _______, _______, QWERTY , AC_TOGG, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, CRTN   , CG_TOGG, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _NAV, _NUM, _SYM);
// }

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case NUM:
    case NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case SYM:
    case NAV:
    case NUM:
    case OS_SFT:
    case OS_CTL:
    case OS_GUI:
    case OS_ALT:
        return true;
    default:
        return false;
    }
}

oneshot_state os_sft_state = os_up_unqueued;
oneshot_state os_ctl_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_sft_state, KC_LSFT, OS_SFT,
        keycode, record
    );
    update_oneshot(
        &os_ctl_state, KC_LCTL, OS_CTL,
        keycode, record
    );
    update_oneshot(
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );

    return true;
}

const key_override_t quote_override = ko_make_basic(MOD_MASK_SHIFT, DE_QUOT, DE_DQUO);
const key_override_t spc_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, DE_UNDS);
const key_override_t slsh_override = ko_make_basic(MOD_MASK_SHIFT, DE_SLSH, DE_MINS);

const key_override_t **key_overrides = (const key_override_t *[]){
        &quote_override,
        &spc_override,
        &slsh_override,
	NULL // Null terminate the array of overrides!
};
