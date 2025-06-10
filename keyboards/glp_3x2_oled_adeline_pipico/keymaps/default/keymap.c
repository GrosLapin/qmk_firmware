#include QMK_KEYBOARD_H

#include "keymap_spanish.h"
#include "i2c_master.h"

enum combo_events {
    cb_to_maj,
    cb_to_min,
};

enum enum_layer {
    min,
    maj,
};

const uint16_t PROGMEM go_maj[]     = {ES_NTIL, ES_Z, COMBO_END};
const uint16_t PROGMEM go_min[]     = {ES_1, ES_2, COMBO_END};
combo_t                key_combos[] = {
    //
    [cb_to_min] = COMBO_ACTION(go_min), //
    [cb_to_maj] = COMBO_ACTION(go_maj),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case cb_to_maj: {
            oled_write_ln("to maj", false);
            layer_move(maj);
            break;
        }
        case cb_to_min: {
            oled_write_ln("to min", false);
            layer_move(min);
            break;
        }
    }
}

#define ____ KC_TRNS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off
    [min] = LAYOUT(
        ES_NTIL,  ES_Z, ES_E,
        ES_Q,     ES_S, ES_D
    ),
    [maj] = LAYOUT(
        ES_1,  ES_2, ES_3,
        ES_4,  ES_5, ES_6
    )
    // clang-format on

};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    uprintf("call oled");
    oled_write_ln("Test OLED", false);
    return false;
}
#endif