#pragma once

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

// Note we should flash both side if we want this option
//#define SPLIT_HAND_PIN GP5 // hight mean left, should be link to vbus (5v) with 10kohm res on left, and to ground on right
// #define MASTER_RIGHT
#define MASTER_LEFT
