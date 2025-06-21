#include QMK_KEYBOARD_H

#include "keymap_spanish.h"
#include "keymap_french.h"
#include "i2c_master.h"

enum custom_keycodes {
    a_ = SAFE_RANGE,
    A_,
    n_,
    N_,
    o_,
    O_,
    i_,
    I_,
    u_,
    U_,
    question_mark_,
    point_excla_,
};

enum combo_events {
    cb_to_maj,
    cb_to_min,
};

enum enum_layer {
    min,
    maj,
};

const uint16_t PROGMEM go_maj[]     = {a_, n_, COMBO_END};
const uint16_t PROGMEM go_min[]     = {A_, N_, COMBO_END};
combo_t                key_combos[] = {
    //
    [cb_to_min] = COMBO_ACTION(go_min), //
    [cb_to_maj] = COMBO_ACTION(go_maj),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case cb_to_maj: {
            layer_move(maj);
            break;
        }
        case cb_to_min: {
            layer_move(min);
            break;
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case a_:
            if (record->event.pressed) {
                send_string(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_0)));
                return false;
            }
            break;
        case A_:
            if (record->event.pressed) {
                send_string(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_1)));
                return false;
            }
            break;
        case i_:
            if (record->event.pressed) {
                send_string(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_1)));
                return false;
            }
            break;
        case I_:
            if (record->event.pressed) {
                send_string(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_4)));
                return false;
            }
            break;
        case o_:
            if (record->event.pressed) {
                send_string(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_2)));
                return false;
            }
            break;
        case O_:
            if (record->event.pressed) {
                send_string(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_4)));
                return false;
            }
            break;
        case u_:
            if (record->event.pressed) {
                send_string(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_3)));
                return false;
            }
            break;
        case U_:
            if (record->event.pressed) {
                send_string(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_3)));
                return false;
            }
            break;
        case n_:
            if (record->event.pressed) {
                send_string(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_4)));
                return false;
            }
            break;
        case N_:
            if (record->event.pressed) {
                send_string(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_5)));
                return false;
            }
            break;
        case question_mark_:
            if (record->event.pressed) {
                send_string(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_8)));
                return false;
            }
            break;
        case point_excla_:
            if (record->event.pressed) {
                send_string(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_3)));
                return false;
            }
            break;
    }
    return true;
};

#define ____ KC_TRNS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [min] = LAYOUT(
        a_,  n_, o_,
        i_,  u_, question_mark_
    ),
    [maj] = LAYOUT(
        A_,  N_, O_,
        I_,  U_, point_excla_
    )
    // clang-format on

};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_set_cursor(10, 4);

    switch (get_highest_layer(layer_state)) {
        case min:
            oled_write("Min", false);
            break;

        case maj:
            oled_write("Maj", false);
            break;
    }

    return false;
}
#endif