#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_MACRO_17,
  ST_MACRO_18,
  ST_MACRO_19,
  ST_MACRO_20,
  ST_MACRO_21,
  ST_MACRO_22,
};

static bool activeNumLockLed = true;
static bool linuxSystem = true;

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_11,
  DANCE_12,
  DANCE_13,
  DANCE_14,
  DANCE_15,
  DANCE_16,
  DANCE_17,
  DANCE_18,
  DANCE_19,
  DANCE_20,
  DANCE_21,
  DANCE_23,
  DANCE_24,
  DANCE_25,
  DANCE_26,
  DANCE_27,
  DANCE_28,
  DANCE_29,
  DANCE_30,
  DANCE_32,
  DANCE_33,
  DANCE_34,
  DANCE_35,
  DANCE_36,
  DANCE_38,
  DANCE_39,
  DANCE_40,
  DANCE_41,
  DANCE_42,
  DANCE_43,
  DANCE_44,
  DANCE_ENTER,
  DANCE_LAST_ARRAY_SIZE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,TD(DANCE_0),  TD(DANCE_12),   TD(DANCE_18),   TO(9),                                          KC_APPLICATION, KC_CALCULATOR,  KC_MY_COMPUTER, TD(DANCE_44),   KC_WWW_REFRESH, KC_F13,         KC_WWW_SEARCH,
    KC_ESCAPE,      BP_B,           BP_ECUT,        BP_P,           BP_O,           BP_EGRV,        KC_MS_WH_UP,                                    KC_MS_WH_DOWN,  BP_V,           BP_D,           BP_L,           BP_J,           BP_Z,           KC_UP,
    KC_TAB,         BP_A,           BP_U,           BP_I,           BP_E,           TD(DANCE_6),    KC_MS_WH_LEFT,                                  KC_MS_WH_RIGHT, BP_T,           BP_S,           BP_R,           BP_N,           BP_M,           KC_DOWN,
#ifdef VM_USE_DOUBLE_SHIFT_CAPS_WORD
    OSM(MOD_LSFT),  BP_AGRV,        BP_Y,           BP_X,           TD(DANCE_7),    KC_BSPC,                                                                        KC_RIGHT_ALT,   BP_G,           BP_H,           BP_F,           BP_Q,           OSM(MOD_RSFT),
#else
    OSM(MOD_LSFT),  BP_AGRV,        BP_Y,           BP_X,           TD(DANCE_7),    KC_BSPC,                                                                        KC_RIGHT_ALT,   BP_G,           BP_H,           BP_F,           BP_Q,           OSM(MOD_LSFT),
#endif
    TD(DANCE_8),    TD(DANCE_9),    TD(DANCE_10),   OSL(2),         BP_C,           TD(DANCE_11),                                                                   TD(DANCE_19),   KC_SPACE,       OSL(1),         KC_LEFT,        KC_RIGHT,       OSM(MOD_RGUI),
                                                                                    KC_ENTER,       BP_CCED,        KC_LEFT_CTRL,   KC_RIGHT_CTRL,  BP_K,           BP_W
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
#ifndef VM_USE_NUMPAD_ONLY
    KC_TRANSPARENT, BP_PIPE,        BP_AMPR,        BP_MINS,        BP_ASTR,        TD(DANCE_20),   KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_21),   BP_SLSH,        BP_PLUS,        BP_HASH,        BP_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, BP_6,           BP_4,           BP_8,           BP_0,           BP_2,           KC_TRANSPARENT,                                 KC_TRANSPARENT, BP_3,           BP_1,           BP_9,           BP_5,           BP_7,           KC_TRANSPARENT,
#else
    KC_TRANSPARENT, BP_PIPE,        BP_AMPR,        KC_KP_MINUS,    KC_KP_ASTERISK, TD(DANCE_20),   KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_21),   KC_KP_SLASH,    KC_KP_PLUS,     BP_HASH,        BP_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_3,        KC_KP_1,        KC_KP_9,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT,
#endif
    KC_TRANSPARENT, BP_UNDS,        BP_LBRC,        BP_LPRN,        BP_EQL,         KC_TRANSPARENT,                                                                 KC_TRANSPARENT, BP_PERC,        BP_RPRN,        BP_RBRC,        BP_EXLM,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, BP_DCRC,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    BP_LESS,        BP_GRTR,        TD(DANCE_ENTER),KC_TRANSPARENT, TD(DANCE_6),    KC_DELETE
  ),
  [2] = LAYOUT_moonlander(
#ifndef VM_USE_NUMPAD_ONLY
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_3,        KC_KP_1,        KC_KP_9,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT,
#else
    KC_TRANSPARENT, BP_6,           BP_4,           BP_8,           BP_0,           BP_2,           KC_TRANSPARENT,                                 KC_TRANSPARENT, BP_3,           BP_1,           BP_9,           BP_5,           BP_7,           KC_TRANSPARENT,
#endif
    TD(DANCE_43),   TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    TD(DANCE_5),    KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_13),   TD(DANCE_14),   TD(DANCE_23),   TD(DANCE_24),   TD(DANCE_25),   KC_TRANSPARENT,
    KC_TRANSPARENT, BP_AT,          BP_TILD,        RALT(BP_COMM),  BP_APOS,        BP_LGIL,        KC_TRANSPARENT,                                 KC_TRANSPARENT, BP_RGIL,        BP_GRV,         BP_DQOT,        BP_DTRM,        TD(DANCE_26),   KC_TRANSPARENT,
    KC_TRANSPARENT, BP_QEST,        BP_LCBR,        RALT(LSFT(BP_P)),BP_AE,         KC_TRANSPARENT,                                                                 KC_TRANSPARENT, BP_OE,          BP_MDSH,        BP_RCBR,        BP_UGRV,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_SPACE,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, RALT(BP_3),     ST_MACRO_0,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_ENTER,       KC_NUM,         KC_LEFT_CTRL,   KC_TRANSPARENT, RALT(BP_2),     BP_DLR
  ),
  [3] = LAYOUT_moonlander(
    KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,TD(DANCE_0),  TD(DANCE_12),   TD(DANCE_18),   TO(9),                                          KC_APPLICATION, KC_CALCULATOR,  KC_MY_COMPUTER, TD(DANCE_44),   KC_WWW_REFRESH, KC_F13,         KC_WWW_SEARCH,
    KC_ESCAPE,      KC_B,           ST_MACRO_1,     KC_P,           KC_O,           ST_MACRO_2,     KC_MS_WH_UP,                                    KC_MS_WH_DOWN,  KC_V,           KC_D,           KC_L,           KC_J,           KC_Z,           KC_UP,
    KC_TAB,         KC_A,           KC_U,           KC_I,           KC_E,           TD(DANCE_27),   KC_MS_WH_LEFT,                                  KC_MS_WH_RIGHT, KC_T,           KC_S,           KC_R,           KC_N,           KC_M,           KC_DOWN,
#ifdef VM_USE_DOUBLE_SHIFT_CAPS_WORD
    OSM(MOD_LSFT),  ST_MACRO_3,     KC_Y,           KC_X,           TD(DANCE_28),   KC_BSPC,                                                                        KC_RIGHT_ALT,   KC_G,           KC_H,           KC_F,           KC_Q,           OSM(MOD_RSFT),
#else
    OSM(MOD_LSFT),  ST_MACRO_3,     KC_Y,           KC_X,           TD(DANCE_28),   KC_BSPC,                                                                        KC_RIGHT_ALT,   KC_G,           KC_H,           KC_F,           KC_Q,           OSM(MOD_LSFT),
#endif
    TD(DANCE_8),    TD(DANCE_9),    TD(DANCE_10),   OSL(5),         KC_C,           TD(DANCE_11),                                                                   TD(DANCE_19),   KC_SPACE,       OSL(4),         KC_LEFT,        KC_RIGHT,       OSM(MOD_RGUI),
                                                                                    KC_ENTER,       ST_MACRO_4,     KC_LEFT_CTRL,   KC_RIGHT_CTRL,  KC_K,           KC_W
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
#ifndef VM_USE_NUMPAD_ONLY
    KC_TRANSPARENT, KC_PIPE,        KC_AMPR,        KC_MINUS,       KC_ASTR,        TD(DANCE_29),   KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_30),   KC_SLASH,       KC_PLUS,        KC_HASH,        KC_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_6,           KC_4,           KC_8,           KC_0,           KC_2,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_3,           KC_1,           KC_9,           KC_5,           KC_7,           KC_TRANSPARENT,
#else
    KC_TRANSPARENT, KC_PIPE,        KC_AMPR,        KC_KP_MINUS,    KC_KP_ASTERISK, TD(DANCE_29),   KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_30),   KC_KP_SLASH,    KC_KP_PLUS,     KC_HASH,        KC_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_3,        KC_KP_1,        KC_KP_9,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT,
#endif
    KC_TRANSPARENT, KC_UNDS,        KC_LBRC,        KC_LPRN,        KC_EQUAL,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_PERC,        KC_RPRN,        KC_RBRC,        KC_EXLM,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_LABK,        KC_RABK,        TD(DANCE_ENTER),KC_TRANSPARENT, TD(DANCE_27),   KC_DELETE
  ),
  [5] = LAYOUT_moonlander(
#ifndef VM_USE_NUMPAD_ONLY
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_3,        KC_KP_1,        KC_KP_9,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT,
#else
    KC_TRANSPARENT, KC_6,           KC_4,           KC_8,           KC_0,           KC_2,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_3,           KC_1,           KC_9,           KC_5,           KC_7,           KC_TRANSPARENT,
#endif
    TD(DANCE_43),   TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    TD(DANCE_5),    KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_13),   TD(DANCE_14),   TD(DANCE_23),   TD(DANCE_24),   TD(DANCE_25),   KC_TRANSPARENT,
    KC_TRANSPARENT, KC_AT,          ST_MACRO_5,     ST_MACRO_6,     KC_QUOTE,       ST_MACRO_21,    KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_12,    ST_MACRO_8,     ST_MACRO_9,     KC_DQUO,        TD(DANCE_32),   KC_TRANSPARENT,
    KC_TRANSPARENT, KC_QUES,        KC_LCBR,        ST_MACRO_10,    ST_MACRO_7,     KC_TRANSPARENT,                                                                 KC_TRANSPARENT, RALT(KC_Q),     RALT(RSFT(KC_MINUS)),KC_RCBR,   ST_MACRO_11,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_SPACE,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, RALT(RSFT(KC_LBRC)),RALT(KC_M), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_ENTER,       KC_NUM,         KC_LEFT_CTRL,   KC_TRANSPARENT, RALT(KC_LBRC),  KC_DLR
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_B,           FR_EACU,        KC_P,           KC_O,           FR_EGRV,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_V,           KC_D,           KC_L,           KC_J,           FR_Z,           KC_TRANSPARENT,
    KC_TRANSPARENT, FR_A,           KC_U,           KC_I,           KC_E,           TD(DANCE_33),   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_T,           KC_S,           KC_R,           KC_N,           FR_M,           KC_TRANSPARENT,
    KC_TRANSPARENT, FR_AGRV,        KC_Y,           KC_X,           TD(DANCE_34),   KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_G,           KC_H,           KC_F,           FR_Q,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSL(8),         KC_C,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, OSL(7),         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, FR_CCED,        KC_TRANSPARENT, KC_TRANSPARENT, KC_K,           FR_W
  ),
  [7] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
#ifndef VM_USE_NUMPAD_ONLY
    KC_TRANSPARENT, FR_PIPE,        FR_AMP,         FR_MINS,        FR_ASTR,        TD(DANCE_35),   KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_36),   FR_SLSH,        FR_PLUS,        FR_HASH,        FR_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, FR_6,           FR_4,           FR_8,           FR_0,           FR_2,           KC_TRANSPARENT,                                 KC_TRANSPARENT, FR_3,           FR_1,           FR_9,           FR_5,           FR_7,           KC_TRANSPARENT,
#else
    KC_TRANSPARENT, FR_PIPE,        FR_AMP,         KC_KP_MINUS,    KC_KP_ASTERISK, TD(DANCE_35),   KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_36),   KC_KP_SLASH,    KC_KP_PLUS,     FR_HASH,        FR_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_3,        KC_KP_1,        KC_KP_9,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT,
#endif
    KC_TRANSPARENT, FR_UNDS,        FR_LBRC,        FR_LPRN,        FR_EQL,         KC_TRANSPARENT,                                                                 KC_TRANSPARENT, FR_PERC,        FR_RPRN,        FR_RBRC,        FR_EXLM,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, FR_CIRC,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    FR_LESS,        FR_GRTR,        TD(DANCE_ENTER),KC_TRANSPARENT, TD(DANCE_33),   KC_DELETE
  ),
  [8] = LAYOUT_moonlander(
#ifndef VM_USE_NUMPAD_ONLY
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_3,        KC_KP_1,        KC_KP_9,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT,
#else
    KC_TRANSPARENT, FR_6,           FR_4,           FR_8,           FR_0,           FR_2,           KC_TRANSPARENT,                                 KC_TRANSPARENT, FR_3,           FR_1,           FR_9,           FR_5,           FR_7,           KC_TRANSPARENT,
#endif
    TD(DANCE_43),   TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    TD(DANCE_5),    KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_13),   TD(DANCE_14),   TD(DANCE_23),   TD(DANCE_24),   TD(DANCE_25),   KC_TRANSPARENT,
    KC_TRANSPARENT, FR_AT,          FR_TILD,        FR_APOS,        FR_SUP2,        ST_MACRO_13,    KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_16,    ST_MACRO_17,    FR_DQUO,        FR_UMLT,        TD(DANCE_38),   KC_TRANSPARENT,
    KC_TRANSPARENT, FR_QUES,        FR_LCBR,        FR_SECT,        ST_MACRO_14,    KC_TRANSPARENT,                                                                 KC_TRANSPARENT, ST_MACRO_18,    ST_MACRO_19,    FR_RCBR,        FR_UGRV,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_SPACE,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, ST_MACRO_20,    FR_MU,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_ENTER,       KC_NUM,         KC_LEFT_CTRL,   KC_TRANSPARENT, ST_MACRO_15,    FR_DLR
  ),
  [9] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_ESCAPE,      TO(0),          KC_PAGE_UP,     KC_UP,          DM_REC1,        DM_REC2,        DM_PLY1,                                        DM_PLY2,        KC_KP_SLASH,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     KC_MS_UP,
    KC_TRANSPARENT, TO(6),          KC_LEFT,        KC_HOME,        KC_RIGHT,       KC_DELETE,      RGB_VAD,                                        RGB_VAI,        KC_KP_ASTERISK, KC_KP_4,        KC_KP_5,        KC_KP_6,        ST_MACRO_22,    KC_MS_DOWN,
    KC_CAPS,        KC_NUM,         KC_PGDN,        KC_DOWN,        KC_END,         KC_RIGHT_ALT,                                                                   KC_KP_MINUS,    KC_KP_1,        KC_KP_2,        KC_KP_3,        TO(3),          CW_TOGG,
    KC_LEFT_ALT,    KC_MS_WH_UP,    KC_MS_WH_DOWN,  QK_BOOT,        DM_RSTP,        KC_MS_BTN1,                                                                     KC_MS_BTN2,     KC_MS_BTN3,     KC_KP_0,        KC_MS_LEFT,     KC_MS_RIGHT,    TOGGLE_LAYER_COLOR,
                                                                                    KC_KP_ENTER,    RGB_TOG,        TD(DANCE_ENTER),KC_TRANSPARENT, TOGGLE_LAYER_COLOR,TD(DANCE_42)
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,237,170}, {225,224,255}, {74,255,255}, {0,245,245}, {0,245,245}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {41,255,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {41,255,255}, {188,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {86,95,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {188,255,255}, {74,255,255}, {74,255,255}, {225,224,255}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {74,255,255}, {19,245,255}, {0,245,245}, {19,245,255}, {46,215,244}, {46,215,244}, {0,245,245}, {0,245,245}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {46,215,244}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {46,215,244}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {19,245,255}, {74,255,255}, {74,255,255}, {0,245,245}, {19,245,255}, {41,255,255}, {41,255,255}, {74,255,255}, {74,255,255}, {19,245,255}, {0,245,245} },

    [1] = { {0,237,170}, {225,224,255}, {168,218,204}, {0,245,245}, {0,245,245}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {41,255,255}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {41,255,255}, {188,255,255}, {168,218,204}, {78,218,204}, {168,218,204}, {0,0,255}, {86,95,255}, {168,218,204}, {78,218,204}, {168,218,204}, {168,218,204}, {188,255,255}, {168,218,204}, {78,218,204}, {225,224,255}, {0,0,255}, {41,255,255}, {41,255,255}, {168,218,204}, {168,218,204}, {225,224,255}, {0,245,245}, {19,245,255}, {46,215,244}, {46,215,244}, {0,245,245}, {0,245,245}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {46,215,244}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {46,215,244}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {0,0,255}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {168,218,204}, {19,245,255}, {168,218,204}, {78,218,204}, {0,245,245}, {19,245,255}, {41,255,255}, {41,255,255}, {225,224,255}, {168,218,204}, {19,245,255}, {0,245,245} },

    [2] = { {0,237,170}, {0,0,255}, {62,219,138}, {0,245,245}, {0,245,245}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {41,255,255}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {41,255,255}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {0,0,255}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {168,218,204}, {19,245,255}, {62,219,138}, {225,224,255}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {0,245,245}, {19,245,255}, {0,245,245}, {19,245,255}, {46,215,244}, {46,215,244}, {0,245,245}, {0,245,245}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {46,215,244}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {46,215,244}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {168,218,204}, {19,245,255}, {62,219,138}, {0,245,245}, {19,245,255}, {41,255,255}, {41,255,255}, {62,219,138}, {62,219,138}, {19,245,255}, {0,245,245} },

    [3] = { {0,237,170}, {225,224,255}, {131,255,255}, {0,245,245}, {0,245,245}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {41,255,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {41,255,255}, {188,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {86,95,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {188,255,255}, {131,255,255}, {131,255,255}, {225,224,255}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {131,255,255}, {19,245,255}, {19,245,255}, {19,245,255}, {46,215,244}, {46,215,244}, {0,245,245}, {0,245,245}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {46,215,244}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {46,215,244}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {19,245,255}, {131,255,255}, {131,255,255}, {0,245,245}, {19,245,255}, {41,255,255}, {41,255,255}, {131,255,255}, {131,255,255}, {19,245,255}, {0,245,245} },

    [4] = { {0,237,170}, {225,224,255}, {0,219,138}, {0,245,245}, {0,245,245}, {19,245,255}, {0,219,138}, {74,255,255}, {0,219,138}, {41,255,255}, {19,245,255}, {0,219,138}, {74,255,255}, {0,219,138}, {41,255,255}, {188,255,255}, {0,219,138}, {74,255,255}, {0,219,138}, {0,0,255}, {86,95,255}, {0,219,138}, {74,255,255}, {0,219,138}, {0,219,138}, {188,255,255}, {0,219,138}, {74,255,255}, {225,224,255}, {0,0,255}, {41,255,255}, {41,255,255}, {0,219,138}, {0,219,138}, {225,224,255}, {0,245,245}, {19,245,255}, {46,215,244}, {46,215,244}, {0,245,245}, {0,245,245}, {19,245,255}, {0,219,138}, {74,255,255}, {0,219,138}, {46,215,244}, {19,245,255}, {0,219,138}, {74,255,255}, {0,219,138}, {46,215,244}, {19,245,255}, {0,219,138}, {74,255,255}, {0,219,138}, {0,0,255}, {19,245,255}, {0,219,138}, {74,255,255}, {0,219,138}, {0,219,138}, {19,245,255}, {0,219,138}, {74,255,255}, {0,245,245}, {19,245,255}, {41,255,255}, {41,255,255}, {225,224,255}, {0,219,138}, {152,255,255}, {0,245,245} },

    [5] = { {0,237,170}, {0,0,255}, {152,255,255}, {0,245,245}, {0,245,245}, {0,219,138}, {19,245,255}, {152,255,255}, {152,255,255}, {41,255,255}, {0,219,138}, {19,245,255}, {152,255,255}, {152,255,255}, {46,215,244}, {0,219,138}, {19,245,255}, {152,255,255}, {152,255,255}, {0,0,255}, {0,219,138}, {19,245,255}, {152,255,255}, {152,255,255}, {152,255,255}, {1,181,132}, {19,245,255}, {152,255,255}, {225,224,255}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {0,245,245}, {19,245,255}, {0,245,245}, {19,245,255}, {46,215,244}, {46,215,244}, {0,245,245}, {0,245,245}, {0,219,138}, {19,245,255}, {152,255,255}, {152,255,255}, {46,215,244}, {0,219,138}, {19,245,255}, {152,255,255}, {152,255,255}, {46,215,244}, {0,219,138}, {19,245,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,219,138}, {19,245,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,219,138}, {19,245,255}, {152,255,255}, {0,245,245}, {19,245,255}, {41,255,255}, {41,255,255}, {152,255,255}, {0,0,0}, {19,245,255}, {0,245,245} },

    [6] = { {0,237,170}, {74,255,255}, {198,255,255}, {0,245,245}, {0,245,245}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {41,255,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {41,255,255}, {188,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {0,0,255}, {86,95,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {188,255,255}, {198,255,255}, {198,255,255}, {74,255,255}, {0,0,255}, {41,255,255}, {41,255,255}, {74,255,255}, {198,255,255}, {19,245,255}, {0,245,245}, {19,245,255}, {46,215,244}, {46,215,244}, {0,245,245}, {0,245,245}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {46,215,244}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {46,215,244}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {0,0,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {19,245,255}, {198,255,255}, {198,255,255}, {0,245,245}, {19,245,255}, {41,255,255}, {41,255,255}, {198,255,255}, {198,255,255}, {19,245,255}, {0,245,245} },

    [7] = { {0,237,170}, {225,224,255}, {62,219,138}, {0,245,245}, {0,245,245}, {19,245,255}, {62,219,138}, {206,255,160}, {62,219,138}, {41,255,255}, {19,245,255}, {62,219,138}, {206,255,160}, {62,219,138}, {41,255,255}, {188,255,255}, {62,219,138}, {206,255,160}, {62,219,138}, {0,0,255}, {86,95,255}, {62,219,138}, {206,255,160}, {62,219,138}, {62,219,138}, {188,255,255}, {62,219,138}, {206,255,160}, {225,224,255}, {0,0,255}, {41,255,255}, {41,255,255}, {62,219,138}, {62,219,138}, {225,224,255}, {0,245,245}, {19,245,255}, {46,215,244}, {46,215,244}, {0,245,245}, {0,245,245}, {19,245,255}, {62,219,138}, {206,255,160}, {62,219,138}, {46,215,244}, {19,245,255}, {62,219,138}, {206,255,160}, {62,219,138}, {46,215,244}, {19,245,255}, {62,219,138}, {206,255,160}, {62,219,138}, {0,0,255}, {19,245,255}, {62,219,138}, {206,255,160}, {62,219,138}, {62,219,138}, {19,245,255}, {62,219,138}, {206,255,160}, {0,245,245}, {19,245,255}, {41,255,255}, {41,255,255}, {225,224,255}, {62,219,138}, {19,245,255}, {0,245,245} },

    [8] = { {0,237,170}, {0,0,255}, {206,255,160}, {0,245,245}, {0,245,245}, {62,219,138}, {19,245,255}, {206,255,160}, {206,255,160}, {41,255,255}, {62,219,138}, {19,245,255}, {206,255,160}, {206,255,160}, {41,255,255}, {62,219,138}, {19,245,255}, {206,255,160}, {206,255,160}, {0,0,255}, {62,219,138}, {19,245,255}, {206,255,160}, {206,255,160}, {62,219,138}, {62,219,138}, {19,245,255}, {206,255,160}, {225,224,255}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {0,245,245}, {19,245,255}, {0,245,245}, {19,245,255}, {46,215,244}, {46,215,244}, {0,245,245}, {0,245,245}, {62,219,138}, {19,245,255}, {206,255,160}, {206,255,160}, {46,215,244}, {62,219,138}, {19,245,255}, {206,255,160}, {206,255,160}, {46,215,244}, {62,219,138}, {19,245,255}, {206,255,160}, {206,255,160}, {206,255,160}, {62,219,138}, {19,245,255}, {206,255,160}, {206,255,160}, {206,255,160}, {62,219,138}, {19,245,255}, {206,255,160}, {0,245,245}, {19,245,255}, {41,255,255}, {41,255,255}, {206,255,160}, {0,0,0}, {19,245,255}, {0,245,245} },

    [9] = { {0,237,170}, {19,245,255}, {62,219,138}, {206,255,160}, {0,245,245}, {19,245,255}, {0,0,255}, {0,0,255}, {0,245,245}, {41,255,255}, {19,245,255}, {0,245,245}, {19,245,255}, {0,245,245}, {41,255,255}, {188,255,255}, {19,245,255}, {0,245,245}, {19,245,255}, {131,255,255}, {86,95,255}, {0,245,245}, {19,245,255}, {0,245,245}, {0,245,245}, {188,255,255}, {0,245,245}, {225,224,255}, {0,245,245}, {225,224,255}, {74,255,255}, {19,245,255}, {225,224,255}, {19,245,255}, {19,245,255}, {41,255,255}, {19,245,255}, {46,215,244}, {46,215,244}, {206,255,160}, {0,245,245}, {19,245,255}, {1,181,132}, {1,181,132}, {0,0,255}, {46,215,244}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {41,255,255}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {41,255,255}, {19,245,255}, {1,181,132}, {1,181,132}, {1,181,132}, {19,245,255}, {74,255,255}, {19,245,255}, {1,181,132}, {19,245,255}, {19,245,255}, {41,255,255} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
    case 9:
      set_layer_color(9);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t mods_used;

  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_COMMA)) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      if (is_caps_word_on()) {
         SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_LSFT(SS_TAP(X_E)));
      } else if ((mods_used = get_mods()) & MOD_MASK_SHIFT) {
         del_mods(MOD_MASK_SHIFT);
         SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_LSFT(SS_TAP(X_E)));
         set_mods(mods_used);
      } else if (get_oneshot_mods() & MOD_MASK_SHIFT) {
         del_oneshot_mods(MOD_MASK_SHIFT);
         SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_LSFT(SS_TAP(X_E)));
      } else {
         SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_E));
      }
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      if (is_caps_word_on()) {
         SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_LSFT(SS_TAP(X_E)));
      } else if ((mods_used = get_mods()) & MOD_MASK_SHIFT) {
         del_mods(MOD_MASK_SHIFT);
         SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_LSFT(SS_TAP(X_E)));
         set_mods(mods_used);
      } else if (get_oneshot_mods() & MOD_MASK_SHIFT) {
         del_oneshot_mods(MOD_MASK_SHIFT);
         SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_LSFT(SS_TAP(X_E)));
      } else {
         SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_E));
      }
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      if (is_caps_word_on()) {
         SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_LSFT(SS_TAP(X_A)));
      } else if ((mods_used = get_mods()) & MOD_MASK_SHIFT) {
         del_mods(MOD_MASK_SHIFT);
         SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_LSFT(SS_TAP(X_A)));
         set_mods(mods_used);
      } else if (get_oneshot_mods() & MOD_MASK_SHIFT) {
         del_oneshot_mods(MOD_MASK_SHIFT);
         SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_LSFT(SS_TAP(X_A)));
      } else {
         SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_A));
      }
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      if (is_caps_word_on()) {
          if (!activeNumLockLed) {
            SEND_STRING(SS_RALT(SS_RSFT(SS_TAP(X_C))));
          } else {
            SEND_STRING(SS_RALT(SS_RSFT(SS_TAP(X_COMMA))));
          }
      } else {
          if (!activeNumLockLed) {
            SEND_STRING(SS_RALT(SS_TAP(X_C)));
          } else {
            SEND_STRING(SS_RALT(SS_TAP(X_COMMA)));
          }
      }
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_GRAVE)) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      if (is_caps_word_on()) {
         if (!activeNumLockLed) {
           SEND_STRING(SS_RALT(SS_RSFT(SS_TAP(X_QUOTE))));
         } else {
           SEND_STRING(SS_RALT(SS_RSFT(SS_TAP(X_Z))));
         }
      } else {
        if (!activeNumLockLed) {
          SEND_STRING(SS_RALT(SS_TAP(X_QUOTE)));
        } else {
          SEND_STRING(SS_RALT(SS_TAP(X_Z)));
        }
      }
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      if (!activeNumLockLed) {
        SEND_STRING(SS_RALT(SS_TAP(X_6)));
      } else {
        SEND_STRING(SS_RALT(SS_RSFT(SS_TAP(X_S))));
      }
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      if (is_caps_word_on()) {
         SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_LSFT(SS_TAP(X_U)));
      } else if ((mods_used = get_mods()) & MOD_MASK_SHIFT) {
         del_mods(MOD_MASK_SHIFT);
         SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_LSFT(SS_TAP(X_U)));
         set_mods(mods_used);
      } else if (get_oneshot_mods() & MOD_MASK_SHIFT) {
         del_oneshot_mods(MOD_MASK_SHIFT);
         SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_LSFT(SS_TAP(X_U)));
      } else {
         SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_U));
      }
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      if (!activeNumLockLed) {
        SEND_STRING(SS_RALT(SS_RSFT(SS_TAP(X_BSLS))));
      } else {
        SEND_STRING(SS_RALT(SS_TAP(X_RBRC)));
      }
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_1) ));
    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_0) ));
    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_0) ));
    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_7) ));
    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_7)) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_3) SS_TAP(X_KP_3) SS_TAP(X_KP_9) ));
    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_2) ));
    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_1) ));
    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      if (!activeNumLockLed) {
        SEND_STRING(SS_RALT(SS_TAP(X_BSLS)));
      } else {
        SEND_STRING(SS_RALT(SS_TAP(X_LBRC)));
      }
    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      if ((mods_used = get_mods()) & MOD_MASK_CTRL) {
        linuxSystem = !linuxSystem;
      } else {
        activeNumLockLed = !activeNumLockLed;

        led_update_kb(host_keyboard_led_state());
      }
    }
    break;

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[DANCE_LAST_ARRAY_SIZE];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PREV_TRACK);
        tap_code16(KC_MEDIA_PREV_TRACK);
        tap_code16(KC_MEDIA_PREV_TRACK);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PREV_TRACK);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_0].step = dance_step(state);
    switch (dance_state[DANCE_0].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_REWIND); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PREV_TRACK); register_code16(KC_MEDIA_PREV_TRACK);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_0].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_REWIND); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
    }
    dance_state[DANCE_0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F6);
        tap_code16(KC_F6);
        tap_code16(KC_F6);
    }
    if(state->count > 3) {
        tap_code16(KC_F6);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_1].step = dance_step(state);
    switch (dance_state[DANCE_1].step) {
        case SINGLE_TAP: register_code16(KC_F6); break;
        case SINGLE_HOLD: register_code16(KC_F6); break;
        case DOUBLE_TAP: register_code16(KC_CALCULATOR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_1].step) {
        case SINGLE_TAP: unregister_code16(KC_F6); break;
        case SINGLE_HOLD: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_CALCULATOR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[DANCE_1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_2].step = dance_step(state);
    switch (dance_state[DANCE_2].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case SINGLE_HOLD: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(KC_WWW_FAVORITES); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_2].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case SINGLE_HOLD: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_FAVORITES); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[DANCE_2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F8);
        tap_code16(KC_F8);
        tap_code16(KC_F8);
    }
    if(state->count > 3) {
        tap_code16(KC_F8);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_3].step = dance_step(state);
    switch (dance_state[DANCE_3].step) {
        case SINGLE_TAP: register_code16(KC_F8); break;
        case SINGLE_HOLD: register_code16(KC_F8); break;
        case DOUBLE_TAP: register_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F8); register_code16(KC_F8);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_3].step) {
        case SINGLE_TAP: unregister_code16(KC_F8); break;
        case SINGLE_HOLD: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F8); break;
    }
    dance_state[DANCE_3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F10);
        tap_code16(KC_F10);
        tap_code16(KC_F10);
    }
    if(state->count > 3) {
        tap_code16(KC_F10);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_4].step = dance_step(state);
    switch (dance_state[DANCE_4].step) {
        case SINGLE_TAP: register_code16(KC_F10); break;
        case SINGLE_HOLD: register_code16(KC_F10); break;
        case DOUBLE_TAP: register_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F10); register_code16(KC_F10);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_4].step) {
        case SINGLE_TAP: unregister_code16(KC_F10); break;
        case SINGLE_HOLD: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F10); break;
    }
    dance_state[DANCE_4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F2);
        tap_code16(KC_F2);
        tap_code16(KC_F2);
    }
    if(state->count > 3) {
        tap_code16(KC_F2);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_5].step = dance_step(state);
    switch (dance_state[DANCE_5].step) {
        case SINGLE_TAP: register_code16(KC_F2); break;
        case SINGLE_HOLD: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F2); register_code16(KC_F2);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_5].step) {
        case SINGLE_TAP: unregister_code16(KC_F2); break;
        case SINGLE_HOLD: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F2); break;
    }
    dance_state[DANCE_5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_COMM);
        tap_code16(BP_COMM);
        tap_code16(BP_COMM);
    }
    if(state->count > 3) {
        tap_code16(BP_COMM);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_6].step = dance_step(state);
    switch (dance_state[DANCE_6].step) {
        case SINGLE_TAP: register_code16(BP_COMM); break;
        case SINGLE_HOLD: register_code16(BP_SCLN); break;
        case DOUBLE_TAP: register_code16(BP_COMM); register_code16(BP_COMM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_COMM); register_code16(BP_COMM);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_6].step) {
        case SINGLE_TAP: unregister_code16(BP_COMM); break;
        case SINGLE_HOLD: unregister_code16(BP_SCLN); break;
        case DOUBLE_TAP: unregister_code16(BP_COMM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_COMM); break;
    }
    dance_state[DANCE_6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_DOT);
        tap_code16(BP_DOT);
        tap_code16(BP_DOT);
    }
    if(state->count > 3) {
        tap_code16(BP_DOT);
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_7].step = dance_step(state);
    switch (dance_state[DANCE_7].step) {
        case SINGLE_TAP: register_code16(BP_DOT); break;
        case SINGLE_HOLD: register_code16(BP_COLN); break;
        case DOUBLE_TAP: register_code16(BP_DOT); register_code16(BP_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_DOT); register_code16(BP_DOT);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_7].step) {
        case SINGLE_TAP: unregister_code16(BP_DOT); break;
        case SINGLE_HOLD: unregister_code16(BP_COLN); break;
        case DOUBLE_TAP: unregister_code16(BP_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_DOT); break;
    }
    dance_state[DANCE_7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT_ALT);
        tap_code16(KC_LEFT_ALT);
        tap_code16(KC_LEFT_ALT);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT_ALT);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_8].step = dance_step(state);
    switch (dance_state[DANCE_8].step) {
        case SINGLE_TAP: register_code16(KC_LEFT_ALT); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT_ALT); register_code16(KC_LEFT_ALT);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_8].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT_ALT); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT_ALT); break;
    }
    dance_state[DANCE_8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PAGE_UP);
        tap_code16(KC_PAGE_UP);
        tap_code16(KC_PAGE_UP);
    }
    if(state->count > 3) {
        tap_code16(KC_PAGE_UP);
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_9].step = dance_step(state);
    switch (dance_state[DANCE_9].step) {
        case SINGLE_TAP: register_code16(KC_PAGE_UP); break;
        case SINGLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_PAGE_UP); register_code16(KC_PAGE_UP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PAGE_UP); register_code16(KC_PAGE_UP);
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_9].step) {
        case SINGLE_TAP: unregister_code16(KC_PAGE_UP); break;
        case SINGLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_PAGE_UP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PAGE_UP); break;
    }
    dance_state[DANCE_9].step = 0;
}
void on_dance_10(tap_dance_state_t *state, void *user_data);
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void on_dance_10(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PGDN);
        tap_code16(KC_PGDN);
        tap_code16(KC_PGDN);
    }
    if(state->count > 3) {
        tap_code16(KC_PGDN);
    }
}

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_10].step = dance_step(state);
    switch (dance_state[DANCE_10].step) {
        case SINGLE_TAP: register_code16(KC_PGDN); break;
        case SINGLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_TAP: register_code16(KC_PGDN); register_code16(KC_PGDN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PGDN); register_code16(KC_PGDN);
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_10].step) {
        case SINGLE_TAP: unregister_code16(KC_PGDN); break;
        case SINGLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_TAP: unregister_code16(KC_PGDN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PGDN); break;
    }
    dance_state[DANCE_10].step = 0;
}
void on_dance_11(tap_dance_state_t *state, void *user_data);
void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void on_dance_11(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT_GUI);
        tap_code16(KC_LEFT_GUI);
        tap_code16(KC_LEFT_GUI);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT_GUI);
    }
}

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_11].step = dance_step(state);
    switch (dance_state[DANCE_11].step) {
        case SINGLE_TAP: register_code16(KC_LEFT_GUI); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT_GUI); register_code16(KC_LEFT_GUI);
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_11].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT_GUI); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT_GUI); break;
    }
    dance_state[DANCE_11].step = 0;
}
void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_12].step = dance_step(state);
    switch (dance_state[DANCE_12].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_12].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[DANCE_12].step = 0;
}
void on_dance_13(tap_dance_state_t *state, void *user_data);
void dance_13_finished(tap_dance_state_t *state, void *user_data);
void dance_13_reset(tap_dance_state_t *state, void *user_data);

void on_dance_13(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F3);
        tap_code16(KC_F3);
        tap_code16(KC_F3);
    }
    if(state->count > 3) {
        tap_code16(KC_F3);
    }
}

void dance_13_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_13].step = dance_step(state);
    switch (dance_state[DANCE_13].step) {
        case SINGLE_TAP: register_code16(KC_F3); break;
        case SINGLE_HOLD: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
    }
}

void dance_13_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_13].step) {
        case SINGLE_TAP: unregister_code16(KC_F3); break;
        case SINGLE_HOLD: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
    }
    dance_state[DANCE_13].step = 0;
}
void on_dance_14(tap_dance_state_t *state, void *user_data);
void dance_14_finished(tap_dance_state_t *state, void *user_data);
void dance_14_reset(tap_dance_state_t *state, void *user_data);

void on_dance_14(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F1);
        tap_code16(KC_F1);
        tap_code16(KC_F1);
    }
    if(state->count > 3) {
        tap_code16(KC_F1);
    }
}

void dance_14_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_14].step = dance_step(state);
    switch (dance_state[DANCE_14].step) {
        case SINGLE_TAP: register_code16(KC_F1); break;
        case SINGLE_HOLD: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
    }
}

void dance_14_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_14].step) {
        case SINGLE_TAP: unregister_code16(KC_F1); break;
        case SINGLE_HOLD: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
    }
    dance_state[DANCE_14].step = 0;
}
void on_dance_15(tap_dance_state_t *state, void *user_data);
void dance_15_finished(tap_dance_state_t *state, void *user_data);
void dance_15_reset(tap_dance_state_t *state, void *user_data);

void on_dance_15(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if(state->count > 3) {
        tap_code16(KC_F9);
    }
}

void dance_15_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_15].step = dance_step(state);
    switch (dance_state[DANCE_15].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case SINGLE_HOLD: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}

void dance_15_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_15].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case SINGLE_HOLD: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[DANCE_15].step = 0;
}
void on_dance_16(tap_dance_state_t *state, void *user_data);
void dance_16_finished(tap_dance_state_t *state, void *user_data);
void dance_16_reset(tap_dance_state_t *state, void *user_data);

void on_dance_16(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_16_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_16].step = dance_step(state);
    switch (dance_state[DANCE_16].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case SINGLE_HOLD: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_WWW_REFRESH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_16_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_16].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case SINGLE_HOLD: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_REFRESH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[DANCE_16].step = 0;
}
void on_dance_17(tap_dance_state_t *state, void *user_data);
void dance_17_finished(tap_dance_state_t *state, void *user_data);
void dance_17_reset(tap_dance_state_t *state, void *user_data);

void on_dance_17(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if(state->count > 3) {
        tap_code16(KC_F7);
    }
}

void dance_17_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_17].step = dance_step(state);
    switch (dance_state[DANCE_17].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case SINGLE_HOLD: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}

void dance_17_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_17].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case SINGLE_HOLD: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[DANCE_17].step = 0;
}
void on_dance_18(tap_dance_state_t *state, void *user_data);
void dance_18_finished(tap_dance_state_t *state, void *user_data);
void dance_18_reset(tap_dance_state_t *state, void *user_data);

void on_dance_18(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_NEXT_TRACK);
        tap_code16(KC_MEDIA_NEXT_TRACK);
        tap_code16(KC_MEDIA_NEXT_TRACK);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_NEXT_TRACK);
    }
}

void dance_18_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_18].step = dance_step(state);
    switch (dance_state[DANCE_18].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_FAST_FORWARD); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_NEXT_TRACK); register_code16(KC_MEDIA_NEXT_TRACK);
    }
}

void dance_18_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_18].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_FAST_FORWARD); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
    }
    dance_state[DANCE_18].step = 0;
}
void on_dance_19(tap_dance_state_t *state, void *user_data);
void dance_19_finished(tap_dance_state_t *state, void *user_data);
void dance_19_reset(tap_dance_state_t *state, void *user_data);

void on_dance_19(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RIGHT_GUI);
        tap_code16(KC_RIGHT_GUI);
        tap_code16(KC_RIGHT_GUI);
    }
    if(state->count > 3) {
        tap_code16(KC_RIGHT_GUI);
    }
}

void dance_19_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_19].step = dance_step(state);
    switch (dance_state[DANCE_19].step) {
        case SINGLE_TAP: register_code16(KC_RIGHT_GUI); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_UP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RIGHT_GUI); register_code16(KC_RIGHT_GUI);
    }
}

void dance_19_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_19].step) {
        case SINGLE_TAP: unregister_code16(KC_RIGHT_GUI); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_UP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RIGHT_GUI); break;
    }
    dance_state[DANCE_19].step = 0;
}
void on_dance_20(tap_dance_state_t *state, void *user_data);
void dance_20_finished(tap_dance_state_t *state, void *user_data);
void dance_20_reset(tap_dance_state_t *state, void *user_data);

void on_dance_20(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_COLN);
        tap_code16(BP_COLN);
        tap_code16(BP_COLN);
    }
    if(state->count > 3) {
        tap_code16(BP_COLN);
    }
}

void dance_20_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_20].step = dance_step(state);
    switch (dance_state[DANCE_20].step) {
        case SINGLE_TAP: register_code16(BP_COLN); break;
        case SINGLE_HOLD: register_code16(BP_EURO); break;
        case DOUBLE_TAP: register_code16(BP_COLN); register_code16(BP_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_COLN); register_code16(BP_COLN);
    }
}

void dance_20_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_20].step) {
        case SINGLE_TAP: unregister_code16(BP_COLN); break;
        case SINGLE_HOLD: unregister_code16(BP_EURO); break;
        case DOUBLE_TAP: unregister_code16(BP_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_COLN); break;
    }
    dance_state[DANCE_20].step = 0;
}
void on_dance_21(tap_dance_state_t *state, void *user_data);
void dance_21_finished(tap_dance_state_t *state, void *user_data);
void dance_21_reset(tap_dance_state_t *state, void *user_data);

void on_dance_21(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_DOT);
        tap_code16(BP_DOT);
        tap_code16(BP_DOT);
    }
    if(state->count > 3) {
        tap_code16(BP_DOT);
    }
}

void dance_21_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_21].step = dance_step(state);
    switch (dance_state[DANCE_21].step) {
        case SINGLE_TAP: register_code16(BP_DOT); break;
        case SINGLE_HOLD: register_code16(RALT(RSFT(BP_L))); break;
        case DOUBLE_TAP: register_code16(BP_DOT); register_code16(BP_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_DOT); register_code16(BP_DOT);
    }
}

void dance_21_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_21].step) {
        case SINGLE_TAP: unregister_code16(BP_DOT); break;
        case SINGLE_HOLD: unregister_code16(RALT(RSFT(BP_L))); break;
        case DOUBLE_TAP: unregister_code16(BP_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_DOT); break;
    }
    dance_state[DANCE_21].step = 0;
}
void on_dance_23(tap_dance_state_t *state, void *user_data);
void dance_23_finished(tap_dance_state_t *state, void *user_data);
void dance_23_reset(tap_dance_state_t *state, void *user_data);

void on_dance_23(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if(state->count > 3) {
        tap_code16(KC_F9);
    }
}

void dance_23_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_23].step = dance_step(state);
    switch (dance_state[DANCE_23].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case SINGLE_HOLD: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_EJECT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}

void dance_23_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_23].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case SINGLE_HOLD: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_EJECT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[DANCE_23].step = 0;
}
void on_dance_24(tap_dance_state_t *state, void *user_data);
void dance_24_finished(tap_dance_state_t *state, void *user_data);
void dance_24_reset(tap_dance_state_t *state, void *user_data);

void on_dance_24(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_24_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_24].step = dance_step(state);
    switch (dance_state[DANCE_24].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case SINGLE_HOLD: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_STOP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_24_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_24].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case SINGLE_HOLD: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_STOP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[DANCE_24].step = 0;
}
void on_dance_25(tap_dance_state_t *state, void *user_data);
void dance_25_finished(tap_dance_state_t *state, void *user_data);
void dance_25_reset(tap_dance_state_t *state, void *user_data);

void on_dance_25(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if(state->count > 3) {
        tap_code16(KC_F7);
    }
}

void dance_25_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_25].step = dance_step(state);
    switch (dance_state[DANCE_25].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case SINGLE_HOLD: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}

void dance_25_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_25].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case SINGLE_HOLD: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[DANCE_25].step = 0;
}
void on_dance_26(tap_dance_state_t *state, void *user_data);
void dance_26_finished(tap_dance_state_t *state, void *user_data);
void dance_26_reset(tap_dance_state_t *state, void *user_data);

void on_dance_26(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_DEGR);
        tap_code16(BP_DEGR);
        tap_code16(BP_DEGR);
    }
    if(state->count > 3) {
        tap_code16(BP_DEGR);
    }
}

void dance_26_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_26].step = dance_step(state);
    switch (dance_state[DANCE_26].step) {
        case SINGLE_TAP: register_code16(BP_DEGR); break;
        case SINGLE_HOLD: register_code16(RALT(BP_EGRV)); break;
        case DOUBLE_TAP: register_code16(BP_DEGR); register_code16(BP_DEGR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_DEGR); register_code16(BP_DEGR);
    }
}

void dance_26_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_26].step) {
        case SINGLE_TAP: unregister_code16(BP_DEGR); break;
        case SINGLE_HOLD: unregister_code16(RALT(BP_EGRV)); break;
        case DOUBLE_TAP: unregister_code16(BP_DEGR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_DEGR); break;
    }
    dance_state[DANCE_26].step = 0;
}
void on_dance_27(tap_dance_state_t *state, void *user_data);
void dance_27_finished(tap_dance_state_t *state, void *user_data);
void dance_27_reset(tap_dance_state_t *state, void *user_data);

void on_dance_27(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_27_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_27].step = dance_step(state);
    switch (dance_state[DANCE_27].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(KC_SCLN); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_27_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_27].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(KC_SCLN); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[DANCE_27].step = 0;
}
void on_dance_28(tap_dance_state_t *state, void *user_data);
void dance_28_finished(tap_dance_state_t *state, void *user_data);
void dance_28_reset(tap_dance_state_t *state, void *user_data);

void on_dance_28(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_28_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_28].step = dance_step(state);
    switch (dance_state[DANCE_28].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(KC_COLN); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_28_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_28].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(KC_COLN); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[DANCE_28].step = 0;
}
void on_dance_29(tap_dance_state_t *state, void *user_data);
void dance_29_finished(tap_dance_state_t *state, void *user_data);
void dance_29_reset(tap_dance_state_t *state, void *user_data);

void on_dance_29(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
    }
    if(state->count > 3) {
        tap_code16(KC_COLN);
    }
}

void dance_29_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_29].step = dance_step(state);
    switch (dance_state[DANCE_29].step) {
        case SINGLE_TAP: register_code16(KC_COLN); break;
        case SINGLE_HOLD:
           if (!activeNumLockLed) {
               register_code16(RALT(RSFT(KC_2)));
           } else {
               register_code16(RALT(KC_5));
           }
           break;
        case DOUBLE_TAP: register_code16(KC_COLN); register_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COLN); register_code16(KC_COLN);
    }
}

void dance_29_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_29].step) {
        case SINGLE_TAP: unregister_code16(KC_COLN); break;
        case SINGLE_HOLD:
           if (!activeNumLockLed) {
               unregister_code16(RALT(RSFT(KC_2)));
           } else {
               unregister_code16(RALT(KC_5));
           }
           break;
        case DOUBLE_TAP: unregister_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COLN); break;
    }
    dance_state[DANCE_29].step = 0;
}
void on_dance_30(tap_dance_state_t *state, void *user_data);
void dance_30_finished(tap_dance_state_t *state, void *user_data);
void dance_30_reset(tap_dance_state_t *state, void *user_data);

void on_dance_30(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_30_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_30].step = dance_step(state);
    switch (dance_state[DANCE_30].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD:
           if (!activeNumLockLed) {
               register_code16(RALT(KC_3));
           } else {
               register_code16(RALT(RSFT(KC_4)));
           }
           break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_30_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_30].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD:
           if (!activeNumLockLed) {
               unregister_code16(RALT(KC_3));
           } else {
               unregister_code16(RALT(RSFT(KC_4)));
           }
           break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[DANCE_30].step = 0;
}
void on_dance_32(tap_dance_state_t *state, void *user_data);
void dance_32_finished(tap_dance_state_t *state, void *user_data);
void dance_32_reset(tap_dance_state_t *state, void *user_data);

void on_dance_32(tap_dance_state_t *state, void *user_data) {
    if (!activeNumLockLed) {
        if(state->count == 3) {
            tap_code16(RALT(RSFT(KC_8)));
            tap_code16(RALT(RSFT(KC_8)));
            tap_code16(RALT(RSFT(KC_8)));
        }
        if(state->count > 3) {
            tap_code16(RALT(RSFT(KC_8)));
        }
    } else {
        if(state->count == 3) {
            tap_code16(LSFT(RALT(KC_SCLN)));
            tap_code16(LSFT(RALT(KC_SCLN)));
            tap_code16(LSFT(RALT(KC_SCLN)));
        }
        if(state->count > 3) {
            tap_code16(LSFT(RALT(KC_SCLN)));
        }
    }
}

void dance_32_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_32].step = dance_step(state);
    if (!activeNumLockLed) {
        switch (dance_state[DANCE_32].step) {
            case SINGLE_TAP: register_code16(RALT(RSFT(KC_8))); break;
            case SINGLE_HOLD: register_code16(KC_GRAVE); break;
            case DOUBLE_TAP: register_code16(RALT(RSFT(KC_8))); register_code16(RALT(RSFT(KC_8))); break;
            case DOUBLE_SINGLE_TAP: tap_code16(RALT(RSFT(KC_8))); register_code16(RALT(RSFT(KC_8)));
        }
    } else {
        switch (dance_state[DANCE_32].step) {
            case SINGLE_TAP: register_code16(LSFT(RALT(KC_SCLN))); break;
            case SINGLE_HOLD: register_code16(KC_GRAVE); break;
            case DOUBLE_TAP: register_code16(LSFT(RALT(KC_SCLN))); register_code16(LSFT(RALT(KC_SCLN))); break;
            case DOUBLE_SINGLE_TAP: tap_code16(LSFT(RALT(KC_SCLN))); register_code16(LSFT(RALT(KC_SCLN)));
        }
    }
}

void dance_32_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    if (!activeNumLockLed) {
        switch (dance_state[DANCE_32].step) {
            case SINGLE_TAP: unregister_code16(RALT(RSFT(KC_8))); break;
            case SINGLE_HOLD: unregister_code16(KC_GRAVE); break;
            case DOUBLE_TAP: unregister_code16(RALT(RSFT(KC_8))); break;
            case DOUBLE_SINGLE_TAP: unregister_code16(RALT(RSFT(KC_8))); break;
        }
    } else {
        switch (dance_state[DANCE_32].step) {
            case SINGLE_TAP: unregister_code16(LSFT(RALT(KC_SCLN))); break;
            case SINGLE_HOLD: unregister_code16(KC_GRAVE); break;
            case DOUBLE_TAP: unregister_code16(LSFT(RALT(KC_SCLN))); break;
            case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(RALT(KC_SCLN))); break;
        }
    }
    dance_state[DANCE_32].step = 0;
}
void on_dance_33(tap_dance_state_t *state, void *user_data);
void dance_33_finished(tap_dance_state_t *state, void *user_data);
void dance_33_reset(tap_dance_state_t *state, void *user_data);

void on_dance_33(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_COMM);
        tap_code16(FR_COMM);
        tap_code16(FR_COMM);
    }
    if(state->count > 3) {
        tap_code16(FR_COMM);
    }
}

void dance_33_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_33].step = dance_step(state);
    switch (dance_state[DANCE_33].step) {
        case SINGLE_TAP: register_code16(FR_COMM); break;
        case SINGLE_HOLD: register_code16(FR_SCLN); break;
        case DOUBLE_TAP: register_code16(FR_COMM); register_code16(FR_COMM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_COMM); register_code16(FR_COMM);
    }
}

void dance_33_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_33].step) {
        case SINGLE_TAP: unregister_code16(FR_COMM); break;
        case SINGLE_HOLD: unregister_code16(FR_SCLN); break;
        case DOUBLE_TAP: unregister_code16(FR_COMM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_COMM); break;
    }
    dance_state[DANCE_33].step = 0;
}
void on_dance_34(tap_dance_state_t *state, void *user_data);
void dance_34_finished(tap_dance_state_t *state, void *user_data);
void dance_34_reset(tap_dance_state_t *state, void *user_data);

void on_dance_34(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_DOT);
        tap_code16(FR_DOT);
        tap_code16(FR_DOT);
    }
    if(state->count > 3) {
        tap_code16(FR_DOT);
    }
}

void dance_34_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_34].step = dance_step(state);
    switch (dance_state[DANCE_34].step) {
        case SINGLE_TAP: register_code16(FR_DOT); break;
        case SINGLE_HOLD: register_code16(FR_COLN); break;
        case DOUBLE_TAP: register_code16(FR_DOT); register_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_DOT); register_code16(FR_DOT);
    }
}

void dance_34_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_34].step) {
        case SINGLE_TAP: unregister_code16(FR_DOT); break;
        case SINGLE_HOLD: unregister_code16(FR_COLN); break;
        case DOUBLE_TAP: unregister_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_DOT); break;
    }
    dance_state[DANCE_34].step = 0;
}
void on_dance_35(tap_dance_state_t *state, void *user_data);
void dance_35_finished(tap_dance_state_t *state, void *user_data);
void dance_35_reset(tap_dance_state_t *state, void *user_data);

void on_dance_35(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_COLN);
        tap_code16(FR_COLN);
        tap_code16(FR_COLN);
    }
    if(state->count > 3) {
        tap_code16(FR_COLN);
    }
}

void dance_35_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_35].step = dance_step(state);
    switch (dance_state[DANCE_35].step) {
        case SINGLE_TAP: register_code16(FR_COLN); break;
        case SINGLE_HOLD: register_code16(FR_EURO); break;
        case DOUBLE_TAP: register_code16(FR_COLN); register_code16(FR_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_COLN); register_code16(FR_COLN);
    }
}

void dance_35_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_35].step) {
        case SINGLE_TAP: unregister_code16(FR_DOT); break;
        case SINGLE_HOLD: unregister_code16(FR_EURO); break;
        case DOUBLE_TAP: unregister_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_DOT); break;
    }
    dance_state[DANCE_35].step = 0;
}
void on_dance_36(tap_dance_state_t *state, void *user_data);
void dance_36_finished(tap_dance_state_t *state, void *user_data);
void dance_36_reset(tap_dance_state_t *state, void *user_data);

void on_dance_36(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_DOT);
        tap_code16(FR_DOT);
        tap_code16(FR_DOT);
    }
    if(state->count > 3) {
        tap_code16(FR_DOT);
    }
}

void dance_36_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_36].step = dance_step(state);
    switch (dance_state[DANCE_36].step) {
        case SINGLE_TAP: register_code16(FR_DOT); break;
        case SINGLE_HOLD: register_code16(FR_PND); break;
        case DOUBLE_TAP: register_code16(FR_DOT); register_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_DOT); register_code16(FR_DOT);
    }
}

void dance_36_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_36].step) {
        case SINGLE_TAP: unregister_code16(FR_DOT); break;
        case SINGLE_HOLD: unregister_code16(FR_PND); break;
        case DOUBLE_TAP: unregister_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_DOT); break;
    }
    dance_state[DANCE_36].step = 0;
}
void on_dance_38(tap_dance_state_t *state, void *user_data);
void dance_38_finished(tap_dance_state_t *state, void *user_data);
void dance_38_reset(tap_dance_state_t *state, void *user_data);

void on_dance_38(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_OVRR);
        tap_code16(FR_OVRR);
        tap_code16(FR_OVRR);
    }
    if(state->count > 3) {
        tap_code16(FR_OVRR);
    }
}

void dance_38_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_38].step = dance_step(state);
    switch (dance_state[DANCE_38].step) {
        case SINGLE_TAP: register_code16(FR_OVRR); break;
        case SINGLE_HOLD: register_code16(FR_GRV); break;
        case DOUBLE_TAP: register_code16(FR_OVRR); register_code16(FR_OVRR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_OVRR); register_code16(FR_OVRR);
    }
}

void dance_38_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_38].step) {
        case SINGLE_TAP: unregister_code16(FR_OVRR); break;
        case SINGLE_HOLD: unregister_code16(FR_GRV); break;
        case DOUBLE_TAP: unregister_code16(FR_OVRR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_OVRR); break;
    }
    dance_state[DANCE_38].step = 0;
}
void dance_39_finished(tap_dance_state_t *state, void *user_data);
void dance_39_reset(tap_dance_state_t *state, void *user_data);

void dance_39_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_39].step = dance_step(state);
    switch (dance_state[DANCE_39].step) {
        case SINGLE_TAP: register_code16(KC_COLN); break;
        case SINGLE_HOLD: register_code16(RALT(RSFT(KC_2))); break;
        case DOUBLE_TAP: register_code16(KC_COLN); register_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COLN); register_code16(KC_COLN);
    }
}

void dance_39_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_39].step) {
        case SINGLE_TAP: unregister_code16(KC_COLN); break;
        case SINGLE_HOLD: unregister_code16(RALT(RSFT(KC_2))); break;
        case DOUBLE_TAP: unregister_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COLN); break;
    }
    dance_state[DANCE_39].step = 0;
}
void dance_40_finished(tap_dance_state_t *state, void *user_data);
void dance_40_reset(tap_dance_state_t *state, void *user_data);

void dance_40_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_40].step = dance_step(state);
    switch (dance_state[DANCE_40].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(RALT(KC_3)); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_40_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_40].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(RALT(KC_3)); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[DANCE_40].step = 0;
}
void on_dance_41(tap_dance_state_t *state, void *user_data);
void dance_41_finished(tap_dance_state_t *state, void *user_data);
void dance_41_reset(tap_dance_state_t *state, void *user_data);

void on_dance_41(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RALT(RSFT(KC_8)));
        tap_code16(RALT(RSFT(KC_8)));
        tap_code16(RALT(RSFT(KC_8)));
    }
    if(state->count > 3) {
        tap_code16(RALT(RSFT(KC_8)));
    }
}

void dance_41_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_41].step = dance_step(state);
    switch (dance_state[DANCE_41].step) {
        case SINGLE_TAP: register_code16(RALT(RSFT(KC_8))); break;
        case SINGLE_HOLD: register_code16(KC_GRAVE); break;
        case DOUBLE_TAP: register_code16(RALT(RSFT(KC_8))); register_code16(RALT(RSFT(KC_8))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RALT(RSFT(KC_8))); register_code16(RALT(RSFT(KC_8)));
    }
}

void dance_41_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_41].step) {
        case SINGLE_TAP: unregister_code16(RALT(RSFT(KC_8))); break;
        case SINGLE_HOLD: unregister_code16(KC_GRAVE); break;
        case DOUBLE_TAP: unregister_code16(RALT(RSFT(KC_8))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RALT(RSFT(KC_8))); break;
    }
    dance_state[DANCE_41].step = 0;
}
void on_dance_42(tap_dance_state_t *state, void *user_data);
void dance_42_finished(tap_dance_state_t *state, void *user_data);
void dance_42_reset(tap_dance_state_t *state, void *user_data);

void on_dance_42(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_DOT);
        tap_code16(KC_KP_DOT);
        tap_code16(KC_KP_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_DOT);
    }
}

void dance_42_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_42].step = dance_step(state);
    switch (dance_state[DANCE_42].step) {
        case SINGLE_TAP: register_code16(KC_KP_DOT); break;
        case SINGLE_HOLD: register_code16(KC_KP_COMMA); break;
        case DOUBLE_TAP: register_code16(KC_KP_DOT); register_code16(KC_KP_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_DOT); register_code16(KC_KP_DOT);
    }
}

void dance_42_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_42].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_DOT); break;
        case SINGLE_HOLD: unregister_code16(KC_KP_COMMA); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_DOT); break;
    }
    dance_state[DANCE_42].step = 0;
}
void on_dance_43(tap_dance_state_t *state, void *user_data);
void dance_43_finished(tap_dance_state_t *state, void *user_data);
void dance_43_reset(tap_dance_state_t *state, void *user_data);

void on_dance_43(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_43_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_43].step = dance_step(state);
    switch (dance_state[DANCE_43].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: layer_move(9); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_43_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_43].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[DANCE_43].step = 0;
}
void on_dance_44(tap_dance_state_t *state, void *user_data);
void dance_44_finished(tap_dance_state_t *state, void *user_data);
void dance_44_reset(tap_dance_state_t *state, void *user_data);

void on_dance_44(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MAIL);
        tap_code16(KC_MAIL);
        tap_code16(KC_MAIL);
    }
    if(state->count > 3) {
        tap_code16(KC_MAIL);
    }
}

void dance_44_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_44].step = dance_step(state);
    switch (dance_state[DANCE_44].step) {
        case SINGLE_TAP: register_code16(KC_MAIL); break;
        case SINGLE_HOLD: register_code16(KC_WWW_HOME); break;
        case DOUBLE_TAP: register_code16(KC_MAIL); register_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MAIL); register_code16(KC_MAIL);
    }
}

void dance_44_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_44].step) {
        case SINGLE_TAP: unregister_code16(KC_MAIL); break;
        case SINGLE_HOLD: unregister_code16(KC_WWW_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MAIL); break;
    }
    dance_state[DANCE_44].step = 0;
}
void on_dance_enter(tap_dance_state_t *state, void *user_data);
void dance_enter_finished(tap_dance_state_t *state, void *user_data);
void dance_enter_reset(tap_dance_state_t *state, void *user_data);

void on_dance_enter(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
    }
    if(state->count > 3) {
        tap_code16(KC_ENTER);
    }
}

void dance_enter_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_ENTER].step = dance_step(state);
    switch (dance_state[DANCE_ENTER].step) {
        case SINGLE_TAP: register_code16(KC_ENTER); break;
        case SINGLE_HOLD: register_code16(KC_ENTER); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER);
    }
}

void dance_enter_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_ENTER].step) {
        case SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case SINGLE_HOLD: unregister_code16(KC_ENTER); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
    }
    dance_state[DANCE_ENTER].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
        [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
        [DANCE_14] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
        [DANCE_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
        [DANCE_16] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
        [DANCE_17] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_17, dance_17_finished, dance_17_reset),
        [DANCE_18] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_18, dance_18_finished, dance_18_reset),
        [DANCE_19] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_19, dance_19_finished, dance_19_reset),
        [DANCE_20] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_20, dance_20_finished, dance_20_reset),
        [DANCE_21] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_21, dance_21_finished, dance_21_reset),
        [DANCE_23] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_23, dance_23_finished, dance_23_reset),
        [DANCE_24] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_24, dance_24_finished, dance_24_reset),
        [DANCE_25] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_25, dance_25_finished, dance_25_reset),
        [DANCE_26] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_26, dance_26_finished, dance_26_reset),
        [DANCE_27] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_27, dance_27_finished, dance_27_reset),
        [DANCE_28] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_28, dance_28_finished, dance_28_reset),
        [DANCE_29] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_29, dance_29_finished, dance_29_reset),
        [DANCE_30] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_30, dance_30_finished, dance_30_reset),
        [DANCE_32] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_32, dance_32_finished, dance_32_reset),
        [DANCE_33] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_33, dance_33_finished, dance_33_reset),
        [DANCE_34] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_34, dance_34_finished, dance_34_reset),
        [DANCE_35] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_35, dance_35_finished, dance_35_reset),
        [DANCE_36] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_36, dance_36_finished, dance_36_reset),
        [DANCE_38] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_38, dance_38_finished, dance_38_reset),
        [DANCE_39] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_29, dance_39_finished, dance_39_reset),
        [DANCE_40] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_30, dance_40_finished, dance_40_reset),
        [DANCE_41] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_41, dance_41_finished, dance_41_reset),
        [DANCE_42] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_42, dance_42_finished, dance_42_reset),
        [DANCE_43] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_43, dance_43_finished, dance_43_reset),
        [DANCE_44] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_44, dance_44_finished, dance_44_reset),
        [DANCE_ENTER] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_enter, dance_enter_finished, dance_enter_reset),
};

/* Vince specific code */

bool caps_word_press_user(uint16_t keycode) {
   switch (biton32(layer_state)) {
      case 0:           // BEPO
      case 1:
      case 2:
         switch (keycode) {
            // Keycodes that continue Caps Word, with shift applied.
            case BP_A:
            case BP_B:
            case BP_C:
            case BP_D:
            case BP_E:
            case BP_F:
            case BP_G:
            case BP_H:
            case BP_I:
            case BP_J:
            case BP_K:
            case BP_L:
            case BP_M:
            case BP_N:
            case BP_O:
            case BP_P:
            case BP_Q:
            case BP_R:
            case BP_S:
            case BP_T:
            case BP_U:
            case BP_V:
            case BP_W:
            case BP_X:
            case BP_Y:
            case BP_Z:
            case BP_ECUT:
            case BP_EGRV:
            case BP_AGRV:
            case BP_CCED:
            case BP_UGRV:
            case BP_AE:
            case BP_OE:
               add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
               return true;

            // Keycodes that continue Caps Word, without shifting.
            case BP_1 ... BP_0:
            case KC_KP_1 ... KC_KP_0:
            case KC_BSPC:
            case KC_DELETE:
            case QK_LLCK:
            case BP_UNDS:
            case BP_DCRC:
            case BP_DTRM:
               return true;

            default: return false;  // Deactivate Caps Word.
         }
      case 3:           // QWERTY
      case 4:
      case 5:
         switch (keycode) {
            // Keycodes that continue Caps Word, with shift applied.
            case KC_UNDS:
            case KC_DQUO:
            case ST_MACRO_4:
            case ST_MACRO_7:
            case ALGR(KC_Q):
            case KC_A ... KC_Z:
               add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
               return true;

            // Keycodes that continue Caps Word, without shifting.
            case KC_1 ... KC_0:
            case KC_KP_1 ... KC_KP_0:
            case KC_BSPC:
            case KC_DELETE:
            case QK_LLCK:
            case KC_CIRC:
            case KC_QUOTE:
            case KC_GRAVE:
            case ST_MACRO_1:
            case ST_MACRO_2:
            case ST_MACRO_3:
            case ST_MACRO_11:
               return true;

            case KC_AT:
            case KC_LCBR:
            case KC_RCBR:
            case KC_LPRN:
            case KC_RPRN:
               add_oneshot_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));  // Apply shift to next key.
               return false;

            default: return false;  // Deactivate Caps Word.
         }
      case 6:           // AZERTY
      case 7:
      case 8:
         switch (keycode) {
            // Keycodes that continue Caps Word, with shift applied.
            case FR_A:
            case KC_B:
            case KC_C:
            case KC_D:
            case KC_E:
            case KC_F:
            case KC_G:
            case KC_H:
            case KC_I:
            case KC_J:
            case KC_K:
            case KC_L:
            case FR_M:
            case KC_N:
            case KC_O:
            case KC_P:
            case FR_Q:
            case KC_R:
            case KC_S:
            case KC_T:
            case KC_U:
            case KC_V:
            case FR_W:
            case KC_X:
            case KC_Y:
            case FR_Z:
               add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
               return true;

            // Keycodes that continue Caps Word, without shifting.
            case FR_1 ... FR_0:
            case KC_KP_1 ... KC_KP_0:
            case KC_BSPC:
            case KC_DELETE:
            case QK_LLCK:
            case FR_UNDS:
               return true;

            default:
               return false;  // Deactivate Caps Word.
         }
      case 9:           // Keyboard
         switch (keycode) {
            // Keycodes that continue Caps Word, without shifting.
            case KC_KP_1 ... KC_KP_0:
            case KC_BSPC:
            case KC_DELETE:
            case QK_LLCK:
               return true;

            default: return false;  // Deactivate Caps Word.
         }
      default: return false;
   }

   return false;
}

extern bool is_launching;

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (!is_launching && res) {
        if (!activeNumLockLed) {
        STATUS_LED_5(false);
        } else {
#ifndef VM_USE_NUMPAD_ONLY
        STATUS_LED_5(led_state.num_lock);
#else
        STATUS_LED_5(!led_state.num_lock);
#endif
        }
        STATUS_LED_3(led_state.caps_lock);
    }
    return res;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);
    if (is_launching || !keyboard_config.led_level) return state;
    bool LED_1 = false;
    bool LED_4 = false;

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 1:
            LED_4 = true;
            break;
        case 2:
            LED_1 = true;
            break;
        case 3:
            break;
        case 4:
            LED_4 = true;
            break;
        case 5:
            LED_1 = true;
            break;
        case 6:
            break;
        case 7:
            LED_4 = true;
            break;
        case 8:
            LED_1 = true;
            break;
        case 9:
            LED_4 = true;
            LED_1 = true;
            break;
        default:
            break;
    }

    STATUS_LED_1(LED_1);
    STATUS_LED_4(LED_4);

    return state;
}

void caps_word_set_user(bool active) {
    if (!is_launching) {
        STATUS_LED_6(active);
    }
}

// OS detection code
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        layer_move(0);
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            // This variable identify that we are running on a mac
            activeNumLockLed = false;

        case OS_WINDOWS:
            layer_move(3);
            break;
        case OS_LINUX:
        case OS_UNSURE:
            layer_move(0);

            linuxSystem = true;
            break;
    }

    return true;
}
