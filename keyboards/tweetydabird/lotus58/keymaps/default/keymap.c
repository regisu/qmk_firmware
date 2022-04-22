/* Copyright 2021 TweetyDaBird
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

enum layers {
    _QWERTY,
    _NUM,
    _FUNC,
    _SYSTEM,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_FUNC,
};
#define IGNORE_MOD_TAP_INTERRUPT
// Tap Dance declarations
enum {
    MEDIA_SCROLL,
    PG_UP,
    PG_DN,
    DEL_INS,
    ESC_PIPE,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [MEDIA_SCROLL] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MUTE),
    [PG_DN] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN),
    [PG_UP] = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_PGUP),
    [DEL_INS] = ACTION_TAP_DANCE_DOUBLE(KC_DEL, KC_INS),
    [ESC_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_NUBS),
};
// Kombosy
const uint16_t PROGMEM test_combo1[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, KC_ENT),
    COMBO(test_combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
};

#define CK_ESC TD(ESC_PIPE)
#define CK_LCTRL MT(MOD_LCTL, KC_LEFT)
#define CK_LALT MT(MOD_LALT, KC_LGUI)
#define CK_LSPC MT(MOD_LSFT, KC_SPC)
#define CK_DELINS TD(DEL_INS)
#define CK_RENT MT(MOD_RSFT, KC_ENT)
#define CK_RENT2 MT(MOD_RSFT, KC_BSPC)
#define CK_RALT MT(MOD_RALT, KC_APP)
#define CK_RCTRL MT(MOD_RCTL, KC_RIGHT)
#define CK_ALTF1 LALT(KC_F1)
#define CK_ALTF2 LALT(KC_F2)
#define CK_ALTF3 LALT(KC_F3)
#define CK_ALTF4 LALT(KC_F4)
#define CK_ALTF5 LALT(KC_F5)

//One Shot Modifier
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_RCTL OSM(MOD_RCTL)
#define OSM_RALT OSM(MOD_RALT)
#define OSM_RSFT OSM(MOD_RSFT)
#define OSM_RGUI OSM(MOD_RGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   +  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   Å  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   '  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |  L   |  Ö   |  Ä   |
 * |------+------+------+------+------+------|  Down |    |  Up   |------+------+------+------+------+------|
 * |L_Ctrl|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,   |  .   |  -   |R_Ctrl|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                    | Del  | Lower| Alt | / Space /       \ Enter\  |  Alt |Raise | Bksp |
 *                    | Ins  |      | Win |/ Shift /         \ Shift\ | Menu |      |      |
 *                    `---------------------------'           '------'---------------------'
 */
    KC_ESC, KC_1, KC_2,   KC_3,     KC_4,    KC_5,                             KC_6, KC_7,      KC_8,    KC_9,   KC_0,    KC_MINS,
    KC_TAB, KC_Q, KC_W,   KC_E,     KC_R,    KC_T,                             KC_Y, KC_U,      KC_I,    KC_O,   KC_P,    KC_BSLS,
    KC_DEL, KC_A, KC_S,   KC_D,    KC_F,    KC_G,                             KC_H, KC_J,      KC_K,    KC_L,   KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z, KC_X,   KC_C,     KC_V,    KC_B, OSM(MOD_LSFT),      OSM(MOD_RSFT),  KC_N, KC_M,      KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LGUI, CK_LALT, TT(_NUM), KC_LCTL,   KC_SPC,      KC_BSPC, KC_RALT, KC_RALT, OSL(_FUNC), TD(MEDIA_SCROLL)
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |   ^  |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |  Up  |      |      |      |                    |   #  |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  Lt  |  Dn  |  Rt  |   [  |   ]  |-------.    ,-------|   &  |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  *   |  +   |  /   |  =   |-------|    |-------|   $  |   0  |   ;  |   :  |   -  |      |
 * `----------------------------------------/       /      \      \-----------------------------------------'
 *           |      |      |      |      | /       /        \      \  |      |      |      |      |
 *           |      |      |      |      |/       /          \      \ |      |      |      |      |
 *           `-----------------------------------'            '------''---------------------------'
 */
[_NUM] = LAYOUT(
  KC_GRAVE, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5),                         KC_CIRC,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,
  KC_CAPS, CK_ALTF1,  CK_ALTF2, CK_ALTF3, CK_ALTF4, KC_LBRC,                        KC_RBRC,    KC_HOME,    KC_UP,    KC_END, KC_EQL, _______,
  KC_TILDE, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), S(KC_LBRC),                         S(KC_RBRC),    KC_LEFT,    KC_DOWN,    KC_RIGHT, KC_QUOT, XXXXXXX,
  _______, XXXXXXX, _______,  S(LCTL(KC_C)), S(LCTL(KC_V)),  KC_EQL, RESET,       RESET, _______, KC_PGUP, S(LCTL(KC_PSCR)), KC_PGDN, _______, _______,
                    _______,  _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/      /     \      \-----------------------------------------'
 *            |      |      |      |      | /      /       \      \  |      |      |      |      |
 *            |      |      |      |      |/      /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_FUNC] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11,
  RESET, RGB_MODE_FORWARD, RGB_VAI, S(LCTL(KC_E)), _______, S(LCTL(KC_T)),                         _______, _______, LALT(KC_UP), S(LCTL(KC_O)), _______, _______,
  RGB_TOG, RGB_RMOD, RGB_VAD, _______, _______, _______,                         _______, LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_RIGHT), _______, _______,
  _______, _______, S(LCTL(KC_X)), _______, _______, _______, _______,       RESET, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_SYSTEM] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RESET  , XXXXXXX,KC_QWERTY,XXXXXXX,XXXXXXX,KC_ASTG,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _NUM, _FUNC, _SYSTEM);
}

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_GREEN);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif
