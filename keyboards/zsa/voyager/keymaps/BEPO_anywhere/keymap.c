#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#define BEPO_BASE_LAYER 0
#define QWERTY_BASE_LAYER (3 - BEPO_BASE_LAYER)

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
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
  ST_MACRO_23,
  ST_MACRO_24,
  ST_MACRO_25,
  ST_MACRO_26,
  ST_MACRO_27,
  ST_MACRO_28,
  ST_MACRO_29,
};

static bool activeNumLockLed = true;
static bool linuxSystem = true;
static int lastLayerActivation = 0;
static int accentLayerActivation = 0;
static bool web1OneShot = false;
static bool web2OneShot = false;
static bool runAccent = false;

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
  DANCE_22,
  DANCE_23,
  DANCE_24,
  DANCE_25,
  DANCE_26,
  DANCE_27,
  DANCE_28,
  DANCE_29,
  DANCE_30,
  DANCE_31,
  DANCE_32,
  DANCE_33,
  DANCE_34,
  DANCE_38,
  DANCE_39,
  DANCE_40,
#ifdef AUTOMOUSE_LAYER
  DANCE_41,
#endif
  DANCE_42,
  DANCE_43,
  DANCE_44,
  DANCE_45,
  DANCE_46,
  DANCE_47,
  DANCE_ENTER,
  DANCE_ESC,
  DANCE_WEB1,
  DANCE_WEB2,
  DANCE_QUIT,
  DANCE_BTN2,
  DANCE_BTN8,
#ifdef VM_USE_LEFTPAD_ONLY
  DANCE_49,
  DANCE_50,
  DANCE_51,
  DANCE_52,
  DANCE_53,
#endif
  DANCE_LAST_ARRAY_SIZE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BEPO_BASE_LAYER + 0] = LAYOUT_voyager(
    KC_ESCAPE,      BP_B,           BP_ECUT,        BP_P,           BP_O,           BP_EGRV,                                        BP_V,           BP_D,           BP_L,           BP_J,           BP_Z,           KC_UP,
    KC_TAB,         BP_A,           BP_U,           BP_I,           BP_E,           TD(DANCE_0),                                    BP_T,           BP_S,           BP_R,           BP_N,           BP_M,           KC_DOWN,
#ifdef VM_USE_DOUBLE_SHIFT_CAPS_WORD
    OSM(MOD_LSFT),  BP_AGRV,        BP_Y,           BP_X,           TD(DANCE_1),    KC_BSPC,                                        TD(DANCE_6),    BP_G,           BP_H,           BP_F,           BP_Q,           OSM(MOD_RSFT),
#else
    OSM(MOD_LSFT),  BP_AGRV,        BP_Y,           BP_X,           TD(DANCE_1),    KC_BSPC,                                        TD(DANCE_6),    BP_G,           BP_H,           BP_F,           BP_Q,           OSM(MOD_LSFT),
#endif
    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    OSL(BEPO_BASE_LAYER + 2),BP_C,  BP_CCED,                                        BP_K,           KC_SPACE,       OSL(BEPO_BASE_LAYER + 1),KC_LEFT,KC_RIGHT,      OSM(MOD_RGUI),
                                                                                    KC_ENTER,       TD(DANCE_5),    TD(DANCE_7),    BP_W
  ),
  [BEPO_BASE_LAYER + 1] = LAYOUT_voyager(
#ifndef VM_USE_NUMPAD_ONLY
    KC_TRANSPARENT, BP_PIPE,        BP_AMPR,        BP_MINS,        BP_ASTR,        TD(DANCE_8),                                    TD(DANCE_9),    BP_SLSH,        BP_PLUS,        BP_HASH,        BP_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, BP_6,           BP_4,           BP_8,           BP_0,           BP_2,                                           BP_3,           BP_1,           BP_9,           BP_5,           BP_7,           KC_TRANSPARENT,
#else
    KC_TRANSPARENT, BP_PIPE,        BP_AMPR,        KC_KP_MINUS,    KC_KP_ASTERISK, TD(DANCE_8),                                    TD(DANCE_9),    KC_KP_SLASH,    KC_KP_PLUS,     BP_HASH,        BP_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,                                        KC_KP_3,        KC_KP_1,        KC_KP_9,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT,
#endif
    KC_TRANSPARENT, BP_UNDS,        BP_LBRC,        BP_LPRN,        BP_EQL,         KC_TRANSPARENT,                                 KC_TRANSPARENT, BP_PERC,        BP_RPRN,        BP_RBRC,        BP_EXLM,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, BP_DCRC,        BP_LESS,                                        TD(DANCE_10),   KC_TRANSPARENT, QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    BP_GRTR,        TD(DANCE_ENTER),KC_TRANSPARENT, KC_DELETE
  ),
  [BEPO_BASE_LAYER + 2] = LAYOUT_voyager(
    TD(DANCE_16),   TD(DANCE_11),   TD(DANCE_12),   TD(DANCE_13),   TD(DANCE_14),   TD(DANCE_15),                                   TD(DANCE_17),   TD(DANCE_18),   TD(DANCE_19),   TD(DANCE_20),   TD(DANCE_21),   KC_TRANSPARENT,
    KC_TRANSPARENT, BP_AT,          BP_TILD,        RALT(BP_COMM),  BP_APOS,        BP_LGIL,                                        BP_RGIL,        BP_GRV,         BP_DQOT,        BP_DTRM,        TD(DANCE_22),   KC_TRANSPARENT,
    KC_TRANSPARENT, BP_QEST,        BP_LCBR,        RALT(LSFT(BP_P)),BP_AE,         KC_TRANSPARENT,                                 TD(DANCE_6),    BP_OE,          BP_MDSH,        BP_RCBR,        BP_UGRV,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_SPACE,       KC_NUM,                                         RALT(BP_2),     RALT(BP_3),     ST_MACRO_0,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_ENTER,       TD(DANCE_5),    KC_TRANSPARENT, BP_DLR
  ),
  [QWERTY_BASE_LAYER + 0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_B,           ST_MACRO_1,     KC_P,           KC_O,           ST_MACRO_2,                                     KC_V,           KC_D,           KC_L,           KC_J,           KC_Z,           KC_UP,
    KC_TAB,         KC_A,           KC_U,           KC_I,           KC_E,           TD(DANCE_23),                                   KC_T,           KC_S,           KC_R,           KC_N,           KC_M,           KC_DOWN,
#ifdef VM_USE_DOUBLE_SHIFT_CAPS_WORD
    OSM(MOD_LSFT),  ST_MACRO_3,     KC_Y,           KC_X,           TD(DANCE_24),   KC_BSPC,                                        TD(DANCE_6),    KC_G,           KC_H,           KC_F,           KC_Q,           OSM(MOD_RSFT),
#else
    OSM(MOD_LSFT),  ST_MACRO_3,     KC_Y,           KC_X,           TD(DANCE_24),   KC_BSPC,                                        TD(DANCE_6),    KC_G,           KC_H,           KC_F,           KC_Q,           OSM(MOD_LSFT),
#endif
    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    OSL(QWERTY_BASE_LAYER + 2),KC_C,ST_MACRO_25,                                    KC_K,           KC_SPACE,       OSL(QWERTY_BASE_LAYER + 1),KC_LEFT,KC_RIGHT,    OSM(MOD_RGUI),
                                                                                    KC_ENTER,       TD(DANCE_5),    TD(DANCE_7),    KC_W
  ),
  [QWERTY_BASE_LAYER + 1] = LAYOUT_voyager(
#ifndef VM_USE_NUMPAD_ONLY
    KC_TRANSPARENT, KC_PIPE,        KC_AMPR,        KC_MINUS,       KC_ASTR,        TD(DANCE_25),                                   TD(DANCE_26),   KC_SLASH,       KC_PLUS,        KC_HASH,        KC_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_6,           KC_4,           KC_8,           KC_0,           KC_2,                                           KC_3,           KC_1,           KC_9,           KC_5,           KC_7,           KC_TRANSPARENT,
#else
    KC_TRANSPARENT, KC_PIPE,        KC_AMPR,        KC_KP_MINUS,    KC_KP_ASTERISK, TD(DANCE_25),                                   TD(DANCE_26),   KC_KP_SLASH,    KC_KP_PLUS,     KC_HASH,        KC_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,                                        KC_KP_3,        KC_KP_1,        KC_KP_9,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT,
#endif
    KC_TRANSPARENT, KC_UNDS,        KC_LBRC,        KC_LPRN,        KC_EQUAL,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PERC,        KC_RPRN,        KC_RBRC,        KC_EXLM,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_LABK,                                        TD(DANCE_27),   KC_TRANSPARENT, QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_RABK,        TD(DANCE_ENTER),KC_TRANSPARENT, KC_DELETE
  ),
  [QWERTY_BASE_LAYER + 2] = LAYOUT_voyager(
    TD(DANCE_16),   TD(DANCE_11),   TD(DANCE_12),   TD(DANCE_13),   TD(DANCE_14),   TD(DANCE_15),                                   TD(DANCE_17),   TD(DANCE_18),   TD(DANCE_19),   TD(DANCE_20),   TD(DANCE_21),   KC_TRANSPARENT,
    KC_TRANSPARENT, KC_AT,          ST_MACRO_5,     ST_MACRO_6,     KC_QUOTE,       ST_MACRO_28,                                    ST_MACRO_29,    ST_MACRO_8,     ST_MACRO_9,     KC_DQUO,        TD(DANCE_28),   KC_TRANSPARENT,
    KC_TRANSPARENT, KC_QUES,        KC_LCBR,        ST_MACRO_10,    ST_MACRO_7,     KC_TRANSPARENT,                                 TD(DANCE_6),    RALT(KC_Q),     RALT(RSFT(KC_MINUS)),KC_RCBR,   ST_MACRO_11,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_SPACE,       KC_NUM,                                         RALT(KC_LBRC),  RALT(RSFT(KC_LBRC)),RALT(KC_M), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_ENTER,       TD(DANCE_5),    KC_TRANSPARENT, KC_DLR
  ),
  [6] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_B,           FR_EACU,        KC_P,           KC_O,           FR_EGRV,                                        KC_V,           KC_D,           KC_L,           KC_J,           FR_Z,           KC_TRANSPARENT,
    KC_TRANSPARENT, FR_A,           KC_U,           KC_I,           KC_E,           TD(DANCE_29),                                   KC_T,           KC_S,           KC_R,           KC_N,           FR_M,           KC_TRANSPARENT,
    KC_TRANSPARENT, FR_AGRV,        KC_Y,           KC_X,           TD(DANCE_30),   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_G,           KC_H,           KC_F,           FR_Q,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSL(8),         KC_C,           FR_CCED,                                        KC_K,           KC_TRANSPARENT, OSL(7),         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, FR_W
  ),
  [7] = LAYOUT_voyager(
#ifndef VM_USE_NUMPAD_ONLY
    KC_TRANSPARENT, FR_PIPE,        FR_AMP,         FR_MINS,        FR_ASTR,        TD(DANCE_31),                                   TD(DANCE_32),   FR_SLSH,        FR_PLUS,        FR_HASH,        FR_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, FR_6,           FR_4,           FR_8,           FR_0,           FR_2,                                           FR_3,           FR_1,           FR_9,           FR_5,           FR_7,           KC_TRANSPARENT,
#else
    KC_TRANSPARENT, FR_PIPE,        FR_AMP,         KC_KP_MINUS,    KC_KP_ASTERISK, TD(DANCE_31),                                   TD(DANCE_32),   KC_KP_SLASH,    KC_KP_PLUS,     FR_HASH,        FR_BSLS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,                                        KC_KP_3,        KC_KP_1,        KC_KP_9,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT,
#endif
    KC_TRANSPARENT, FR_UNDS,        FR_LBRC,        FR_LPRN,        FR_EQL,         KC_TRANSPARENT,                                 KC_TRANSPARENT, FR_PERC,        FR_RPRN,        FR_RBRC,        FR_EXLM,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, FR_CCIRC,       FR_LESS,                                        TD(DANCE_33),   KC_TRANSPARENT, QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    FR_GRTR,        TD(DANCE_ENTER),KC_TRANSPARENT, KC_DELETE
  ),
  [8] = LAYOUT_voyager(
    TD(DANCE_16),   TD(DANCE_11),   TD(DANCE_12),   TD(DANCE_13),   TD(DANCE_14),   TD(DANCE_15),                                   TD(DANCE_17),   TD(DANCE_18),   TD(DANCE_19),   TD(DANCE_20),   TD(DANCE_21),   KC_TRANSPARENT,
    KC_TRANSPARENT, FR_AT,          FR_TILD,        FR_APOS,        FR_SUP2,        ST_MACRO_13,                                    ST_MACRO_16,    ST_MACRO_17,    FR_DQUO,        FR_UMLT,        TD(DANCE_34),   KC_TRANSPARENT,
    KC_TRANSPARENT, FR_QUES,        FR_LCBR,        FR_SECT,        ST_MACRO_14,    KC_TRANSPARENT,                                 TD(DANCE_6),    ST_MACRO_18,    ST_MACRO_19,    FR_RCBR,        FR_UGRV,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_SPACE,       KC_NUM,                                         ST_MACRO_15,    ST_MACRO_20,    FR_MU,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_ENTER,       TD(DANCE_5),    KC_TRANSPARENT, FR_DLR
  ),
  [VM_APPLICATION_WEB_LAYER] = LAYOUT_voyager(
    TD(DANCE_ESC),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 TD(DANCE_BTN2), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_WEB2), KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_WEB1), KC_MS_WH_LEFT,  KC_MS_WH_RIGHT, KC_TRANSPARENT,
                                                                                    KC_MS_BTN1,     TD(DANCE_ENTER),KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [FUNCTION_LAYER] = LAYOUT_voyager(
#ifdef AUTOMOUSE_LAYER
    KC_ESCAPE,      TD(DANCE_38),   TD(DANCE_39),   TD(DANCE_40),   TD(DANCE_41),   RGB_VAD,                                        RGB_VAI,        TD(DANCE_18),   TD(DANCE_19),   TD(DANCE_42),   TD(DANCE_21),   KC_UP,
#else
    KC_ESCAPE,      TD(DANCE_38),   TD(DANCE_39),   TD(DANCE_40),   TD(DANCE_14),   RGB_VAD,                                        RGB_VAI,        TD(DANCE_18),   TD(DANCE_19),   TD(DANCE_42),   TD(DANCE_21),   KC_UP,
#endif
    KC_TAB,         KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,                                        KC_KP_3,        KC_KP_1,        KC_KP_9,        KC_KP_5,        KC_KP_7,        KC_DOWN,
#ifndef VM_USE_NUMPAD_ONLY
    KC_CAPS,        KC_KP_DOT,      KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1,     KC_BSPC,                                        TD(DANCE_6),    TD(DANCE_43),   TD(DANCE_44),   TD(DANCE_45),   KC_KP_COMMA,    CW_TOGG,
#else
    KC_CAPS,        KC_KP_DOT,      KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1,     KC_BSPC,                                        TD(DANCE_6),    TD(DANCE_43),   TD(DANCE_44),   TD(DANCE_45),   KC_KP_COMMA,    OSM(MOD_RSFT),
#endif
    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    RGB_TOG,        TOGGLE_LAYER_COLOR,TOGGLE_SCROLL,                               ST_MACRO_24,    KC_SPACE,       TD(DANCE_46),   KC_MS_LEFT,     KC_MS_RIGHT,    OSM(MOD_RGUI),
                                                                                    KC_KP_ENTER,    TD(DANCE_5),    TD(DANCE_7),    TD(DANCE_47)
  ),
#ifdef AUTOMOUSE_LAYER
  [AUTOMOUSE_LAYER] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_MS_BTN7,     KC_MS_BTN6,     KC_MS_BTN5,     KC_MS_BTN4,     NAVIGATOR_INC_CPI,                              KC_CAPS,        TD(DANCE_43),   TD(DANCE_44),   TD(DANCE_45),   KC_CALCULATOR,  KC_TRANSPARENT,
    TD(DANCE_BTN8), ST_MACRO_22,    ST_MACRO_21,    ST_MACRO_23,    TOGGLE_SCROLL,  NAVIGATOR_DEC_CPI,                              KC_MY_COMPUTER, KC_WWW_SEARCH,  KC_MEDIA_EJECT, KC_WWW_HOME,    KC_MAIL,        KC_TRANSPARENT,
    KC_TRANSPARENT, ST_MACRO_12,    ST_MACRO_27,    KC_AUDIO_MUTE,  KC_APPLICATION, KC_TRANSPARENT,                                 KC_NUM,         KC_KP_MINUS,    KC_KP_EQUAL,    KC_KP_PLUS,     ST_MACRO_26,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_LLCK,        KC_MS_BTN2,     KC_MS_BTN3,                                     TD(DANCE_QUIT), KC_ENTER,       QK_LLCK,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_MS_BTN1,     KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE
  ),
#endif
#ifdef VM_USE_LEFTPAD_ONLY
  [VM_USE_LEFTPAD_ONLY] = LAYOUT_voyager(
    KC_ESCAPE,      BP_B,           BP_ECUT,        BP_P,           BP_O,           BP_EGRV,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TAB,         BP_A,           BP_U,           BP_I,           BP_E,           TD(DANCE_0),                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#ifdef VM_USE_DOUBLE_SHIFT_CAPS_WORD
    OSM(MOD_LSFT),  BP_AGRV,        BP_Y,           BP_X,           TD(DANCE_1),    KC_BSPC,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#else
    OSM(MOD_LSFT),  BP_AGRV,        BP_Y,           BP_X,           TD(DANCE_1),    KC_BSPC,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#endif
    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    OSL(BEPO_BASE_LAYER + 2),BP_C,  BP_CCED,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                    KC_ENTER,       TD(DANCE_5),    KC_NO,          KC_NO
  ),
  [VM_USE_LEFTPAD_ONLY + 1] = LAYOUT_voyager(
    KC_UP,          BP_Z,           BP_J,           BP_L,           BP_D,           BP_V,                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_DOWN,        BP_M,           BP_N,           BP_R,           BP_S,           BP_T,                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#ifdef VM_USE_DOUBLE_SHIFT_CAPS_WORD
    OSM(MOD_RSFT),  BP_Q,           BP_F,           BP_H,           BP_G,           TD(DANCE_6),                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#else
    KC_TRANSPARENT, BP_Q,           BP_F,           BP_H,           BP_G,           TD(DANCE_6),                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#endif
    OSM(MOD_RGUI),  KC_LEFT,        KC_RIGHT,       TD(DANCE_49),   KC_SPACE,       BP_K,                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                    BP_W,           TD(DANCE_7),    KC_NO,          KC_NO
  ),
  [VM_USE_LEFTPAD_ONLY + 2] = LAYOUT_voyager(
#ifndef VM_USE_NUMPAD_ONLY
    KC_ESCAPE,      BP_PIPE,        BP_AMPR,        BP_MINS,        BP_ASTR,        TD(DANCE_8),                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TAB,         BP_6,           BP_4,           BP_8,           BP_0,           BP_2,                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#else
    KC_ESCAPE,      BP_PIPE,        BP_AMPR,        KC_KP_MINUS,    KC_KP_ASTERISK, TD(DANCE_8),                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TAB,         KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#endif
#ifdef VM_USE_DOUBLE_SHIFT_CAPS_WORD
    OSM(MOD_LSFT),  BP_UNDS,        BP_LBRC,        BP_LPRN,        BP_EQL,         KC_BSPC,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#else
    KC_TRANSPARENT, BP_UNDS,        BP_LBRC,        BP_LPRN,        BP_EQL,         KC_BSPC,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#endif
    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    TD(DANCE_50),   BP_DCRC,        BP_LESS,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                    BP_GRTR,        KC_ENTER,       KC_NO,          KC_NO
  ),
  [VM_USE_LEFTPAD_ONLY + 3] = LAYOUT_voyager(
#ifndef VM_USE_NUMPAD_ONLY
    KC_UP,          BP_BSLS,        BP_HASH,        BP_PLUS,        BP_SLSH,        TD(DANCE_9),                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_DOWN,        BP_7,           BP_5,           BP_9,           BP_1,           BP_3,                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#else
    KC_UP,          BP_BSLS,        BP_HASH,        KC_KP_PLUS,     KC_KP_SLASH,    TD(DANCE_9),                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_DOWN,        KC_KP_7,        KC_KP_5,        KC_KP_9,        KC_KP_1,        KC_KP_3,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#endif
#ifdef VM_USE_DOUBLE_SHIFT_CAPS_WORD
    OSM(MOD_RSFT),  BP_EXLM,        BP_RBRC,        BP_RPRN,        BP_PERC,        TD(DANCE_6),                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#else
    KC_TRANSPARENT, BP_EXLM,        BP_RBRC,        BP_RPRN,        BP_PERC,        TD(DANCE_6),                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#endif
    OSM(MOD_RGUI),  KC_LEFT,        KC_RIGHT,       TD(DANCE_51),   KC_SPACE,       TD(DANCE_0),                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                    KC_DELETE,      TD(DANCE_7),    KC_NO,          KC_NO
  ),
  [VM_USE_LEFTPAD_ONLY + 4] = LAYOUT_voyager(
    TD(DANCE_16),   TD(DANCE_11),   TD(DANCE_12),   TD(DANCE_13),   TD(DANCE_14),   TD(DANCE_15),                                   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TAB,         BP_AT,          BP_TILD,        RALT(BP_COMM),  BP_APOS,        BP_LGIL,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#ifdef VM_USE_DOUBLE_SHIFT_CAPS_WORD
    OSM(MOD_LSFT),  BP_QEST,        BP_LCBR,        RALT(LSFT(BP_P)),BP_AE,         KC_BSPC,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#else
    KC_TRANSPARENT, BP_QEST,        BP_LCBR,        RALT(LSFT(BP_P)),BP_AE,         KC_BSPC,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#endif
    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    TD(DANCE_52),   ST_MACRO_0,     KC_NUM,                                         KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                    KC_ENTER,       TD(DANCE_5),    KC_NO,          KC_NO
  ),
  [VM_USE_LEFTPAD_ONLY + 5] = LAYOUT_voyager(
    KC_UP,          TD(DANCE_21),   TD(DANCE_20),   TD(DANCE_19),   TD(DANCE_18),   TD(DANCE_17),                                   KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_DOWN,        TD(DANCE_22),   BP_DTRM,        BP_DQOT,        BP_GRV,         BP_RGIL,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#ifdef VM_USE_DOUBLE_SHIFT_CAPS_WORD
    OSM(MOD_RSFT),  BP_UGRV,        BP_RCBR,        BP_MDSH,        BP_OE,          TD(DANCE_6),                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#else
    KC_TRANSPARENT, BP_UGRV,        BP_RCBR,        BP_MDSH,        BP_OE,          TD(DANCE_6),                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
#endif
    OSM(MOD_RGUI),  KC_LEFT,        KC_RIGHT,       TD(DANCE_53),   RALT(BP_2),     RALT(BP_3),                                     KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                                                                    BP_DLR,         TD(DANCE_7),    KC_NO,          KC_NO
  ),
#endif
};



extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [BEPO_BASE_LAYER + 0] = { {225,224,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,245,245}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {74,255,255}, {74,255,255}, {225,224,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {46,215,244}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {46,215,244}, {0,245,245}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,245,245}, {74,255,255}, {74,255,255}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {74,255,255} },

    [BEPO_BASE_LAYER + 1] = { {225,224,255}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {0,245,245}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {168,218,204}, {168,218,204}, {168,218,204}, {225,224,255}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {46,215,244}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {46,215,244}, {0,245,245}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {0,245,245}, {168,218,204}, {168,218,204}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {225,224,255} },

    [BEPO_BASE_LAYER + 2] = { {0,0,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {0,245,245}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {62,219,138}, {188,255,255}, {225,224,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {46,215,244}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {46,215,244}, {0,245,245}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {0,245,245}, {62,219,138}, {62,219,138}, {62,219,138}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {62,219,138} },

    [QWERTY_BASE_LAYER + 0] = { {225,224,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,245,245}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {131,255,255}, {131,255,255}, {225,224,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {46,215,244}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {46,215,244}, {0,245,245}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,245,245}, {131,255,255}, {131,255,255}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {131,255,255} },

    [QWERTY_BASE_LAYER + 1] = { {225,224,255}, {0,219,138}, {0,219,138}, {0,219,138}, {0,219,138}, {0,219,138}, {0,219,138}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {0,219,138}, {0,219,138}, {0,219,138}, {0,219,138}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {0,219,138}, {0,219,138}, {0,219,138}, {225,224,255}, {0,219,138}, {0,219,138}, {0,219,138}, {0,219,138}, {0,219,138}, {46,215,244}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {46,215,244}, {0,245,245}, {0,219,138}, {0,219,138}, {0,219,138}, {0,219,138}, {0,245,245}, {0,219,138}, {0,219,138}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {225,224,255} },

    [QWERTY_BASE_LAYER + 2] = { {0,0,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {152,255,255}, {188,255,255}, {225,224,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {46,215,244}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {46,215,244}, {0,245,245}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {152,255,255}, {152,255,255}, {152,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {152,255,255} },

    [6] = { {225,224,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {0,245,245}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {152,255,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {198,255,255}, {198,255,255}, {152,255,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {46,215,244}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {46,215,244}, {0,245,245}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {0,245,245}, {198,255,255}, {198,255,255}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {198,255,255} },

    [7] = { {225,224,255}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {206,255,160}, {206,255,160}, {206,255,160}, {206,255,160}, {206,255,160}, {0,245,245}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {62,219,138}, {62,219,138}, {62,219,138}, {225,224,255}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {46,215,244}, {206,255,160}, {206,255,160}, {206,255,160}, {206,255,160}, {206,255,160}, {46,215,244}, {0,245,245}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {0,245,245}, {62,219,138}, {62,219,138}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {225,224,255} },

    [8] = { {0,0,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {206,255,160}, {206,255,160}, {206,255,160}, {206,255,160}, {206,255,160}, {206,255,160}, {0,245,245}, {206,255,160}, {206,255,160}, {206,255,160}, {206,255,160}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {206,255,160}, {188,255,255}, {225,224,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {46,215,244}, {206,255,160}, {206,255,160}, {206,255,160}, {206,255,160}, {206,255,160}, {46,215,244}, {0,245,245}, {206,255,160}, {206,255,160}, {206,255,160}, {206,255,160}, {0,245,245}, {206,255,160}, {206,255,160}, {206,255,160}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {206,255,160} },

    [VM_APPLICATION_WEB_LAYER] = { {0,0,255}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,245,245}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {0,0,160}, {0,0,160}, {131,255,255}, {225,224,255}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {46,215,244}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {46,215,244}, {131,255,255}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,245,245}, {0,0,160}, {0,0,160}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {0,0,160} },
#ifdef AUTOMOUSE_LAYER
    [FUNCTION_LAYER] = { {225,224,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {74,255,255}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {206,255,160}, {62,219,138}, {131,255,255}, {131,255,255}, {131,255,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {74,255,255}, {74,255,255}, {86,237,170}, {225,224,255}, {19,245,255}, {74,255,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {46,215,244}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {46,215,244}, {0,245,245}, {19,245,255}, {74,255,255}, {19,245,255}, {62,219,138}, {0,245,245}, {0,219,138}, {152,255,255}, {152,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {152,255,255} },
    [AUTOMOUSE_LAYER] = { {225,224,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {86,237,170}, {188,255,255}, {0,0,160}, {0,0,160}, {0,0,160}, {86,237,170}, {86,237,170}, {0,245,245}, {62,219,138}, {0,219,138}, {0,245,245}, {86,95,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {188,255,255}, {188,255,255}, {188,255,255}, {19,245,255}, {206,255,160}, {19,245,255}, {74,255,255}, {19,245,255}, {86,95,255}, {46,215,244}, {86,95,255}, {86,95,255}, {86,95,255}, {86,95,255}, {86,95,255}, {46,215,244}, {206,255,160}, {0,0,160}, {168,218,204}, {0,0,160}, {62,219,138}, {0,245,245}, {0,219,138}, {225,224,255}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {225,224,255} },
#else
    [FUNCTION_LAYER] = { {225,224,255}, {0,0,255}, {0,0,255}, {0,0,255}, {19,245,255}, {74,255,255}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {206,255,160}, {62,219,138}, {131,255,255}, {131,255,255}, {131,255,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {74,255,255}, {74,255,255}, {86,237,170}, {225,224,255}, {19,245,255}, {74,255,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {46,215,244}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {46,215,244}, {0,245,245}, {19,245,255}, {74,255,255}, {19,245,255}, {62,219,138}, {0,245,245}, {0,219,138}, {152,255,255}, {152,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {152,255,255} },
#endif
#ifdef VM_USE_LEFTPAD_ONLY
    [VM_USE_LEFTPAD_ONLY] = { {225,224,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {152,255,255}, {152,255,255}, {225,224,255}, {19,245,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [VM_USE_LEFTPAD_ONLY + 1] = { {46,215,244}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {46,215,244}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {152,255,255}, {152,255,255}, {152,255,255}, {19,245,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [VM_USE_LEFTPAD_ONLY + 2] = { {225,224,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {74,255,255}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,245,245}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {74,255,255}, {74,255,255}, {74,255,255}, {225,224,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [VM_USE_LEFTPAD_ONLY + 3] = { {46,215,244}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {46,215,244}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,0,160}, {0,245,245}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,245,245}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {74,255,255}, {74,255,255}, {225,224,255}, {19,245,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [VM_USE_LEFTPAD_ONLY + 4] = { {0,0,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {86,95,255}, {86,95,255}, {86,95,255}, {86,95,255}, {86,95,255}, {86,95,255}, {0,245,245}, {86,95,255}, {86,95,255}, {86,95,255}, {86,95,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {86,95,255}, {188,255,255}, {225,224,255}, {19,245,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [VM_USE_LEFTPAD_ONLY + 5] = { {46,215,244}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {46,215,244}, {86,95,255}, {86,95,255}, {86,95,255}, {86,95,255}, {86,95,255}, {0,245,245}, {86,95,255}, {86,95,255}, {86,95,255}, {86,95,255}, {0,245,245}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {86,95,255}, {86,95,255}, {86,95,255}, {19,245,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
#endif
};

const uint8_t PROGMEM ledmapAlt[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {0,245,245}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {188,255,255}, {188,255,255}, {131,255,255}, {225,224,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {46,215,244}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {46,215,244}, {131,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,245,245}, {188,255,255}, {188,255,255}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {225,224,255} },
    [1] = { {0,0,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,245,245}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {188,255,255}, {188,255,255}, {131,255,255}, {225,224,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {46,215,244}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {46,215,244}, {131,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,245,245}, {188,255,255}, {188,255,255}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {188,255,255} },
};

#define set_layer_color(layer) set_layer_color_internal(layer, &ledmap)
#define set_alt_layer_color(layer) set_layer_color_internal(layer, &ledmapAlt)

typedef uint8_t led_map_array_t[][RGB_MATRIX_LED_COUNT][3];

void set_layer_color_internal(int layer, const led_map_array_t* ledmap_used) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&(*ledmap_used)[layer][i][0]),
      .s = pgm_read_byte(&(*ledmap_used)[layer][i][1]),
      .v = pgm_read_byte(&(*ledmap_used)[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) {
    switch (biton32(layer_state)) {
      case 0:
        accentLayerActivation = 0;
        set_layer_color(0);
        break;
      case 1:
        accentLayerActivation = 0;
        set_layer_color(1);
        break;
      case 2:
        accentLayerActivation = 0;
        set_layer_color(2);
        break;
      case 3:
        accentLayerActivation = 0;
        set_layer_color(3);
        break;
      case 4:
        accentLayerActivation = 0;
        set_layer_color(4);
        break;
      case 5:
        accentLayerActivation = 0;
        set_layer_color(5);
        break;
      case 6:
        accentLayerActivation = 0;
        set_layer_color(6);
        break;
      case 7:
        accentLayerActivation = 0;
        set_layer_color(7);
        break;
      case 8:
        accentLayerActivation = 0;
        set_layer_color(8);
        break;
      case FUNCTION_LAYER:
        accentLayerActivation = 0;
        set_layer_color(FUNCTION_LAYER);
        break;
      case VM_APPLICATION_WEB_LAYER:
        switch (biton32(layer_state & ~((layer_state_t)1 << VM_APPLICATION_WEB_LAYER))) {
          case 0:
            accentLayerActivation = 0;
            lastLayerActivation = 0;
            break;
          case 1:
            accentLayerActivation = 0;
            lastLayerActivation = 1;
            break;
          case 2:
            accentLayerActivation = 2;
            lastLayerActivation = biton32(layer_state & ~((layer_state_t)1 << 2 | (layer_state_t)1 << VM_APPLICATION_WEB_LAYER));
            break;
          case 3:
            accentLayerActivation = 0;
            lastLayerActivation = 3;
            break;
          case 4:
            accentLayerActivation = 0;
            lastLayerActivation = 4;
            break;
          case 5:
            accentLayerActivation = 5;
            lastLayerActivation = biton32(layer_state & ~((layer_state_t)1 << 5 | (layer_state_t)1 << VM_APPLICATION_WEB_LAYER));
            break;
          case 6:
            accentLayerActivation = 0;
            lastLayerActivation = 6;
            break;
          case 7:
            accentLayerActivation = 0;
            lastLayerActivation = 7;
            break;
          case 8:
            accentLayerActivation = 8;
            lastLayerActivation = biton32(layer_state & ~((layer_state_t)1 << 8 | (layer_state_t)1 << VM_APPLICATION_WEB_LAYER));
            break;
          default:
            break;
        }
        if (accentLayerActivation != 0) {
        set_alt_layer_color(VM_APPLICATION_WEB_ALT_LAYER2);
        } else if ((lastLayerActivation % 3) == 0) {
        set_layer_color(VM_APPLICATION_WEB_LAYER);
        } else {
        set_alt_layer_color(VM_APPLICATION_WEB_ALT_LAYER1);
        }
        break;
#ifdef AUTOMOUSE_LAYER
      case AUTOMOUSE_LAYER:
        set_layer_color(AUTOMOUSE_LAYER);
        break;
#endif
#ifdef VM_USE_LEFTPAD_ONLY
      case VM_USE_LEFTPAD_ONLY:
        accentLayerActivation = 0;
        set_layer_color(VM_USE_LEFTPAD_ONLY);
        break;
      case VM_USE_LEFTPAD_ONLY + 1:
        accentLayerActivation = 0;
        set_layer_color(VM_USE_LEFTPAD_ONLY + 1);
        break;
      case VM_USE_LEFTPAD_ONLY + 2:
        accentLayerActivation = 0;
        set_layer_color(VM_USE_LEFTPAD_ONLY + 2);
        break;
      case VM_USE_LEFTPAD_ONLY + 3:
        accentLayerActivation = 0;
        set_layer_color(VM_USE_LEFTPAD_ONLY + 3);
        break;
      case VM_USE_LEFTPAD_ONLY + 4:
        accentLayerActivation = 0;
        set_layer_color(VM_USE_LEFTPAD_ONLY + 4);
        break;
      case VM_USE_LEFTPAD_ONLY + 5:
        accentLayerActivation = 0;
        set_layer_color(VM_USE_LEFTPAD_ONLY + 5);
        break;
#endif
      default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
        break;
    }
  } else if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
    rgb_matrix_set_color_all(0, 0, 0);
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
        tap_code16(BP_COMM);
        tap_code16(BP_COMM);
        tap_code16(BP_COMM);
    }
    if(state->count > 3) {
        tap_code16(BP_COMM);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_0].step = dance_step(state);
    switch (dance_state[DANCE_0].step) {
        case SINGLE_TAP: register_code16(BP_COMM); break;
        case SINGLE_HOLD: register_code16(BP_SCLN); break;
        case DOUBLE_TAP: register_code16(BP_COMM); register_code16(BP_COMM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_COMM); register_code16(BP_COMM);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_0].step) {
        case SINGLE_TAP: unregister_code16(BP_COMM); break;
        case SINGLE_HOLD: unregister_code16(BP_SCLN); break;
        case DOUBLE_TAP: unregister_code16(BP_COMM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_COMM); break;
    }
    dance_state[DANCE_0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_DOT);
        tap_code16(BP_DOT);
        tap_code16(BP_DOT);
    }
    if(state->count > 3) {
        tap_code16(BP_DOT);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_1].step = dance_step(state);
    switch (dance_state[DANCE_1].step) {
        case SINGLE_TAP: register_code16(BP_DOT); break;
        case SINGLE_HOLD: register_code16(BP_COLN); break;
        case DOUBLE_TAP: register_code16(BP_DOT); register_code16(BP_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_DOT); register_code16(BP_DOT);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_1].step) {
        case SINGLE_TAP: unregister_code16(BP_DOT); break;
        case SINGLE_HOLD: unregister_code16(BP_COLN); break;
        case DOUBLE_TAP: unregister_code16(BP_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_DOT); break;
    }
    dance_state[DANCE_1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT_ALT);
        tap_code16(KC_LEFT_ALT);
        tap_code16(KC_LEFT_ALT);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT_ALT);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_2].step = dance_step(state);
    switch (dance_state[DANCE_2].step) {
        case SINGLE_TAP: register_code16(KC_LEFT_ALT); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT_ALT); register_code16(KC_LEFT_ALT);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_2].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT_ALT); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT_ALT); break;
    }
    dance_state[DANCE_2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PAGE_UP);
        tap_code16(KC_PAGE_UP);
        tap_code16(KC_PAGE_UP);
    }
    if(state->count > 3) {
        tap_code16(KC_PAGE_UP);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_3].step = dance_step(state);
    switch (dance_state[DANCE_3].step) {
        case SINGLE_TAP: register_code16(KC_PAGE_UP); break;
        case SINGLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PAGE_UP); register_code16(KC_PAGE_UP);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_3].step) {
        case SINGLE_TAP: unregister_code16(KC_PAGE_UP); break;
        case SINGLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PAGE_UP); break;
    }
    dance_state[DANCE_3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PGDN);
        tap_code16(KC_PGDN);
        tap_code16(KC_PGDN);
    }
    if(state->count > 3) {
        tap_code16(KC_PGDN);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_4].step = dance_step(state);
    switch (dance_state[DANCE_4].step) {
        case SINGLE_TAP: register_code16(KC_PGDN); break;
        case SINGLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PGDN); register_code16(KC_PGDN);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_4].step) {
        case SINGLE_TAP: unregister_code16(KC_PGDN); break;
        case SINGLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PGDN); break;
    }
    dance_state[DANCE_4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT_CTRL);
        tap_code16(KC_LEFT_CTRL);
        tap_code16(KC_LEFT_CTRL);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT_CTRL);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_5].step = dance_step(state);
    switch (dance_state[DANCE_5].step) {
        case SINGLE_TAP: register_code16(KC_LEFT_CTRL); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT_CTRL); register_code16(KC_LEFT_CTRL);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_5].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT_CTRL); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT_CTRL); break;
    }
    dance_state[DANCE_5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RIGHT_ALT);
        tap_code16(KC_RIGHT_ALT);
        tap_code16(KC_RIGHT_ALT);
    }
    if(state->count > 3) {
        tap_code16(KC_RIGHT_ALT);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_6].step = dance_step(state);
    switch (dance_state[DANCE_6].step) {
        case SINGLE_TAP: register_code16(KC_RIGHT_ALT); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RIGHT_ALT); register_code16(KC_RIGHT_ALT);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_6].step) {
        case SINGLE_TAP: unregister_code16(KC_RIGHT_ALT); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RIGHT_ALT); break;
    }
    dance_state[DANCE_6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RIGHT_CTRL);
        tap_code16(KC_RIGHT_CTRL);
        tap_code16(KC_RIGHT_CTRL);
    }
    if(state->count > 3) {
        tap_code16(KC_RIGHT_CTRL);
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_7].step = dance_step(state);
    switch (dance_state[DANCE_7].step) {
        case SINGLE_TAP: register_code16(KC_RIGHT_CTRL); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_UP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RIGHT_CTRL); register_code16(KC_RIGHT_CTRL);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_7].step) {
        case SINGLE_TAP: unregister_code16(KC_RIGHT_CTRL); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_UP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RIGHT_CTRL); break;
    }
    dance_state[DANCE_7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_COLN);
        tap_code16(BP_COLN);
        tap_code16(BP_COLN);
    }
    if(state->count > 3) {
        tap_code16(BP_COLN);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_8].step = dance_step(state);
    switch (dance_state[DANCE_8].step) {
        case SINGLE_TAP: register_code16(BP_COLN); break;
        case SINGLE_HOLD: register_code16(BP_EURO); break;
        case DOUBLE_TAP: register_code16(BP_COLN); register_code16(BP_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_COLN); register_code16(BP_COLN);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_8].step) {
        case SINGLE_TAP: unregister_code16(BP_COLN); break;
        case SINGLE_HOLD: unregister_code16(BP_EURO); break;
        case DOUBLE_TAP: unregister_code16(BP_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_COLN); break;
    }
    dance_state[DANCE_8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_DOT);
        tap_code16(BP_DOT);
        tap_code16(BP_DOT);
    }
    if(state->count > 3) {
        tap_code16(BP_DOT);
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_9].step = dance_step(state);
    switch (dance_state[DANCE_9].step) {
        case SINGLE_TAP: register_code16(BP_DOT); break;
        case SINGLE_HOLD: register_code16(LSFT(RALT(BP_L))); break;
        case DOUBLE_TAP: register_code16(BP_DOT); register_code16(BP_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_DOT); register_code16(BP_DOT);
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_9].step) {
        case SINGLE_TAP: unregister_code16(BP_DOT); break;
        case SINGLE_HOLD: unregister_code16(LSFT(RALT(BP_L))); break;
        case DOUBLE_TAP: unregister_code16(BP_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_DOT); break;
    }
    dance_state[DANCE_9].step = 0;
}
void on_dance_10(tap_dance_state_t *state, void *user_data);
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void on_dance_10(tap_dance_state_t *state, void *user_data) {
    if (layer_state_is(VM_APPLICATION_WEB_LAYER)) {
        if(state->count == 3) {
           tap_code16(BP_GRTR);
           tap_code16(BP_GRTR);
           tap_code16(BP_GRTR);
        }
        if(state->count > 3) {
           tap_code16(BP_GRTR);
        }
    }
    else {
        if(state->count == 3) {
           tap_code16(BP_COMM);
           tap_code16(BP_COMM);
           tap_code16(BP_COMM);
        }
        if(state->count > 3) {
           tap_code16(BP_COMM);
        }
    }
}

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_10].step = dance_step(state);
    if (layer_state_is(VM_APPLICATION_WEB_LAYER)) {
        switch (dance_state[DANCE_10].step) {
            case SINGLE_TAP: register_code16(BP_GRTR); break;
            case SINGLE_HOLD: register_code16(BP_GRTR); break;
            case DOUBLE_TAP: register_code16(BP_GRTR); register_code16(BP_GRTR); break;
            case DOUBLE_SINGLE_TAP: tap_code16(BP_GRTR); register_code16(BP_GRTR);
        }
    }
    else {
        switch (dance_state[DANCE_10].step) {
            case SINGLE_TAP: register_code16(BP_COMM); break;
            case SINGLE_HOLD: register_code16(BP_SCLN); break;
            case DOUBLE_TAP: register_code16(BP_COMM); register_code16(BP_COMM); break;
            case DOUBLE_SINGLE_TAP: tap_code16(BP_COMM); register_code16(BP_COMM);
        }
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    if (layer_state_is(VM_APPLICATION_WEB_LAYER)) {
        switch (dance_state[DANCE_10].step) {
            case SINGLE_TAP: unregister_code16(BP_GRTR); break;
            case SINGLE_HOLD: unregister_code16(BP_GRTR); break;
            case DOUBLE_TAP: unregister_code16(BP_GRTR); break;
            case DOUBLE_SINGLE_TAP: unregister_code16(BP_GRTR); break;
        }
    }
    else {
        switch (dance_state[DANCE_10].step) {
            case SINGLE_TAP: unregister_code16(BP_COMM); break;
            case SINGLE_HOLD: unregister_code16(BP_SCLN); break;
            case DOUBLE_TAP: unregister_code16(BP_COMM); break;
            case DOUBLE_SINGLE_TAP: unregister_code16(BP_COMM); break;
        }
    }
    dance_state[DANCE_10].step = 0;
}
void on_dance_11(tap_dance_state_t *state, void *user_data);
void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void on_dance_11(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F6);
        tap_code16(KC_F6);
        tap_code16(KC_F6);
    }
    if(state->count > 3) {
        tap_code16(KC_F6);
    }
}

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_11].step = dance_step(state);
    switch (dance_state[DANCE_11].step) {
        case SINGLE_TAP: register_code16(KC_F6); break;
        case SINGLE_HOLD: register_code16(KC_F6); break;
        case DOUBLE_TAP: register_code16(KC_CALCULATOR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_11].step) {
        case SINGLE_TAP: unregister_code16(KC_F6); break;
        case SINGLE_HOLD: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_CALCULATOR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[DANCE_11].step = 0;
}
void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_12].step = dance_step(state);
    switch (dance_state[DANCE_12].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case SINGLE_HOLD: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(KC_WWW_FAVORITES); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_12].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case SINGLE_HOLD: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_FAVORITES); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[DANCE_12].step = 0;
}
void on_dance_13(tap_dance_state_t *state, void *user_data);
void dance_13_finished(tap_dance_state_t *state, void *user_data);
void dance_13_reset(tap_dance_state_t *state, void *user_data);

void on_dance_13(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F8);
        tap_code16(KC_F8);
        tap_code16(KC_F8);
    }
    if(state->count > 3) {
        tap_code16(KC_F8);
    }
}

void dance_13_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_13].step = dance_step(state);
    switch (dance_state[DANCE_13].step) {
        case SINGLE_TAP: register_code16(KC_F8); break;
        case SINGLE_HOLD: register_code16(KC_F8); break;
        case DOUBLE_TAP: register_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F8); register_code16(KC_F8);
    }
}

void dance_13_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_13].step) {
        case SINGLE_TAP: unregister_code16(KC_F8); break;
        case SINGLE_HOLD: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F8); break;
    }
    dance_state[DANCE_13].step = 0;
}
void on_dance_14(tap_dance_state_t *state, void *user_data);
void dance_14_finished(tap_dance_state_t *state, void *user_data);
void dance_14_reset(tap_dance_state_t *state, void *user_data);

void on_dance_14(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F10);
        tap_code16(KC_F10);
        tap_code16(KC_F10);
    }
    if(state->count > 3) {
        tap_code16(KC_F10);
    }
}

void dance_14_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_14].step = dance_step(state);
    switch (dance_state[DANCE_14].step) {
        case SINGLE_TAP: register_code16(KC_F10); break;
        case SINGLE_HOLD: register_code16(KC_F10); break;
        case DOUBLE_TAP: register_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F10); register_code16(KC_F10);
    }
}

void dance_14_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_14].step) {
        case SINGLE_TAP: unregister_code16(KC_F10); break;
        case SINGLE_HOLD: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F10); break;
    }
    dance_state[DANCE_14].step = 0;
}
void on_dance_15(tap_dance_state_t *state, void *user_data);
void dance_15_finished(tap_dance_state_t *state, void *user_data);
void dance_15_reset(tap_dance_state_t *state, void *user_data);

void on_dance_15(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F2);
        tap_code16(KC_F2);
        tap_code16(KC_F2);
    }
    if(state->count > 3) {
        tap_code16(KC_F2);
    }
}

void dance_15_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_15].step = dance_step(state);
    switch (dance_state[DANCE_15].step) {
        case SINGLE_TAP: register_code16(KC_F2); break;
        case SINGLE_HOLD: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F2); register_code16(KC_F2);
    }
}

void dance_15_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_15].step) {
        case SINGLE_TAP: unregister_code16(KC_F2); break;
        case SINGLE_HOLD: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F2); break;
    }
    dance_state[DANCE_15].step = 0;
}
void on_dance_16(tap_dance_state_t *state, void *user_data);
void dance_16_finished(tap_dance_state_t *state, void *user_data);
void dance_16_reset(tap_dance_state_t *state, void *user_data);

void on_dance_16(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_16_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_16].step = dance_step(state);
    switch (dance_state[DANCE_16].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: layer_move(FUNCTION_LAYER); break;
        case DOUBLE_TAP: layer_on(VM_APPLICATION_WEB_LAYER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_16_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_16].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[DANCE_16].step = 0;
}
void on_dance_17(tap_dance_state_t *state, void *user_data);
void dance_17_finished(tap_dance_state_t *state, void *user_data);
void dance_17_reset(tap_dance_state_t *state, void *user_data);

void on_dance_17(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F3);
        tap_code16(KC_F3);
        tap_code16(KC_F3);
    }
    if(state->count > 3) {
        tap_code16(KC_F3);
    }
}

void dance_17_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_17].step = dance_step(state);
    switch (dance_state[DANCE_17].step) {
        case SINGLE_TAP: register_code16(KC_F3); break;
        case SINGLE_HOLD: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
    }
}

void dance_17_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_17].step) {
        case SINGLE_TAP: unregister_code16(KC_F3); break;
        case SINGLE_HOLD: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
    }
    dance_state[DANCE_17].step = 0;
}
void on_dance_18(tap_dance_state_t *state, void *user_data);
void dance_18_finished(tap_dance_state_t *state, void *user_data);
void dance_18_reset(tap_dance_state_t *state, void *user_data);

void on_dance_18(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F1);
        tap_code16(KC_F1);
        tap_code16(KC_F1);
    }
    if(state->count > 3) {
        tap_code16(KC_F1);
    }
}

void dance_18_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_18].step = dance_step(state);
    switch (dance_state[DANCE_18].step) {
        case SINGLE_TAP: register_code16(KC_F1); break;
        case SINGLE_HOLD: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
    }
}

void dance_18_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_18].step) {
        case SINGLE_TAP: unregister_code16(KC_F1); break;
        case SINGLE_HOLD: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
    }
    dance_state[DANCE_18].step = 0;
}
void on_dance_19(tap_dance_state_t *state, void *user_data);
void dance_19_finished(tap_dance_state_t *state, void *user_data);
void dance_19_reset(tap_dance_state_t *state, void *user_data);

void on_dance_19(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if(state->count > 3) {
        tap_code16(KC_F9);
    }
}

void dance_19_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_19].step = dance_step(state);
    switch (dance_state[DANCE_19].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case SINGLE_HOLD: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_EJECT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}

void dance_19_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_19].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case SINGLE_HOLD: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_EJECT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[DANCE_19].step = 0;
}
void on_dance_20(tap_dance_state_t *state, void *user_data);
void dance_20_finished(tap_dance_state_t *state, void *user_data);
void dance_20_reset(tap_dance_state_t *state, void *user_data);

void on_dance_20(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_20_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_20].step = dance_step(state);
    switch (dance_state[DANCE_20].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case SINGLE_HOLD: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_STOP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_20_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_20].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case SINGLE_HOLD: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_STOP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[DANCE_20].step = 0;
}
void on_dance_21(tap_dance_state_t *state, void *user_data);
void dance_21_finished(tap_dance_state_t *state, void *user_data);
void dance_21_reset(tap_dance_state_t *state, void *user_data);

void on_dance_21(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if(state->count > 3) {
        tap_code16(KC_F7);
    }
}

void dance_21_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_21].step = dance_step(state);
    switch (dance_state[DANCE_21].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case SINGLE_HOLD: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}

void dance_21_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_21].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case SINGLE_HOLD: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[DANCE_21].step = 0;
}
void on_dance_22(tap_dance_state_t *state, void *user_data);
void dance_22_finished(tap_dance_state_t *state, void *user_data);
void dance_22_reset(tap_dance_state_t *state, void *user_data);

void on_dance_22(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_DEGR);
        tap_code16(BP_DEGR);
        tap_code16(BP_DEGR);
    }
    if(state->count > 3) {
        tap_code16(BP_DEGR);
    }
}

void dance_22_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_22].step = dance_step(state);
    switch (dance_state[DANCE_22].step) {
        case SINGLE_TAP: register_code16(BP_DEGR); break;
        case SINGLE_HOLD: register_code16(RALT(BP_EGRV)); break;
        case DOUBLE_TAP: register_code16(BP_DEGR); register_code16(BP_DEGR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_DEGR); register_code16(BP_DEGR);
    }
}

void dance_22_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_22].step) {
        case SINGLE_TAP: unregister_code16(BP_DEGR); break;
        case SINGLE_HOLD: unregister_code16(RALT(BP_EGRV)); break;
        case DOUBLE_TAP: unregister_code16(BP_DEGR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_DEGR); break;
    }
    dance_state[DANCE_22].step = 0;
}
void on_dance_23(tap_dance_state_t *state, void *user_data);
void dance_23_finished(tap_dance_state_t *state, void *user_data);
void dance_23_reset(tap_dance_state_t *state, void *user_data);

void on_dance_23(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_23_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_23].step = dance_step(state);
    switch (dance_state[DANCE_23].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(KC_SCLN); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_23_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_23].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(KC_SCLN); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[DANCE_23].step = 0;
}
void on_dance_24(tap_dance_state_t *state, void *user_data);
void dance_24_finished(tap_dance_state_t *state, void *user_data);
void dance_24_reset(tap_dance_state_t *state, void *user_data);

void on_dance_24(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_24_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_24].step = dance_step(state);
    switch (dance_state[DANCE_24].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(KC_COLN); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_24_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_24].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(KC_COLN); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[DANCE_24].step = 0;
}
void on_dance_25(tap_dance_state_t *state, void *user_data);
void dance_25_finished(tap_dance_state_t *state, void *user_data);
void dance_25_reset(tap_dance_state_t *state, void *user_data);

void on_dance_25(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
    }
    if(state->count > 3) {
        tap_code16(KC_COLN);
    }
}

void dance_25_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_25].step = dance_step(state);
    switch (dance_state[DANCE_25].step) {
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

void dance_25_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_25].step) {
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
    dance_state[DANCE_25].step = 0;
}
void on_dance_26(tap_dance_state_t *state, void *user_data);
void dance_26_finished(tap_dance_state_t *state, void *user_data);
void dance_26_reset(tap_dance_state_t *state, void *user_data);

void on_dance_26(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_26_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_26].step = dance_step(state);
    switch (dance_state[DANCE_26].step) {
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

void dance_26_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_26].step) {
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
    dance_state[DANCE_26].step = 0;
}
void on_dance_27(tap_dance_state_t *state, void *user_data);
void dance_27_finished(tap_dance_state_t *state, void *user_data);
void dance_27_reset(tap_dance_state_t *state, void *user_data);

void on_dance_27(tap_dance_state_t *state, void *user_data) {
    if (layer_state_is(VM_APPLICATION_WEB_LAYER)) {
       if(state->count == 3) {
           tap_code16(KC_RABK);
           tap_code16(KC_RABK);
           tap_code16(KC_RABK);
       }
       if(state->count > 3) {
           tap_code16(KC_RABK);
       }
    }
    else {
       if(state->count == 3) {
           tap_code16(KC_COMMA);
           tap_code16(KC_COMMA);
           tap_code16(KC_COMMA);
       }
       if(state->count > 3) {
           tap_code16(KC_COMMA);
       }
    }
}

void dance_27_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_27].step = dance_step(state);
    if (layer_state_is(VM_APPLICATION_WEB_LAYER)) {
        switch (dance_state[DANCE_27].step) {
            case SINGLE_TAP: register_code16(KC_RABK); break;
            case SINGLE_HOLD: register_code16(KC_RABK); break;
            case DOUBLE_TAP: register_code16(KC_RABK); register_code16(KC_RABK); break;
            case DOUBLE_SINGLE_TAP: tap_code16(KC_RABK); register_code16(KC_RABK);
        }
    }
    else {
        switch (dance_state[DANCE_27].step) {
            case SINGLE_TAP: register_code16(KC_COMMA); break;
            case SINGLE_HOLD: register_code16(KC_SCLN); break;
            case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
            case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
        }
    }
}

void dance_27_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    if (layer_state_is(VM_APPLICATION_WEB_LAYER)) {
        switch (dance_state[DANCE_27].step) {
            case SINGLE_TAP: unregister_code16(KC_RABK); break;
            case SINGLE_HOLD: unregister_code16(KC_RABK); break;
            case DOUBLE_TAP: unregister_code16(KC_RABK); break;
            case DOUBLE_SINGLE_TAP: unregister_code16(KC_RABK); break;
        }
    }
    else {
        switch (dance_state[DANCE_27].step) {
            case SINGLE_TAP: unregister_code16(KC_COMMA); break;
            case SINGLE_HOLD: unregister_code16(KC_SCLN); break;
            case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
            case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
        }
    }
    dance_state[DANCE_27].step = 0;
}
void on_dance_28(tap_dance_state_t *state, void *user_data);
void dance_28_finished(tap_dance_state_t *state, void *user_data);
void dance_28_reset(tap_dance_state_t *state, void *user_data);

void on_dance_28(tap_dance_state_t *state, void *user_data) {
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

void dance_28_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_28].step = dance_step(state);
    if (!activeNumLockLed) {
        switch (dance_state[DANCE_28].step) {
            case SINGLE_TAP: register_code16(RALT(RSFT(KC_8))); break;
            case SINGLE_HOLD: register_code16(KC_GRAVE); break;
            case DOUBLE_TAP: register_code16(RALT(RSFT(KC_8))); register_code16(RALT(RSFT(KC_8))); break;
            case DOUBLE_SINGLE_TAP: tap_code16(RALT(RSFT(KC_8))); register_code16(RALT(RSFT(KC_8)));
        }
    } else {
        switch (dance_state[DANCE_28].step) {
            case SINGLE_TAP: register_code16(LSFT(RALT(KC_SCLN))); break;
            case SINGLE_HOLD: register_code16(KC_GRAVE); break;
            case DOUBLE_TAP: register_code16(LSFT(RALT(KC_SCLN))); register_code16(LSFT(RALT(KC_SCLN))); break;
            case DOUBLE_SINGLE_TAP: tap_code16(LSFT(RALT(KC_SCLN))); register_code16(LSFT(RALT(KC_SCLN)));
        }
    }
}

void dance_28_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    if (!activeNumLockLed) {
        switch (dance_state[DANCE_28].step) {
            case SINGLE_TAP: unregister_code16(RALT(RSFT(KC_8))); break;
            case SINGLE_HOLD: unregister_code16(KC_GRAVE); break;
            case DOUBLE_TAP: unregister_code16(RALT(RSFT(KC_8))); break;
            case DOUBLE_SINGLE_TAP: unregister_code16(RALT(RSFT(KC_8))); break;
        }
    } else {
        switch (dance_state[DANCE_28].step) {
            case SINGLE_TAP: unregister_code16(LSFT(RALT(KC_SCLN))); break;
            case SINGLE_HOLD: unregister_code16(KC_GRAVE); break;
            case DOUBLE_TAP: unregister_code16(LSFT(RALT(KC_SCLN))); break;
            case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(RALT(KC_SCLN))); break;
        }
    }
    dance_state[DANCE_28].step = 0;
}
void on_dance_29(tap_dance_state_t *state, void *user_data);
void dance_29_finished(tap_dance_state_t *state, void *user_data);
void dance_29_reset(tap_dance_state_t *state, void *user_data);

void on_dance_29(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_COMM);
        tap_code16(FR_COMM);
        tap_code16(FR_COMM);
    }
    if(state->count > 3) {
        tap_code16(FR_COMM);
    }
}

void dance_29_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_29].step = dance_step(state);
    switch (dance_state[DANCE_29].step) {
        case SINGLE_TAP: register_code16(FR_COMM); break;
        case SINGLE_HOLD: register_code16(FR_SCLN); break;
        case DOUBLE_TAP: register_code16(FR_COMM); register_code16(FR_COMM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_COMM); register_code16(FR_COMM);
    }
}

void dance_29_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_29].step) {
        case SINGLE_TAP: unregister_code16(FR_COMM); break;
        case SINGLE_HOLD: unregister_code16(FR_SCLN); break;
        case DOUBLE_TAP: unregister_code16(FR_COMM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_COMM); break;
    }
    dance_state[DANCE_29].step = 0;
}
void on_dance_30(tap_dance_state_t *state, void *user_data);
void dance_30_finished(tap_dance_state_t *state, void *user_data);
void dance_30_reset(tap_dance_state_t *state, void *user_data);

void on_dance_30(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_DOT);
        tap_code16(FR_DOT);
        tap_code16(FR_DOT);
    }
    if(state->count > 3) {
        tap_code16(FR_DOT);
    }
}

void dance_30_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_30].step = dance_step(state);
    switch (dance_state[DANCE_30].step) {
        case SINGLE_TAP: register_code16(FR_DOT); break;
        case SINGLE_HOLD: register_code16(FR_COLN); break;
        case DOUBLE_TAP: register_code16(FR_DOT); register_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_DOT); register_code16(FR_DOT);
    }
}

void dance_30_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_30].step) {
        case SINGLE_TAP: unregister_code16(FR_DOT); break;
        case SINGLE_HOLD: unregister_code16(FR_COLN); break;
        case DOUBLE_TAP: unregister_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_DOT); break;
    }
    dance_state[DANCE_30].step = 0;
}
void on_dance_31(tap_dance_state_t *state, void *user_data);
void dance_31_finished(tap_dance_state_t *state, void *user_data);
void dance_31_reset(tap_dance_state_t *state, void *user_data);

void on_dance_31(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_COLN);
        tap_code16(FR_COLN);
        tap_code16(FR_COLN);
    }
    if(state->count > 3) {
        tap_code16(FR_COLN);
    }
}

void dance_31_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_31].step = dance_step(state);
    switch (dance_state[DANCE_31].step) {
        case SINGLE_TAP: register_code16(FR_COLN); break;
        case SINGLE_HOLD: register_code16(FR_EURO); break;
        case DOUBLE_TAP: register_code16(FR_COLN); register_code16(FR_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_COLN); register_code16(FR_COLN);
    }
}

void dance_31_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_31].step) {
        case SINGLE_TAP: unregister_code16(FR_COLN); break;
        case SINGLE_HOLD: unregister_code16(FR_EURO); break;
        case DOUBLE_TAP: unregister_code16(FR_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_COLN); break;
    }
    dance_state[DANCE_31].step = 0;
}
void on_dance_32(tap_dance_state_t *state, void *user_data);
void dance_32_finished(tap_dance_state_t *state, void *user_data);
void dance_32_reset(tap_dance_state_t *state, void *user_data);

void on_dance_32(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_SCLN);
        tap_code16(FR_SCLN);
        tap_code16(FR_SCLN);
    }
    if(state->count > 3) {
        tap_code16(FR_SCLN);
    }
}

void dance_32_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_32].step = dance_step(state);
    switch (dance_state[DANCE_32].step) {
        case SINGLE_TAP: register_code16(FR_DOT); break;
        case SINGLE_HOLD: register_code16(FR_PND); break;
        case DOUBLE_TAP: register_code16(FR_DOT); register_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_DOT); register_code16(FR_DOT);
    }
}

void dance_32_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_32].step) {
        case SINGLE_TAP: unregister_code16(FR_DOT); break;
        case SINGLE_HOLD: unregister_code16(FR_PND); break;
        case DOUBLE_TAP: unregister_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_DOT); break;
    }
    dance_state[DANCE_32].step = 0;
}
void on_dance_33(tap_dance_state_t *state, void *user_data);
void dance_33_finished(tap_dance_state_t *state, void *user_data);
void dance_33_reset(tap_dance_state_t *state, void *user_data);

void on_dance_33(tap_dance_state_t *state, void *user_data) {
    if (layer_state_is(VM_APPLICATION_WEB_LAYER)) {
        if(state->count == 3) {
            tap_code16(FR_GRTR);
            tap_code16(FR_GRTR);
            tap_code16(FR_GRTR);
        }
        if(state->count > 3) {
            tap_code16(FR_GRTR);
        }
    }
    else {
        if(state->count == 3) {
            tap_code16(FR_COMM);
            tap_code16(FR_COMM);
            tap_code16(FR_COMM);
        }
        if(state->count > 3) {
            tap_code16(FR_COMM);
        }
    }
}

void dance_33_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_33].step = dance_step(state);
    if (layer_state_is(VM_APPLICATION_WEB_LAYER)) {
       switch (dance_state[DANCE_33].step) {
           case SINGLE_TAP: register_code16(FR_GRTR); break;
           case SINGLE_HOLD: register_code16(FR_GRTR); break;
           case DOUBLE_TAP: register_code16(FR_GRTR); register_code16(FR_GRTR); break;
           case DOUBLE_SINGLE_TAP: tap_code16(FR_GRTR); register_code16(FR_GRTR);
       }
    }
    else {
       switch (dance_state[DANCE_33].step) {
           case SINGLE_TAP: register_code16(FR_COMM); break;
           case SINGLE_HOLD: register_code16(FR_SCLN); break;
           case DOUBLE_TAP: register_code16(FR_COMM); register_code16(FR_COMM); break;
           case DOUBLE_SINGLE_TAP: tap_code16(FR_COMM); register_code16(FR_COMM);
       }
    }
}

void dance_33_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    if (layer_state_is(VM_APPLICATION_WEB_LAYER)) {
       switch (dance_state[DANCE_33].step) {
           case SINGLE_TAP: unregister_code16(FR_GRTR); break;
           case SINGLE_HOLD: unregister_code16(FR_GRTR); break;
           case DOUBLE_TAP: unregister_code16(FR_GRTR); break;
           case DOUBLE_SINGLE_TAP: unregister_code16(FR_GRTR); break;
       }
    }
    else {
       switch (dance_state[DANCE_33].step) {
           case SINGLE_TAP: unregister_code16(FR_COMM); break;
           case SINGLE_HOLD: unregister_code16(FR_SCLN); break;
           case DOUBLE_TAP: unregister_code16(FR_COMM); break;
           case DOUBLE_SINGLE_TAP: unregister_code16(FR_COMM); break;
       }
    }
    dance_state[DANCE_33].step = 0;
}
void on_dance_34(tap_dance_state_t *state, void *user_data);
void dance_34_finished(tap_dance_state_t *state, void *user_data);
void dance_34_reset(tap_dance_state_t *state, void *user_data);

void on_dance_34(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_OVRR);
        tap_code16(FR_OVRR);
        tap_code16(FR_OVRR);
    }
    if(state->count > 3) {
        tap_code16(FR_OVRR);
    }
}

void dance_34_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_34].step = dance_step(state);
    switch (dance_state[DANCE_34].step) {
        case SINGLE_TAP: register_code16(FR_OVRR); break;
        case SINGLE_HOLD: register_code16(FR_GRV); break;
        case DOUBLE_TAP: register_code16(FR_OVRR); register_code16(FR_OVRR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_OVRR); register_code16(FR_OVRR);
    }
}

void dance_34_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_34].step) {
        case SINGLE_TAP: unregister_code16(FR_OVRR); break;
        case SINGLE_HOLD: unregister_code16(FR_GRV); break;
        case DOUBLE_TAP: unregister_code16(FR_OVRR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_OVRR); break;
    }
    dance_state[DANCE_34].step = 0;
}
void dance_38_finished(tap_dance_state_t *state, void *user_data);
void dance_38_reset(tap_dance_state_t *state, void *user_data);

void dance_38_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_38].step = dance_step(state);
    switch (dance_state[DANCE_38].step) {
        case SINGLE_TAP: layer_move(BEPO_BASE_LAYER + 0); break;
#ifdef VM_USE_LEFTPAD_ONLY
        case SINGLE_HOLD: layer_move(VM_USE_LEFTPAD_ONLY); break;
#else
        case SINGLE_HOLD: layer_move(BEPO_BASE_LAYER + 0); break;
#endif
        case DOUBLE_TAP: register_code16(KC_F6); return;
        case DOUBLE_SINGLE_TAP: layer_move(BEPO_BASE_LAYER + 0); break;
    }
    layer_state_set_kb(layer_state);
}

void dance_38_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_38].step) {
        case DOUBLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[DANCE_38].step = 0;
}
void dance_39_finished(tap_dance_state_t *state, void *user_data);
void dance_39_reset(tap_dance_state_t *state, void *user_data);

void dance_39_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_39].step = dance_step(state);
    switch (dance_state[DANCE_39].step) {
        case SINGLE_TAP: layer_move(QWERTY_BASE_LAYER + 0); break;
        case SINGLE_HOLD: layer_move(QWERTY_BASE_LAYER + 0); break;
        case DOUBLE_TAP: register_code16(KC_F4); return;
        case DOUBLE_SINGLE_TAP: layer_move(QWERTY_BASE_LAYER + 0); break;
    }
    layer_state_set_kb(layer_state);
}

void dance_39_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_39].step) {
        case DOUBLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[DANCE_39].step = 0;
}
void dance_40_finished(tap_dance_state_t *state, void *user_data);
void dance_40_reset(tap_dance_state_t *state, void *user_data);

void dance_40_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_40].step = dance_step(state);
    switch (dance_state[DANCE_40].step) {
        case SINGLE_TAP: layer_move(6); break;
        case SINGLE_HOLD: layer_move(6); break;
        case DOUBLE_TAP: register_code16(KC_F8); return;
        case DOUBLE_SINGLE_TAP: layer_move(6); break;
    }
    layer_state_set_kb(layer_state);
}

void dance_40_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_40].step) {
        case DOUBLE_TAP: unregister_code16(KC_F8); break;
    }
    dance_state[DANCE_40].step = 0;
}
#ifdef AUTOMOUSE_LAYER
void dance_41_finished(tap_dance_state_t *state, void *user_data);
void dance_41_reset(tap_dance_state_t *state, void *user_data);

void dance_41_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_41].step = dance_step(state);
    switch (dance_state[DANCE_41].step) {
        case SINGLE_TAP: set_oneshot_layer(AUTOMOUSE_LAYER, ONESHOT_START); break;
        case SINGLE_HOLD: set_oneshot_layer(AUTOMOUSE_LAYER, ONESHOT_START); break;
        case DOUBLE_TAP: register_code16(KC_F10); return;
        case DOUBLE_SINGLE_TAP: set_oneshot_layer(AUTOMOUSE_LAYER, ONESHOT_START); break;
    }
    layer_state_set_kb(layer_state);
}

void dance_41_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_41].step) {
        case SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case SINGLE_HOLD: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
        case DOUBLE_TAP: unregister_code16(KC_F10); break;
        case DOUBLE_SINGLE_TAP: clear_oneshot_layer_state(ONESHOT_PRESSED); break;
    }
    dance_state[DANCE_41].step = 0;
}
#endif

void on_dance_42(tap_dance_state_t *state, void *user_data);
void dance_42_finished(tap_dance_state_t *state, void *user_data);
void dance_42_reset(tap_dance_state_t *state, void *user_data);

void on_dance_42(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_42_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_42].step = dance_step(state);
    switch (dance_state[DANCE_42].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case SINGLE_HOLD: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_WWW_REFRESH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_42_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_42].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case SINGLE_HOLD: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_REFRESH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[DANCE_42].step = 0;
}
void on_dance_43(tap_dance_state_t *state, void *user_data);
void dance_43_finished(tap_dance_state_t *state, void *user_data);
void dance_43_reset(tap_dance_state_t *state, void *user_data);

void on_dance_43(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PREV_TRACK);
        tap_code16(KC_MEDIA_PREV_TRACK);
        tap_code16(KC_MEDIA_PREV_TRACK);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PREV_TRACK);
    }
}

void dance_43_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_43].step = dance_step(state);
    switch (dance_state[DANCE_43].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_REWIND); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PREV_TRACK); register_code16(KC_MEDIA_PREV_TRACK);
    }
}

void dance_43_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_43].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_REWIND); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
    }
    dance_state[DANCE_43].step = 0;
}
void on_dance_44(tap_dance_state_t *state, void *user_data);
void dance_44_finished(tap_dance_state_t *state, void *user_data);
void dance_44_reset(tap_dance_state_t *state, void *user_data);

void on_dance_44(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_44_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_44].step = dance_step(state);
    switch (dance_state[DANCE_44].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_44_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_44].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[DANCE_44].step = 0;
}
void on_dance_45(tap_dance_state_t *state, void *user_data);
void dance_45_finished(tap_dance_state_t *state, void *user_data);
void dance_45_reset(tap_dance_state_t *state, void *user_data);

void on_dance_45(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_NEXT_TRACK);
        tap_code16(KC_MEDIA_NEXT_TRACK);
        tap_code16(KC_MEDIA_NEXT_TRACK);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_NEXT_TRACK);
    }
}

void dance_45_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_45].step = dance_step(state);
    switch (dance_state[DANCE_45].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_FAST_FORWARD); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_NEXT_TRACK); register_code16(KC_MEDIA_NEXT_TRACK);
    }
}

void dance_45_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_45].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_FAST_FORWARD); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
    }
    dance_state[DANCE_45].step = 0;
}
void on_dance_46(tap_dance_state_t *state, void *user_data);
void dance_46_finished(tap_dance_state_t *state, void *user_data);
void dance_46_reset(tap_dance_state_t *state, void *user_data);

void on_dance_46(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_WWW_HOME);
        tap_code16(KC_WWW_HOME);
        tap_code16(KC_WWW_HOME);
    }
    if(state->count > 3) {
        tap_code16(KC_WWW_HOME);
    }
}

void dance_46_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_46].step = dance_step(state);
    switch (dance_state[DANCE_46].step) {
        case SINGLE_TAP: register_code16(KC_WWW_HOME); break;
        case SINGLE_HOLD: register_code16(KC_MY_COMPUTER); break;
        case DOUBLE_TAP: register_code16(KC_WWW_HOME); register_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_WWW_HOME); register_code16(KC_WWW_HOME);
    }
}

void dance_46_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_46].step) {
        case SINGLE_TAP: unregister_code16(KC_MAIL); break;
        case SINGLE_HOLD: unregister_code16(KC_MY_COMPUTER); break;
        case DOUBLE_TAP: unregister_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MAIL); break;
    }
    dance_state[DANCE_46].step = 0;
}
void on_dance_47(tap_dance_state_t *state, void *user_data);
void dance_47_finished(tap_dance_state_t *state, void *user_data);
void dance_47_reset(tap_dance_state_t *state, void *user_data);

void on_dance_47(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_APPLICATION);
        tap_code16(KC_APPLICATION);
        tap_code16(KC_APPLICATION);
    }
    if(state->count > 3) {
        tap_code16(KC_APPLICATION);
    }
}

void dance_47_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_47].step = dance_step(state);
    switch (dance_state[DANCE_47].step) {
        case SINGLE_TAP: register_code16(KC_APPLICATION); break;
        case SINGLE_HOLD: register_code16(KC_CALCULATOR); break;
        case DOUBLE_TAP: register_code16(KC_APPLICATION); register_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_APPLICATION); register_code16(KC_APPLICATION);
    }
}

void dance_47_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_47].step) {
        case SINGLE_TAP: unregister_code16(KC_APPLICATION); break;
        case SINGLE_HOLD: unregister_code16(KC_CALCULATOR); break;
        case DOUBLE_TAP: unregister_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_APPLICATION); break;
    }
    dance_state[DANCE_47].step = 0;
}
void on_dance_esc(tap_dance_state_t *state, void *user_data);
void dance_esc_finished(tap_dance_state_t *state, void *user_data);
void dance_esc_reset(tap_dance_state_t *state, void *user_data);

void on_dance_esc(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_esc_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_ESC].step = dance_step(state);
    switch (dance_state[DANCE_ESC].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: layer_off(VM_APPLICATION_WEB_LAYER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_esc_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_ESC].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[DANCE_ESC].step = 0;
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
void on_dance_web1(tap_dance_state_t *state, void *user_data);
void dance_web1_finished(tap_dance_state_t *state, void *user_data);
void dance_web1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_web1(tap_dance_state_t *state, void *user_data) {
    if (accentLayerActivation != 0 || runAccent) {
       if (state->count == 3) {
           if (layer_state_is(QWERTY_BASE_LAYER)) {
               tap_code16(RALT(KC_M));
               tap_code16(RALT(KC_M));
               tap_code16(RALT(KC_M));
           } else if (layer_state_is(6)) {
               tap_code16(FR_MU);
               tap_code16(FR_MU);
               tap_code16(FR_MU);
           } else {
               tap_code16(RALT(KC_COMMA));
               tap_code16(KC_SPACE);
               tap_code16(RALT(KC_COMMA));
               tap_code16(KC_SPACE);
               tap_code16(RALT(KC_COMMA));
               tap_code16(KC_SPACE);
           }
           runAccent = false;
       }
       if (state->count > 3) {
           if (layer_state_is(QWERTY_BASE_LAYER)) {
               tap_code16(RALT(KC_M));
           } else if (layer_state_is(6)) {
               tap_code16(FR_MU);
           } else {
               tap_code16(RALT(KC_COMMA));
               tap_code16(KC_SPACE);
           }
           runAccent = false;
       }
    }
}

void dance_web1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_WEB1].step = dance_step(state);
    if (accentLayerActivation != 0 || runAccent) {
       switch (dance_state[DANCE_WEB1].step) {
           case SINGLE_TAP:
           case SINGLE_HOLD:
               if (layer_state_is(QWERTY_BASE_LAYER)) {
                   register_code16(RALT(KC_M));
               } else if (layer_state_is(6)) {
                   register_code16(FR_MU);
               } else {
                   tap_code16(RALT(KC_COMMA));
                   register_code16(KC_SPACE);
               }
               break;
           case DOUBLE_TAP:
           case DOUBLE_SINGLE_TAP:
               if (layer_state_is(QWERTY_BASE_LAYER)) {
                   tap_code16(RALT(KC_M));
                   register_code16(RALT(KC_M));
               } else if (layer_state_is(6)) {
                   tap_code16(FR_MU);
                   register_code16(FR_MU);
               } else {
                   tap_code16(RALT(KC_COMMA));
                   tap_code16(KC_SPACE);
                   tap_code16(RALT(KC_COMMA));
                   register_code16(KC_SPACE);
               }
               break;
       }
    } else if (lastLayerActivation % 3 == 0) {
        switch (dance_state[DANCE_WEB1].step) {
            case SINGLE_TAP:
                if (web1OneShot) {
                    web1OneShot = false;
                    layer_on(++lastLayerActivation);
                } else {
                    web1OneShot = true; set_oneshot_layer(lastLayerActivation + 1, ONESHOT_START);
                }
                break;
            case SINGLE_HOLD: web1OneShot = false; layer_on(++lastLayerActivation); break;
            case DOUBLE_TAP: web1OneShot = false; layer_on(++lastLayerActivation); break;
        }
    } else if (dance_state[DANCE_WEB1].step == SINGLE_TAP) {
        layer_off(lastLayerActivation--);
    }
}

void dance_web1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    if (accentLayerActivation != 0 || runAccent) {
        runAccent = false;

        if (layer_state_is(QWERTY_BASE_LAYER)) {
            unregister_code16(RALT(KC_M));
        } else if (layer_state_is(6)) {
            unregister_code16(FR_MU);
        } else {
            unregister_code16(KC_SPACE);
        }
    } else if (lastLayerActivation % 3 != 0) {
        if (dance_state[DANCE_WEB1].step == SINGLE_HOLD) {
            layer_off(lastLayerActivation--);
        }
    }
    else if (dance_state[DANCE_WEB1].step == SINGLE_TAP) {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    }
    dance_state[DANCE_WEB1].step = 0;
}
void dance_web2_finished(tap_dance_state_t *state, void *user_data);
void dance_web2_reset(tap_dance_state_t *state, void *user_data);

void dance_web2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_WEB2].step = dance_step(state);
    if (accentLayerActivation == 0 && web2OneShot == false) {
        accentLayerActivation = ((lastLayerActivation / 3) * 3) + 2;

        switch (dance_state[DANCE_WEB2].step) {
            case SINGLE_TAP: runAccent = true; web2OneShot = true; set_oneshot_layer(accentLayerActivation, ONESHOT_START); break;
            case SINGLE_HOLD: web2OneShot = false; layer_on(accentLayerActivation); break;
            case DOUBLE_TAP: web2OneShot = false; layer_on(accentLayerActivation); break;
        }
    } else if (dance_state[DANCE_WEB2].step == SINGLE_TAP) {
        if (web2OneShot) {
            accentLayerActivation = ((lastLayerActivation / 3) * 3) + 2;
            web2OneShot = false;
            layer_on(accentLayerActivation);
        } else {
            layer_off(accentLayerActivation);
            accentLayerActivation = 0;
        }
    }
}

void dance_web2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    if (accentLayerActivation != 0) {
        switch (dance_state[DANCE_WEB2].step) {
            case SINGLE_HOLD:
                layer_off(accentLayerActivation);
                accentLayerActivation = 0;
                break;
            case SINGLE_TAP:
                clear_oneshot_layer_state(ONESHOT_PRESSED);
                runAccent = true;
                break;
        }
    }
    dance_state[DANCE_WEB2].step = 0;
}
void on_dance_quit(tap_dance_state_t *state, void *user_data);
void dance_quit_finished(tap_dance_state_t *state, void *user_data);
void dance_quit_reset(tap_dance_state_t *state, void *user_data);

void on_dance_quit(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        if (linuxSystem) {
            if (layer_state_is(QWERTY_BASE_LAYER)) {
                tap_code16(LCTL(KC_Q));
                tap_code16(LCTL(KC_Q));
                tap_code16(LCTL(KC_Q));
            } else if (layer_state_is(6)) {
                tap_code16(LCTL(FR_Q));
                tap_code16(LCTL(FR_Q));
                tap_code16(LCTL(FR_Q));
            } else {
                tap_code16(LCTL(BP_Q));
                tap_code16(LCTL(BP_Q));
                tap_code16(LCTL(BP_Q));
            }
        } else if (!activeNumLockLed) {
            if (layer_state_is(QWERTY_BASE_LAYER)) {
                tap_code16(LGUI(KC_Q));
                tap_code16(LGUI(KC_Q));
                tap_code16(LGUI(KC_Q));
            } else if (layer_state_is(6)) {
                tap_code16(LGUI(FR_Q));
                tap_code16(LGUI(FR_Q));
                tap_code16(LGUI(FR_Q));
            } else {
                tap_code16(LGUI(BP_Q));
                tap_code16(LGUI(BP_Q));
                tap_code16(LGUI(BP_Q));
            }
        } else {
            tap_code16(LALT(KC_F4));
            tap_code16(LALT(KC_F4));
            tap_code16(LALT(KC_F4));
        }
    }
    if(state->count > 3) {
        if (linuxSystem) {
            if (layer_state_is(QWERTY_BASE_LAYER)) {
                tap_code16(LCTL(KC_Q));
            } else if (layer_state_is(6)) {
                tap_code16(LCTL(FR_Q));
            } else {
                tap_code16(LCTL(BP_Q));
            }
        } else if (!activeNumLockLed) {
            if (layer_state_is(QWERTY_BASE_LAYER)) {
                tap_code16(LGUI(KC_Q));
            } else if (layer_state_is(6)) {
                tap_code16(LGUI(FR_Q));
            } else {
                tap_code16(LGUI(BP_Q));
            }
        } else {
            tap_code16(LALT(KC_F4));
        }
    }
}

void dance_quit_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_QUIT].step = dance_step(state);
    switch (dance_state[DANCE_QUIT].step) {
        case SINGLE_TAP:
            if (linuxSystem) {
                if (layer_state_is(QWERTY_BASE_LAYER)) {
                    register_code16(LCTL(KC_Q));
                } else if (layer_state_is(6)) {
                    register_code16(LCTL(FR_Q));
                } else {
                    register_code16(LCTL(BP_Q));
                }
            } else if (!activeNumLockLed) {
                if (layer_state_is(QWERTY_BASE_LAYER)) {
                    register_code16(LGUI(KC_Q));
                } else if (layer_state_is(6)) {
                    register_code16(LGUI(FR_Q));
                } else {
                    register_code16(LGUI(BP_Q));
                }
            } else {
                register_code16(LALT(KC_F4));
            }
            break;
        case SINGLE_HOLD:
            if (linuxSystem) {
                if (layer_state_is(QWERTY_BASE_LAYER)) {
                    register_code16(LCTL(KC_W));
                } else if (layer_state_is(6)) {
                    register_code16(LCTL(FR_W));
                } else {
                    register_code16(LCTL(BP_W));
                }
            } else if (!activeNumLockLed) {
                if (layer_state_is(QWERTY_BASE_LAYER)) {
                    register_code16(LGUI(KC_Q));
                } else if (layer_state_is(6)) {
                    register_code16(LGUI(FR_Q));
                } else {
                    register_code16(LGUI(BP_Q));
                }
            } else {
                register_code16(LALT(KC_F4));
            }
            break;
        case DOUBLE_TAP:
            if (linuxSystem) {
                if (layer_state_is(6) || layer_state_is(QWERTY_BASE_LAYER)) {
                    register_code16(LGUI(LSFT(KC_E)));
                } else {
                    register_code16(LGUI(LSFT(BP_E)));
                }
            } else if (!activeNumLockLed) {
                if (layer_state_is(QWERTY_BASE_LAYER)) {
                    tap_code16(LGUI(KC_Q));
                    register_code16(LGUI(KC_Q));
                } else if (layer_state_is(6)) {
                    tap_code16(LGUI(FR_Q));
                    register_code16(LGUI(FR_Q));
                } else {
                    tap_code16(LGUI(BP_Q));
                    register_code16(LGUI(BP_Q));
                }
            } else {
                tap_code16(LALT(KC_F4));
                register_code16(LALT(KC_F4));
            }
            break;
        case DOUBLE_SINGLE_TAP:
            if (linuxSystem) {
                if (layer_state_is(QWERTY_BASE_LAYER)) {
                    tap_code16(LCTL(KC_Q));
                    register_code16(LCTL(KC_Q));
                } else if (layer_state_is(6)) {
                    tap_code16(LCTL(FR_Q));
                    register_code16(LCTL(FR_Q));
                } else {
                    tap_code16(LCTL(BP_Q));
                    register_code16(LCTL(BP_Q));
                }
            } else if (!activeNumLockLed) {
                if (layer_state_is(QWERTY_BASE_LAYER)) {
                    tap_code16(LGUI(KC_Q));
                    register_code16(LGUI(KC_Q));
                } else if (layer_state_is(6)) {
                    tap_code16(LGUI(FR_Q));
                    register_code16(LGUI(FR_Q));
                } else {
                    tap_code16(LGUI(BP_Q));
                    register_code16(LGUI(BP_Q));
                }
            } else {
                tap_code16(LALT(KC_F4));
                register_code16(LALT(KC_F4));
            }
            break;
    }
}

void dance_quit_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_QUIT].step) {
        case SINGLE_TAP:
            if (linuxSystem) {
                if (layer_state_is(QWERTY_BASE_LAYER)) {
                    unregister_code16(LCTL(KC_Q));
                } else if (layer_state_is(6)) {
                    unregister_code16(LCTL(FR_Q));
                } else {
                    unregister_code16(LCTL(BP_Q));
                }
            } else if (!activeNumLockLed) {
                if (layer_state_is(QWERTY_BASE_LAYER)) {
                    unregister_code16(LGUI(KC_Q));
                } else if (layer_state_is(6)) {
                    unregister_code16(LGUI(FR_Q));
                } else {
                    unregister_code16(LGUI(BP_Q));
                }
            } else {
                unregister_code16(LALT(KC_F4));
            }
            break;
        case SINGLE_HOLD:
            if (linuxSystem) {
                if (layer_state_is(QWERTY_BASE_LAYER)) {
                    unregister_code16(LCTL(KC_W));
                } else if (layer_state_is(6)) {
                    unregister_code16(LCTL(FR_W));
                } else {
                    unregister_code16(LCTL(BP_W));
                }
            } else if (!activeNumLockLed) {
                if (layer_state_is(QWERTY_BASE_LAYER)) {
                    unregister_code16(LGUI(KC_Q));
                } else if (layer_state_is(6)) {
                    unregister_code16(LGUI(FR_Q));
                } else {
                    unregister_code16(LGUI(BP_Q));
                }
            } else {
                unregister_code16(LALT(KC_F4));
            }
            break;
        case DOUBLE_TAP:
            if (linuxSystem) {
                if (layer_state_is(6) || layer_state_is(QWERTY_BASE_LAYER)) {
                    unregister_code16(LGUI(LSFT(KC_E)));
                } else {
                    unregister_code16(LGUI(LSFT(BP_E)));
                }
            } else if (!activeNumLockLed) {
                if (layer_state_is(QWERTY_BASE_LAYER)) {
                    unregister_code16(LGUI(KC_Q));
                } else if (layer_state_is(6)) {
                    unregister_code16(LGUI(FR_Q));
                } else {
                    unregister_code16(LGUI(BP_Q));
                }
            } else {
                unregister_code16(LALT(KC_F4));
            }
            break;
        case DOUBLE_SINGLE_TAP:
            if (linuxSystem) {
                if (layer_state_is(QWERTY_BASE_LAYER)) {
                    unregister_code16(LCTL(KC_Q));
                } else if (layer_state_is(6)) {
                    unregister_code16(LCTL(FR_Q));
                } else {
                    unregister_code16(LCTL(BP_Q));
                }
            } else if (!activeNumLockLed) {
                if (layer_state_is(QWERTY_BASE_LAYER)) {
                    unregister_code16(LGUI(KC_Q));
                } else if (layer_state_is(6)) {
                    unregister_code16(LGUI(FR_Q));
                } else {
                    unregister_code16(LGUI(BP_Q));
                }
            } else {
                unregister_code16(LALT(KC_F4));
            }
            break;
    }
    dance_state[DANCE_QUIT].step = 0;
}
void on_dance_btn2(tap_dance_state_t *state, void *user_data);
void dance_btn2_finished(tap_dance_state_t *state, void *user_data);
void dance_btn2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_btn2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MS_BTN2);
        tap_code16(KC_MS_BTN2);
        tap_code16(KC_MS_BTN2);
    }
    if(state->count > 3) {
        tap_code16(KC_MS_BTN2);
    }
}

void dance_btn2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_BTN2].step = dance_step(state);
    switch (dance_state[DANCE_BTN2].step) {
        case SINGLE_TAP: register_code16(KC_MS_BTN2); break;
        case SINGLE_HOLD: register_code16(KC_MS_BTN2); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MS_BTN2); register_code16(KC_MS_BTN2);
    }
}

void dance_btn2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_BTN2].step) {
        case SINGLE_TAP: unregister_code16(KC_MS_BTN2); break;
        case SINGLE_HOLD: unregister_code16(KC_MS_BTN2); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MS_BTN2); break;
    }
    dance_state[DANCE_BTN2].step = 0;
}
void on_dance_btn8(tap_dance_state_t *state, void *user_data);
void dance_btn8_finished(tap_dance_state_t *state, void *user_data);
void dance_btn8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_btn8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        if (layer_state_is(6) || layer_state_is(QWERTY_BASE_LAYER)) {
            tap_code16(RCTL(KC_J));
            tap_code16(RCTL(KC_J));
            tap_code16(RCTL(KC_J));
        } else {
            tap_code16(RCTL(BP_J));
            tap_code16(RCTL(BP_J));
            tap_code16(RCTL(BP_J));
        }
    }
    if(state->count > 3) {
        if (layer_state_is(6) || layer_state_is(QWERTY_BASE_LAYER)) {
            tap_code16(RCTL(KC_J));
        } else {
            tap_code16(RCTL(BP_J));
        }
    }
}

void dance_btn8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_BTN8].step = dance_step(state);
    switch (dance_state[DANCE_BTN8].step) {
        case SINGLE_TAP:
        case SINGLE_HOLD:
               if (layer_state_is(6) || layer_state_is(QWERTY_BASE_LAYER)) {
                   register_code16(RCTL(KC_J));
               } else {
                   register_code16(RCTL(BP_J));
               }
               break;
        case DOUBLE_TAP: register_code16(KC_MS_BTN8); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MS_BTN8); register_code16(KC_MS_BTN8);
    }
}

void dance_btn8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_BTN8].step) {
        case SINGLE_TAP:
        case SINGLE_HOLD:
               if (layer_state_is(6) || layer_state_is(QWERTY_BASE_LAYER)) {
                   unregister_code16(RCTL(KC_J));
               } else {
                   unregister_code16(RCTL(BP_J));
               }
               break;
        case DOUBLE_TAP: unregister_code16(KC_MS_BTN8); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MS_BTN8); break;
    }
    dance_state[DANCE_BTN8].step = 0;
}
#ifdef VM_USE_LEFTPAD_ONLY
void dance_49_finished(tap_dance_state_t *state, void *user_data);
void dance_49_reset(tap_dance_state_t *state, void *user_data);

void dance_49_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_49].step = dance_step(state);
    switch (dance_state[DANCE_49].step) {
        case SINGLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY); break;
        case SINGLE_HOLD: layer_move(VM_USE_LEFTPAD_ONLY + 2); break;
        case DOUBLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY + 4); break;
        case DOUBLE_SINGLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY); break;
    }
}

void dance_49_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_49].step) {
    }
    dance_state[DANCE_49].step = 0;
}
void dance_50_finished(tap_dance_state_t *state, void *user_data);
void dance_50_reset(tap_dance_state_t *state, void *user_data);

void dance_50_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_50].step = dance_step(state);
    switch (dance_state[DANCE_50].step) {
        case SINGLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY + 3); break;
        case SINGLE_HOLD: layer_move(VM_USE_LEFTPAD_ONLY + 4); break;
        case DOUBLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY); break;
        case DOUBLE_SINGLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY + 3); break;
    }
}

void dance_50_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_50].step) {
    }
    dance_state[DANCE_50].step = 0;
}
void dance_51_finished(tap_dance_state_t *state, void *user_data);
void dance_51_reset(tap_dance_state_t *state, void *user_data);

void dance_51_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_51].step = dance_step(state);
    switch (dance_state[DANCE_51].step) {
        case SINGLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY + 2); break;
        case SINGLE_HOLD: layer_move(VM_USE_LEFTPAD_ONLY + 4); break;
        case DOUBLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY); break;
        case DOUBLE_SINGLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY + 2); break;
    }
}

void dance_51_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_51].step) {
    }
    dance_state[DANCE_51].step = 0;
}
void dance_52_finished(tap_dance_state_t *state, void *user_data);
void dance_52_reset(tap_dance_state_t *state, void *user_data);

void dance_52_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_52].step = dance_step(state);
    switch (dance_state[DANCE_52].step) {
        case SINGLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY + 5); break;
        case SINGLE_HOLD: layer_move(VM_USE_LEFTPAD_ONLY); break;
        case DOUBLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY + 2); break;
        case DOUBLE_SINGLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY + 5); break;
    }
}

void dance_52_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_52].step) {
    }
    dance_state[DANCE_52].step = 0;
}
void dance_53_finished(tap_dance_state_t *state, void *user_data);
void dance_53_reset(tap_dance_state_t *state, void *user_data);

void dance_53_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_53].step = dance_step(state);
    switch (dance_state[DANCE_53].step) {
        case SINGLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY + 4); break;
        case SINGLE_HOLD: layer_move(VM_USE_LEFTPAD_ONLY); break;
        case DOUBLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY + 2); break;
        case DOUBLE_SINGLE_TAP: layer_move(VM_USE_LEFTPAD_ONLY + 4); break;
    }
}

void dance_53_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_53].step) {
    }
    dance_state[DANCE_53].step = 0;
}
#endif

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
        [DANCE_22] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_22, dance_22_finished, dance_22_reset),
        [DANCE_23] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_23, dance_23_finished, dance_23_reset),
        [DANCE_24] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_24, dance_24_finished, dance_24_reset),
        [DANCE_25] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_25, dance_25_finished, dance_25_reset),
        [DANCE_26] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_26, dance_26_finished, dance_26_reset),
        [DANCE_27] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_27, dance_27_finished, dance_27_reset),
        [DANCE_28] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_28, dance_28_finished, dance_28_reset),
        [DANCE_29] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_29, dance_29_finished, dance_29_reset),
        [DANCE_30] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_30, dance_30_finished, dance_30_reset),
        [DANCE_31] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_31, dance_31_finished, dance_31_reset),
        [DANCE_32] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_32, dance_32_finished, dance_32_reset),
        [DANCE_33] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_33, dance_33_finished, dance_33_reset),
        [DANCE_34] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_34, dance_34_finished, dance_34_reset),
        [DANCE_38] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_38_finished, dance_38_reset),
        [DANCE_39] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_39_finished, dance_39_reset),
        [DANCE_40] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_40_finished, dance_40_reset),
#ifdef AUTOMOUSE_LAYER
        [DANCE_41] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_41_finished, dance_41_reset),
#endif
        [DANCE_42] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_42, dance_42_finished, dance_42_reset),
        [DANCE_43] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_43, dance_43_finished, dance_43_reset),
        [DANCE_44] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_44, dance_44_finished, dance_44_reset),
        [DANCE_45] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_45, dance_45_finished, dance_45_reset),
        [DANCE_46] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_46, dance_46_finished, dance_46_reset),
        [DANCE_47] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_47, dance_47_finished, dance_47_reset),
        [DANCE_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_esc, dance_esc_finished, dance_esc_reset),
        [DANCE_ENTER] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_enter, dance_enter_finished, dance_enter_reset),
        [DANCE_WEB1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_web1, dance_web1_finished, dance_web1_reset),
        [DANCE_WEB2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_web2_finished, dance_web2_reset),
        [DANCE_QUIT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_quit, dance_quit_finished, dance_quit_reset),
        [DANCE_BTN2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_btn2, dance_btn2_finished, dance_btn2_reset),
        [DANCE_BTN8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_btn8, dance_btn8_finished, dance_btn8_reset),
#ifdef VM_USE_LEFTPAD_ONLY
        [DANCE_49] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_49_finished, dance_49_reset),
        [DANCE_50] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_50_finished, dance_50_reset),
        [DANCE_51] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_51_finished, dance_51_reset),
        [DANCE_52] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_52_finished, dance_52_reset),
        [DANCE_53] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_53_finished, dance_53_reset),
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t mods_used;

  if (keycode != TD(DANCE_WEB1)) {
    web1OneShot = false;
    runAccent = false;
  }
  if (keycode != TD(DANCE_WEB2)) {
    if (web2OneShot) {
      accentLayerActivation = 0;
    }
    web2OneShot = false;
  }
  switch (keycode) {
    case QK_MODS ... QK_MODS_MAX:
    // Mouse and consumer keys (volume, media) with modifiers work inconsistently across operating systems,
    // this makes sure that modifiers are always applied to the key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode)) || IS_CONSUMER_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
      if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;
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
        if (layer_state_is(6) || layer_state_is(QWERTY_BASE_LAYER)) {
           SEND_STRING(SS_RCTL(SS_RGUI(SS_TAP(X_F))));
        } else {
           SEND_STRING(SS_RCTL(SS_RGUI(SS_TAP(X_SLSH))));
        }
      } else {
        if (layer_state_is(6) || layer_state_is(QWERTY_BASE_LAYER)) {
           SEND_STRING(SS_TAP(X_F));
        } else {
           SEND_STRING(SS_TAP(X_SLSH));
        }
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
      if (layer_state_is(QWERTY_BASE_LAYER) && !activeNumLockLed) {
         SEND_STRING(SS_RGUI(SS_TAP(X_C)));
      } else if (layer_state_is(6) || layer_state_is(QWERTY_BASE_LAYER)) {
         SEND_STRING(SS_RCTL(SS_TAP(X_C)));
      } else {
         SEND_STRING(SS_RCTL(SS_TAP(X_H)));
      }
    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      if (layer_state_is(QWERTY_BASE_LAYER) && !activeNumLockLed) {
         SEND_STRING(SS_RGUI(SS_TAP(X_X)));
      } else if (layer_state_is(6) || layer_state_is(QWERTY_BASE_LAYER)) {
         SEND_STRING(SS_RCTL(SS_TAP(X_X)));
      } else {
         SEND_STRING(SS_RCTL(SS_TAP(X_C)));
      }
    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      if (layer_state_is(QWERTY_BASE_LAYER) && !activeNumLockLed) {
         SEND_STRING(SS_RGUI(SS_TAP(X_V)));
      } else if (layer_state_is(6) || layer_state_is(QWERTY_BASE_LAYER)) {
         SEND_STRING(SS_RCTL(SS_TAP(X_V)));
      } else {
         SEND_STRING(SS_RCTL(SS_TAP(X_U)));
      }
    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      if ((mods_used = get_mods()) & MOD_MASK_CTRL) {
        linuxSystem = !linuxSystem;
      } else {
        activeNumLockLed = !activeNumLockLed;
      }
      led_update_kb(host_keyboard_led_state());
    }
    break;
    case ST_MACRO_25:
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
    case ST_MACRO_26:
    if (record->event.pressed) {
      if (layer_state_is(6) || layer_state_is(QWERTY_BASE_LAYER)) {
         SEND_STRING(SS_TAP(X_B));
      } else {
         SEND_STRING(SS_TAP(X_Q));
      }
    }
    break;
    case ST_MACRO_27:
    if (record->event.pressed) {
      if (!activeNumLockLed) {
        if (layer_state_is(QWERTY_BASE_LAYER)) {
           SEND_STRING(SS_RCTL(SS_RGUI(SS_TAP(X_Q))));
        } else if (layer_state_is(6)) {
           SEND_STRING(SS_RCTL(SS_RGUI(SS_TAP(X_A))));
        } else {
           SEND_STRING(SS_RCTL(SS_RGUI(SS_TAP(X_M))));
        }
      } else {
        if (layer_state_is(6) || layer_state_is(QWERTY_BASE_LAYER)) {
           SEND_STRING(SS_RGUI(SS_TAP(X_L)));
        } else {
           SEND_STRING(SS_RGUI(SS_TAP(X_O)));
        }
      }
    }
    break;
    case ST_MACRO_28:
    if (record->event.pressed) {
      if (!activeNumLockLed) {
        SEND_STRING(SS_RALT(SS_TAP(X_BSLS)));
      } else {
        SEND_STRING(SS_RALT(SS_TAP(X_LBRC)));
      }
    }
    break;
    case ST_MACRO_29:
    if (record->event.pressed) {
      if (!activeNumLockLed) {
        SEND_STRING(SS_RALT(SS_RSFT(SS_TAP(X_BSLS))));
      } else {
        SEND_STRING(SS_RALT(SS_TAP(X_RBRC)));
      }
    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

/* Vince specific code */

// Handle the caps word depending on the current layer
bool caps_word_press_user(uint16_t keycode) {
   // When I use this key, it is for locking or leaving the number layout on the Web layout
   if (keycode == TD(DANCE_WEB1) || keycode == TD(DANCE_WEB2)) {
      return true;
   }
   // The web layout is just an applicative layout that comes other the layouts used to text, so I am ignoring this layout.
   layer_state_t used_layer = layer_state & ~((layer_state_t)1 << VM_APPLICATION_WEB_LAYER);
   switch (biton32(used_layer)) {
      case BEPO_BASE_LAYER + 0 ... BEPO_BASE_LAYER + 2:           // BEPO
#ifdef VM_USE_LEFTPAD_ONLY
      case VM_USE_LEFTPAD_ONLY ... VM_USE_LEFTPAD_ONLY + 5:
#endif
         switch (keycode) {
            case BP_1 ... BP_0:
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
            case KC_KP_1 ... KC_KP_0:
            case KC_BSPC:
            case KC_DELETE:
            case QK_LLCK:
            case BP_UNDS:
            case BP_DCRC:
            case BP_DTRM:
               del_weak_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));  // Apply shift to next key.
               del_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));  // Apply shift to next key.
               del_oneshot_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));  // Apply shift to next key.
               return true;

            case BP_LCBR:
            case BP_RCBR:
               del_weak_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));  // Apply shift to next key.
               del_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));  // Apply shift to next key.
               del_oneshot_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));  // Apply shift to next key.
            default: return false;  // Deactivate Caps Word.
         }
      case QWERTY_BASE_LAYER + 0 ... QWERTY_BASE_LAYER + 2:       // QWERTY
         switch (keycode) {
            // Keycodes that continue Caps Word, with shift applied.
            case KC_UNDS:
            case KC_DQUO:
            case ST_MACRO_25:
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
      case 6 ... 8:                                               // AZERTY
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
      case FUNCTION_LAYER:           // Keyboard
         switch (keycode) {
            // Keycodes that continue Caps Word, without shifting.
            case KC_KP_1 ... KC_KP_0:
            case KC_BSPC:
            case KC_DELETE:
            case QK_LLCK:
            case KC_MS_WH_LEFT:
            case KC_MS_WH_RIGHT:
            case KC_MS_WH_UP:
            case KC_MS_WH_DOWN:
            case KC_MS_LEFT:
            case KC_MS_RIGHT:
            case KC_MS_UP:
            case KC_MS_DOWN:
            case KC_MS_BTN2:
            case KC_MS_BTN3:
            case KC_MS_BTN1:
               return true;

            default: return false;  // Deactivate Caps Word.
         }
#ifdef AUTOMOUSE_LAYER
      case AUTOMOUSE_LAYER:           // Mouse
         switch (keycode) {
            // Keycodes that continue Caps Word, without shifting.
            case KC_MS_BTN7:
            case KC_MS_BTN6:
            case KC_MS_BTN5:
            case KC_MS_BTN4:
            case DRAG_SCROLL:
            case KC_MS_BTN8:
            case KC_MS_WH_LEFT:
            case KC_MS_WH_RIGHT:
            case KC_MS_WH_UP:
            case KC_MS_WH_DOWN:
            case KC_MS_LEFT:
            case KC_MS_RIGHT:
            case KC_MS_UP:
            case KC_MS_DOWN:
            case TOGGLE_SCROLL:
            case KC_BSPC:
            case KC_DELETE:
            case NAVIGATOR_INC_CPI:
            case NAVIGATOR_DEC_CPI:
            case KC_MS_BTN2:
            case KC_MS_BTN3:
            case KC_MS_BTN1:
            case QK_LLCK:
               return true;

            default: return false;  // Deactivate Caps Word.
         }
#endif
      default: return false;
   }

   return false;
}

// OS detection code
bool process_detected_host_os_kb(os_variant_t detected_os) {
    activeNumLockLed = true;
    linuxSystem = false;

    if (!process_detected_host_os_user(detected_os)) {
        layer_move(BEPO_BASE_LAYER);
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            // This variable identify that we are running on a mac
            activeNumLockLed = false;
            layer_move(QWERTY_BASE_LAYER);
            break;

        case OS_LINUX:
        case OS_UNSURE:
            linuxSystem = true;

        case OS_WINDOWS:
            layer_move(BEPO_BASE_LAYER);

            break;
    }

    return true;
}

extern bool is_launching;

// Handle the caps lock and num lock leds
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    // Before updating the led, it is better to wait for the end of the launching animation
    if (!is_launching && res) {
        // On the function layer the leds are used to show the current system configuration
        // used for keys conversion (for example the copy key : Ctrl-C on linux and windows, Meta-C on Mac)
        //
        // Led 1 : Caps-Lock status
        // Led 2 : Unix (on) Windows (Off)
        // Led 3&4 : Mac (off) Unix or Windows (on)
        if (layer_state_is(FUNCTION_LAYER)) {
        STATUS_LED_2(linuxSystem);
        STATUS_LED_3(activeNumLockLed);
        STATUS_LED_4(activeNumLockLed);
        }
        else if (!activeNumLockLed) {
        STATUS_LED_4(false);
        } else {
#ifndef VM_USE_NUMPAD_ONLY
        STATUS_LED_4(led_state.num_lock);
#else
        STATUS_LED_4(!led_state.num_lock);
#endif
        }
        // As the led 1 is associated to the caps-lock
        // and only the function layer has the caps-lock key,
        // the led 1 remains for the caps-lock status even on the function layer
        STATUS_LED_1(led_state.caps_lock);
    }
    return res;
}

static bool capsWordActive = false;

// Handle the word lock led
void caps_word_set_user(bool active) {
    capsWordActive = active;
    // Before updating the led, it is better to wait for the end of the launching animation
    if (!is_launching && keyboard_config.led_level && !layer_state_is(FUNCTION_LAYER)) {
       STATUS_LED_3(active);
    }
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);
#ifdef AUTOMOUSE_LAYER
    if (is_launching || !keyboard_config.led_level) return state;

    uint8_t layer = get_highest_layer(state);

    if (layer != FUNCTION_LAYER) {
       STATUS_LED_2(layer == AUTOMOUSE_LAYER);
       STATUS_LED_3(capsWordActive);
    }
    led_update_kb(host_keyboard_led_state());
#endif

    return state;
}
#ifdef VM_OVERRIDE_ENABLE
/*
 * The overrided keys :
 * Shift + backspace : Stop
 * RAlt + Tab : Next
 * RAlt + Shift + Tab : Prev
 * RAlt + Esc : NumLock
 * RAlt + Left : Mouse left
 * RAlt + Up : Mouse Up
 * RAlt + Right : Mouse Right
 * RAlt + Down : Mouse Down
 * RAlt + (Pgdown/End) : Wheel Down
 * RAlt + (PgUp/Home) : Wheel Up
 * LAlt + (Pgdown/End) : Wheel Right
 * LAlt + (PgUp/Home) : Wheel Left
*/
static const key_override_t next_key_override             = ko_make_with_layers_negmods_and_options(MOD_BIT(KC_RIGHT_ALT), KC_TAB, KC_MEDIA_NEXT_TRACK, ~0, MOD_MASK_SHIFT, ko_option_no_reregister_trigger);
static const key_override_t prev_key_override             = ko_make_basic(MOD_BIT(KC_RIGHT_ALT)|MOD_MASK_SHIFT, KC_TAB,              KC_MEDIA_PREV_TRACK);

static const key_override_t backspace_key_override        = ko_make_basic(MOD_BIT(KC_RIGHT_ALT), KC_BSPC,      KC_MEDIA_STOP);
static const key_override_t esc_key_override              = ko_make_basic(MOD_BIT(KC_RIGHT_ALT), KC_ESCAPE,    KC_NUM);
static const key_override_t left_key_override             = ko_make_basic(MOD_BIT(KC_RIGHT_ALT), KC_LEFT,      KC_MS_LEFT);
static const key_override_t up_key_override               = ko_make_basic(MOD_BIT(KC_RIGHT_ALT), KC_UP,        KC_MS_UP);
static const key_override_t right_key_override            = ko_make_basic(MOD_BIT(KC_RIGHT_ALT), KC_RIGHT,     KC_MS_RIGHT);
static const key_override_t down_key_override             = ko_make_basic(MOD_BIT(KC_RIGHT_ALT), KC_DOWN,      KC_MS_DOWN);
static const key_override_t ralt_page_down_key_override   = ko_make_basic(MOD_BIT(KC_RIGHT_ALT), TD(DANCE_4),  KC_MS_WH_DOWN);
static const key_override_t ralt_page_up_key_override     = ko_make_basic(MOD_BIT(KC_RIGHT_ALT), TD(DANCE_3),  KC_MS_WH_UP);
static const key_override_t lalt_page_end_key_override    = ko_make_basic(MOD_BIT(KC_LEFT_ALT),  TD(DANCE_4),  KC_MS_WH_RIGHT);
static const key_override_t lalt_page_home_key_override   = ko_make_basic(MOD_BIT(KC_LEFT_ALT),  TD(DANCE_3),  KC_MS_WH_LEFT);

// The array of the key override definitions
static const key_override_t* my_key_overrides[] = {
   &backspace_key_override,
   &next_key_override,
   &prev_key_override,
   &esc_key_override,
   &left_key_override,
   &up_key_override,
   &right_key_override,
   &down_key_override,
   &ralt_page_down_key_override,
   &ralt_page_up_key_override,
   &lalt_page_end_key_override,
   &lalt_page_home_key_override
};

const key_override_t** key_overrides = my_key_overrides;
#endif
