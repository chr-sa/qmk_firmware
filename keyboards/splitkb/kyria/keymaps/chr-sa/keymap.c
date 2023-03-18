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
    _DEIA = 0,
    _QWERTY,
    _HEJ,
    _JUNGLE,
    _SNUG,
    _CRTN,
    _NAV,
    _NUM,
    _SYM,
    _NAV_LS,
    _NUM_LS,
    _SYM_LS,
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
#define DEIA     DF(_DEIA)
#define JUNGLE   DF(_JUNGLE)
#define HEJ      DF(_HEJ)
#define SNUG      DF(_SNUG)
#define CRTN      DF(_CRTN)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define NUM      MO(_NUM)
#define SYM_LS   MO(_SYM_LS)
#define NAV_LS   MO(_NAV_LS)
#define NUM_LS   MO(_NUM_LS)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define OSS      OSM(KC_LSFT)

// clang-format off
#define ALPHA_LAYOUT( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29) \
    LAYOUT( \
      KC_NO, K00, K01, K02, K03, K04,                                      K05, K06, K07, K08, K09, KC_NO, \
      KC_NO, K10, K11, K12, K13, K14,                                      K15, K16, K17, K18, K19, KC_NO, \
      KC_NO, K20, K21, K22, K23, K24, _______,  _______, _______, _______, K25, K26, K27, K28, K29, KC_NO, \
               ADJUST, KC_LGUI, NAV, OSS, SYM, KC_BSPC, KC_SPC, NUM, KC_RGUI, KC_APP \
    )

#define ALPHA_LAYOUT_LS( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29) \
    LAYOUT( \
      KC_NO, K00, K01, K02, K03, K04,                                      K05, K06, K07, K08, K09, KC_NO, \
      KC_NO, K10, K11, K12, K13, K14,                                      K15, K16, K17, K18, K19, KC_NO, \
      KC_NO, K20, K21, K22, K23, K24, _______,  _______, _______, _______, K25, K26, K27, K28, K29, KC_NO, \
               ADJUST, KC_LGUI, NUM_LS, KC_SPC, KC_BSPC, SYM, OSS, NAV_LS, KC_RGUI, KC_APP \
    )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // f l h m b  p c o u /
    // s r n t k  y d e i a
    // x j q w v  z g ' , .
    [_DEIA] = ALPHA_LAYOUT_LS(
     DE_F, DE_L, DE_H, DE_M, DE_B, DE_P, DE_C, DE_O   , DE_U   , DE_QUOT,
     DE_S, DE_R, DE_N, DE_T, DE_K, DE_Y, DE_D, DE_E   , DE_I   , DE_A   ,
     DE_X, DE_J, DE_Q, DE_W, DE_V, DE_Z, DE_G, DE_SLSH, DE_COMM, DE_DOT
    ),

    [_QWERTY] = ALPHA_LAYOUT(
     DE_Q, DE_W, DE_E, DE_R, DE_T, DE_Z, DE_U, DE_I   , DE_O  , DE_P   ,
     DE_A, DE_S, DE_D, DE_F, DE_G, DE_H, DE_J, DE_K   , DE_L  , DE_SLSH,
     DE_Y, DE_X, DE_C, DE_V, DE_B, DE_N, DE_M, DE_COMM, DE_DOT, DE_MINS
    ),

    // Maybe d g swap back. There are for sure swaps possibel with lnm column, for example this:
    // z w l c v k y o u ;
    // s r n t g j h e i a
    // f x m d p q b ' , .

    // x l w c q  b k o u '
    // s r n t g  y h e i a
    // z j m d v  p f / , .
    [_HEJ] = ALPHA_LAYOUT(
     DE_X, DE_L, DE_W, DE_C, DE_Q, DE_B, DE_K, DE_O   , DE_U   , DE_QUOT,
     DE_S, DE_R, DE_N, DE_T, DE_G, DE_Y, DE_H, DE_E   , DE_I   , DE_A   ,
     DE_Z, DE_J, DE_M, DE_D, DE_V, DE_P, DE_F, DE_SLSH, DE_COMM, DE_DOT
    ),

    // j g l c b  y u o z k
    // r s n t p  , i e a h
    // q w m d v  / x ' . f
    [_JUNGLE] = ALPHA_LAYOUT(
     DE_J, DE_G, DE_L, DE_C, DE_B, DE_Y   , DE_U, DE_O   , DE_Z   , DE_K,
     DE_R, DE_S, DE_N, DE_T, DE_P, DE_COMM, DE_I, DE_E   , DE_A   , DE_H   ,
     DE_Q, DE_W, DE_M, DE_D, DE_V, DE_SLSH, DE_X, DE_QUOT, DE_DOT , DE_F
    ),

    // q l d m b  y f o u '
    // s r t c g  p n e i a
    // z x k w v  j h / , .
    [_SNUG] = ALPHA_LAYOUT(
     DE_Q, DE_L, DE_D, DE_M, DE_B, DE_Y, DE_F, DE_O   , DE_U   , DE_QUOT,
     DE_S, DE_R, DE_T, DE_C, DE_G, DE_P, DE_N, DE_E   , DE_I   , DE_A   ,
     DE_Z, DE_X, DE_K, DE_W, DE_V, DE_J, DE_H, DE_SLSH, DE_COMM , DE_DOT
    ),

    // g l d v q f m o u /
    // c r t n b y s e i a
    // z j k h p x w ' , .
    [_CRTN] = ALPHA_LAYOUT(
     DE_G, DE_L, DE_D, DE_V, DE_Q, DE_K, DE_F, DE_O   , DE_U   , DE_QUOT,
     DE_C, DE_R, DE_T, DE_N, DE_P, DE_Y, DE_S, DE_E   , DE_I   , DE_A   ,
     DE_Z, DE_J, DE_M, DE_H, DE_B, DE_X, DE_W, DE_SLSH, DE_COMM, DE_DOT
    ),

    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP  , KC_END , CW_TOGG, KC_NO,
      _______, OS_SFT , OS_ALT , OS_GUI , OS_CTL , _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB , KC_NO,
      _______, _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______, KC_RGUI, KC_BSPC, KC_ESC , KC_TAB , KC_DEL , KC_NO,
                                 _______, _______, _______, _______, _______, _______, KC_ENT, _______, _______, _______
    ),

    [_NUM] = LAYOUT(
      _______, DE_SLSH, DE_9, DE_8 ,DE_7 , DE_PLUS,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_ENT , DE_6, DE_5 ,DE_4 , DE_MINS,                                     _______, OS_CTL , OS_GUI , OS_ALT , OS_SFT , _______,
      _______, DE_ASTR, DE_3, DE_2 ,DE_1 , DE_EQL , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, DE_0, _______, _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NAV_LS] = LAYOUT(
      _______, CW_TOGG, KC_END , KC_UP  , KC_HOME, KC_PGUP,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_TAB , KC_RGHT, KC_DOWN, KC_LEFT, KC_PGDN,                                     _______, OS_CTL , OS_GUI , OS_ALT , OS_SFT , _______,
      _______, KC_DEL , KC_TAB , KC_ESC , KC_BSPC, KC_RGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, KC_ENT, _______, _______, _______, _______, _______, _______
    ),

    [_NUM_LS] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     DE_PLUS, DE_7, DE_8, DE_9, DE_SLSH, _______,
      _______, OS_SFT , OS_ALT , OS_GUI , OS_CTL , _______,                                     DE_MINS, DE_4, DE_5, DE_6, KC_ENT , _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DE_EQL , DE_1, DE_2, DE_3, DE_ASTR, _______,
                                 _______, _______, _______, _______, _______, _______, DE_0, _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, OS_CTL , OS_GUI , OS_ALT , OS_SFT , _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
      _______, _______, _______, QWERTY , AC_TOGG, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, HEJ    , DEIA   , CG_TOGG, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, SNUG   , CRTN   , _______, _______,_______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _NUM, _SYM);
}

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
    case SYM_LS:
    case NAV_LS:
    case NUM_LS:
    // case KC_LSFT:
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

