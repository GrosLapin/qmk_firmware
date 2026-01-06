#pragma once

#define OLED_DISPLAY_128X64
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3
// #define OLED_IC OLED_IC_SH1106

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define SPLIT_HAND_PIN 28 // hight mean left, should be link to 3v3 with 10kohm res on left, and to ground on right
// #define MASTER_RIGHT

#define SPLIT_USB_TIMEOUT 10000 // seul ne marche pas
#define SPLIT_USB_TIMEOUT_POLL 10

#define SPLIT_WATCHDOG_ENABLE

// je veux que hold enter + fast a => A maj, pas "a\n"
// check PERMISSIVE_HOLD si ça me plait pas : https://docs.qmk.fm/tap_hold
#define HOLD_ON_OTHER_KEY_PRESS
