#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
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
};



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
  DANCE_35,
  DANCE_36,
  DANCE_37,
  DANCE_38,
  DANCE_39,
  DANCE_40,
  DANCE_41,
  DANCE_42,
  DANCE_43,
  DANCE_44,
  DANCE_45,
  DANCE_46,
  DANCE_47,
  DANCE_48,
  DANCE_49,
  DANCE_50,
  DANCE_51,
  DANCE_52,
  DANCE_53,
  DANCE_54,
  DANCE_55,
  DANCE_56,
  DANCE_57,
  DANCE_58,
  DANCE_59,
  DANCE_60,
  DANCE_61,
  DANCE_62,
  DANCE_63,
  DANCE_64,
  DANCE_65,
  DANCE_66,
  DANCE_67,
  DANCE_68,
  DANCE_69,
  DANCE_70,
  DANCE_71,
  DANCE_72,
  DANCE_73,
  DANCE_74,
  DANCE_75,
  DANCE_76,
  DANCE_77,
  DANCE_78,
  DANCE_79,
  DANCE_80,
  DANCE_81,
  DANCE_82,
  DANCE_83,
  DANCE_84,
  DANCE_85,
  DANCE_86,
  DANCE_87,
  DANCE_88,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      BP_B,           BP_ECUT,        BP_P,           BP_O,           BP_EGRV,                                        BP_V,           BP_D,           BP_L,           BP_J,           BP_Z,           KC_UP,          
    KC_TAB,         BP_A,           BP_U,           BP_I,           BP_E,           TD(DANCE_0),                                    BP_T,           BP_S,           BP_R,           BP_N,           BP_M,           KC_DOWN,        
    OSM(MOD_LSFT),  BP_AGRV,        BP_Y,           BP_X,           TD(DANCE_1),    KC_BSPC,                                        TD(DANCE_6),    BP_G,           BP_H,           BP_F,           BP_CCED,        OSM(MOD_RSFT),  
    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    TT(2),          BP_C,           BP_Q,                                           BP_K,           BP_W,           TT(1),          KC_LEFT,        KC_RIGHT,       OSM(MOD_RGUI),  
                                                    KC_ENTER,       TD(DANCE_5),                                    TD(DANCE_7),    KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    TO(12),         BP_PIPE,        BP_AMPR,        BP_MINS,        BP_ASTR,        TD(DANCE_8),                                    TD(DANCE_9),    BP_SLSH,        BP_PLUS,        BP_HASH,        BP_BSLS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, BP_6,           BP_4,           BP_8,           BP_0,           BP_2,                                           BP_3,           BP_1,           BP_9,           BP_5,           BP_7,           KC_TRANSPARENT, 
    KC_TRANSPARENT, BP_UNDS,        BP_LBRC,        BP_LPRN,        BP_EQL,         KC_TRANSPARENT,                                 KC_TRANSPARENT, BP_PERC,        BP_RPRN,        BP_RBRC,        BP_EXLM,        CW_TOGG,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, BP_DCRC,        BP_LESS,                                        TD(DANCE_10),   BP_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    BP_GRTR,        KC_ENTER,                                       KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_DELETE,      TD(DANCE_11),   TD(DANCE_12),   TD(DANCE_13),   TD(DANCE_14),   TD(DANCE_15),                                   TD(DANCE_17),   TD(DANCE_18),   TD(DANCE_19),   TD(DANCE_20),   TD(DANCE_21),   KC_TRANSPARENT, 
    KC_TRANSPARENT, BP_AT,          BP_TILD,        RALT(BP_COMM),  BP_APOS,        BP_LGIL,                                        BP_RGIL,        BP_GRV,         BP_DQOT,        BP_DTRM,        TD(DANCE_22),   KC_TRANSPARENT, 
    KC_CAPS,        BP_QEST,        BP_LCBR,        RALT(LSFT(BP_P)),RALT(BP_A),     KC_TRANSPARENT,                                 KC_TRANSPARENT, RALT(BP_O),     BP_MDSH,        BP_RCBR,        BP_UGRV,        OSM(MOD_RSFT),  
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, BP_DCRC,        RALT(BP_2),                                     RALT(BP_3),     BP_DLR,         ST_MACRO_0,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_ENTER,       TD(DANCE_16),                                   KC_TRANSPARENT, KC_ESCAPE
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_B,           ST_MACRO_1,     KC_P,           KC_O,           ST_MACRO_2,                                     KC_V,           KC_D,           KC_L,           KC_J,           KC_Z,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_U,           KC_I,           KC_E,           TD(DANCE_23),                                   KC_T,           KC_S,           KC_R,           KC_N,           KC_M,           KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_3,     KC_Y,           KC_X,           TD(DANCE_24),   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_G,           KC_H,           KC_F,           ST_MACRO_4,     KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TT(5),          KC_C,           KC_Q,                                           KC_K,           KC_W,           TT(4),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    TO(12),         KC_PIPE,        KC_AMPR,        KC_MINUS,       KC_ASTR,        TD(DANCE_25),                                   TD(DANCE_26),   KC_SLASH,       KC_PLUS,        KC_HASH,        KC_BSLS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_6,           KC_4,           KC_8,           KC_0,           KC_2,                                           KC_3,           KC_1,           KC_9,           KC_5,           KC_7,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_UNDS,        KC_LBRC,        KC_LPRN,        KC_EQUAL,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PERC,        KC_RPRN,        KC_RBRC,        KC_EXLM,        CW_TOGG,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_LABK,                                        TD(DANCE_27),   KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_RABK,        KC_ENTER,                                       KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_DELETE,      TD(DANCE_28),   TD(DANCE_29),   TD(DANCE_30),   TD(DANCE_31),   TD(DANCE_32),                                   TD(DANCE_34),   TD(DANCE_35),   TD(DANCE_36),   TD(DANCE_37),   TD(DANCE_38),   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_AT,          KC_TILD,        ST_MACRO_5,     KC_QUOTE,       RALT(KC_LBRC),                                  RALT(KC_RBRC),  ST_MACRO_7,     ST_MACRO_8,     KC_DQUO,        TD(DANCE_39),   KC_TRANSPARENT, 
    KC_CAPS,        KC_QUES,        KC_LCBR,        RALT(LSFT(KC_S)),RALT(KC_Z),     KC_TRANSPARENT,                                 KC_TRANSPARENT, RALT(KC_X),     ST_MACRO_9,     KC_RCBR,        ST_MACRO_10,    OSM(MOD_RSFT),  
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        ST_MACRO_6,                                     ST_MACRO_11,    KC_DLR,         RALT(KC_M),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_ENTER,       TD(DANCE_33),                                   KC_TRANSPARENT, KC_ESCAPE
  ),
  [6] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_B,           FR_EACU,        KC_P,           KC_O,           FR_EGRV,                                        KC_V,           KC_D,           KC_L,           KC_J,           FR_Z,           KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_A,           KC_U,           KC_I,           KC_E,           TD(DANCE_40),                                   KC_T,           KC_S,           KC_R,           KC_N,           FR_M,           KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_AGRV,        KC_Y,           KC_X,           TD(DANCE_41),   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_G,           KC_H,           KC_F,           FR_CCED,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TT(8),          KC_C,           FR_Q,                                           KC_K,           FR_W,           TT(7),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_voyager(
    TO(12),         FR_PIPE,        FR_AMP,         FR_MINS,        FR_ASTR,        TD(DANCE_42),                                   TD(DANCE_43),   FR_SLSH,        FR_PLUS,        FR_HASH,        FR_BSLS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_6,           FR_4,           FR_8,           FR_0,           FR_2,                                           FR_3,           FR_1,           FR_9,           FR_5,           FR_7,           KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_UNDS,        FR_LBRC,        FR_LPRN,        FR_EQL,         KC_TRANSPARENT,                                 KC_TRANSPARENT, FR_PERC,        FR_RPRN,        FR_RBRC,        FR_EXLM,        CW_TOGG,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, FR_CCIRC,       FR_LESS,                                        TD(DANCE_44),   FR_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    FR_GRTR,        KC_ENTER,                                       KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_voyager(
    KC_DELETE,      TD(DANCE_45),   TD(DANCE_46),   TD(DANCE_47),   TD(DANCE_48),   TD(DANCE_49),                                   TD(DANCE_51),   TD(DANCE_52),   TD(DANCE_53),   TD(DANCE_54),   TD(DANCE_55),   KC_TRANSPARENT, 
    KC_TRANSPARENT, FR_AT,          FR_TILD,        FR_APOS,        FR_SUP2,        ST_MACRO_12,                                    ST_MACRO_15,    ST_MACRO_16,    FR_DQUO,        FR_UMLT,        TD(DANCE_56),   KC_TRANSPARENT, 
    KC_CAPS,        FR_QUES,        FR_LCBR,        FR_SECT,        ST_MACRO_13,    KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_17,    ST_MACRO_18,    FR_RCBR,        FR_UGRV,        OSM(MOD_RSFT),  
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, FR_CCIRC,       ST_MACRO_14,                                    ST_MACRO_19,    FR_DLR,         FR_MU,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_ENTER,       TD(DANCE_50),                                   KC_TRANSPARENT, KC_ESCAPE
  ),
  [9] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_B,           ST_MACRO_20,    KC_P,           KC_O,           ST_MACRO_21,                                    KC_V,           KC_D,           KC_L,           KC_J,           KC_Z,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_U,           KC_I,           KC_E,           TD(DANCE_57),                                   KC_T,           KC_S,           KC_R,           KC_N,           KC_M,           KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_22,    KC_Y,           KC_X,           TD(DANCE_58),   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_G,           KC_H,           KC_F,           ST_MACRO_23,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TT(11),         KC_C,           KC_Q,                                           KC_K,           KC_W,           TT(10),         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [10] = LAYOUT_voyager(
    TO(12),         KC_PIPE,        KC_AMPR,        KC_MINUS,       KC_ASTR,        TD(DANCE_59),                                   TD(DANCE_60),   KC_SLASH,       KC_PLUS,        KC_HASH,        KC_BSLS,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_6,           KC_4,           KC_8,           KC_0,           KC_2,                                           KC_3,           KC_1,           KC_9,           KC_5,           KC_7,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_UNDS,        KC_LBRC,        KC_LPRN,        KC_EQUAL,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PERC,        KC_RPRN,        KC_RBRC,        KC_EXLM,        CW_TOGG,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_LABK,                                        TD(DANCE_61),   KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_RABK,        KC_ENTER,                                       KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [11] = LAYOUT_voyager(
    KC_DELETE,      TD(DANCE_62),   TD(DANCE_63),   TD(DANCE_64),   TD(DANCE_65),   TD(DANCE_66),                                   TD(DANCE_68),   TD(DANCE_69),   TD(DANCE_70),   TD(DANCE_71),   TD(DANCE_72),   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_AT,          ST_MACRO_24,    ST_MACRO_25,    KC_QUOTE,       RALT(KC_BSLS),                                  RALT(RSFT(KC_BSLS)),ST_MACRO_26,    ST_MACRO_27,    KC_DQUO,        TD(DANCE_73),   KC_TRANSPARENT, 
    KC_CAPS,        KC_QUES,        KC_LCBR,        RALT(KC_6),     RALT(KC_QUOTE), KC_TRANSPARENT,                                 KC_TRANSPARENT, RALT(KC_Q),     RALT(RSFT(KC_MINUS)),KC_RCBR,        ST_MACRO_28,    OSM(MOD_RSFT),  
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        RALT(KC_LBRC),                                  RALT(RSFT(KC_LBRC)),KC_DLR,         RALT(KC_M),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_ENTER,       TD(DANCE_67),                                   KC_TRANSPARENT, KC_ESCAPE
  ),
  [12] = LAYOUT_voyager(
    KC_TRANSPARENT, TD(DANCE_74),   TD(DANCE_75),   TD(DANCE_76),   TD(DANCE_77),   TD(DANCE_78),                                   TD(DANCE_79),   TD(DANCE_80),   TD(DANCE_81),   TD(DANCE_82),   TD(DANCE_83),   KC_MS_UP,       
    KC_TRANSPARENT, KC_KP_6,        KC_KP_4,        KC_KP_8,        KC_KP_0,        KC_KP_2,                                        KC_KP_3,        KC_KP_1,        KC_KP_9,        KC_KP_5,        KC_KP_7,        KC_MS_DOWN,     
    KC_LEFT_SHIFT,  KC_MS_BTN1,     KC_MS_BTN3,     KC_MS_BTN2,     KC_KP_DOT,      KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(DANCE_84),   TD(DANCE_85),   TD(DANCE_86),   KC_KP_COMMA,    KC_NUM,         
    KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_RIGHT, RGB_TOG,        TOGGLE_LAYER_COLOR,KC_MS_WH_UP,                                    KC_MS_WH_DOWN,  TD(DANCE_87),   TD(DANCE_88),   KC_MS_LEFT,     KC_MS_RIGHT,    KC_TRANSPARENT, 
                                                    KC_KP_ENTER,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {225,224,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,245,245}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {74,255,255}, {74,255,255}, {225,224,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {46,215,244}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {46,215,244}, {0,245,245}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,245,245}, {74,255,255}, {74,255,255}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {74,255,255} },

    [1] = { {0,0,255}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {0,245,245}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {168,218,204}, {168,218,204}, {168,218,204}, {225,224,255}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {46,215,244}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {46,215,244}, {0,245,245}, {168,218,204}, {168,218,204}, {168,218,204}, {168,218,204}, {0,245,245}, {168,218,204}, {168,218,204}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {168,218,204} },

    [2] = { {225,224,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {0,245,245}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {62,219,138}, {62,219,138}, {225,224,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {46,215,244}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {46,215,244}, {0,245,245}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {0,245,245}, {62,219,138}, {62,219,138}, {62,219,138}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {225,224,255} },

    [3] = { {225,224,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,245,245}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {131,255,255}, {131,255,255}, {225,224,255}, {19,245,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {46,215,244}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {46,215,244}, {0,245,245}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {0,245,245}, {131,255,255}, {131,255,255}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {131,255,255} },

    [4] = { {0,0,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {19,245,255}, {19,245,255}, {19,245,255}, {225,224,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {46,215,244}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {46,215,244}, {0,245,245}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {0,245,245}, {19,245,255}, {19,245,255}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {152,255,255}, {19,245,255} },

    [5] = { {225,224,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,245,245}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {74,255,255}, {74,255,255}, {225,224,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {46,215,244}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {46,215,244}, {0,245,245}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {0,245,245}, {74,255,255}, {74,255,255}, {74,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {225,224,255} },

    [6] = { {152,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {0,245,245}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {152,255,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {198,255,255}, {198,255,255}, {152,255,255}, {19,245,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {46,215,244}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {46,215,244}, {0,245,245}, {198,255,255}, {198,255,255}, {198,255,255}, {198,255,255}, {0,245,245}, {198,255,255}, {198,255,255}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {198,255,255} },

    [7] = { {0,0,255}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {62,219,138}, {62,219,138}, {62,219,138}, {225,224,255}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {46,215,244}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {46,215,244}, {0,245,245}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {0,245,245}, {62,219,138}, {62,219,138}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {62,219,138} },

    [8] = { {225,224,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {152,255,255}, {152,255,255}, {225,224,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {46,215,244}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {46,215,244}, {0,245,245}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {152,255,255}, {152,255,255}, {152,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {225,224,255} },

    [9] = { {225,224,255}, {0,234,170}, {0,234,170}, {0,234,170}, {0,234,170}, {0,234,170}, {0,234,170}, {0,234,170}, {0,234,170}, {0,234,170}, {0,234,170}, {0,234,170}, {0,245,245}, {0,234,170}, {0,234,170}, {0,234,170}, {0,234,170}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {0,234,170}, {0,234,170}, {225,224,255}, {19,245,255}, {0,234,170}, {0,234,170}, {0,234,170}, {0,234,170}, {0,234,170}, {46,215,244}, {0,234,170}, {0,234,170}, {0,234,170}, {0,234,170}, {0,234,170}, {46,215,244}, {0,245,245}, {0,234,170}, {0,234,170}, {0,234,170}, {0,234,170}, {0,245,245}, {0,234,170}, {0,234,170}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {0,234,170} },

    [10] = { {0,0,255}, {86,234,170}, {86,234,170}, {86,234,170}, {86,234,170}, {86,234,170}, {86,234,170}, {172,234,170}, {172,234,170}, {172,234,170}, {172,234,170}, {172,234,170}, {0,245,245}, {86,234,170}, {86,234,170}, {86,234,170}, {86,234,170}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {86,234,170}, {86,234,170}, {86,234,170}, {225,224,255}, {86,234,170}, {86,234,170}, {86,234,170}, {86,234,170}, {86,234,170}, {46,215,244}, {172,234,170}, {172,234,170}, {172,234,170}, {172,234,170}, {172,234,170}, {46,215,244}, {0,245,245}, {86,234,170}, {86,234,170}, {86,234,170}, {86,234,170}, {0,245,245}, {86,234,170}, {86,234,170}, {0,0,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {86,234,170} },

    [11] = { {225,224,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {172,234,170}, {172,234,170}, {172,234,170}, {172,234,170}, {172,234,170}, {172,234,170}, {0,245,245}, {172,234,170}, {172,234,170}, {172,234,170}, {172,234,170}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {0,0,255}, {172,234,170}, {172,234,170}, {225,224,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {46,215,244}, {172,234,170}, {172,234,170}, {172,234,170}, {172,234,170}, {172,234,170}, {46,215,244}, {0,245,245}, {172,234,170}, {172,234,170}, {172,234,170}, {172,234,170}, {0,245,245}, {172,234,170}, {172,234,170}, {172,234,170}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {225,224,255} },

    [12] = { {225,224,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {19,245,255}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {0,245,245}, {19,245,255}, {19,245,255}, {19,245,255}, {62,219,138}, {225,224,255}, {0,245,245}, {46,215,244}, {46,215,244}, {74,255,255}, {74,255,255}, {46,215,244}, {225,224,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {19,245,255}, {46,215,244}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {62,219,138}, {46,215,244}, {0,245,245}, {19,245,255}, {74,255,255}, {19,245,255}, {62,219,138}, {188,255,255}, {46,215,244}, {152,255,255}, {152,255,255}, {46,215,244}, {46,215,244}, {0,245,245}, {19,245,255}, {62,219,138} },

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
    case 10:
      set_layer_color(10);
      break;
    case 11:
      set_layer_color(11);
      break;
    case 12:
      set_layer_color(12);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
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
      SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_0) ));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_2) ));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_U));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_KP_8) SS_DELAY(100) SS_TAP(X_KP_2) SS_DELAY(100) SS_TAP(X_KP_2) SS_DELAY(100) SS_TAP(X_KP_1));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_1) ));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_0) ));
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
      SEND_STRING(SS_LALT(SS_TAP(X_KP_3) SS_TAP(X_KP_3) SS_TAP(X_KP_9) ));
    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_2) ));
    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_8) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_1) ));
    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_E));
    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_E));
    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_A));
    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_C));
    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_GRAVE)) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_25:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_26:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_27:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_28:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_U));
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

static tap dance_state[89];

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
        tap_code16(BP_COMM);
        tap_code16(BP_COMM);
        tap_code16(BP_COMM);
    }
    if(state->count > 3) {
        tap_code16(BP_COMM);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(BP_COMM); break;
        case SINGLE_HOLD: register_code16(BP_SCLN); break;
        case DOUBLE_TAP: register_code16(BP_COMM); register_code16(BP_COMM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_COMM); register_code16(BP_COMM);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(BP_COMM); break;
        case SINGLE_HOLD: unregister_code16(BP_SCLN); break;
        case DOUBLE_TAP: unregister_code16(BP_COMM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_COMM); break;
    }
    dance_state[0].step = 0;
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
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(BP_DOT); break;
        case SINGLE_HOLD: register_code16(BP_COLN); break;
        case DOUBLE_TAP: register_code16(BP_DOT); register_code16(BP_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_DOT); register_code16(BP_DOT);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(BP_DOT); break;
        case SINGLE_HOLD: unregister_code16(BP_COLN); break;
        case DOUBLE_TAP: unregister_code16(BP_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_DOT); break;
    }
    dance_state[1].step = 0;
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
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_LEFT_ALT); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT_ALT); register_code16(KC_LEFT_ALT);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT_ALT); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT_ALT); break;
    }
    dance_state[2].step = 0;
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
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_PAGE_UP); break;
        case SINGLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_TAP: register_code16(KC_PAGE_UP); register_code16(KC_PAGE_UP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PAGE_UP); register_code16(KC_PAGE_UP);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_PAGE_UP); break;
        case SINGLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_TAP: unregister_code16(KC_PAGE_UP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PAGE_UP); break;
    }
    dance_state[3].step = 0;
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
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_PGDN); break;
        case SINGLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_TAP: register_code16(KC_PGDN); register_code16(KC_PGDN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PGDN); register_code16(KC_PGDN);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_PGDN); break;
        case SINGLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_TAP: unregister_code16(KC_PGDN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PGDN); break;
    }
    dance_state[4].step = 0;
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
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_LEFT_CTRL); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT_CTRL); register_code16(KC_LEFT_CTRL);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT_CTRL); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT_CTRL); break;
    }
    dance_state[5].step = 0;
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
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_RIGHT_ALT); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RIGHT_ALT); register_code16(KC_RIGHT_ALT);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_RIGHT_ALT); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RIGHT_ALT); break;
    }
    dance_state[6].step = 0;
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
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_RIGHT_CTRL); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_UP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RIGHT_CTRL); register_code16(KC_RIGHT_CTRL);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_RIGHT_CTRL); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_UP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RIGHT_CTRL); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_DOT);
        tap_code16(BP_DOT);
        tap_code16(BP_DOT);
    }
    if(state->count > 3) {
        tap_code16(BP_DOT);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(BP_DOT); break;
        case SINGLE_HOLD: register_code16(BP_EURO); break;
        case DOUBLE_TAP: register_code16(BP_DOT); register_code16(BP_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_DOT); register_code16(BP_DOT);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(BP_DOT); break;
        case SINGLE_HOLD: unregister_code16(BP_EURO); break;
        case DOUBLE_TAP: unregister_code16(BP_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_DOT); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_COMM);
        tap_code16(BP_COMM);
        tap_code16(BP_COMM);
    }
    if(state->count > 3) {
        tap_code16(BP_COMM);
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(BP_COMM); break;
        case SINGLE_HOLD: register_code16(LSFT(RALT(BP_L))); break;
        case DOUBLE_TAP: register_code16(BP_COMM); register_code16(BP_COMM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_COMM); register_code16(BP_COMM);
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(BP_COMM); break;
        case SINGLE_HOLD: unregister_code16(LSFT(RALT(BP_L))); break;
        case DOUBLE_TAP: unregister_code16(BP_COMM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_COMM); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(tap_dance_state_t *state, void *user_data);
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void on_dance_10(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_COLN);
        tap_code16(BP_COLN);
        tap_code16(BP_COLN);
    }
    if(state->count > 3) {
        tap_code16(BP_COLN);
    }
}

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(BP_COLN); break;
        case SINGLE_HOLD: register_code16(BP_SCLN); break;
        case DOUBLE_TAP: register_code16(BP_COLN); register_code16(BP_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_COLN); register_code16(BP_COLN);
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(BP_COLN); break;
        case SINGLE_HOLD: unregister_code16(BP_SCLN); break;
        case DOUBLE_TAP: unregister_code16(BP_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_COLN); break;
    }
    dance_state[10].step = 0;
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
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_F6); break;
        case DOUBLE_TAP: register_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[11].step = 0;
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
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[12].step = 0;
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
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_F8); break;
        case DOUBLE_TAP: register_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F8); register_code16(KC_F8);
    }
}

void dance_13_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F8); break;
    }
    dance_state[13].step = 0;
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
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(KC_F10); break;
        case DOUBLE_TAP: register_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F10); register_code16(KC_F10);
    }
}

void dance_14_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F10); break;
    }
    dance_state[14].step = 0;
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
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F2); register_code16(KC_F2);
    }
}

void dance_15_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F2); break;
    }
    dance_state[15].step = 0;
}
void on_dance_16(tap_dance_state_t *state, void *user_data);
void dance_16_finished(tap_dance_state_t *state, void *user_data);
void dance_16_reset(tap_dance_state_t *state, void *user_data);

void on_dance_16(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT_CTRL);
        tap_code16(KC_LEFT_CTRL);
        tap_code16(KC_LEFT_CTRL);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT_CTRL);
    }
}

void dance_16_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP: register_code16(KC_LEFT_CTRL); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT_CTRL); register_code16(KC_LEFT_CTRL);
    }
}

void dance_16_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT_CTRL); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT_CTRL); break;
    }
    dance_state[16].step = 0;
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
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
    }
}

void dance_17_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
    }
    dance_state[17].step = 0;
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
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
    }
}

void dance_18_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
    }
    dance_state[18].step = 0;
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
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}

void dance_19_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[19].step = 0;
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
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_20_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[20].step = 0;
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
    dance_state[21].step = dance_step(state);
    switch (dance_state[21].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}

void dance_21_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[21].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[21].step = 0;
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
    dance_state[22].step = dance_step(state);
    switch (dance_state[22].step) {
        case SINGLE_TAP: register_code16(BP_DEGR); break;
        case SINGLE_HOLD: register_code16(RALT(BP_EGRV)); break;
        case DOUBLE_TAP: register_code16(BP_DEGR); register_code16(BP_DEGR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_DEGR); register_code16(BP_DEGR);
    }
}

void dance_22_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[22].step) {
        case SINGLE_TAP: unregister_code16(BP_DEGR); break;
        case SINGLE_HOLD: unregister_code16(RALT(BP_EGRV)); break;
        case DOUBLE_TAP: unregister_code16(BP_DEGR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_DEGR); break;
    }
    dance_state[22].step = 0;
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
    dance_state[23].step = dance_step(state);
    switch (dance_state[23].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(KC_SCLN); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_23_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[23].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(KC_SCLN); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[23].step = 0;
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
    dance_state[24].step = dance_step(state);
    switch (dance_state[24].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(KC_COLN); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_24_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[24].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(KC_COLN); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[24].step = 0;
}
void on_dance_25(tap_dance_state_t *state, void *user_data);
void dance_25_finished(tap_dance_state_t *state, void *user_data);
void dance_25_reset(tap_dance_state_t *state, void *user_data);

void on_dance_25(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_25_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[25].step = dance_step(state);
    switch (dance_state[25].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(RALT(KC_5)); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_25_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[25].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(RALT(KC_5)); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[25].step = 0;
}
void on_dance_26(tap_dance_state_t *state, void *user_data);
void dance_26_finished(tap_dance_state_t *state, void *user_data);
void dance_26_reset(tap_dance_state_t *state, void *user_data);

void on_dance_26(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_26_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[26].step = dance_step(state);
    switch (dance_state[26].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(RALT(RSFT(KC_4))); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_26_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[26].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(RALT(RSFT(KC_4))); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[26].step = 0;
}
void on_dance_27(tap_dance_state_t *state, void *user_data);
void dance_27_finished(tap_dance_state_t *state, void *user_data);
void dance_27_reset(tap_dance_state_t *state, void *user_data);

void on_dance_27(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
    }
    if(state->count > 3) {
        tap_code16(KC_COLN);
    }
}

void dance_27_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[27].step = dance_step(state);
    switch (dance_state[27].step) {
        case SINGLE_TAP: register_code16(KC_COLN); break;
        case SINGLE_HOLD: register_code16(KC_SCLN); break;
        case DOUBLE_TAP: register_code16(KC_COLN); register_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COLN); register_code16(KC_COLN);
    }
}

void dance_27_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[27].step) {
        case SINGLE_TAP: unregister_code16(KC_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_SCLN); break;
        case DOUBLE_TAP: unregister_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COLN); break;
    }
    dance_state[27].step = 0;
}
void on_dance_28(tap_dance_state_t *state, void *user_data);
void dance_28_finished(tap_dance_state_t *state, void *user_data);
void dance_28_reset(tap_dance_state_t *state, void *user_data);

void on_dance_28(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F6);
        tap_code16(KC_F6);
        tap_code16(KC_F6);
    }
    if(state->count > 3) {
        tap_code16(KC_F6);
    }
}

void dance_28_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[28].step = dance_step(state);
    switch (dance_state[28].step) {
        case SINGLE_TAP: register_code16(KC_F6); break;
        case DOUBLE_TAP: register_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
    }
}

void dance_28_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[28].step) {
        case SINGLE_TAP: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[28].step = 0;
}
void on_dance_29(tap_dance_state_t *state, void *user_data);
void dance_29_finished(tap_dance_state_t *state, void *user_data);
void dance_29_reset(tap_dance_state_t *state, void *user_data);

void on_dance_29(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}

void dance_29_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[29].step = dance_step(state);
    switch (dance_state[29].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void dance_29_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[29].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[29].step = 0;
}
void on_dance_30(tap_dance_state_t *state, void *user_data);
void dance_30_finished(tap_dance_state_t *state, void *user_data);
void dance_30_reset(tap_dance_state_t *state, void *user_data);

void on_dance_30(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F8);
        tap_code16(KC_F8);
        tap_code16(KC_F8);
    }
    if(state->count > 3) {
        tap_code16(KC_F8);
    }
}

void dance_30_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[30].step = dance_step(state);
    switch (dance_state[30].step) {
        case SINGLE_TAP: register_code16(KC_F8); break;
        case DOUBLE_TAP: register_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F8); register_code16(KC_F8);
    }
}

void dance_30_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[30].step) {
        case SINGLE_TAP: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F8); break;
    }
    dance_state[30].step = 0;
}
void on_dance_31(tap_dance_state_t *state, void *user_data);
void dance_31_finished(tap_dance_state_t *state, void *user_data);
void dance_31_reset(tap_dance_state_t *state, void *user_data);

void on_dance_31(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F10);
        tap_code16(KC_F10);
        tap_code16(KC_F10);
    }
    if(state->count > 3) {
        tap_code16(KC_F10);
    }
}

void dance_31_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[31].step = dance_step(state);
    switch (dance_state[31].step) {
        case SINGLE_TAP: register_code16(KC_F10); break;
        case DOUBLE_TAP: register_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F10); register_code16(KC_F10);
    }
}

void dance_31_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[31].step) {
        case SINGLE_TAP: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F10); break;
    }
    dance_state[31].step = 0;
}
void on_dance_32(tap_dance_state_t *state, void *user_data);
void dance_32_finished(tap_dance_state_t *state, void *user_data);
void dance_32_reset(tap_dance_state_t *state, void *user_data);

void on_dance_32(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F2);
        tap_code16(KC_F2);
        tap_code16(KC_F2);
    }
    if(state->count > 3) {
        tap_code16(KC_F2);
    }
}

void dance_32_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[32].step = dance_step(state);
    switch (dance_state[32].step) {
        case SINGLE_TAP: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F2); register_code16(KC_F2);
    }
}

void dance_32_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[32].step) {
        case SINGLE_TAP: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F2); break;
    }
    dance_state[32].step = 0;
}
void on_dance_33(tap_dance_state_t *state, void *user_data);
void dance_33_finished(tap_dance_state_t *state, void *user_data);
void dance_33_reset(tap_dance_state_t *state, void *user_data);

void on_dance_33(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT_CTRL);
        tap_code16(KC_LEFT_CTRL);
        tap_code16(KC_LEFT_CTRL);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT_CTRL);
    }
}

void dance_33_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[33].step = dance_step(state);
    switch (dance_state[33].step) {
        case SINGLE_TAP: register_code16(KC_LEFT_CTRL); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT_CTRL); register_code16(KC_LEFT_CTRL);
    }
}

void dance_33_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[33].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT_CTRL); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT_CTRL); break;
    }
    dance_state[33].step = 0;
}
void on_dance_34(tap_dance_state_t *state, void *user_data);
void dance_34_finished(tap_dance_state_t *state, void *user_data);
void dance_34_reset(tap_dance_state_t *state, void *user_data);

void on_dance_34(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F3);
        tap_code16(KC_F3);
        tap_code16(KC_F3);
    }
    if(state->count > 3) {
        tap_code16(KC_F3);
    }
}

void dance_34_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[34].step = dance_step(state);
    switch (dance_state[34].step) {
        case SINGLE_TAP: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
    }
}

void dance_34_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[34].step) {
        case SINGLE_TAP: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
    }
    dance_state[34].step = 0;
}
void on_dance_35(tap_dance_state_t *state, void *user_data);
void dance_35_finished(tap_dance_state_t *state, void *user_data);
void dance_35_reset(tap_dance_state_t *state, void *user_data);

void on_dance_35(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F1);
        tap_code16(KC_F1);
        tap_code16(KC_F1);
    }
    if(state->count > 3) {
        tap_code16(KC_F1);
    }
}

void dance_35_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[35].step = dance_step(state);
    switch (dance_state[35].step) {
        case SINGLE_TAP: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
    }
}

void dance_35_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[35].step) {
        case SINGLE_TAP: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
    }
    dance_state[35].step = 0;
}
void on_dance_36(tap_dance_state_t *state, void *user_data);
void dance_36_finished(tap_dance_state_t *state, void *user_data);
void dance_36_reset(tap_dance_state_t *state, void *user_data);

void on_dance_36(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if(state->count > 3) {
        tap_code16(KC_F9);
    }
}

void dance_36_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[36].step = dance_step(state);
    switch (dance_state[36].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}

void dance_36_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[36].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[36].step = 0;
}
void on_dance_37(tap_dance_state_t *state, void *user_data);
void dance_37_finished(tap_dance_state_t *state, void *user_data);
void dance_37_reset(tap_dance_state_t *state, void *user_data);

void on_dance_37(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_37_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[37].step = dance_step(state);
    switch (dance_state[37].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_37_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[37].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[37].step = 0;
}
void on_dance_38(tap_dance_state_t *state, void *user_data);
void dance_38_finished(tap_dance_state_t *state, void *user_data);
void dance_38_reset(tap_dance_state_t *state, void *user_data);

void on_dance_38(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if(state->count > 3) {
        tap_code16(KC_F7);
    }
}

void dance_38_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[38].step = dance_step(state);
    switch (dance_state[38].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}

void dance_38_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[38].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[38].step = 0;
}
void on_dance_39(tap_dance_state_t *state, void *user_data);
void dance_39_finished(tap_dance_state_t *state, void *user_data);
void dance_39_reset(tap_dance_state_t *state, void *user_data);

void on_dance_39(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(RALT(KC_SCLN)));
        tap_code16(LSFT(RALT(KC_SCLN)));
        tap_code16(LSFT(RALT(KC_SCLN)));
    }
    if(state->count > 3) {
        tap_code16(LSFT(RALT(KC_SCLN)));
    }
}

void dance_39_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[39].step = dance_step(state);
    switch (dance_state[39].step) {
        case SINGLE_TAP: register_code16(LSFT(RALT(KC_SCLN))); break;
        case SINGLE_HOLD: register_code16(KC_GRAVE); break;
        case DOUBLE_TAP: register_code16(LSFT(RALT(KC_SCLN))); register_code16(LSFT(RALT(KC_SCLN))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(RALT(KC_SCLN))); register_code16(LSFT(RALT(KC_SCLN)));
    }
}

void dance_39_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[39].step) {
        case SINGLE_TAP: unregister_code16(LSFT(RALT(KC_SCLN))); break;
        case SINGLE_HOLD: unregister_code16(KC_GRAVE); break;
        case DOUBLE_TAP: unregister_code16(LSFT(RALT(KC_SCLN))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(RALT(KC_SCLN))); break;
    }
    dance_state[39].step = 0;
}
void on_dance_40(tap_dance_state_t *state, void *user_data);
void dance_40_finished(tap_dance_state_t *state, void *user_data);
void dance_40_reset(tap_dance_state_t *state, void *user_data);

void on_dance_40(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_COMM);
        tap_code16(FR_COMM);
        tap_code16(FR_COMM);
    }
    if(state->count > 3) {
        tap_code16(FR_COMM);
    }
}

void dance_40_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[40].step = dance_step(state);
    switch (dance_state[40].step) {
        case SINGLE_TAP: register_code16(FR_COMM); break;
        case SINGLE_HOLD: register_code16(FR_SCLN); break;
        case DOUBLE_TAP: register_code16(FR_COMM); register_code16(FR_COMM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_COMM); register_code16(FR_COMM);
    }
}

void dance_40_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[40].step) {
        case SINGLE_TAP: unregister_code16(FR_COMM); break;
        case SINGLE_HOLD: unregister_code16(FR_SCLN); break;
        case DOUBLE_TAP: unregister_code16(FR_COMM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_COMM); break;
    }
    dance_state[40].step = 0;
}
void on_dance_41(tap_dance_state_t *state, void *user_data);
void dance_41_finished(tap_dance_state_t *state, void *user_data);
void dance_41_reset(tap_dance_state_t *state, void *user_data);

void on_dance_41(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_DOT);
        tap_code16(FR_DOT);
        tap_code16(FR_DOT);
    }
    if(state->count > 3) {
        tap_code16(FR_DOT);
    }
}

void dance_41_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[41].step = dance_step(state);
    switch (dance_state[41].step) {
        case SINGLE_TAP: register_code16(FR_DOT); break;
        case SINGLE_HOLD: register_code16(FR_COLN); break;
        case DOUBLE_TAP: register_code16(FR_DOT); register_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_DOT); register_code16(FR_DOT);
    }
}

void dance_41_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[41].step) {
        case SINGLE_TAP: unregister_code16(FR_DOT); break;
        case SINGLE_HOLD: unregister_code16(FR_COLN); break;
        case DOUBLE_TAP: unregister_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_DOT); break;
    }
    dance_state[41].step = 0;
}
void on_dance_42(tap_dance_state_t *state, void *user_data);
void dance_42_finished(tap_dance_state_t *state, void *user_data);
void dance_42_reset(tap_dance_state_t *state, void *user_data);

void on_dance_42(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_DOT);
        tap_code16(FR_DOT);
        tap_code16(FR_DOT);
    }
    if(state->count > 3) {
        tap_code16(FR_DOT);
    }
}

void dance_42_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[42].step = dance_step(state);
    switch (dance_state[42].step) {
        case SINGLE_TAP: register_code16(FR_DOT); break;
        case SINGLE_HOLD: register_code16(FR_EURO); break;
        case DOUBLE_TAP: register_code16(FR_DOT); register_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_DOT); register_code16(FR_DOT);
    }
}

void dance_42_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[42].step) {
        case SINGLE_TAP: unregister_code16(FR_DOT); break;
        case SINGLE_HOLD: unregister_code16(FR_EURO); break;
        case DOUBLE_TAP: unregister_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_DOT); break;
    }
    dance_state[42].step = 0;
}
void on_dance_43(tap_dance_state_t *state, void *user_data);
void dance_43_finished(tap_dance_state_t *state, void *user_data);
void dance_43_reset(tap_dance_state_t *state, void *user_data);

void on_dance_43(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_COMM);
        tap_code16(FR_COMM);
        tap_code16(FR_COMM);
    }
    if(state->count > 3) {
        tap_code16(FR_COMM);
    }
}

void dance_43_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[43].step = dance_step(state);
    switch (dance_state[43].step) {
        case SINGLE_TAP: register_code16(FR_COMM); break;
        case SINGLE_HOLD: register_code16(FR_PND); break;
        case DOUBLE_TAP: register_code16(FR_COMM); register_code16(FR_COMM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_COMM); register_code16(FR_COMM);
    }
}

void dance_43_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[43].step) {
        case SINGLE_TAP: unregister_code16(FR_COMM); break;
        case SINGLE_HOLD: unregister_code16(FR_PND); break;
        case DOUBLE_TAP: unregister_code16(FR_COMM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_COMM); break;
    }
    dance_state[43].step = 0;
}
void on_dance_44(tap_dance_state_t *state, void *user_data);
void dance_44_finished(tap_dance_state_t *state, void *user_data);
void dance_44_reset(tap_dance_state_t *state, void *user_data);

void on_dance_44(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_COLN);
        tap_code16(FR_COLN);
        tap_code16(FR_COLN);
    }
    if(state->count > 3) {
        tap_code16(FR_COLN);
    }
}

void dance_44_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[44].step = dance_step(state);
    switch (dance_state[44].step) {
        case SINGLE_TAP: register_code16(FR_COLN); break;
        case SINGLE_HOLD: register_code16(FR_SCLN); break;
        case DOUBLE_TAP: register_code16(FR_COLN); register_code16(FR_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_COLN); register_code16(FR_COLN);
    }
}

void dance_44_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[44].step) {
        case SINGLE_TAP: unregister_code16(FR_COLN); break;
        case SINGLE_HOLD: unregister_code16(FR_SCLN); break;
        case DOUBLE_TAP: unregister_code16(FR_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_COLN); break;
    }
    dance_state[44].step = 0;
}
void on_dance_45(tap_dance_state_t *state, void *user_data);
void dance_45_finished(tap_dance_state_t *state, void *user_data);
void dance_45_reset(tap_dance_state_t *state, void *user_data);

void on_dance_45(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F6);
        tap_code16(KC_F6);
        tap_code16(KC_F6);
    }
    if(state->count > 3) {
        tap_code16(KC_F6);
    }
}

void dance_45_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[45].step = dance_step(state);
    switch (dance_state[45].step) {
        case SINGLE_TAP: register_code16(KC_F6); break;
        case DOUBLE_TAP: register_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
    }
}

void dance_45_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[45].step) {
        case SINGLE_TAP: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[45].step = 0;
}
void on_dance_46(tap_dance_state_t *state, void *user_data);
void dance_46_finished(tap_dance_state_t *state, void *user_data);
void dance_46_reset(tap_dance_state_t *state, void *user_data);

void on_dance_46(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}

void dance_46_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[46].step = dance_step(state);
    switch (dance_state[46].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void dance_46_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[46].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[46].step = 0;
}
void on_dance_47(tap_dance_state_t *state, void *user_data);
void dance_47_finished(tap_dance_state_t *state, void *user_data);
void dance_47_reset(tap_dance_state_t *state, void *user_data);

void on_dance_47(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F8);
        tap_code16(KC_F8);
        tap_code16(KC_F8);
    }
    if(state->count > 3) {
        tap_code16(KC_F8);
    }
}

void dance_47_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[47].step = dance_step(state);
    switch (dance_state[47].step) {
        case SINGLE_TAP: register_code16(KC_F8); break;
        case DOUBLE_TAP: register_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F8); register_code16(KC_F8);
    }
}

void dance_47_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[47].step) {
        case SINGLE_TAP: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F8); break;
    }
    dance_state[47].step = 0;
}
void on_dance_48(tap_dance_state_t *state, void *user_data);
void dance_48_finished(tap_dance_state_t *state, void *user_data);
void dance_48_reset(tap_dance_state_t *state, void *user_data);

void on_dance_48(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F10);
        tap_code16(KC_F10);
        tap_code16(KC_F10);
    }
    if(state->count > 3) {
        tap_code16(KC_F10);
    }
}

void dance_48_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[48].step = dance_step(state);
    switch (dance_state[48].step) {
        case SINGLE_TAP: register_code16(KC_F10); break;
        case DOUBLE_TAP: register_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F10); register_code16(KC_F10);
    }
}

void dance_48_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[48].step) {
        case SINGLE_TAP: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F10); break;
    }
    dance_state[48].step = 0;
}
void on_dance_49(tap_dance_state_t *state, void *user_data);
void dance_49_finished(tap_dance_state_t *state, void *user_data);
void dance_49_reset(tap_dance_state_t *state, void *user_data);

void on_dance_49(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F2);
        tap_code16(KC_F2);
        tap_code16(KC_F2);
    }
    if(state->count > 3) {
        tap_code16(KC_F2);
    }
}

void dance_49_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[49].step = dance_step(state);
    switch (dance_state[49].step) {
        case SINGLE_TAP: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F2); register_code16(KC_F2);
    }
}

void dance_49_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[49].step) {
        case SINGLE_TAP: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F2); break;
    }
    dance_state[49].step = 0;
}
void on_dance_50(tap_dance_state_t *state, void *user_data);
void dance_50_finished(tap_dance_state_t *state, void *user_data);
void dance_50_reset(tap_dance_state_t *state, void *user_data);

void on_dance_50(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT_CTRL);
        tap_code16(KC_LEFT_CTRL);
        tap_code16(KC_LEFT_CTRL);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT_CTRL);
    }
}

void dance_50_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[50].step = dance_step(state);
    switch (dance_state[50].step) {
        case SINGLE_TAP: register_code16(KC_LEFT_CTRL); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT_CTRL); register_code16(KC_LEFT_CTRL);
    }
}

void dance_50_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[50].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT_CTRL); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT_CTRL); break;
    }
    dance_state[50].step = 0;
}
void on_dance_51(tap_dance_state_t *state, void *user_data);
void dance_51_finished(tap_dance_state_t *state, void *user_data);
void dance_51_reset(tap_dance_state_t *state, void *user_data);

void on_dance_51(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F3);
        tap_code16(KC_F3);
        tap_code16(KC_F3);
    }
    if(state->count > 3) {
        tap_code16(KC_F3);
    }
}

void dance_51_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[51].step = dance_step(state);
    switch (dance_state[51].step) {
        case SINGLE_TAP: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
    }
}

void dance_51_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[51].step) {
        case SINGLE_TAP: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
    }
    dance_state[51].step = 0;
}
void on_dance_52(tap_dance_state_t *state, void *user_data);
void dance_52_finished(tap_dance_state_t *state, void *user_data);
void dance_52_reset(tap_dance_state_t *state, void *user_data);

void on_dance_52(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F1);
        tap_code16(KC_F1);
        tap_code16(KC_F1);
    }
    if(state->count > 3) {
        tap_code16(KC_F1);
    }
}

void dance_52_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[52].step = dance_step(state);
    switch (dance_state[52].step) {
        case SINGLE_TAP: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
    }
}

void dance_52_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[52].step) {
        case SINGLE_TAP: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
    }
    dance_state[52].step = 0;
}
void on_dance_53(tap_dance_state_t *state, void *user_data);
void dance_53_finished(tap_dance_state_t *state, void *user_data);
void dance_53_reset(tap_dance_state_t *state, void *user_data);

void on_dance_53(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if(state->count > 3) {
        tap_code16(KC_F9);
    }
}

void dance_53_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[53].step = dance_step(state);
    switch (dance_state[53].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}

void dance_53_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[53].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[53].step = 0;
}
void on_dance_54(tap_dance_state_t *state, void *user_data);
void dance_54_finished(tap_dance_state_t *state, void *user_data);
void dance_54_reset(tap_dance_state_t *state, void *user_data);

void on_dance_54(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_54_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[54].step = dance_step(state);
    switch (dance_state[54].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_54_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[54].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[54].step = 0;
}
void on_dance_55(tap_dance_state_t *state, void *user_data);
void dance_55_finished(tap_dance_state_t *state, void *user_data);
void dance_55_reset(tap_dance_state_t *state, void *user_data);

void on_dance_55(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if(state->count > 3) {
        tap_code16(KC_F7);
    }
}

void dance_55_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[55].step = dance_step(state);
    switch (dance_state[55].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}

void dance_55_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[55].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[55].step = 0;
}
void on_dance_56(tap_dance_state_t *state, void *user_data);
void dance_56_finished(tap_dance_state_t *state, void *user_data);
void dance_56_reset(tap_dance_state_t *state, void *user_data);

void on_dance_56(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(FR_OVRR);
        tap_code16(FR_OVRR);
        tap_code16(FR_OVRR);
    }
    if(state->count > 3) {
        tap_code16(FR_OVRR);
    }
}

void dance_56_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[56].step = dance_step(state);
    switch (dance_state[56].step) {
        case SINGLE_TAP: register_code16(FR_OVRR); break;
        case SINGLE_HOLD: register_code16(FR_GRV); break;
        case DOUBLE_TAP: register_code16(FR_OVRR); register_code16(FR_OVRR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_OVRR); register_code16(FR_OVRR);
    }
}

void dance_56_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[56].step) {
        case SINGLE_TAP: unregister_code16(FR_OVRR); break;
        case SINGLE_HOLD: unregister_code16(FR_GRV); break;
        case DOUBLE_TAP: unregister_code16(FR_OVRR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_OVRR); break;
    }
    dance_state[56].step = 0;
}
void on_dance_57(tap_dance_state_t *state, void *user_data);
void dance_57_finished(tap_dance_state_t *state, void *user_data);
void dance_57_reset(tap_dance_state_t *state, void *user_data);

void on_dance_57(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_57_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[57].step = dance_step(state);
    switch (dance_state[57].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(KC_SCLN); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_57_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[57].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(KC_SCLN); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[57].step = 0;
}
void on_dance_58(tap_dance_state_t *state, void *user_data);
void dance_58_finished(tap_dance_state_t *state, void *user_data);
void dance_58_reset(tap_dance_state_t *state, void *user_data);

void on_dance_58(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_58_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[58].step = dance_step(state);
    switch (dance_state[58].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(KC_COLN); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_58_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[58].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(KC_COLN); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[58].step = 0;
}
void on_dance_59(tap_dance_state_t *state, void *user_data);
void dance_59_finished(tap_dance_state_t *state, void *user_data);
void dance_59_reset(tap_dance_state_t *state, void *user_data);

void on_dance_59(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_59_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[59].step = dance_step(state);
    switch (dance_state[59].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(RALT(RSFT(KC_2))); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_59_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[59].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(RALT(RSFT(KC_2))); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[59].step = 0;
}
void on_dance_60(tap_dance_state_t *state, void *user_data);
void dance_60_finished(tap_dance_state_t *state, void *user_data);
void dance_60_reset(tap_dance_state_t *state, void *user_data);

void on_dance_60(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_60_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[60].step = dance_step(state);
    switch (dance_state[60].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(RALT(KC_3)); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_60_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[60].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(RALT(KC_3)); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[60].step = 0;
}
void on_dance_61(tap_dance_state_t *state, void *user_data);
void dance_61_finished(tap_dance_state_t *state, void *user_data);
void dance_61_reset(tap_dance_state_t *state, void *user_data);

void on_dance_61(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
    }
    if(state->count > 3) {
        tap_code16(KC_COLN);
    }
}

void dance_61_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[61].step = dance_step(state);
    switch (dance_state[61].step) {
        case SINGLE_TAP: register_code16(KC_COLN); break;
        case SINGLE_HOLD: register_code16(KC_SCLN); break;
        case DOUBLE_TAP: register_code16(KC_COLN); register_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COLN); register_code16(KC_COLN);
    }
}

void dance_61_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[61].step) {
        case SINGLE_TAP: unregister_code16(KC_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_SCLN); break;
        case DOUBLE_TAP: unregister_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COLN); break;
    }
    dance_state[61].step = 0;
}
void on_dance_62(tap_dance_state_t *state, void *user_data);
void dance_62_finished(tap_dance_state_t *state, void *user_data);
void dance_62_reset(tap_dance_state_t *state, void *user_data);

void on_dance_62(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F6);
        tap_code16(KC_F6);
        tap_code16(KC_F6);
    }
    if(state->count > 3) {
        tap_code16(KC_F6);
    }
}

void dance_62_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[62].step = dance_step(state);
    switch (dance_state[62].step) {
        case SINGLE_TAP: register_code16(KC_F6); break;
        case DOUBLE_TAP: register_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F6); register_code16(KC_F6);
    }
}

void dance_62_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[62].step) {
        case SINGLE_TAP: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[62].step = 0;
}
void on_dance_63(tap_dance_state_t *state, void *user_data);
void dance_63_finished(tap_dance_state_t *state, void *user_data);
void dance_63_reset(tap_dance_state_t *state, void *user_data);

void on_dance_63(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F4);
        tap_code16(KC_F4);
        tap_code16(KC_F4);
    }
    if(state->count > 3) {
        tap_code16(KC_F4);
    }
}

void dance_63_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[63].step = dance_step(state);
    switch (dance_state[63].step) {
        case SINGLE_TAP: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F4); register_code16(KC_F4);
    }
}

void dance_63_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[63].step) {
        case SINGLE_TAP: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[63].step = 0;
}
void on_dance_64(tap_dance_state_t *state, void *user_data);
void dance_64_finished(tap_dance_state_t *state, void *user_data);
void dance_64_reset(tap_dance_state_t *state, void *user_data);

void on_dance_64(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F8);
        tap_code16(KC_F8);
        tap_code16(KC_F8);
    }
    if(state->count > 3) {
        tap_code16(KC_F8);
    }
}

void dance_64_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[64].step = dance_step(state);
    switch (dance_state[64].step) {
        case SINGLE_TAP: register_code16(KC_F8); break;
        case DOUBLE_TAP: register_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F8); register_code16(KC_F8);
    }
}

void dance_64_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[64].step) {
        case SINGLE_TAP: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_MY_COMPUTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F8); break;
    }
    dance_state[64].step = 0;
}
void on_dance_65(tap_dance_state_t *state, void *user_data);
void dance_65_finished(tap_dance_state_t *state, void *user_data);
void dance_65_reset(tap_dance_state_t *state, void *user_data);

void on_dance_65(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F10);
        tap_code16(KC_F10);
        tap_code16(KC_F10);
    }
    if(state->count > 3) {
        tap_code16(KC_F10);
    }
}

void dance_65_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[65].step = dance_step(state);
    switch (dance_state[65].step) {
        case SINGLE_TAP: register_code16(KC_F10); break;
        case DOUBLE_TAP: register_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F10); register_code16(KC_F10);
    }
}

void dance_65_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[65].step) {
        case SINGLE_TAP: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_APPLICATION); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F10); break;
    }
    dance_state[65].step = 0;
}
void on_dance_66(tap_dance_state_t *state, void *user_data);
void dance_66_finished(tap_dance_state_t *state, void *user_data);
void dance_66_reset(tap_dance_state_t *state, void *user_data);

void on_dance_66(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F2);
        tap_code16(KC_F2);
        tap_code16(KC_F2);
    }
    if(state->count > 3) {
        tap_code16(KC_F2);
    }
}

void dance_66_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[66].step = dance_step(state);
    switch (dance_state[66].step) {
        case SINGLE_TAP: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F2); register_code16(KC_F2);
    }
}

void dance_66_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[66].step) {
        case SINGLE_TAP: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F2); break;
    }
    dance_state[66].step = 0;
}
void on_dance_67(tap_dance_state_t *state, void *user_data);
void dance_67_finished(tap_dance_state_t *state, void *user_data);
void dance_67_reset(tap_dance_state_t *state, void *user_data);

void on_dance_67(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT_CTRL);
        tap_code16(KC_LEFT_CTRL);
        tap_code16(KC_LEFT_CTRL);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT_CTRL);
    }
}

void dance_67_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[67].step = dance_step(state);
    switch (dance_state[67].step) {
        case SINGLE_TAP: register_code16(KC_LEFT_CTRL); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT_CTRL); register_code16(KC_LEFT_CTRL);
    }
}

void dance_67_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[67].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT_CTRL); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT_CTRL); break;
    }
    dance_state[67].step = 0;
}
void on_dance_68(tap_dance_state_t *state, void *user_data);
void dance_68_finished(tap_dance_state_t *state, void *user_data);
void dance_68_reset(tap_dance_state_t *state, void *user_data);

void on_dance_68(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F3);
        tap_code16(KC_F3);
        tap_code16(KC_F3);
    }
    if(state->count > 3) {
        tap_code16(KC_F3);
    }
}

void dance_68_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[68].step = dance_step(state);
    switch (dance_state[68].step) {
        case SINGLE_TAP: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
    }
}

void dance_68_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[68].step) {
        case SINGLE_TAP: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
    }
    dance_state[68].step = 0;
}
void on_dance_69(tap_dance_state_t *state, void *user_data);
void dance_69_finished(tap_dance_state_t *state, void *user_data);
void dance_69_reset(tap_dance_state_t *state, void *user_data);

void on_dance_69(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F1);
        tap_code16(KC_F1);
        tap_code16(KC_F1);
    }
    if(state->count > 3) {
        tap_code16(KC_F1);
    }
}

void dance_69_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[69].step = dance_step(state);
    switch (dance_state[69].step) {
        case SINGLE_TAP: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
    }
}

void dance_69_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[69].step) {
        case SINGLE_TAP: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
    }
    dance_state[69].step = 0;
}
void on_dance_70(tap_dance_state_t *state, void *user_data);
void dance_70_finished(tap_dance_state_t *state, void *user_data);
void dance_70_reset(tap_dance_state_t *state, void *user_data);

void on_dance_70(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if(state->count > 3) {
        tap_code16(KC_F9);
    }
}

void dance_70_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[70].step = dance_step(state);
    switch (dance_state[70].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}

void dance_70_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[70].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[70].step = 0;
}
void on_dance_71(tap_dance_state_t *state, void *user_data);
void dance_71_finished(tap_dance_state_t *state, void *user_data);
void dance_71_reset(tap_dance_state_t *state, void *user_data);

void on_dance_71(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_71_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[71].step = dance_step(state);
    switch (dance_state[71].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_71_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[71].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[71].step = 0;
}
void on_dance_72(tap_dance_state_t *state, void *user_data);
void dance_72_finished(tap_dance_state_t *state, void *user_data);
void dance_72_reset(tap_dance_state_t *state, void *user_data);

void on_dance_72(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if(state->count > 3) {
        tap_code16(KC_F7);
    }
}

void dance_72_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[72].step = dance_step(state);
    switch (dance_state[72].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}

void dance_72_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[72].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[72].step = 0;
}
void on_dance_73(tap_dance_state_t *state, void *user_data);
void dance_73_finished(tap_dance_state_t *state, void *user_data);
void dance_73_reset(tap_dance_state_t *state, void *user_data);

void on_dance_73(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(RALT(RSFT(KC_8)));
        tap_code16(RALT(RSFT(KC_8)));
        tap_code16(RALT(RSFT(KC_8)));
    }
    if(state->count > 3) {
        tap_code16(RALT(RSFT(KC_8)));
    }
}

void dance_73_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[73].step = dance_step(state);
    switch (dance_state[73].step) {
        case SINGLE_TAP: register_code16(RALT(RSFT(KC_8))); break;
        case SINGLE_HOLD: register_code16(KC_GRAVE); break;
        case DOUBLE_TAP: register_code16(RALT(RSFT(KC_8))); register_code16(RALT(RSFT(KC_8))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(RALT(RSFT(KC_8))); register_code16(RALT(RSFT(KC_8)));
    }
}

void dance_73_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[73].step) {
        case SINGLE_TAP: unregister_code16(RALT(RSFT(KC_8))); break;
        case SINGLE_HOLD: unregister_code16(KC_GRAVE); break;
        case DOUBLE_TAP: unregister_code16(RALT(RSFT(KC_8))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(RALT(RSFT(KC_8))); break;
    }
    dance_state[73].step = 0;
}
void dance_74_finished(tap_dance_state_t *state, void *user_data);
void dance_74_reset(tap_dance_state_t *state, void *user_data);

void dance_74_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[74].step = dance_step(state);
    switch (dance_state[74].step) {
        case SINGLE_TAP: layer_move(0); break;
        case DOUBLE_TAP: register_code16(KC_F6); break;
        case DOUBLE_SINGLE_TAP: layer_move(0); break;
    }
}

void dance_74_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[74].step) {
        case DOUBLE_TAP: unregister_code16(KC_F6); break;
    }
    dance_state[74].step = 0;
}
void dance_75_finished(tap_dance_state_t *state, void *user_data);
void dance_75_reset(tap_dance_state_t *state, void *user_data);

void dance_75_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[75].step = dance_step(state);
    switch (dance_state[75].step) {
        case SINGLE_TAP: layer_move(3); break;
        case DOUBLE_TAP: register_code16(KC_F4); break;
        case DOUBLE_SINGLE_TAP: layer_move(3); break;
    }
}

void dance_75_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[75].step) {
        case DOUBLE_TAP: unregister_code16(KC_F4); break;
    }
    dance_state[75].step = 0;
}
void dance_76_finished(tap_dance_state_t *state, void *user_data);
void dance_76_reset(tap_dance_state_t *state, void *user_data);

void dance_76_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[76].step = dance_step(state);
    switch (dance_state[76].step) {
        case SINGLE_TAP: layer_move(6); break;
        case DOUBLE_TAP: register_code16(KC_F8); break;
        case DOUBLE_SINGLE_TAP: layer_move(6); break;
    }
}

void dance_76_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[76].step) {
        case DOUBLE_TAP: unregister_code16(KC_F8); break;
    }
    dance_state[76].step = 0;
}
void dance_77_finished(tap_dance_state_t *state, void *user_data);
void dance_77_reset(tap_dance_state_t *state, void *user_data);

void dance_77_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[77].step = dance_step(state);
    switch (dance_state[77].step) {
        case SINGLE_TAP: layer_move(9); break;
        case DOUBLE_TAP: register_code16(KC_F10); break;
        case DOUBLE_SINGLE_TAP: layer_move(9); break;
    }
}

void dance_77_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[77].step) {
        case DOUBLE_TAP: unregister_code16(KC_F10); break;
    }
    dance_state[77].step = 0;
}
void on_dance_78(tap_dance_state_t *state, void *user_data);
void dance_78_finished(tap_dance_state_t *state, void *user_data);
void dance_78_reset(tap_dance_state_t *state, void *user_data);

void on_dance_78(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F2);
        tap_code16(KC_F2);
        tap_code16(KC_F2);
    }
    if(state->count > 3) {
        tap_code16(KC_F2);
    }
}

void dance_78_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[78].step = dance_step(state);
    switch (dance_state[78].step) {
        case SINGLE_TAP: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F2); register_code16(KC_F2);
    }
}

void dance_78_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[78].step) {
        case SINGLE_TAP: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_F12); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F2); break;
    }
    dance_state[78].step = 0;
}
void on_dance_79(tap_dance_state_t *state, void *user_data);
void dance_79_finished(tap_dance_state_t *state, void *user_data);
void dance_79_reset(tap_dance_state_t *state, void *user_data);

void on_dance_79(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F3);
        tap_code16(KC_F3);
        tap_code16(KC_F3);
    }
    if(state->count > 3) {
        tap_code16(KC_F3);
    }
}

void dance_79_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[79].step = dance_step(state);
    switch (dance_state[79].step) {
        case SINGLE_TAP: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F3); register_code16(KC_F3);
    }
}

void dance_79_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[79].step) {
        case SINGLE_TAP: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_F13); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F3); break;
    }
    dance_state[79].step = 0;
}
void on_dance_80(tap_dance_state_t *state, void *user_data);
void dance_80_finished(tap_dance_state_t *state, void *user_data);
void dance_80_reset(tap_dance_state_t *state, void *user_data);

void on_dance_80(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F1);
        tap_code16(KC_F1);
        tap_code16(KC_F1);
    }
    if(state->count > 3) {
        tap_code16(KC_F1);
    }
}

void dance_80_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[80].step = dance_step(state);
    switch (dance_state[80].step) {
        case SINGLE_TAP: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F1); register_code16(KC_F1);
    }
}

void dance_80_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[80].step) {
        case SINGLE_TAP: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_F11); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F1); break;
    }
    dance_state[80].step = 0;
}
void on_dance_81(tap_dance_state_t *state, void *user_data);
void dance_81_finished(tap_dance_state_t *state, void *user_data);
void dance_81_reset(tap_dance_state_t *state, void *user_data);

void on_dance_81(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F9);
        tap_code16(KC_F9);
        tap_code16(KC_F9);
    }
    if(state->count > 3) {
        tap_code16(KC_F9);
    }
}

void dance_81_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[81].step = dance_step(state);
    switch (dance_state[81].step) {
        case SINGLE_TAP: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_EJECT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F9); register_code16(KC_F9);
    }
}

void dance_81_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[81].step) {
        case SINGLE_TAP: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_EJECT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F9); break;
    }
    dance_state[81].step = 0;
}
void on_dance_82(tap_dance_state_t *state, void *user_data);
void dance_82_finished(tap_dance_state_t *state, void *user_data);
void dance_82_reset(tap_dance_state_t *state, void *user_data);

void on_dance_82(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F5);
        tap_code16(KC_F5);
        tap_code16(KC_F5);
    }
    if(state->count > 3) {
        tap_code16(KC_F5);
    }
}

void dance_82_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[82].step = dance_step(state);
    switch (dance_state[82].step) {
        case SINGLE_TAP: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_WWW_REFRESH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F5); register_code16(KC_F5);
    }
}

void dance_82_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[82].step) {
        case SINGLE_TAP: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_REFRESH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F5); break;
    }
    dance_state[82].step = 0;
}
void on_dance_83(tap_dance_state_t *state, void *user_data);
void dance_83_finished(tap_dance_state_t *state, void *user_data);
void dance_83_reset(tap_dance_state_t *state, void *user_data);

void on_dance_83(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_F7);
        tap_code16(KC_F7);
        tap_code16(KC_F7);
    }
    if(state->count > 3) {
        tap_code16(KC_F7);
    }
}

void dance_83_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[83].step = dance_step(state);
    switch (dance_state[83].step) {
        case SINGLE_TAP: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_F7); register_code16(KC_F7);
    }
}

void dance_83_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[83].step) {
        case SINGLE_TAP: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_SEARCH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_F7); break;
    }
    dance_state[83].step = 0;
}
void on_dance_84(tap_dance_state_t *state, void *user_data);
void dance_84_finished(tap_dance_state_t *state, void *user_data);
void dance_84_reset(tap_dance_state_t *state, void *user_data);

void on_dance_84(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PREV_TRACK);
        tap_code16(KC_MEDIA_PREV_TRACK);
        tap_code16(KC_MEDIA_PREV_TRACK);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PREV_TRACK);
    }
}

void dance_84_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[84].step = dance_step(state);
    switch (dance_state[84].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_REWIND); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PREV_TRACK); register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PREV_TRACK); register_code16(KC_MEDIA_PREV_TRACK);
    }
}

void dance_84_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[84].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_REWIND); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PREV_TRACK); break;
    }
    dance_state[84].step = 0;
}
void on_dance_85(tap_dance_state_t *state, void *user_data);
void dance_85_finished(tap_dance_state_t *state, void *user_data);
void dance_85_reset(tap_dance_state_t *state, void *user_data);

void on_dance_85(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_85_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[85].step = dance_step(state);
    switch (dance_state[85].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_85_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[85].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_STOP); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[85].step = 0;
}
void on_dance_86(tap_dance_state_t *state, void *user_data);
void dance_86_finished(tap_dance_state_t *state, void *user_data);
void dance_86_reset(tap_dance_state_t *state, void *user_data);

void on_dance_86(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_NEXT_TRACK);
        tap_code16(KC_MEDIA_NEXT_TRACK);
        tap_code16(KC_MEDIA_NEXT_TRACK);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_NEXT_TRACK);
    }
}

void dance_86_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[86].step = dance_step(state);
    switch (dance_state[86].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_FAST_FORWARD); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_NEXT_TRACK); register_code16(KC_MEDIA_NEXT_TRACK);
    }
}

void dance_86_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[86].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_FAST_FORWARD); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
    }
    dance_state[86].step = 0;
}
void on_dance_87(tap_dance_state_t *state, void *user_data);
void dance_87_finished(tap_dance_state_t *state, void *user_data);
void dance_87_reset(tap_dance_state_t *state, void *user_data);

void on_dance_87(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_WWW_HOME);
        tap_code16(KC_WWW_HOME);
        tap_code16(KC_WWW_HOME);
    }
    if(state->count > 3) {
        tap_code16(KC_WWW_HOME);
    }
}

void dance_87_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[87].step = dance_step(state);
    switch (dance_state[87].step) {
        case SINGLE_TAP: register_code16(KC_WWW_HOME); break;
        case SINGLE_HOLD: register_code16(KC_CALCULATOR); break;
        case DOUBLE_TAP: register_code16(KC_WWW_HOME); register_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_WWW_HOME); register_code16(KC_WWW_HOME);
    }
}

void dance_87_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[87].step) {
        case SINGLE_TAP: unregister_code16(KC_WWW_HOME); break;
        case SINGLE_HOLD: unregister_code16(KC_CALCULATOR); break;
        case DOUBLE_TAP: unregister_code16(KC_WWW_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_WWW_HOME); break;
    }
    dance_state[87].step = 0;
}
void on_dance_88(tap_dance_state_t *state, void *user_data);
void dance_88_finished(tap_dance_state_t *state, void *user_data);
void dance_88_reset(tap_dance_state_t *state, void *user_data);

void on_dance_88(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MAIL);
        tap_code16(KC_MAIL);
        tap_code16(KC_MAIL);
    }
    if(state->count > 3) {
        tap_code16(KC_MAIL);
    }
}

void dance_88_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[88].step = dance_step(state);
    switch (dance_state[88].step) {
        case SINGLE_TAP: register_code16(KC_MAIL); break;
        case SINGLE_HOLD: register_code16(KC_MY_COMPUTER); break;
        case DOUBLE_TAP: register_code16(KC_MAIL); register_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MAIL); register_code16(KC_MAIL);
    }
}

void dance_88_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[88].step) {
        case SINGLE_TAP: unregister_code16(KC_MAIL); break;
        case SINGLE_HOLD: unregister_code16(KC_MY_COMPUTER); break;
        case DOUBLE_TAP: unregister_code16(KC_MAIL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MAIL); break;
    }
    dance_state[88].step = 0;
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
        [DANCE_35] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_35, dance_35_finished, dance_35_reset),
        [DANCE_36] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_36, dance_36_finished, dance_36_reset),
        [DANCE_37] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_37, dance_37_finished, dance_37_reset),
        [DANCE_38] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_38, dance_38_finished, dance_38_reset),
        [DANCE_39] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_39, dance_39_finished, dance_39_reset),
        [DANCE_40] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_40, dance_40_finished, dance_40_reset),
        [DANCE_41] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_41, dance_41_finished, dance_41_reset),
        [DANCE_42] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_42, dance_42_finished, dance_42_reset),
        [DANCE_43] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_43, dance_43_finished, dance_43_reset),
        [DANCE_44] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_44, dance_44_finished, dance_44_reset),
        [DANCE_45] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_45, dance_45_finished, dance_45_reset),
        [DANCE_46] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_46, dance_46_finished, dance_46_reset),
        [DANCE_47] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_47, dance_47_finished, dance_47_reset),
        [DANCE_48] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_48, dance_48_finished, dance_48_reset),
        [DANCE_49] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_49, dance_49_finished, dance_49_reset),
        [DANCE_50] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_50, dance_50_finished, dance_50_reset),
        [DANCE_51] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_51, dance_51_finished, dance_51_reset),
        [DANCE_52] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_52, dance_52_finished, dance_52_reset),
        [DANCE_53] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_53, dance_53_finished, dance_53_reset),
        [DANCE_54] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_54, dance_54_finished, dance_54_reset),
        [DANCE_55] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_55, dance_55_finished, dance_55_reset),
        [DANCE_56] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_56, dance_56_finished, dance_56_reset),
        [DANCE_57] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_57, dance_57_finished, dance_57_reset),
        [DANCE_58] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_58, dance_58_finished, dance_58_reset),
        [DANCE_59] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_59, dance_59_finished, dance_59_reset),
        [DANCE_60] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_60, dance_60_finished, dance_60_reset),
        [DANCE_61] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_61, dance_61_finished, dance_61_reset),
        [DANCE_62] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_62, dance_62_finished, dance_62_reset),
        [DANCE_63] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_63, dance_63_finished, dance_63_reset),
        [DANCE_64] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_64, dance_64_finished, dance_64_reset),
        [DANCE_65] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_65, dance_65_finished, dance_65_reset),
        [DANCE_66] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_66, dance_66_finished, dance_66_reset),
        [DANCE_67] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_67, dance_67_finished, dance_67_reset),
        [DANCE_68] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_68, dance_68_finished, dance_68_reset),
        [DANCE_69] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_69, dance_69_finished, dance_69_reset),
        [DANCE_70] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_70, dance_70_finished, dance_70_reset),
        [DANCE_71] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_71, dance_71_finished, dance_71_reset),
        [DANCE_72] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_72, dance_72_finished, dance_72_reset),
        [DANCE_73] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_73, dance_73_finished, dance_73_reset),
        [DANCE_74] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_74_finished, dance_74_reset),
        [DANCE_75] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_75_finished, dance_75_reset),
        [DANCE_76] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_76_finished, dance_76_reset),
        [DANCE_77] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_77_finished, dance_77_reset),
        [DANCE_78] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_78, dance_78_finished, dance_78_reset),
        [DANCE_79] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_79, dance_79_finished, dance_79_reset),
        [DANCE_80] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_80, dance_80_finished, dance_80_reset),
        [DANCE_81] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_81, dance_81_finished, dance_81_reset),
        [DANCE_82] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_82, dance_82_finished, dance_82_reset),
        [DANCE_83] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_83, dance_83_finished, dance_83_reset),
        [DANCE_84] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_84, dance_84_finished, dance_84_reset),
        [DANCE_85] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_85, dance_85_finished, dance_85_reset),
        [DANCE_86] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_86, dance_86_finished, dance_86_reset),
        [DANCE_87] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_87, dance_87_finished, dance_87_reset),
        [DANCE_88] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_88, dance_88_finished, dance_88_reset),
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
               add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
               return true;

            // Keycodes that continue Caps Word, without shifting.
            case BP_1 ... BP_0:
            case KC_KP_1 ... KC_KP_0:
            case KC_KP_MINUS:
            case KC_BSPC:
            case KC_DELETE:
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
      case 9:           // QWERTY mac
      case 10:
      case 11:
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
            case KC_DELETE:
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
            case KC_DELETE:
            case FR_UNDS:
            case FR_MINS:
               return true;

            default:
               return false;  // Deactivate Caps Word.
         }
      case 12:           // Keyboard
         switch (keycode) {
            // Keycodes that continue Caps Word, without shifting.
            case KC_KP_1 ... KC_KP_0:
            case KC_KP_MINUS:
            case KC_BSPC:
            case KC_DELETE:
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
        STATUS_LED_2(led_state.num_lock);
        STATUS_LED_4(led_state.caps_lock);
    }
    return res;
}

extern bool is_launching;

layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);

    return state;
}

void caps_word_set_user(bool active) {
    STATUS_LED_1(active);
    STATUS_LED_3(active);
}
