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
    Azerty,
    Lol_classique,
    Lol_Varus_Cait,
    Dispatch_layers,
    Empty
};

// tap_hold
#define Enter_Maj LT(0, KC_ENTER)

// full redifined
#define CtrlSpace_Ctrl LT(0, KC_SPC)

enum custom_keycodes {
    Range_display = SAFE_RANGE, //
};

const char* layer_names_str[] = {
    "Graphite",        //
    "Azerty",          //
    "Lol classique",   //
    "Lol  Varus_Cait", //
    "Dispatch layers", //
    "Empty"            //
};

// Use `A_B` in your layout...

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [Graphite] = LAYOUT(
    KC_ESCAPE/* */, FR_AMPR/* */,FR_EACU/* */,FR_DQUO/*"*/, FR_QUOT/*'*/,  FR_LPRN,    /*||*/    FR_MINS,    FR_EGRV,        FR_UNDS,        FR_CCED,        FR_AGRV,     KC_BACKSPACE,
    KC_TAB,         FR_B,        FR_L,        FR_D,         FR_W,          FR_Z,       /*||*/    FR_COLN/*:*/,   FR_F,       FR_O,           FR_U,           FR_J,        FR_CIRC,
    KC_LEFT_SHIFT,  FR_N,        FR_R,        FR_T,         FR_S,          FR_G,       /*||*/    FR_Y,           FR_H,       FR_A,           FR_E,           FR_I,        FR_UGRV,
    KC_LEFT_CTRL,   FR_Q,        FR_X,        FR_M,         FR_C,          FR_V,       /*||*/    FR_K,           FR_P,       FR_SCLN/*;*/,   FR_COMM/*,*/,   FR_MINS,     FR_EXLM,
                                  KC_LEFT_ALT,      KC_SPC,   OSL(Dispatch_layers),    /*||*/      KC_LEFT_CTRL,        Enter_Maj,          KC_BACKSPACE

    ),

    [Azerty] =  LAYOUT(
    ____   ,        FR_AMPR,     FR_EACU,     FR_DQUO,     FR_QUOT,        FR_LPRN,    /*||*/    FR_MINS,        FR_EGRV,    FR_UNDS,        FR_CCED,        FR_AGRV,     FR_RPRN,
    KC_TAB,         FR_A,        FR_Z,        FR_E,        FR_R,           FR_T,       /*||*/    FR_Y,           FR_U,       FR_I,           FR_O,           FR_P,        FR_CIRC,
    KC_LSFT,        FR_Q,        FR_S,        FR_D,        FR_F,           FR_G,       /*||*/    FR_H,           FR_J,       FR_K,           FR_L,           FR_M,        FR_UGRV,
    KC_LCTL,        FR_W,        FR_X,        FR_C,        FR_V,           FR_B,       /*||*/    FR_N,           FR_COMM,    FR_SCLN,        FR_COLN,        FR_EXLM,     KC_ENT,
                                    KC_LEFT_CTRL,      ____,         ____,            /*||*/     ____,        ____,        ____
    ),

    [Lol_classique] =  LAYOUT(
     ____   ,       FR_AMPR,     FR_EACU,     FR_DQUO,     FR_QUOT,        FR_LPRN,    /*||*/    FR_MINS,        FR_EGRV,    FR_UNDS,        FR_CCED,        FR_AGRV,     FR_RPRN,
    Range_display,  FR_AMPR,     FR_EACU,     FR_DQUO,     FR_QUOT,        FR_P,    /*||*/    FR_MINS,        FR_EGRV,    FR_UNDS,        FR_CCED,        FR_AGRV,     FR_RPRN,
    KC_TAB,         FR_A,        FR_Z,        FR_E,        FR_R,           FR_T,       /*||*/    FR_Y,           FR_U,       FR_I,           FR_O,           FR_P,        FR_CIRC,
    KC_LSFT,        FR_Q,        FR_S,        FR_D,        FR_F,           FR_G,       /*||*/    FR_H,           FR_J,       FR_K,           FR_L,           FR_M,        FR_UGRV,
                                     CtrlSpace_Ctrl,      ____,         FR_B,            /*||*/     ____,        ____,        TO(Dispatch_layers)
    ),

    [Lol_Varus_Cait] =  LAYOUT(
     ____   ,       FR_AMPR,     FR_EACU,     FR_DQUO,     FR_QUOT,        FR_LPRN,    /*||*/    FR_MINS,        FR_EGRV,    FR_UNDS,        FR_CCED,        FR_AGRV,     FR_RPRN,
    Range_display,  FR_AMPR,     FR_EACU,     FR_DQUO,     FR_QUOT,        FR_P,    /*||*/    FR_MINS,        FR_EGRV,    FR_UNDS,        FR_CCED,        FR_AGRV,     FR_RPRN,
    KC_TAB,         FR_Z,        FR_E,        FR_A,        FR_R,           FR_T,       /*||*/    FR_Y,           FR_U,       FR_I,           FR_O,           FR_P,        FR_CIRC,
    KC_LSFT,        FR_Q,        FR_S,        FR_D,        FR_F,           FR_G,       /*||*/    FR_H,           FR_J,       FR_K,           FR_L,           FR_M,        FR_UGRV,
                                   CtrlSpace_Ctrl,      ____,         FR_B,            /*||*/    ____,        ____,        TO(Dispatch_layers)
    ),


    [Dispatch_layers] =  LAYOUT(
    ____,           ____,       ____,               ____,             ____,        ____,/*||*/    ____,        ____,        ____,          ____,        ____,       ____,
    ____,           ____,       ____,               ____,             ____,        ____,/*||*/    ____,        ____,        ____,          ____,        ____,       ____,
    ____,           TO(Azerty), TO(Lol_Varus_Cait), TO(Lol_classique),TO(Graphite),____,/*||*/    ____,        ____,        ____,          ____,        ____,       ____,
    ____,           ____,       ____,               ____,             ____,        ____,/*||*/    ____,        ____,        ____,          ____,        ____,       ____,
                                    ____,     ____,        ____,                        /*||*/    ____,        ____,        ____
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

// a quoi sert le bool de retour ?
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case Range_display:
            if (record->event.pressed) {
                range_displayed = !range_displayed;
                if (!range_displayed) {
                    unregister_code(FR_C);
                } else {
                    register_code(FR_C); // danger la version 16 ne fait pas ce qu'on veut, elle "unregister" si on touche une autre key
                }
            }
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