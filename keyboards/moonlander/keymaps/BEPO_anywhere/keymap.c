#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "keymap_croatian.h"
#include "keymap_turkish_q.h"
#include "keymap_slovak.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

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
  BP_LSPO,
  BP_RSPC,
  FR_LSPO,
  FR_RSPC,
};


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
qk_tap_dance_action_t *action;

enum tap_dance_codes {
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_24,
  DANCE_25,
  DANCE_26,
  DANCE_27,
  DANCE_28,
  DANCE_30,
  DANCE_31,
  DANCE_33,
  DANCE_34,
  DANCE_35,
  DANCE_36,
  DANCE_37,
  DANCE_39,
  DANCE_40,
  DANCE_42,
  DANCE_43,
  DANCE_44,
  DANCE_45,
  DANCE_46,
  DANCE_48,
  DANCE_49,
  DANCE_50,
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
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
  DANCE_29,
  DANCE_32,
  DANCE_38,
  DANCE_41,
  DANCE_47,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    TD(DANCE_0),    TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    TD(DANCE_5),    TO(9),                                          TD(DANCE_14),   TD(DANCE_15),   TD(DANCE_16),   TD(DANCE_17),   TD(DANCE_18),   TD(DANCE_19),   TD(DANCE_20),   
    KC_TAB,         BP_B,           BP_ECUT,        BP_P,           BP_O,           BP_EGRV,        TD(DANCE_6),                                    KC_HOME,        BP_V,           BP_D,           BP_L,           BP_J,           BP_Z,           KC_UP,          
    TD(DANCE_7),    BP_A,           BP_U,           BP_I,           BP_E,           TD(DANCE_8),    TD(DANCE_9),                                                                    KC_END,         BP_T,           BP_S,           BP_R,           BP_N,           BP_M,           KC_DOWN,        
    OSM(MOD_LSFT),  BP_AGRV,        BP_Y,           BP_X,           TD(DANCE_10),   BP_K,                                           BP_Q,           BP_G,           BP_H,           BP_F,           BP_CCED,        OSM(MOD_RSFT),  
    KC_LALT,        TD(DANCE_11),   TD(DANCE_12),   TT(2),          BP_C,           TD(DANCE_13),                                                                                                   TD(DANCE_22),   BP_W,           TT(1),          KC_LEFT,        KC_RIGHT,       TD(DANCE_21),   
    KC_ENTER,       MT(MOD_LCTL, KC_ESCAPE),KC_BSPACE,                      MT(MOD_RCTL, KC_ESCAPE),KC_RALT,        KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, BP_PIPE,        BP_AMPR,        BP_MINS,        BP_ASTR,        BP_LESS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, BP_GRTR,        BP_SLSH,        BP_PLUS,        BP_HASH,        BP_BSLS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, BP_6,           BP_4,           BP_8,           BP_0,           BP_2,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, BP_3,           BP_9,           BP_1,           BP_5,           BP_7,           KC_TRANSPARENT, 
    TD(DANCE_23),   BP_UNDS,        BP_LBRC,        BP_LPRN,        BP_EQL,         TD(DANCE_24),                                   TD(DANCE_25),   BP_PERC,        BP_RPRN,        BP_RBRC,        BP_EXLM,        CAPS_WORD,      
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, BP_DCRC,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, BP_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, BP_AT,          BP_TILD,        RALT(BP_COMM),  BP_APOS,        BP_LGIL,        KC_TRANSPARENT,                                 KC_TRANSPARENT, BP_RGIL,        BP_GRV,         BP_DQOT,        BP_DTRM,        TD(DANCE_27),   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_KP_3,        KC_KP_9,        KC_KP_1,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT, 
    KC_CAPSLOCK,    BP_QEST,        BP_LCBR,        RALT(LSFT(BP_P)),TD(DANCE_26),   RALT(BP_2),                                     RALT(BP_3),     TD(DANCE_28),   RALT(BP_DQOT),  BP_RCBR,        BP_UGRV,        TD(DANCE_29),   
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, BP_DCRC,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, BP_DLR,         ST_MACRO_0,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_B,           ST_MACRO_1,     KC_P,           KC_O,           ST_MACRO_2,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_V,           KC_D,           KC_L,           KC_J,           KC_Z,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_U,           KC_I,           KC_E,           TD(DANCE_30),   KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_T,           KC_S,           KC_R,           KC_N,           KC_M,           KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_3,     KC_Y,           KC_X,           TD(DANCE_31),   KC_K,                                           KC_Q,           KC_G,           KC_H,           KC_F,           ST_MACRO_4,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TT(5),          KC_C,           KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_W,           TT(4),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PIPE,        KC_AMPR,        KC_MINUS,       KC_ASTR,        KC_LABK,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_RABK,        KC_SLASH,       KC_PLUS,        KC_HASH,        KC_BSLASH,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_6,           KC_4,           KC_8,           KC_0,           KC_2,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_3,           KC_9,           KC_1,           KC_5,           KC_7,           KC_TRANSPARENT, 
    TD(DANCE_32),   KC_UNDS,        KC_LBRACKET,    KC_LPRN,        KC_EQUAL,       TD(DANCE_33),                                   TD(DANCE_34),   KC_PERC,        KC_RPRN,        KC_RBRACKET,    KC_EXLM,        CAPS_WORD,      
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_AT,          ST_MACRO_5,     ST_MACRO_6,     KC_QUOTE,       RALT(KC_LBRACKET),KC_TRANSPARENT,                                 KC_TRANSPARENT, RALT(KC_RBRACKET),ST_MACRO_8,     ST_MACRO_9,     KC_DQUO,        TD(DANCE_36),   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_KP_3,        KC_KP_9,        KC_KP_1,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT, 
    KC_CAPSLOCK,    KC_QUES,        KC_LCBR,        RALT(RSFT(KC_S)),TD(DANCE_35),   ST_MACRO_7,                                     ST_MACRO_10,    TD(DANCE_37),   ST_MACRO_11,    KC_RCBR,        ST_MACRO_12,    TD(DANCE_38),   
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_DLR,         RALT(KC_M),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_B,           FR_EACU,        KC_P,           KC_O,           FR_EGRV,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_V,           KC_D,           KC_L,           KC_J,           FR_Z,           KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_A,           KC_U,           KC_I,           KC_E,           TD(DANCE_39),   KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_T,           KC_S,           KC_R,           KC_N,           FR_M,           KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_AGRV,        KC_Y,           KC_X,           TD(DANCE_40),   KC_K,                                           FR_Q,           KC_G,           KC_H,           KC_F,           FR_CCED,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TT(8),          KC_C,           KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, FR_W,           TT(7),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_PIPE,        FR_AMP,         FR_MINS,        FR_ASTR,        FR_LESS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, FR_GRTR,        FR_SLSH,        FR_PLUS,        FR_HASH,        FR_BSLS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_6,           FR_4,           FR_8,           FR_0,           FR_2,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, FR_3,           FR_9,           FR_1,           FR_5,           FR_7,           KC_TRANSPARENT, 
    TD(DANCE_41),   FR_UNDS,        FR_LBRC,        FR_LPRN,        FR_EQL,         TD(DANCE_42),                                   TD(DANCE_43),   FR_PERC,        FR_RPRN,        FR_RBRC,        FR_EXLM,        CAPS_WORD,      
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, FR_CIRC,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, FR_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_AT,          FR_TILD,        FR_APOS,        FR_SUP2,        ST_MACRO_13,    KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_15,    ST_MACRO_16,    FR_DQUO,        FR_UMLT,        TD(DANCE_45),   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_KP_3,        KC_KP_9,        KC_KP_1,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT, 
    KC_CAPSLOCK,    FR_QUES,        FR_LCBR,        FR_SECT,        TD(DANCE_44),   ST_MACRO_14,                                    ST_MACRO_17,    TD(DANCE_46),   ST_MACRO_18,    FR_RCBR,        FR_UGRV,        TD(DANCE_47),   
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, FR_CCIRC,       KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, FR_DLR,         FR_MU,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [9] = LAYOUT_moonlander(
    TD(DANCE_48),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPACE,                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_49),   
    RGB_TOG,        TO(0),          KC_PGUP,        KC_UP,          KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_MS_WH_UP,                                    KC_MS_WH_LEFT,  KC_KP_SLASH,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, KC_MS_UP,       
    KC_TRANSPARENT, TO(6),          KC_LEFT,        KC_HOME,        KC_RIGHT,       KC_AUDIO_VOL_DOWN,KC_MS_WH_DOWN,                                                                  KC_MS_WH_RIGHT, KC_KP_MINUS,    KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_MS_DOWN,     
    KC_LSHIFT,      KC_NUMLOCK,     KC_PGDOWN,      KC_DOWN,        KC_END,         TOGGLE_LAYER_COLOR,                                TO(3),          KC_KP_1,        KC_KP_2,        KC_KP_3,        TD(DANCE_50),   KC_RSHIFT,      
    KC_TRANSPARENT, RESET,          DYN_MACRO_PLAY1,DYN_MACRO_PLAY2,DYN_REC_STOP,   KC_MS_BTN1,                                                                                                     KC_MS_BTN2,     KC_MS_BTN3,     KC_KP_0,        KC_MS_LEFT,     KC_MS_RIGHT,    KC_TRANSPARENT, 
    KC_KP_ENTER,    MT(MOD_LCTL, KC_ESCAPE),DYN_REC_START1,                 DYN_REC_START2, MT(MOD_RALT, KC_ESCAPE),KC_TRANSPARENT
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {188,255,255}, {74,255,255}, {225,224,255}, {0,245,245}, {0,245,245}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {152,255,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {152,255,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {0,245,245}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {46,215,244}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {46,215,244}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {74,255,255}, {0,245,245}, {19,245,255}, {0,245,245} },

    [1] = { {188,255,255}, {168,218,204}, {225,224,255}, {0,245,245}, {0,245,245}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {152,255,255}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {152,255,255}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {0,0,255}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {168,218,204}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {0,245,245}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {46,215,244}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {46,215,244}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {0,0,255}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {168,218,204}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {188,255,255}, {41,255,255}, {41,255,255}, {168,218,204}, {0,245,245}, {19,245,255}, {0,245,245} },

    [2] = { {188,255,255}, {62,219,138}, {225,224,255}, {0,245,245}, {0,245,245}, {19,245,255}, {62,219,138}, {168,218,204}, {62,219,138}, {152,255,255}, {19,245,255}, {62,219,138}, {168,218,204}, {62,219,138}, {152,255,255}, {19,245,255}, {62,219,138}, {168,218,204}, {62,219,138}, {0,0,255}, {19,245,255}, {62,219,138}, {168,218,204}, {62,219,138}, {62,219,138}, {19,245,255}, {62,219,138}, {168,218,204}, {62,219,138}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {0,245,245}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {62,219,138}, {168,218,204}, {62,219,138}, {46,215,244}, {19,245,255}, {62,219,138}, {168,218,204}, {62,219,138}, {46,215,244}, {19,245,255}, {62,219,138}, {168,218,204}, {62,219,138}, {62,219,138}, {19,245,255}, {62,219,138}, {168,218,204}, {62,219,138}, {62,219,138}, {19,245,255}, {62,219,138}, {168,218,204}, {62,219,138}, {188,255,255}, {41,255,255}, {41,255,255}, {62,219,138}, {0,245,245}, {19,245,255}, {0,245,245} },

    [3] = { {188,255,255}, {131,255,255}, {225,224,255}, {0,245,245}, {0,245,245}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {1,181,132}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {1,181,132}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {19,245,255}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {46,215,244}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {46,215,244}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {131,255,255}, {0,245,245}, {19,245,255}, {0,245,245} },

    [4] = { {188,255,255}, {1,181,132}, {225,224,255}, {0,245,245}, {0,245,245}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {152,255,255}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {152,255,255}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {0,0,255}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {1,181,132}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {0,245,245}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {46,215,244}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {46,215,244}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {0,0,255}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {1,181,132}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {188,255,255}, {41,255,255}, {41,255,255}, {1,181,132}, {0,245,245}, {19,245,255}, {0,245,245} },

    [5] = { {188,255,255}, {74,255,255}, {225,224,255}, {0,245,245}, {0,245,245}, {19,245,255}, {74,255,255}, {1,181,132}, {74,255,255}, {152,255,255}, {19,245,255}, {74,255,255}, {1,181,132}, {74,255,255}, {152,255,255}, {19,245,255}, {74,255,255}, {1,181,132}, {74,255,255}, {0,0,255}, {19,245,255}, {74,255,255}, {1,181,132}, {74,255,255}, {74,255,255}, {19,245,255}, {74,255,255}, {1,181,132}, {74,255,255}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {0,245,245}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {74,255,255}, {1,181,132}, {74,255,255}, {46,215,244}, {19,245,255}, {74,255,255}, {1,181,132}, {74,255,255}, {46,215,244}, {19,245,255}, {74,255,255}, {1,181,132}, {74,255,255}, {74,255,255}, {19,245,255}, {74,255,255}, {1,181,132}, {74,255,255}, {74,255,255}, {19,245,255}, {74,255,255}, {1,181,132}, {74,255,255}, {0,0,0}, {46,215,244}, {41,255,255}, {74,255,255}, {0,245,245}, {19,245,255}, {0,245,245} },

    [6] = { {62,219,138}, {198,255,255}, {74,255,255}, {0,245,245}, {0,245,245}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {152,255,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {152,255,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {0,0,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {0,0,255}, {41,255,255}, {41,255,255}, {74,255,255}, {19,245,255}, {74,255,255}, {0,245,245}, {62,219,138}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {46,215,244}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {46,215,244}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {0,0,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {62,219,138}, {41,255,255}, {41,255,255}, {198,255,255}, {0,245,245}, {19,245,255}, {0,245,245} },

    [7] = { {188,255,255}, {62,219,138}, {225,224,255}, {0,245,245}, {0,245,245}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {1,181,132}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {1,181,132}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {0,0,255}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {62,219,138}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {0,245,245}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {46,215,244}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {46,215,244}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {0,0,255}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {62,219,138}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {188,255,255}, {41,255,255}, {41,255,255}, {62,219,138}, {0,245,245}, {19,245,255}, {0,245,245} },

    [8] = { {188,255,255}, {131,255,255}, {225,224,255}, {0,245,245}, {0,245,245}, {19,245,255}, {131,255,255}, {62,219,138}, {131,255,255}, {1,181,132}, {19,245,255}, {131,255,255}, {62,219,138}, {131,255,255}, {1,181,132}, {19,245,255}, {131,255,255}, {62,219,138}, {131,255,255}, {0,0,255}, {19,245,255}, {131,255,255}, {62,219,138}, {131,255,255}, {131,255,255}, {19,245,255}, {131,255,255}, {62,219,138}, {131,255,255}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {0,245,245}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {131,255,255}, {62,219,138}, {131,255,255}, {46,215,244}, {19,245,255}, {131,255,255}, {62,219,138}, {131,255,255}, {46,215,244}, {19,245,255}, {131,255,255}, {62,219,138}, {131,255,255}, {131,255,255}, {19,245,255}, {131,255,255}, {62,219,138}, {131,255,255}, {131,255,255}, {19,245,255}, {131,255,255}, {62,219,138}, {131,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {131,255,255}, {0,245,245}, {19,245,255}, {0,245,245} },

    [9] = { {188,255,255}, {19,245,255}, {225,224,255}, {0,245,245}, {0,245,245}, {19,245,255}, {0,0,255}, {0,0,255}, {0,245,245}, {131,255,255}, {19,245,255}, {0,245,245}, {19,245,255}, {0,245,245}, {74,255,255}, {19,245,255}, {19,245,255}, {0,245,245}, {19,245,255}, {74,255,255}, {19,245,255}, {0,245,245}, {19,245,255}, {0,245,245}, {0,245,245}, {19,245,255}, {131,255,255}, {131,255,255}, {19,245,255}, {225,224,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {0,245,245}, {41,255,255}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {1,181,132}, {1,181,132}, {1,181,132}, {46,215,244}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {41,255,255}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {41,255,255}, {19,245,255}, {1,181,132}, {1,181,132}, {0,0,255}, {188,255,255}, {41,255,255}, {41,255,255}, {62,219,138}, {0,245,245}, {0,245,245}, {41,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
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

void rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return;
  }
  if (keyboard_config.disable_layer_led) { return; }
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
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_COMMA)) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_E));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_E));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_A));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_C));
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
      SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_0) ));
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
      SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_1) ));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_2) ));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_U));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_1) ));
    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_0) ));
    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_7) ));
    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_7)) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_1) ));
    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_2) ));
    }
    break;

    case TD(DANCE_6):
    case TD(DANCE_7):
    case TD(DANCE_8):
    case TD(DANCE_9):
    case TD(DANCE_10):
    case TD(DANCE_24):
    case TD(DANCE_25):
    case TD(DANCE_26):
    case TD(DANCE_27):
    case TD(DANCE_28):
    case TD(DANCE_30):
    case TD(DANCE_31):
    case TD(DANCE_33):
    case TD(DANCE_34):
    case TD(DANCE_35):
    case TD(DANCE_36):
    case TD(DANCE_37):
    case TD(DANCE_39):
    case TD(DANCE_40):
    case TD(DANCE_42):
    case TD(DANCE_43):
    case TD(DANCE_44):
    case TD(DANCE_45):
    case TD(DANCE_46):
    case TD(DANCE_48):
    case TD(DANCE_49):
    case TD(DANCE_50):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
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


void tap_dance_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

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

static tap dance_state[24];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
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


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F6);
        tap_code16(KC_F6);
        tap_code16(KC_F6);
    }
    if(state->count > 3) {
        tap_code16(KC_F6);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_F6); break;
        case DOUBLE_TAP: register_code16(KC_F6); register_code16(KC_F6); break;
        case DOUBLE_HOLD: register_code16(KC_F16); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_F6); break;
        case DOUBLE_HOLD: unregister_code16(KC_F16); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(KC_F14); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_F14); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F8);
        tap_code16(KC_F8);
        tap_code16(KC_F8);
    }
    if(state->count > 3) {
        tap_code16(KC_F8);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_F8); break;
        case DOUBLE_TAP: register_code16(KC_F18); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F8); register_code16(KC_F8);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_F18); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F8); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F10);
        tap_code16(KC_F10);
        tap_code16(KC_F10);
    }
    if(state->count > 3) {
        tap_code16(KC_F10);
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_F10); break;
        case DOUBLE_TAP: register_code16(KC_F20); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F10); register_code16(KC_F10);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_F20); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F10); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F2);
        tap_code16(KC_F2);
        tap_code16(KC_F2);
    }
    if(state->count > 3) {
        tap_code16(KC_F2);
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F2); register_code16(KC_F2);
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F2); break;
    }
    dance_state[5].step = 0;
}
void on_dance_11(qk_tap_dance_state_t *state, void *user_data);
void dance_11_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_11_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_11(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_WWW_HOME);
        tap_code16(KC_WWW_HOME);
        tap_code16(KC_WWW_HOME);
    }
    if(state->count > 3) {
        tap_code16(KC_WWW_HOME);
    }
}

void dance_11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_WWW_HOME); break;
        case SINGLE_HOLD: register_code16(KC_CALCULATOR); break;
        case DOUBLE_TAP: register_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_WWW_HOME); register_code16(KC_WWW_HOME);
    }
}

void dance_11_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_WWW_HOME); break;
        case SINGLE_HOLD: unregister_code16(KC_CALCULATOR); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_WWW_HOME); break;
    }
    dance_state[6].step = 0;
}
void on_dance_12(qk_tap_dance_state_t *state, void *user_data);
void dance_12_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_12_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_12(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MAIL);
        tap_code16(KC_MAIL);
        tap_code16(KC_MAIL);
    }
    if(state->count > 3) {
        tap_code16(KC_MAIL);
    }
}

void dance_12_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_MAIL); break;
        case SINGLE_HOLD: register_code16(KC_MY_COMPUTER); break;
        case DOUBLE_TAP: register_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MAIL); register_code16(KC_MAIL);
    }
}

void dance_12_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_MAIL); break;
        case SINGLE_HOLD: unregister_code16(KC_MY_COMPUTER); break;
        case DOUBLE_TAP: unregister_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MAIL); break;
    }
    dance_state[7].step = 0;
}
void on_dance_13(qk_tap_dance_state_t *state, void *user_data);
void dance_13_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_13_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_13(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LGUI);
        tap_code16(KC_LGUI);
        tap_code16(KC_LGUI);
    }
    if(state->count > 3) {
        tap_code16(KC_LGUI);
    }
}

void dance_13_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_LGUI); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LGUI); register_code16(KC_LGUI);
    }
}

void dance_13_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_LGUI); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LGUI); break;
    }
    dance_state[8].step = 0;
}
void on_dance_14(qk_tap_dance_state_t *state, void *user_data);
void dance_14_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_14_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_14(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_14_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_EJECT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_14_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_EJECT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[9].step = 0;
}
void on_dance_15(qk_tap_dance_state_t *state, void *user_data);
void dance_15_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_15_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_15(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F3);
        tap_code16(KC_F3);
        tap_code16(KC_F3);
    }
    if(state->count > 3) {
        tap_code16(KC_F3);
    }
}

void dance_15_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
    }
}

void dance_15_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
    }
    dance_state[10].step = 0;
}
void on_dance_16(qk_tap_dance_state_t *state, void *user_data);
void dance_16_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_16_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_16(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if(state->count > 3) {
        tap_code16(KC_F9);
    }
}

void dance_16_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_F19); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}

void dance_16_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_F19); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[11].step = 0;
}
void on_dance_17(qk_tap_dance_state_t *state, void *user_data);
void dance_17_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_17_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_17(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F1);
        tap_code16(KC_F1);
        tap_code16(KC_F1);
    }
    if(state->count > 3) {
        tap_code16(KC_F1);
    }
}

void dance_17_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
    }
}

void dance_17_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
    }
    dance_state[12].step = 0;
}
void on_dance_18(qk_tap_dance_state_t *state, void *user_data);
void dance_18_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_18_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_18(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_18_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_F15); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_18_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_F15); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[13].step = 0;
}
void on_dance_19(qk_tap_dance_state_t *state, void *user_data);
void dance_19_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_19_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_19(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if(state->count > 3) {
        tap_code16(KC_F7);
    }
}

void dance_19_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_F17); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}

void dance_19_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_F17); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[14].step = 0;
}
void on_dance_20(qk_tap_dance_state_t *state, void *user_data);
void dance_20_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_20_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_20(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
    }
    if(state->count > 3) {
        tap_code16(KC_DELETE);
    }
}

void dance_20_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(KC_DELETE); break;
        case SINGLE_HOLD: register_code16(KC_DELETE); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DELETE); register_code16(KC_DELETE);
    }
}

void dance_20_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(KC_DELETE); break;
        case SINGLE_HOLD: unregister_code16(KC_DELETE); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DELETE); break;
    }
    dance_state[15].step = 0;
}
void on_dance_21(qk_tap_dance_state_t *state, void *user_data);
void dance_21_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_21_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_21(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_INSERT));
        tap_code16(LSFT(KC_INSERT));
        tap_code16(LSFT(KC_INSERT));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_INSERT));
    }
}

void dance_21_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_INSERT)); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_INSERT)); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_INSERT)); register_code16(LSFT(KC_INSERT));
    }
}

void dance_21_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_INSERT)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_INSERT)); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_INSERT)); break;
    }
    dance_state[16].step = 0;
}
void on_dance_22(qk_tap_dance_state_t *state, void *user_data);
void dance_22_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_22_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_22(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RGUI);
        tap_code16(KC_RGUI);
        tap_code16(KC_RGUI);
    }
    if(state->count > 3) {
        tap_code16(KC_RGUI);
    }
}

void dance_22_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(KC_RGUI); break;
        case SINGLE_HOLD: register_code16(KC_RGUI); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_UP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RGUI); register_code16(KC_RGUI);
    }
}

void dance_22_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(KC_RGUI); break;
        case SINGLE_HOLD: unregister_code16(KC_RGUI); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_UP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RGUI); break;
    }
    dance_state[17].step = 0;
}
void on_dance_23(qk_tap_dance_state_t *state, void *user_data);
void dance_23_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_23_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_23(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LSHIFT);
        tap_code16(KC_LSHIFT);
        tap_code16(KC_LSHIFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LSHIFT);
    }
}

void dance_23_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP: register_code16(KC_LSHIFT); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: layer_move(9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LSHIFT); register_code16(KC_LSHIFT);
    }
}

void dance_23_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP: unregister_code16(KC_LSHIFT); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LSHIFT); break;
    }
    dance_state[18].step = 0;
}
void on_dance_29(qk_tap_dance_state_t *state, void *user_data);
void dance_29_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_29_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_29(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RSHIFT);
        tap_code16(KC_RSHIFT);
        tap_code16(KC_RSHIFT);
    }
    if(state->count > 3) {
        tap_code16(KC_RSHIFT);
    }
}

void dance_29_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP: register_code16(KC_RSHIFT); break;
        case SINGLE_HOLD: register_code16(KC_RSHIFT); break;
        case DOUBLE_TAP: layer_move(9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RSHIFT); register_code16(KC_RSHIFT);
    }
}

void dance_29_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP: unregister_code16(KC_RSHIFT); break;
        case SINGLE_HOLD: unregister_code16(KC_RSHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RSHIFT); break;
    }
    dance_state[19].step = 0;
}
void on_dance_32(qk_tap_dance_state_t *state, void *user_data);
void dance_32_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_32_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_32(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LSHIFT);
        tap_code16(KC_LSHIFT);
        tap_code16(KC_LSHIFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LSHIFT);
    }
}

void dance_32_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP: register_code16(KC_LSHIFT); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: layer_move(9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LSHIFT); register_code16(KC_LSHIFT);
    }
}

void dance_32_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP: unregister_code16(KC_LSHIFT); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LSHIFT); break;
    }
    dance_state[20].step = 0;
}
void on_dance_38(qk_tap_dance_state_t *state, void *user_data);
void dance_38_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_38_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_38(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RSHIFT);
        tap_code16(KC_RSHIFT);
        tap_code16(KC_RSHIFT);
    }
    if(state->count > 3) {
        tap_code16(KC_RSHIFT);
    }
}

void dance_38_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[21].step = dance_step(state);
    switch (dance_state[21].step) {
        case SINGLE_TAP: register_code16(KC_RSHIFT); break;
        case SINGLE_HOLD: register_code16(KC_RSHIFT); break;
        case DOUBLE_TAP: layer_move(9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RSHIFT); register_code16(KC_RSHIFT);
    }
}

void dance_38_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[21].step) {
        case SINGLE_TAP: unregister_code16(KC_RSHIFT); break;
        case SINGLE_HOLD: unregister_code16(KC_RSHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RSHIFT); break;
    }
    dance_state[21].step = 0;
}
void on_dance_41(qk_tap_dance_state_t *state, void *user_data);
void dance_41_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_41_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_41(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LSHIFT);
        tap_code16(KC_LSHIFT);
        tap_code16(KC_LSHIFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LSHIFT);
    }
}

void dance_41_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[22].step = dance_step(state);
    switch (dance_state[22].step) {
        case SINGLE_TAP: register_code16(KC_LSHIFT); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: layer_move(9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LSHIFT); register_code16(KC_LSHIFT);
    }
}

void dance_41_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[22].step) {
        case SINGLE_TAP: unregister_code16(KC_LSHIFT); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LSHIFT); break;
    }
    dance_state[22].step = 0;
}
void on_dance_47(qk_tap_dance_state_t *state, void *user_data);
void dance_47_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_47_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_47(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RSHIFT);
        tap_code16(KC_RSHIFT);
        tap_code16(KC_RSHIFT);
    }
    if(state->count > 3) {
        tap_code16(KC_RSHIFT);
    }
}

void dance_47_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[23].step = dance_step(state);
    switch (dance_state[23].step) {
        case SINGLE_TAP: register_code16(KC_RSHIFT); break;
        case SINGLE_HOLD: register_code16(KC_RSHIFT); break;
        case DOUBLE_TAP: layer_move(9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RSHIFT); register_code16(KC_RSHIFT);
    }
}

void dance_47_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[23].step) {
        case SINGLE_TAP: unregister_code16(KC_RSHIFT); break;
        case SINGLE_HOLD: unregister_code16(KC_RSHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RSHIFT); break;
    }
    dance_state[23].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_6] = ACTION_TAP_DANCE_TAP_HOLD(KC_PGUP, LSFT(KC_PGUP)),
        [DANCE_7] = ACTION_TAP_DANCE_TAP_HOLD(KC_DELETE, LALT(LCTL(KC_DELETE))),
        [DANCE_8] = ACTION_TAP_DANCE_TAP_HOLD(BP_COMM, BP_SCLN),
        [DANCE_9] = ACTION_TAP_DANCE_TAP_HOLD(KC_PGDOWN, LSFT(KC_PGDOWN)),
        [DANCE_10] = ACTION_TAP_DANCE_TAP_HOLD(BP_DOT, BP_COLN),
        [DANCE_24] = ACTION_TAP_DANCE_TAP_HOLD(BP_DOT, BP_EURO),
        [DANCE_25] = ACTION_TAP_DANCE_TAP_HOLD(BP_COMM, RALT(RSFT(BP_L))),
        [DANCE_26] = ACTION_TAP_DANCE_TAP_HOLD(BP_DOT, BP_EURO),
        [DANCE_27] = ACTION_TAP_DANCE_TAP_HOLD(BP_DEGR, RALT(BP_EGRV)),
        [DANCE_28] = ACTION_TAP_DANCE_TAP_HOLD(BP_COMM, RALT(RSFT(BP_L))),
        [DANCE_30] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMMA, KC_SCOLON),
        [DANCE_31] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, KC_COLN),
        [DANCE_33] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, RALT(KC_5)),
        [DANCE_34] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMMA, RALT(RSFT(KC_4))),
        [DANCE_35] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, RALT(KC_5)),
        [DANCE_36] = ACTION_TAP_DANCE_TAP_HOLD(LSFT(RALT(KC_SCOLON)), KC_GRAVE),
        [DANCE_37] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMMA, RALT(RSFT(KC_4))),
        [DANCE_39] = ACTION_TAP_DANCE_TAP_HOLD(FR_COMM, FR_SCLN),
        [DANCE_40] = ACTION_TAP_DANCE_TAP_HOLD(FR_DOT, FR_COLN),
        [DANCE_42] = ACTION_TAP_DANCE_TAP_HOLD(FR_DOT, FR_EURO),
        [DANCE_43] = ACTION_TAP_DANCE_TAP_HOLD(FR_COMM, FR_PND),
        [DANCE_44] = ACTION_TAP_DANCE_TAP_HOLD(FR_DOT, FR_EURO),
        [DANCE_45] = ACTION_TAP_DANCE_TAP_HOLD(FR_OVRR, FR_GRV),
        [DANCE_46] = ACTION_TAP_DANCE_TAP_HOLD(FR_COMM, FR_PND),
        [DANCE_48] = ACTION_TAP_DANCE_TAP_HOLD(KC_MEDIA_PREV_TRACK, KC_MEDIA_REWIND),
        [DANCE_49] = ACTION_TAP_DANCE_TAP_HOLD(KC_MEDIA_NEXT_TRACK, KC_MEDIA_FAST_FORWARD),
        [DANCE_50] = ACTION_TAP_DANCE_TAP_HOLD(KC_KP_DOT, KC_KP_COMMA),
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
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
        [DANCE_29] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_29, dance_29_finished, dance_29_reset),
        [DANCE_32] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_32, dance_32_finished, dance_32_reset),
        [DANCE_38] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_38, dance_38_finished, dance_38_reset),
        [DANCE_41] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_41, dance_41_finished, dance_41_reset),
        [DANCE_47] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_47, dance_47_finished, dance_47_reset),
};

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
               add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
               return true;

            // Keycodes that continue Caps Word, without shifting.
            case BP_1 ... BP_0:
            case KC_KP_1 ... KC_KP_0:
            case KC_KP_MINUS:
            case KC_BSPC:
            case KC_DEL:
            case BP_UNDS:
            case BP_MINS:
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
            case KC_A ... KC_Z:
               add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
               return true;

            // Keycodes that continue Caps Word, without shifting.
            case KC_1 ... KC_0:
            case KC_KP_1 ... KC_KP_0:
            case KC_KP_MINUS:
            case KC_BSPC:
            case KC_DEL:
            case KC_UNDS:
            case KC_MINS:
            case KC_CIRC:
            case KC_DQUO:
            case KC_QUOTE:
            case KC_GRAVE:
               return true;

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
            case KC_KP_MINUS:
            case KC_BSPC:
            case KC_DEL:
            case FR_UNDS:
            case FR_MINS:
               return true;

            default:
               return false;  // Deactivate Caps Word.
         }
      case 9:           // Keyboard
         switch (keycode) {
            // Keycodes that continue Caps Word, without shifting.
            case KC_KP_1 ... KC_KP_0:
            case KC_KP_MINUS:
            case KC_BSPC:
            case KC_DEL:
               return true;

            default: return false;  // Deactivate Caps Word.
         }
      default: return false;
   }

   return false;
}
