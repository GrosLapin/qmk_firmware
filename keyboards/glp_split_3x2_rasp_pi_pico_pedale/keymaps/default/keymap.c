#include QMK_KEYBOARD_H

#include "keymap_french.h"
#include "i2c_master.h"

#define ____ KC_TRNS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off
    [0] = LAYOUT(
        FR_A,  FR_Z, FR_E,             FR_I,  FR_O, FR_P,
        FR_Q,  FR_S, FR_D,             FR_K,  FR_L, FR_M


            //  FR_W,  FR_X, FR_C,   FR_V,  FR_B, FR_N

    )
    // clang-format on

};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    uprintf("!!keyboard_post_init_user");
    wait_ms(2000);
    uprintf("!!end sleep");
    uprintf("call oled");
    oled_write_ln("Test OLED", false);
    return false;
}
#endif