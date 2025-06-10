# glp_split_dual

dans config.h le choix des pin usart

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1


le rules.mk 

SPLIT_KEYBOARD = yes

keyboard.json : on a que la 1er des columns ? 

    "matrix_pins": {
        "cols": ["GP21"],
        "rows": ["GP20"]
    },

 On doit joindre les 3v3 + round des deux board


![glp_split_dual](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Martin Morterol](https://github.com/GrosLapin)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make glp_split_dual:default

Flashing example for this keyboard:

    make glp_split_dual:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
