#include QMK_KEYBOARD_H

#include "keymap_french.h"
#include "i2c_master.h"

#define ____ FR_TRNS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [0] = LAYOUT(
        FR_SUP2,        FR_AMPR,FR_EACU,FR_DQUO,FR_QUOT,        FR_LPRN,FR_MINS,FR_EGRV,FR_UNDS,FR_CCED,FR_AGRV, KC_BACKSPACE,
        KC_TAB,         FR_B, FR_L, FR_D, FR_W, FR_Z,           FR_UNDS, FR_F,   FR_O,    FR_U,    FR_J,    FR_CIRC,
        KC_LEFT_SHIFT,  FR_N, FR_R, FR_T, FR_S, FR_G,           FR_Y,    FR_H,   FR_A,    FR_E,    FR_I,    FR_UGRV,
        KC_LEFT_CTRL,   FR_Q, FR_X, FR_M, FR_C, FR_V,           FR_K,    FR_P,   FR_DQUO, FR_COLN, FR_MINS, FR_EXLM,
                          KC_LEFT_CTRL, KC_SPC, FR_2,           KC_BACKSPACE,  KC_SPC, FR_4

    )

    // clang-format on

};

static void display_layer_min(void) {
    uint8_t     max_col      = oled_max_chars();
    uint8_t     max_line     = oled_max_lines();
    const char* display      = "Graphite";
    int         display_size = 8;

    uint8_t col  = (max_col - display_size) / 2; // dangé faux pour les char hors ascii (é a une size de 2)
    uint8_t line = max_line / 2;

    oled_set_cursor(col, line);
    oled_write(display, false);
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    display_layer_min();
    return false;
}
#endif