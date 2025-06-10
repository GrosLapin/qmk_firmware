#include QMK_KEYBOARD_H

#include "keymap_french.h"

#define ____ KC_TRNS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off
    [0] = LAYOUT(
        FR_A,  FR_Z, FR_E,             FR_I,  FR_O, FR_P,
        FR_Q,  FR_S, FR_D,             FR_K,  FR_L, FR_M

        // FR_W,  FR_X, FR_C,   FR_V,  FR_B, FR_N

    )
    // clang-format on

};
