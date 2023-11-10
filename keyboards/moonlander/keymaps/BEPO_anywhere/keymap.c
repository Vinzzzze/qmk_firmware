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
  DANCE_21,
  DANCE_22,
  DANCE_28,
  DANCE_34,
  DANCE_35,
  DANCE_37,
  DANCE_38,
  DANCE_40,
  DANCE_41,
  DANCE_47,
  DANCE_53,
  DANCE_54,
  DANCE_56,
  DANCE_57,
  DANCE_59,
  DANCE_60,
  DANCE_66,
  DANCE_72,
  DANCE_73,
  DANCE_75,
  DANCE_76,
  DANCE_77,
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
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
  DANCE_23,
  DANCE_24,
  DANCE_25,
  DANCE_26,
  DANCE_27,
  DANCE_29,
  DANCE_30,
  DANCE_31,
  DANCE_32,
  DANCE_33,
  DANCE_36,
  DANCE_39,
  DANCE_42,
  DANCE_43,
  DANCE_44,
  DANCE_45,
  DANCE_46,
  DANCE_48,
  DANCE_49,
  DANCE_50,
  DANCE_51,
  DANCE_52,
  DANCE_55,
  DANCE_58,
  DANCE_61,
  DANCE_62,
  DANCE_63,
  DANCE_64,
  DANCE_65,
  DANCE_67,
  DANCE_68,
  DANCE_69,
  DANCE_70,
  DANCE_71,
  DANCE_74,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    TD(DANCE_0),    TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    TD(DANCE_5),    TO(9),                                          TD(DANCE_11),   TD(DANCE_12),   TD(DANCE_13),   TD(DANCE_14),   TD(DANCE_15),   TD(DANCE_16),   TD(DANCE_17),   
    KC_TAB,         BP_B,           BP_ECUT,        BP_P,           BP_O,           BP_EGRV,        KC_MS_WH_UP,                                    KC_MS_WH_DOWN,  BP_V,           BP_D,           BP_L,           BP_J,           BP_Z,           KC_UP,          
    KC_DELETE,      BP_A,           BP_U,           BP_I,           BP_E,           TD(DANCE_6),    KC_MS_WH_LEFT,                                                                  KC_MS_WH_RIGHT, BP_T,           BP_S,           BP_R,           BP_N,           BP_M,           KC_DOWN,        
    OSM(MOD_LSFT),  BP_AGRV,        BP_Y,           BP_X,           TD(DANCE_7),    BP_K,                                           BP_Q,           BP_G,           BP_H,           BP_F,           BP_CCED,        OSM(MOD_RSFT),  
    KC_LALT,        TD(DANCE_8),    TD(DANCE_9),    TT(2),          BP_C,           TD(DANCE_10),                                                                                                   TD(DANCE_19),   BP_W,           TT(1),          KC_LEFT,        KC_RIGHT,       TD(DANCE_18),   
    KC_ENTER,       KC_LCTRL,       KC_BSPACE,                      MT(MOD_RCTL, KC_ESCAPE),KC_RALT,        KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, BP_PIPE,        BP_AMPR,        BP_MINS,        BP_ASTR,        BP_LESS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, BP_GRTR,        BP_SLSH,        BP_PLUS,        BP_HASH,        BP_BSLS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, BP_6,           BP_4,           BP_8,           BP_0,           BP_2,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, BP_3,           BP_1,           BP_9,           BP_5,           BP_7,           KC_TRANSPARENT, 
    TD(DANCE_20),   BP_UNDS,        BP_LBRC,        BP_LPRN,        BP_EQL,         TD(DANCE_21),                                   TD(DANCE_22),   BP_PERC,        BP_RPRN,        BP_RBRC,        BP_EXLM,        CAPS_WORD,      
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, BP_DCRC,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, BP_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_3,        KC_KP_1,        KC_KP_9,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT, 
    KC_TRANSPARENT, TD(DANCE_23),   TD(DANCE_24),   TD(DANCE_25),   TD(DANCE_26),   TD(DANCE_27),   KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_29),   TD(DANCE_30),   TD(DANCE_31),   TD(DANCE_32),   TD(DANCE_33),   KC_TRANSPARENT, 
    KC_TRANSPARENT, BP_AT,          BP_TILD,        RALT(BP_COMM),  BP_APOS,        BP_LGIL,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, BP_RGIL,        BP_GRV,         BP_DQOT,        BP_DTRM,        TD(DANCE_34),   KC_TRANSPARENT, 
    KC_CAPSLOCK,    BP_QEST,        BP_LCBR,        RALT(LSFT(BP_P)),TD(DANCE_28),   RALT(BP_2),                                     RALT(BP_3),     TD(DANCE_35),   RALT(BP_DQOT),  BP_RCBR,        BP_UGRV,        TD(DANCE_36),   
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, BP_DCRC,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, BP_DLR,         ST_MACRO_0,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_B,           ST_MACRO_1,     KC_P,           KC_O,           ST_MACRO_2,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_V,           KC_D,           KC_L,           KC_J,           KC_Z,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_U,           KC_I,           KC_E,           TD(DANCE_37),   KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_T,           KC_S,           KC_R,           KC_N,           KC_M,           KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_3,     KC_Y,           KC_X,           TD(DANCE_38),   KC_K,                                           KC_Q,           KC_G,           KC_H,           KC_F,           ST_MACRO_4,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TT(5),          KC_C,           KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_W,           TT(4),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PIPE,        KC_AMPR,        KC_MINUS,       KC_ASTR,        KC_LABK,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_RABK,        KC_SLASH,       KC_PLUS,        KC_HASH,        KC_BSLASH,      KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_6,           KC_4,           KC_8,           KC_0,           KC_2,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_3,           KC_1,           KC_9,           KC_5,           KC_7,           KC_TRANSPARENT, 
    TD(DANCE_39),   KC_UNDS,        KC_LBRACKET,    KC_LPRN,        KC_EQUAL,       TD(DANCE_40),                                   TD(DANCE_41),   KC_PERC,        KC_RPRN,        KC_RBRACKET,    KC_EXLM,        CAPS_WORD,      
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_3,        KC_KP_1,        KC_KP_9,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT, 
    KC_TRANSPARENT, TD(DANCE_42),   TD(DANCE_43),   TD(DANCE_44),   TD(DANCE_45),   TD(DANCE_46),   KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_48),   TD(DANCE_49),   TD(DANCE_50),   TD(DANCE_51),   TD(DANCE_52),   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_AT,          ST_MACRO_5,     ST_MACRO_6,     KC_QUOTE,       RALT(KC_LBRACKET),KC_TRANSPARENT,                                                                 KC_TRANSPARENT, RALT(KC_RBRACKET),ST_MACRO_8,     ST_MACRO_9,     KC_DQUO,        TD(DANCE_53),   KC_TRANSPARENT, 
    KC_CAPSLOCK,    KC_QUES,        KC_LCBR,        RALT(RSFT(KC_S)),TD(DANCE_47),   ST_MACRO_7,                                     ST_MACRO_10,    TD(DANCE_54),   ST_MACRO_11,    KC_RCBR,        ST_MACRO_12,    TD(DANCE_55),   
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_DLR,         RALT(KC_M),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_B,           FR_EACU,        KC_P,           KC_O,           FR_EGRV,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_V,           KC_D,           KC_L,           KC_J,           FR_Z,           KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_A,           KC_U,           KC_I,           KC_E,           TD(DANCE_56),   KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_T,           KC_S,           KC_R,           KC_N,           FR_M,           KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_AGRV,        KC_Y,           KC_X,           TD(DANCE_57),   KC_K,                                           FR_Q,           KC_G,           KC_H,           KC_F,           FR_CCED,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TT(8),          KC_C,           KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, FR_W,           TT(7),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_PIPE,        FR_AMP,         FR_MINS,        FR_ASTR,        FR_LESS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, FR_GRTR,        FR_SLSH,        FR_PLUS,        FR_HASH,        FR_BSLS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_6,           FR_4,           FR_8,           FR_0,           FR_2,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, FR_3,           FR_1,           FR_9,           FR_5,           FR_7,           KC_TRANSPARENT, 
    TD(DANCE_58),   FR_UNDS,        FR_LBRC,        FR_LPRN,        FR_EQL,         TD(DANCE_59),                                   TD(DANCE_60),   FR_PERC,        FR_RPRN,        FR_RBRC,        FR_EXLM,        CAPS_WORD,      
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, FR_CIRC,        KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, FR_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_3,        KC_KP_1,        KC_KP_9,        KC_KP_5,        KC_KP_7,        KC_TRANSPARENT, 
    KC_TRANSPARENT, TD(DANCE_61),   TD(DANCE_62),   TD(DANCE_63),   TD(DANCE_64),   TD(DANCE_65),   KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_67),   TD(DANCE_68),   TD(DANCE_69),   TD(DANCE_70),   TD(DANCE_71),   KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_AT,          FR_TILD,        FR_APOS,        FR_SUP2,        ST_MACRO_13,    KC_TRANSPARENT,                                                                 KC_TRANSPARENT, ST_MACRO_15,    ST_MACRO_16,    FR_DQUO,        FR_UMLT,        TD(DANCE_72),   KC_TRANSPARENT, 
    KC_CAPSLOCK,    FR_QUES,        FR_LCBR,        FR_SECT,        TD(DANCE_66),   ST_MACRO_14,                                    ST_MACRO_17,    TD(DANCE_73),   ST_MACRO_18,    FR_RCBR,        FR_UGRV,        TD(DANCE_74),   
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, FR_CCIRC,       KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, FR_DLR,         FR_MU,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [9] = LAYOUT_moonlander(
    TD(DANCE_75),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPACE,                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_76),   
    KC_TRANSPARENT, TO(0),          KC_PGUP,        KC_UP,          KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,DYN_MACRO_PLAY1,                                DYN_MACRO_PLAY2,KC_KP_SLASH,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, KC_MS_UP,       
    KC_TRANSPARENT, TO(6),          KC_LEFT,        KC_HOME,        KC_RIGHT,       KC_AUDIO_VOL_DOWN,KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_KP_MINUS,    KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_MS_DOWN,     
    KC_LSHIFT,      KC_NUMLOCK,     KC_PGDOWN,      KC_DOWN,        KC_END,         KC_LALT,                                        TO(3),          KC_KP_1,        KC_KP_2,        KC_KP_3,        TD(DANCE_77),   KC_RSHIFT,      
    RGB_TOG,        KC_MS_WH_UP,    KC_MS_WH_DOWN,  RESET,          DYN_REC_STOP,   KC_MS_BTN1,                                                                                                     KC_MS_BTN2,     KC_MS_BTN3,     KC_KP_0,        KC_MS_LEFT,     KC_MS_RIGHT,    TOGGLE_LAYER_COLOR,
    KC_KP_ENTER,    MT(MOD_LCTL, KC_ESCAPE),DYN_REC_START1,                 DYN_REC_START2, MT(MOD_RALT, KC_ESCAPE),KC_TRANSPARENT
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {188,255,255}, {74,255,255}, {225,224,255}, {0,245,245}, {0,245,245}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {41,255,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {41,255,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {0,245,245}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {46,215,244}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {46,215,244}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {74,255,255}, {0,245,245}, {19,245,255}, {0,245,245} },

    [1] = { {188,255,255}, {168,218,204}, {225,224,255}, {0,245,245}, {0,245,245}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {41,255,255}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {41,255,255}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {0,0,255}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {168,218,204}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {0,245,245}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {46,215,244}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {46,215,244}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {0,0,255}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {168,218,204}, {19,245,255}, {168,218,204}, {78,218,204}, {168,218,204}, {188,255,255}, {41,255,255}, {41,255,255}, {168,218,204}, {0,245,245}, {19,245,255}, {0,245,245} },

    [2] = { {188,255,255}, {62,219,138}, {225,224,255}, {0,245,245}, {0,245,245}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {41,255,255}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {41,255,255}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {0,0,255}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {0,245,245}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {46,215,244}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {46,215,244}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {168,218,204}, {19,245,255}, {62,219,138}, {62,219,138}, {188,255,255}, {41,255,255}, {41,255,255}, {62,219,138}, {0,245,245}, {19,245,255}, {0,245,245} },

    [3] = { {188,255,255}, {131,255,255}, {225,224,255}, {0,245,245}, {0,245,245}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {41,255,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {41,255,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {19,245,255}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {46,215,244}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {46,215,244}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,0,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {131,255,255}, {0,245,245}, {19,245,255}, {0,245,245} },

    [4] = { {188,255,255}, {1,181,132}, {225,224,255}, {0,245,245}, {0,245,245}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {41,255,255}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {41,255,255}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {0,0,255}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {1,181,132}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {0,245,245}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {46,215,244}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {46,215,244}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {0,0,255}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {1,181,132}, {19,245,255}, {1,181,132}, {74,255,255}, {1,181,132}, {188,255,255}, {41,255,255}, {41,255,255}, {1,181,132}, {0,245,245}, {19,245,255}, {0,245,245} },

    [5] = { {188,255,255}, {74,255,255}, {225,224,255}, {0,245,245}, {0,245,245}, {1,181,132}, {19,245,255}, {74,255,255}, {74,255,255}, {41,255,255}, {1,181,132}, {19,245,255}, {74,255,255}, {74,255,255}, {46,215,244}, {1,181,132}, {19,245,255}, {74,255,255}, {74,255,255}, {0,0,255}, {1,181,132}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {1,181,132}, {19,245,255}, {74,255,255}, {74,255,255}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {0,245,245}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {1,181,132}, {19,245,255}, {74,255,255}, {74,255,255}, {46,215,244}, {1,181,132}, {19,245,255}, {74,255,255}, {74,255,255}, {46,215,244}, {1,181,132}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {1,181,132}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {1,181,132}, {19,245,255}, {74,255,255}, {74,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {74,255,255}, {0,245,245}, {19,245,255}, {0,245,245} },

    [6] = { {62,219,138}, {198,255,255}, {74,255,255}, {0,245,245}, {0,245,245}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {41,255,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {41,255,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {0,0,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {0,0,255}, {41,255,255}, {41,255,255}, {74,255,255}, {19,245,255}, {74,255,255}, {0,245,245}, {62,219,138}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {46,215,244}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {46,215,244}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {0,0,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {62,219,138}, {41,255,255}, {41,255,255}, {198,255,255}, {0,245,245}, {19,245,255}, {0,245,245} },

    [7] = { {188,255,255}, {62,219,138}, {225,224,255}, {0,245,245}, {0,245,245}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {41,255,255}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {41,255,255}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {0,0,255}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {62,219,138}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {0,245,245}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {46,215,244}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {46,215,244}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {0,0,255}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {62,219,138}, {19,245,255}, {62,219,138}, {131,255,255}, {62,219,138}, {188,255,255}, {41,255,255}, {41,255,255}, {62,219,138}, {0,245,245}, {19,245,255}, {0,245,245} },

    [8] = { {188,255,255}, {131,255,255}, {225,224,255}, {0,245,245}, {0,245,245}, {62,219,138}, {19,245,255}, {131,255,255}, {131,255,255}, {41,255,255}, {62,219,138}, {19,245,255}, {131,255,255}, {131,255,255}, {41,255,255}, {62,219,138}, {19,245,255}, {131,255,255}, {131,255,255}, {0,0,255}, {62,219,138}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {62,219,138}, {19,245,255}, {131,255,255}, {131,255,255}, {0,0,255}, {41,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {225,224,255}, {0,245,245}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {225,224,255}, {62,219,138}, {19,245,255}, {131,255,255}, {131,255,255}, {46,215,244}, {62,219,138}, {19,245,255}, {131,255,255}, {131,255,255}, {46,215,244}, {62,219,138}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {62,219,138}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {62,219,138}, {19,245,255}, {131,255,255}, {131,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {131,255,255}, {0,245,245}, {19,245,255}, {0,245,245} },

    [9] = { {188,255,255}, {62,219,138}, {225,224,255}, {0,245,245}, {19,245,255}, {19,245,255}, {0,0,255}, {0,0,255}, {0,245,245}, {41,255,255}, {19,245,255}, {0,245,245}, {19,245,255}, {0,245,245}, {41,255,255}, {19,245,255}, {19,245,255}, {0,245,245}, {19,245,255}, {131,255,255}, {19,245,255}, {0,245,245}, {19,245,255}, {0,245,245}, {0,245,245}, {19,245,255}, {131,255,255}, {131,255,255}, {0,245,245}, {225,224,255}, {74,255,255}, {41,255,255}, {225,224,255}, {19,245,255}, {0,245,245}, {41,255,255}, {188,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {19,245,255}, {1,181,132}, {1,181,132}, {1,181,132}, {46,215,244}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {41,255,255}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {41,255,255}, {19,245,255}, {1,181,132}, {1,181,132}, {0,0,255}, {188,255,255}, {74,255,255}, {41,255,255}, {62,219,138}, {0,245,245}, {0,245,245}, {41,255,255} },

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
    case TD(DANCE_21):
    case TD(DANCE_22):
    case TD(DANCE_28):
    case TD(DANCE_34):
    case TD(DANCE_35):
    case TD(DANCE_37):
    case TD(DANCE_38):
    case TD(DANCE_40):
    case TD(DANCE_41):
    case TD(DANCE_47):
    case TD(DANCE_53):
    case TD(DANCE_54):
    case TD(DANCE_56):
    case TD(DANCE_57):
    case TD(DANCE_59):
    case TD(DANCE_60):
    case TD(DANCE_66):
    case TD(DANCE_72):
    case TD(DANCE_73):
    case TD(DANCE_75):
    case TD(DANCE_76):
    case TD(DANCE_77):
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

static tap dance_state[52];

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
        case DOUBLE_HOLD: register_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_F6); break;
        case DOUBLE_HOLD: unregister_code16(KC_WWW_HOME); break;
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
        case DOUBLE_TAP: register_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_MAIL); break;
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
        case DOUBLE_TAP: register_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F8); register_code16(KC_F8);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_MY_COMPUTER); break;
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
        case DOUBLE_TAP: register_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F10); register_code16(KC_F10);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_MUTE); break;
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
void on_dance_10(qk_tap_dance_state_t *state, void *user_data);
void dance_10_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_10_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_10(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LGUI);
        tap_code16(KC_LGUI);
        tap_code16(KC_LGUI);
    }
    if(state->count > 3) {
        tap_code16(KC_LGUI);
    }
}

void dance_10_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_LGUI); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LGUI); register_code16(KC_LGUI);
    }
}

void dance_10_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_LGUI); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LGUI); break;
    }
    dance_state[6].step = 0;
}
void on_dance_11(qk_tap_dance_state_t *state, void *user_data);
void dance_11_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_11_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_11(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_EJECT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_11_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_EJECT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[7].step = 0;
}
void on_dance_12(qk_tap_dance_state_t *state, void *user_data);
void dance_12_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_12_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_12(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F3);
        tap_code16(KC_F3);
        tap_code16(KC_F3);
    }
    if(state->count > 3) {
        tap_code16(KC_F3);
    }
}

void dance_12_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
    }
}

void dance_12_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
    }
    dance_state[8].step = 0;
}
void on_dance_13(qk_tap_dance_state_t *state, void *user_data);
void dance_13_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_13_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_13(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F1);
        tap_code16(KC_F1);
        tap_code16(KC_F1);
    }
    if(state->count > 3) {
        tap_code16(KC_F1);
    }
}

void dance_13_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
    }
}

void dance_13_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
    }
    dance_state[9].step = 0;
}
void on_dance_14(qk_tap_dance_state_t *state, void *user_data);
void dance_14_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_14_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_14(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if(state->count > 3) {
        tap_code16(KC_F9);
    }
}

void dance_14_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}

void dance_14_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[10].step = 0;
}
void on_dance_15(qk_tap_dance_state_t *state, void *user_data);
void dance_15_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_15_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_15(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_15_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_15_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[11].step = 0;
}
void on_dance_16(qk_tap_dance_state_t *state, void *user_data);
void dance_16_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_16_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_16(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if(state->count > 3) {
        tap_code16(KC_F7);
    }
}

void dance_16_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}

void dance_16_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[12].step = 0;
}
void on_dance_17(qk_tap_dance_state_t *state, void *user_data);
void dance_17_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_17_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_17(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
        tap_code16(KC_DELETE);
    }
    if(state->count > 3) {
        tap_code16(KC_DELETE);
    }
}

void dance_17_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_DELETE); break;
        case SINGLE_HOLD: register_code16(KC_DELETE); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DELETE); register_code16(KC_DELETE);
    }
}

void dance_17_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_DELETE); break;
        case SINGLE_HOLD: unregister_code16(KC_DELETE); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DELETE); break;
    }
    dance_state[13].step = 0;
}
void on_dance_18(qk_tap_dance_state_t *state, void *user_data);
void dance_18_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_18_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_18(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_INSERT));
        tap_code16(LSFT(KC_INSERT));
        tap_code16(LSFT(KC_INSERT));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_INSERT));
    }
}

void dance_18_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_INSERT)); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_INSERT)); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_INSERT)); register_code16(LSFT(KC_INSERT));
    }
}

void dance_18_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_INSERT)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_INSERT)); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_INSERT)); break;
    }
    dance_state[14].step = 0;
}
void on_dance_19(qk_tap_dance_state_t *state, void *user_data);
void dance_19_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_19_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_19(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RGUI);
        tap_code16(KC_RGUI);
        tap_code16(KC_RGUI);
    }
    if(state->count > 3) {
        tap_code16(KC_RGUI);
    }
}

void dance_19_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(KC_RGUI); break;
        case SINGLE_HOLD: register_code16(KC_RGUI); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_UP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RGUI); register_code16(KC_RGUI);
    }
}

void dance_19_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(KC_RGUI); break;
        case SINGLE_HOLD: unregister_code16(KC_RGUI); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_UP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RGUI); break;
    }
    dance_state[15].step = 0;
}
void on_dance_20(qk_tap_dance_state_t *state, void *user_data);
void dance_20_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_20_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_20(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LSHIFT);
        tap_code16(KC_LSHIFT);
        tap_code16(KC_LSHIFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LSHIFT);
    }
}

void dance_20_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP: register_code16(KC_LSHIFT); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: layer_move(9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LSHIFT); register_code16(KC_LSHIFT);
    }
}

void dance_20_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP: unregister_code16(KC_LSHIFT); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LSHIFT); break;
    }
    dance_state[16].step = 0;
}
void on_dance_23(qk_tap_dance_state_t *state, void *user_data);
void dance_23_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_23_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_23(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F6);
        tap_code16(KC_F6);
        tap_code16(KC_F6);
    }
    if(state->count > 3) {
        tap_code16(KC_F6);
    }
}

void dance_23_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(KC_F6); break;
        case DOUBLE_TAP: register_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
    }
}

void dance_23_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[17].step = 0;
}
void on_dance_24(qk_tap_dance_state_t *state, void *user_data);
void dance_24_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_24_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_24(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}

void dance_24_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void dance_24_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[18].step = 0;
}
void on_dance_25(qk_tap_dance_state_t *state, void *user_data);
void dance_25_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_25_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_25(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F8);
        tap_code16(KC_F8);
        tap_code16(KC_F8);
    }
    if(state->count > 3) {
        tap_code16(KC_F8);
    }
}

void dance_25_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP: register_code16(KC_F8); break;
        case DOUBLE_TAP: register_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F8); register_code16(KC_F8);
    }
}

void dance_25_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F8); break;
    }
    dance_state[19].step = 0;
}
void on_dance_26(qk_tap_dance_state_t *state, void *user_data);
void dance_26_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_26_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_26(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F10);
        tap_code16(KC_F10);
        tap_code16(KC_F10);
    }
    if(state->count > 3) {
        tap_code16(KC_F10);
    }
}

void dance_26_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP: register_code16(KC_F10); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F10); register_code16(KC_F10);
    }
}

void dance_26_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F10); break;
    }
    dance_state[20].step = 0;
}
void on_dance_27(qk_tap_dance_state_t *state, void *user_data);
void dance_27_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_27_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_27(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F2);
        tap_code16(KC_F2);
        tap_code16(KC_F2);
    }
    if(state->count > 3) {
        tap_code16(KC_F2);
    }
}

void dance_27_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[21].step = dance_step(state);
    switch (dance_state[21].step) {
        case SINGLE_TAP: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F2); register_code16(KC_F2);
    }
}

void dance_27_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[21].step) {
        case SINGLE_TAP: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F2); break;
    }
    dance_state[21].step = 0;
}
void on_dance_29(qk_tap_dance_state_t *state, void *user_data);
void dance_29_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_29_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_29(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F3);
        tap_code16(KC_F3);
        tap_code16(KC_F3);
    }
    if(state->count > 3) {
        tap_code16(KC_F3);
    }
}

void dance_29_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[22].step = dance_step(state);
    switch (dance_state[22].step) {
        case SINGLE_TAP: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
    }
}

void dance_29_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[22].step) {
        case SINGLE_TAP: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
    }
    dance_state[22].step = 0;
}
void on_dance_30(qk_tap_dance_state_t *state, void *user_data);
void dance_30_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_30_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_30(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F1);
        tap_code16(KC_F1);
        tap_code16(KC_F1);
    }
    if(state->count > 3) {
        tap_code16(KC_F1);
    }
}

void dance_30_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[23].step = dance_step(state);
    switch (dance_state[23].step) {
        case SINGLE_TAP: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
    }
}

void dance_30_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[23].step) {
        case SINGLE_TAP: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
    }
    dance_state[23].step = 0;
}
void on_dance_31(qk_tap_dance_state_t *state, void *user_data);
void dance_31_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_31_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_31(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if(state->count > 3) {
        tap_code16(KC_F9);
    }
}

void dance_31_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[24].step = dance_step(state);
    switch (dance_state[24].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}

void dance_31_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[24].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[24].step = 0;
}
void on_dance_32(qk_tap_dance_state_t *state, void *user_data);
void dance_32_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_32_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_32(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_32_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[25].step = dance_step(state);
    switch (dance_state[25].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_32_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[25].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[25].step = 0;
}
void on_dance_33(qk_tap_dance_state_t *state, void *user_data);
void dance_33_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_33_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_33(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if(state->count > 3) {
        tap_code16(KC_F7);
    }
}

void dance_33_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[26].step = dance_step(state);
    switch (dance_state[26].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}

void dance_33_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[26].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[26].step = 0;
}
void on_dance_36(qk_tap_dance_state_t *state, void *user_data);
void dance_36_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_36_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_36(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RSHIFT);
        tap_code16(KC_RSHIFT);
        tap_code16(KC_RSHIFT);
    }
    if(state->count > 3) {
        tap_code16(KC_RSHIFT);
    }
}

void dance_36_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[27].step = dance_step(state);
    switch (dance_state[27].step) {
        case SINGLE_TAP: register_code16(KC_RSHIFT); break;
        case SINGLE_HOLD: register_code16(KC_RSHIFT); break;
        case DOUBLE_TAP: layer_move(9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RSHIFT); register_code16(KC_RSHIFT);
    }
}

void dance_36_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[27].step) {
        case SINGLE_TAP: unregister_code16(KC_RSHIFT); break;
        case SINGLE_HOLD: unregister_code16(KC_RSHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RSHIFT); break;
    }
    dance_state[27].step = 0;
}
void on_dance_39(qk_tap_dance_state_t *state, void *user_data);
void dance_39_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_39_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_39(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LSHIFT);
        tap_code16(KC_LSHIFT);
        tap_code16(KC_LSHIFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LSHIFT);
    }
}

void dance_39_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[28].step = dance_step(state);
    switch (dance_state[28].step) {
        case SINGLE_TAP: register_code16(KC_LSHIFT); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: layer_move(9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LSHIFT); register_code16(KC_LSHIFT);
    }
}

void dance_39_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[28].step) {
        case SINGLE_TAP: unregister_code16(KC_LSHIFT); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LSHIFT); break;
    }
    dance_state[28].step = 0;
}
void on_dance_42(qk_tap_dance_state_t *state, void *user_data);
void dance_42_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_42_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_42(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F6);
        tap_code16(KC_F6);
        tap_code16(KC_F6);
    }
    if(state->count > 3) {
        tap_code16(KC_F6);
    }
}

void dance_42_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[29].step = dance_step(state);
    switch (dance_state[29].step) {
        case SINGLE_TAP: register_code16(KC_F6); break;
        case DOUBLE_TAP: register_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
    }
}

void dance_42_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[29].step) {
        case SINGLE_TAP: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[29].step = 0;
}
void on_dance_43(qk_tap_dance_state_t *state, void *user_data);
void dance_43_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_43_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_43(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}

void dance_43_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[30].step = dance_step(state);
    switch (dance_state[30].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void dance_43_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[30].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[30].step = 0;
}
void on_dance_44(qk_tap_dance_state_t *state, void *user_data);
void dance_44_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_44_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_44(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F8);
        tap_code16(KC_F8);
        tap_code16(KC_F8);
    }
    if(state->count > 3) {
        tap_code16(KC_F8);
    }
}

void dance_44_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[31].step = dance_step(state);
    switch (dance_state[31].step) {
        case SINGLE_TAP: register_code16(KC_F8); break;
        case DOUBLE_TAP: register_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F8); register_code16(KC_F8);
    }
}

void dance_44_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[31].step) {
        case SINGLE_TAP: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F8); break;
    }
    dance_state[31].step = 0;
}
void on_dance_45(qk_tap_dance_state_t *state, void *user_data);
void dance_45_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_45_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_45(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F10);
        tap_code16(KC_F10);
        tap_code16(KC_F10);
    }
    if(state->count > 3) {
        tap_code16(KC_F10);
    }
}

void dance_45_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[32].step = dance_step(state);
    switch (dance_state[32].step) {
        case SINGLE_TAP: register_code16(KC_F10); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F10); register_code16(KC_F10);
    }
}

void dance_45_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[32].step) {
        case SINGLE_TAP: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F10); break;
    }
    dance_state[32].step = 0;
}
void on_dance_46(qk_tap_dance_state_t *state, void *user_data);
void dance_46_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_46_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_46(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F2);
        tap_code16(KC_F2);
        tap_code16(KC_F2);
    }
    if(state->count > 3) {
        tap_code16(KC_F2);
    }
}

void dance_46_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[33].step = dance_step(state);
    switch (dance_state[33].step) {
        case SINGLE_TAP: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F2); register_code16(KC_F2);
    }
}

void dance_46_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[33].step) {
        case SINGLE_TAP: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F2); break;
    }
    dance_state[33].step = 0;
}
void on_dance_48(qk_tap_dance_state_t *state, void *user_data);
void dance_48_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_48_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_48(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F3);
        tap_code16(KC_F3);
        tap_code16(KC_F3);
    }
    if(state->count > 3) {
        tap_code16(KC_F3);
    }
}

void dance_48_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[34].step = dance_step(state);
    switch (dance_state[34].step) {
        case SINGLE_TAP: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
    }
}

void dance_48_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[34].step) {
        case SINGLE_TAP: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
    }
    dance_state[34].step = 0;
}
void on_dance_49(qk_tap_dance_state_t *state, void *user_data);
void dance_49_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_49_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_49(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F1);
        tap_code16(KC_F1);
        tap_code16(KC_F1);
    }
    if(state->count > 3) {
        tap_code16(KC_F1);
    }
}

void dance_49_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[35].step = dance_step(state);
    switch (dance_state[35].step) {
        case SINGLE_TAP: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
    }
}

void dance_49_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[35].step) {
        case SINGLE_TAP: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
    }
    dance_state[35].step = 0;
}
void on_dance_50(qk_tap_dance_state_t *state, void *user_data);
void dance_50_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_50_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_50(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if(state->count > 3) {
        tap_code16(KC_F9);
    }
}

void dance_50_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[36].step = dance_step(state);
    switch (dance_state[36].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}

void dance_50_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[36].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[36].step = 0;
}
void on_dance_51(qk_tap_dance_state_t *state, void *user_data);
void dance_51_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_51_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_51(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_51_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[37].step = dance_step(state);
    switch (dance_state[37].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_51_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[37].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[37].step = 0;
}
void on_dance_52(qk_tap_dance_state_t *state, void *user_data);
void dance_52_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_52_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_52(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if(state->count > 3) {
        tap_code16(KC_F7);
    }
}

void dance_52_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[38].step = dance_step(state);
    switch (dance_state[38].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}

void dance_52_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[38].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[38].step = 0;
}
void on_dance_55(qk_tap_dance_state_t *state, void *user_data);
void dance_55_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_55_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_55(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RSHIFT);
        tap_code16(KC_RSHIFT);
        tap_code16(KC_RSHIFT);
    }
    if(state->count > 3) {
        tap_code16(KC_RSHIFT);
    }
}

void dance_55_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[39].step = dance_step(state);
    switch (dance_state[39].step) {
        case SINGLE_TAP: register_code16(KC_RSHIFT); break;
        case SINGLE_HOLD: register_code16(KC_RSHIFT); break;
        case DOUBLE_TAP: layer_move(9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RSHIFT); register_code16(KC_RSHIFT);
    }
}

void dance_55_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[39].step) {
        case SINGLE_TAP: unregister_code16(KC_RSHIFT); break;
        case SINGLE_HOLD: unregister_code16(KC_RSHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RSHIFT); break;
    }
    dance_state[39].step = 0;
}
void on_dance_58(qk_tap_dance_state_t *state, void *user_data);
void dance_58_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_58_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_58(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LSHIFT);
        tap_code16(KC_LSHIFT);
        tap_code16(KC_LSHIFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LSHIFT);
    }
}

void dance_58_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[40].step = dance_step(state);
    switch (dance_state[40].step) {
        case SINGLE_TAP: register_code16(KC_LSHIFT); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: layer_move(9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LSHIFT); register_code16(KC_LSHIFT);
    }
}

void dance_58_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[40].step) {
        case SINGLE_TAP: unregister_code16(KC_LSHIFT); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LSHIFT); break;
    }
    dance_state[40].step = 0;
}
void on_dance_61(qk_tap_dance_state_t *state, void *user_data);
void dance_61_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_61_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_61(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F6);
        tap_code16(KC_F6);
        tap_code16(KC_F6);
    }
    if(state->count > 3) {
        tap_code16(KC_F6);
    }
}

void dance_61_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[41].step = dance_step(state);
    switch (dance_state[41].step) {
        case SINGLE_TAP: register_code16(KC_F6); break;
        case DOUBLE_TAP: register_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
    }
}

void dance_61_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[41].step) {
        case SINGLE_TAP: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[41].step = 0;
}
void on_dance_62(qk_tap_dance_state_t *state, void *user_data);
void dance_62_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_62_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_62(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}

void dance_62_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[42].step = dance_step(state);
    switch (dance_state[42].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void dance_62_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[42].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[42].step = 0;
}
void on_dance_63(qk_tap_dance_state_t *state, void *user_data);
void dance_63_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_63_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_63(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F8);
        tap_code16(KC_F8);
        tap_code16(KC_F8);
    }
    if(state->count > 3) {
        tap_code16(KC_F8);
    }
}

void dance_63_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[43].step = dance_step(state);
    switch (dance_state[43].step) {
        case SINGLE_TAP: register_code16(KC_F8); break;
        case DOUBLE_TAP: register_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F8); register_code16(KC_F8);
    }
}

void dance_63_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[43].step) {
        case SINGLE_TAP: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F8); break;
    }
    dance_state[43].step = 0;
}
void on_dance_64(qk_tap_dance_state_t *state, void *user_data);
void dance_64_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_64_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_64(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F10);
        tap_code16(KC_F10);
        tap_code16(KC_F10);
    }
    if(state->count > 3) {
        tap_code16(KC_F10);
    }
}

void dance_64_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[44].step = dance_step(state);
    switch (dance_state[44].step) {
        case SINGLE_TAP: register_code16(KC_F10); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F10); register_code16(KC_F10);
    }
}

void dance_64_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[44].step) {
        case SINGLE_TAP: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F10); break;
    }
    dance_state[44].step = 0;
}
void on_dance_65(qk_tap_dance_state_t *state, void *user_data);
void dance_65_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_65_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_65(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F2);
        tap_code16(KC_F2);
        tap_code16(KC_F2);
    }
    if(state->count > 3) {
        tap_code16(KC_F2);
    }
}

void dance_65_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[45].step = dance_step(state);
    switch (dance_state[45].step) {
        case SINGLE_TAP: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F2); register_code16(KC_F2);
    }
}

void dance_65_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[45].step) {
        case SINGLE_TAP: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F2); break;
    }
    dance_state[45].step = 0;
}
void on_dance_67(qk_tap_dance_state_t *state, void *user_data);
void dance_67_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_67_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_67(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F3);
        tap_code16(KC_F3);
        tap_code16(KC_F3);
    }
    if(state->count > 3) {
        tap_code16(KC_F3);
    }
}

void dance_67_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[46].step = dance_step(state);
    switch (dance_state[46].step) {
        case SINGLE_TAP: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
    }
}

void dance_67_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[46].step) {
        case SINGLE_TAP: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
    }
    dance_state[46].step = 0;
}
void on_dance_68(qk_tap_dance_state_t *state, void *user_data);
void dance_68_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_68_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_68(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F1);
        tap_code16(KC_F1);
        tap_code16(KC_F1);
    }
    if(state->count > 3) {
        tap_code16(KC_F1);
    }
}

void dance_68_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[47].step = dance_step(state);
    switch (dance_state[47].step) {
        case SINGLE_TAP: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
    }
}

void dance_68_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[47].step) {
        case SINGLE_TAP: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
    }
    dance_state[47].step = 0;
}
void on_dance_69(qk_tap_dance_state_t *state, void *user_data);
void dance_69_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_69_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_69(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if(state->count > 3) {
        tap_code16(KC_F9);
    }
}

void dance_69_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[48].step = dance_step(state);
    switch (dance_state[48].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}

void dance_69_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[48].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[48].step = 0;
}
void on_dance_70(qk_tap_dance_state_t *state, void *user_data);
void dance_70_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_70_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_70(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_70_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[49].step = dance_step(state);
    switch (dance_state[49].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_70_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[49].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[49].step = 0;
}
void on_dance_71(qk_tap_dance_state_t *state, void *user_data);
void dance_71_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_71_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_71(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if(state->count > 3) {
        tap_code16(KC_F7);
    }
}

void dance_71_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[50].step = dance_step(state);
    switch (dance_state[50].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}

void dance_71_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[50].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[50].step = 0;
}
void on_dance_74(qk_tap_dance_state_t *state, void *user_data);
void dance_74_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_74_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_74(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RSHIFT);
        tap_code16(KC_RSHIFT);
        tap_code16(KC_RSHIFT);
    }
    if(state->count > 3) {
        tap_code16(KC_RSHIFT);
    }
}

void dance_74_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[51].step = dance_step(state);
    switch (dance_state[51].step) {
        case SINGLE_TAP: register_code16(KC_RSHIFT); break;
        case SINGLE_HOLD: register_code16(KC_RSHIFT); break;
        case DOUBLE_TAP: layer_move(9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RSHIFT); register_code16(KC_RSHIFT);
    }
}

void dance_74_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[51].step) {
        case SINGLE_TAP: unregister_code16(KC_RSHIFT); break;
        case SINGLE_HOLD: unregister_code16(KC_RSHIFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RSHIFT); break;
    }
    dance_state[51].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_6] = ACTION_TAP_DANCE_TAP_HOLD(BP_COMM, BP_SCLN),
        [DANCE_7] = ACTION_TAP_DANCE_TAP_HOLD(BP_DOT, BP_COLN),
        [DANCE_8] = ACTION_TAP_DANCE_TAP_HOLD(KC_PGUP, KC_HOME),
        [DANCE_9] = ACTION_TAP_DANCE_TAP_HOLD(KC_PGDOWN, KC_END),
        [DANCE_21] = ACTION_TAP_DANCE_TAP_HOLD(BP_DOT, BP_EURO),
        [DANCE_22] = ACTION_TAP_DANCE_TAP_HOLD(BP_COMM, RALT(RSFT(BP_L))),
        [DANCE_28] = ACTION_TAP_DANCE_TAP_HOLD(BP_DOT, BP_EURO),
        [DANCE_34] = ACTION_TAP_DANCE_TAP_HOLD(BP_DEGR, RALT(BP_EGRV)),
        [DANCE_35] = ACTION_TAP_DANCE_TAP_HOLD(BP_COMM, RALT(RSFT(BP_L))),
        [DANCE_37] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMMA, KC_SCOLON),
        [DANCE_38] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, KC_COLN),
        [DANCE_40] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, RALT(KC_5)),
        [DANCE_41] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMMA, RALT(RSFT(KC_4))),
        [DANCE_47] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, RALT(KC_5)),
        [DANCE_53] = ACTION_TAP_DANCE_TAP_HOLD(LSFT(RALT(KC_SCOLON)), KC_GRAVE),
        [DANCE_54] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMMA, RALT(RSFT(KC_4))),
        [DANCE_56] = ACTION_TAP_DANCE_TAP_HOLD(FR_COMM, FR_SCLN),
        [DANCE_57] = ACTION_TAP_DANCE_TAP_HOLD(FR_DOT, FR_COLN),
        [DANCE_59] = ACTION_TAP_DANCE_TAP_HOLD(FR_DOT, FR_EURO),
        [DANCE_60] = ACTION_TAP_DANCE_TAP_HOLD(FR_COMM, FR_PND),
        [DANCE_66] = ACTION_TAP_DANCE_TAP_HOLD(FR_DOT, FR_EURO),
        [DANCE_72] = ACTION_TAP_DANCE_TAP_HOLD(FR_OVRR, FR_GRV),
        [DANCE_73] = ACTION_TAP_DANCE_TAP_HOLD(FR_COMM, FR_PND),
        [DANCE_75] = ACTION_TAP_DANCE_TAP_HOLD(KC_MEDIA_PREV_TRACK, KC_MEDIA_REWIND),
        [DANCE_76] = ACTION_TAP_DANCE_TAP_HOLD(KC_MEDIA_NEXT_TRACK, KC_MEDIA_FAST_FORWARD),
        [DANCE_77] = ACTION_TAP_DANCE_TAP_HOLD(KC_KP_DOT, KC_KP_COMMA),
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
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
        [DANCE_23] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_23, dance_23_finished, dance_23_reset),
        [DANCE_24] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_24, dance_24_finished, dance_24_reset),
        [DANCE_25] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_25, dance_25_finished, dance_25_reset),
        [DANCE_26] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_26, dance_26_finished, dance_26_reset),
        [DANCE_27] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_27, dance_27_finished, dance_27_reset),
        [DANCE_29] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_29, dance_29_finished, dance_29_reset),
        [DANCE_30] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_30, dance_30_finished, dance_30_reset),
        [DANCE_31] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_31, dance_31_finished, dance_31_reset),
        [DANCE_32] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_32, dance_32_finished, dance_32_reset),
        [DANCE_33] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_33, dance_33_finished, dance_33_reset),
        [DANCE_36] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_36, dance_36_finished, dance_36_reset),
        [DANCE_39] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_39, dance_39_finished, dance_39_reset),
        [DANCE_42] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_42, dance_42_finished, dance_42_reset),
        [DANCE_43] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_43, dance_43_finished, dance_43_reset),
        [DANCE_44] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_44, dance_44_finished, dance_44_reset),
        [DANCE_45] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_45, dance_45_finished, dance_45_reset),
        [DANCE_46] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_46, dance_46_finished, dance_46_reset),
        [DANCE_48] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_48, dance_48_finished, dance_48_reset),
        [DANCE_49] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_49, dance_49_finished, dance_49_reset),
        [DANCE_50] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_50, dance_50_finished, dance_50_reset),
        [DANCE_51] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_51, dance_51_finished, dance_51_reset),
        [DANCE_52] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_52, dance_52_finished, dance_52_reset),
        [DANCE_55] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_55, dance_55_finished, dance_55_reset),
        [DANCE_58] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_58, dance_58_finished, dance_58_reset),
        [DANCE_61] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_61, dance_61_finished, dance_61_reset),
        [DANCE_62] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_62, dance_62_finished, dance_62_reset),
        [DANCE_63] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_63, dance_63_finished, dance_63_reset),
        [DANCE_64] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_64, dance_64_finished, dance_64_reset),
        [DANCE_65] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_65, dance_65_finished, dance_65_reset),
        [DANCE_67] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_67, dance_67_finished, dance_67_reset),
        [DANCE_68] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_68, dance_68_finished, dance_68_reset),
        [DANCE_69] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_69, dance_69_finished, dance_69_reset),
        [DANCE_70] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_70, dance_70_finished, dance_70_reset),
        [DANCE_71] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_71, dance_71_finished, dance_71_reset),
        [DANCE_74] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_74, dance_74_finished, dance_74_reset),
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

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        ML_LED_5(led_state.num_lock);
        ML_LED_6(led_state.caps_lock);
    }
    return res;
}

extern bool is_launching;

layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);
    if (is_launching || !keyboard_config.led_level) return state;
    bool LED_1 = false;
    bool LED_2 = false;
    bool LED_4 = false;

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 1:
            LED_4 = true;
            break;
        case 2:
            LED_2 = true;
            break;
        case 3:
            break;
        case 4:
            LED_4 = true;
            break;
        case 5:
            LED_2 = true;
            break;
        case 6:
            break;
        case 7:
            LED_4 = true;
            break;
        case 8:
            LED_2 = true;
            break;
        case 9:
            LED_1 = true;
            break;
        default:
            break;
    }

    ML_LED_1(LED_1);
    ML_LED_2(LED_2);
    ML_LED_4(LED_4);

    return state;
}

void caps_word_set_user(bool active) {
    ML_LED_3(active);
}
