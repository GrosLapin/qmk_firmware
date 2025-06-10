// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    PERMA_CLICK = SAFE_RANGE,
    DOUBLE_CLICK,
    Y_DOWN,
};

static bool down = false;
bool        process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PERMA_CLICK:
            if (record->event.pressed) {
                down = true;
            } else {
                down = false;
            }
            break;
        case DOUBLE_CLICK: {
            if (record->event.pressed) {
                tap_code(KC_MS_BTN1);
                SEND_STRING(SS_DELAY(90));
                tap_code(KC_MS_BTN1);
            } else {
            }
            break;
        }
    }
    return true;
};

uint16_t elapse = 0;
bool     once   = true;
void     matrix_scan_user(void) { // The very important timer.
    if (once) {
        elapse = timer_read();
        once   = false;
    }

    if (down) {
        if (timer_elapsed(elapse) > 350) {
            tap_code(KC_MS_BTN1);

            elapse = timer_read();
        }
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬
     * │ 7 │ 8 │ 9 │
     * ├───┼───┼───┼
     * │ 4 │ 5 │ 6 │
     * ├───┼───┼───┼

     */
    // clang-format off
    [0] = LAYOUT(
        PERMA_CLICK,   KC_MS_BTN1, DOUBLE_CLICK,
        KC_MS_BTN4,   KC_MS_BTN5,   KC_MS_U
    )
    // clang-format on
    // KC_MS_BTN3 => click molette
    // KC_MS_BTN4 => lateral arrier
    // KC_MS_BTN5 => lateral avant
};
