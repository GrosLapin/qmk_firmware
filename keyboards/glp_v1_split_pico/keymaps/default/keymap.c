#include QMK_KEYBOARD_H

#include "keymap_french.h"
#include "i2c_master.h"
#include <string.h>

#define ____ KC_TRNS

/**
 * Si une des moitié marche pas, unplug tout, plug le jack PUIS le usb
 */

enum layer_names {
    Graphite, //
    Symboles,
    Azerty,
    Lol_classique,
    Lol_Varus_Cait,
    Wakfu_combat,
    Dispatch_layers,
    Empty
};

// tap_hold
#define Enter_Maj LT(0, KC_ENTER)

// full redifined
#define CtrlSpace_Ctrl LT(0, KC_SPC)
#define Back_or_toggleChamp LT(15, KC_SPC)

enum custom_keycodes {
    Range_display = SAFE_RANGE, //
};

const char* layer_names_str[] = {
    "Graphite",         //
    "Symboles",         //
    "Azerty",           //
    "Lol other champ ", //
    "Lol  Varus_Cait",  //
    "Wakfu Combat",     //
    "Dispatch layers",  //
    "Empty"             //
};

// Use `A_B` in your layout...
// mode tap : https://docs.qmk.fm/mod_tap

// Pb : il me faut 2 mains pour copy past
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [Graphite] = LAYOUT(
    KC_ESCAPE/* */, FR_AMPR/*&*/,FR_EACU/*é*/,FR_DQUO/*"*/, FR_QUOT/*'*/,  FR_LPRN/*(*/,/*||*/    FR_MINS/*-*/,   FR_EGRV/*è*/,FR_UNDS/*_*/,    FR_CCED/*ç*/,    FR_AGRV/*à*/,     OSL(Dispatch_layers),
    KC_TAB,         FR_B,        FR_L,        FR_D,         FR_W,          FR_Z,        /*||*/    FR_UNDS/*_*/,  FR_F,        FR_O,           FR_U,           FR_J,        FR_CIRC,
    KC_LEFT_SHIFT,  FR_N,        FR_R,        FR_T,         FR_S,          FR_G,        /*||*/    FR_Y,           FR_H,        FR_A,           FR_E,           FR_I,        FR_UGRV,
    KC_LEFT_CTRL,   FR_Q,        FR_X,        FR_M,         FR_C,          FR_V,        /*||*/    FR_K,           FR_P,        FR_SCLN/*;*/,   FR_COMM/*,*/,   FR_MINS,     FR_EXLM,
                                  OSL(Symboles),      KC_SPC,  KC_LEFT_ALT ,            /*||*/      LCTL_T(KC_TAB),        Enter_Maj,          KC_BACKSPACE

    ),

    // je peux mettre des truc sur le pousse gauche comme c'est sticky
    [Symboles] =  LAYOUT(
    ____,           ____,        ____,        ____,         ____,          ____,        /*||*/    ____,            ____,        ____,          ____,           ____,          ____,
    ____,           FR_CIRC/*^*/,FR_ASTR/***/,FR_CCED/*ç*/, FR_EGRV/*è*/,  ____,        /*||*/    FR_AT  /*@*/,    FR_PERC/*%*/,FR_EACU/*é*/,  FR_LABK/*<*/,   FR_RABK/*>*/,  ____,
    ____,           FR_DOT/*.*/, FR_LPRN/*(*/,FR_RPRN/*)*/, FR_SLSH/*/*/,  ____,        /*||*/    FR_COLN/*:*/,    FR_LCBR/*{*/,FR_RCBR/*}*/,  FR_AGRV/*à*/,   FR_EQL/*=*/,   ____,
    ____,           FR_HASH/*#*/,FR_AMPR/*&*/,FR_EXLM/*!*/, FR_BSLS /*\\*/,____,        /*||*/    ____,            FR_LBRC/*[*/,FR_RBRC/*]*/,  FR_PLUS/*+*/,   FR_MINS/*-*/,  ____,
                                    FR_EGRV/*è*/,     ____,        ____,                /*||*/    FR_DQUO/*"*/,       FR_EACU/*é*/,        FR_QUOT/*'*/
    ),

    [Azerty] =  LAYOUT(
    ____   ,        FR_AMPR,     FR_EACU,     FR_DQUO,     FR_QUOT,        FR_LPRN,    /*||*/    FR_MINS,        FR_EGRV,    FR_UNDS,        FR_CCED,        FR_AGRV,     FR_RPRN,
    KC_TAB,         FR_A,        FR_Z,        FR_E,        FR_R,           FR_T,       /*||*/    FR_Y,           FR_U,       FR_I,           FR_O,           FR_P,        FR_CIRC,
    KC_LSFT,        FR_Q,        FR_S,        FR_D,        FR_F,           FR_G,       /*||*/    FR_H,           FR_J,       FR_K,           FR_L,           FR_M,        FR_UGRV,
    KC_LCTL,        FR_W,        FR_X,        FR_C,        FR_V,           FR_B,       /*||*/    FR_N,           FR_COMM,    FR_SCLN,        FR_COLN,        FR_EXLM,     KC_ENT,
                                    KC_LEFT_CTRL,      ____,         ____,            /*||*/     ____,        ____,        ____
    ),

    [Lol_classique] =  LAYOUT(
    ____   ,        FR_AMPR,     FR_EACU,     KC_LEFT_ALT, FR_QUOT,        FR_LPRN,    /*||*/    FR_MINS,        FR_EGRV,    FR_UNDS,        FR_CCED,        FR_AGRV,     FR_RPRN,
    Range_display,  FR_AMPR,     FR_EACU,     FR_DQUO,     FR_QUOT,        FR_P,       /*||*/    FR_MINS,        FR_EGRV,    FR_UNDS,        FR_CCED,        FR_AGRV,     FR_RPRN,
    KC_TAB,         FR_E,        FR_A,        FR_Z,        FR_R,           FR_T,       /*||*/    FR_Y,           FR_U,       FR_I,           FR_O,           FR_P,        FR_CIRC,
    KC_LEFT_ALT,        FR_Q,        FR_S,        FR_D,        FR_F,           FR_G,   /*||*/    FR_H,           FR_J,       FR_K,           FR_L,           FR_M,        FR_UGRV,
                                KC_SPC,   CtrlSpace_Ctrl,        Back_or_toggleChamp,  /*||*/    ____,        ____,        TO(Graphite)
    ),

    [Lol_Varus_Cait] =  LAYOUT(

    ____   ,       FR_AMPR,     FR_EACU,     KC_LEFT_ALT, FR_QUOT,        FR_LPRN,    /*||*/    FR_MINS,        FR_EGRV,    FR_UNDS,        FR_CCED,        FR_AGRV,     FR_RPRN,
    Range_display,  FR_AMPR,     FR_EACU,     FR_DQUO,     FR_QUOT,        FR_P,       /*||*/    FR_MINS,        FR_EGRV,    FR_UNDS,        FR_CCED,        FR_AGRV,     FR_RPRN,
    KC_TAB,         FR_A,        FR_Z,        FR_E,        FR_R,           FR_T,       /*||*/    FR_Y,           FR_U,       FR_I,           FR_O,           FR_P,        FR_CIRC,
    KC_LEFT_ALT,        FR_Q,        FR_S,        FR_D,        FR_F,           FR_G,   /*||*/    FR_H,           FR_J,       FR_K,           FR_L,           FR_M,        FR_UGRV,
                                KC_SPC,   CtrlSpace_Ctrl,        Back_or_toggleChamp,  /*||*/     ____,        ____,        TO(Graphite)
    ),


    [Wakfu_combat] =  LAYOUT(
    ____,       ____,        ____,        ____,        ____,         FR_R,             /*||*/    ____,        ____,        ____,          ____,        ____,       ____,
    KC_F6,      KC_F1,       KC_F2,       KC_F3,       KC_F4,        KC_F5,            /*||*/    ____,        S(FR_H),     KC_UP,         FR_K,        ____,       ____,
    FR_MINS,    FR_AMPR,     FR_EACU,     FR_DQUO,     FR_QUOT,      FR_LPRN,          /*||*/    FR_Q,        KC_LEFT,     KC_DOWN,       KC_RIGHT,    FR_I,       ____,
    S(FR_MINS), S(FR_AMPR),  S(FR_EACU),  S(FR_DQUO),  S(FR_QUOT),   S(FR_LPRN),       /*||*/    ____,        FR_S,        FR_O,          FR_P,        ____,       ____,
                                    KC_SPC,     KC_MS_BTN1,   LALT(KC_TAB),                    /*||*/    ____,        KC_TAB,        TO(Graphite)
    ),


    [Dispatch_layers] =  LAYOUT(
    ____,           ____,       ____,               ____,             ____,        ____,        /*||*/    ____,        ____,        ____,          ____,        ____,       ____,
    ____,           ____,       ____,               ____,             ____,        ____,        /*||*/    ____,        ____,        ____,          ____,        ____,       ____,
    ____,           TO(Wakfu_combat), TO(Lol_Varus_Cait), TO(Lol_classique),TO(Graphite),____,  /*||*/    ____,        ____,        ____,          ____,        ____,       ____,
    ____,           ____,       ____,               ____,             ____,        ____,        /*||*/    ____,        ____,        ____,          ____,        ____,       ____,
                                    ____,     ____,        ____,                                /*||*/    ____,        ____,        TO(Graphite)
    ),

    [Empty] =  LAYOUT(
    ____,       ____,     ____,     ____,     ____,        ____,                       /*||*/    ____,        ____,        ____,          ____,        ____,       ____,
    ____,       ____,     ____,     ____,     ____,        ____,                       /*||*/    ____,        ____,        ____,          ____,        ____,       ____,
    ____,       ____,     ____,     ____,     ____,        ____,                       /*||*/    ____,        ____,        ____,          ____,        ____,       ____,
    ____,       ____,     ____,     ____,     ____,        ____,                       /*||*/    ____,        ____,        ____,          ____,        ____,       ____,
                                    ____,     ____,        ____,                       /*||*/    ____,        ____,        ____
    ),
    // clang-format on
};

static bool range_displayed = false;

void toogle_C(keyrecord_t* record) {
    if (record->event.pressed) {
        range_displayed = !range_displayed;
        if (!range_displayed) {
            unregister_code(FR_C);
        } else {
            register_code(FR_C); // danger la version 16 ne fait pas ce qu'on veut, elle "unregister" si on touche une autre key
        }
    }
}

// call at every layer change
layer_state_t layer_state_set_user(layer_state_t state) {
    if (range_displayed) {
        range_displayed = !range_displayed;
        unregister_code(FR_C);
    }
    return state;
}

// a quoi sert le bool de retour ?
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case Range_display:
            toogle_C(record);
            break;

        case Enter_Maj:
            if (record->tap.count == 0) {           // On hold.
                if (record->event.pressed) {        // On press
                    register_code(KC_LEFT_SHIFT);   // Press.
                } else {                            // On release.
                    unregister_code(KC_LEFT_SHIFT); // Release.
                }
                return false; // Skip default handling.
            }
            // On tap, continue default handling to act as KC_A.
            return true;

        // full rebinded
        case CtrlSpace_Ctrl:
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_SPC)); // Intercept tap function to send Ctrl-C
            } else {
                if (record->tap.count == 0) {          // On hold.
                    if (record->event.pressed) {       // On press
                        register_code(KC_LEFT_CTRL);   // Press.
                    } else {                           // On release.
                        unregister_code(KC_LEFT_CTRL); // Release.
                    }
                }
            }
            return false;
        case Back_or_toggleChamp:
            if (record->tap.count && record->event.pressed) {
                tap_code16(FR_B); // Intercept tap
            } else {
                toogle_C(record); // hold
            }
            return false;
    }
    return true;
}

static void display_layer_min(void) {
    oled_clear();
    uint8_t     max_col      = oled_max_chars();
    uint8_t     max_line     = oled_max_lines();
    const char* display      = layer_names_str[get_highest_layer(layer_state)];
    int         display_size = strlen(display);

    uint8_t col  = (max_col - display_size) / 2; // dangé faux pour les char hors ascii (é a une size de 2)
    uint8_t line = max_line / 2;

    oled_set_cursor(col, line);
    oled_write(display, false);

    // factorizable mais j'aime pas le C donc la fleme
    if (range_displayed) {
        const char* display      = "Range ON";
        int         display_size = strlen(display);

        uint8_t col  = (max_col - display_size) / 2; // dangé faux pour les char hors ascii (é a une size de 2)
        uint8_t line = max_line / 2 + 1;

        oled_set_cursor(col, line);
        oled_write(display, false);
    }
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    display_layer_min();
    return false;
}
#endif