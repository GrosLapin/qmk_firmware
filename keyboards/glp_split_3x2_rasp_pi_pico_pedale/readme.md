# glp_split_3x2_rasp_pi_pico_pedale

La version demo avant vrait clavier 

dans config.h le choix des pin usart


## PCB

On doit joindre les vSys + ground des deux board et croiser les GP0 et GP1
 
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1


Le jack de gauche est pour la connection entre board
Le jack de droite permet d'ajouter une ligne de plus avec 3 coll
     col0 col1 col2
Row2    

Pin : 
    col2 => gpio10
    col1 => gpio11
    col0 => gpio12
    
    row 0 => gpio21
    row 1 => gpio20
    row 2 => gpio19


le rules.mk 

SPLIT_KEYBOARD = yes

keyboard.json : on a que la 1er des columns ? 

         // ligne 0
                // main gauche
                {"matrix": [0, 0], "x": 0, "y": 0},
                {"matrix": [0, 1], "x": 0, "y": 1},
                {"matrix": [0, 2], "x": 0, "y": 2},
                // main droite
                {"matrix": [0, 3], "x": 0, "y": 3},
                {"matrix": [0, 4], "x": 0, "y": 4},
                {"matrix": [0, 5], "x": 0, "y": 5},

                // ligne 1
                // main gauche
                {"matrix": [1, 0], "x": 1, "y": 0},
                {"matrix": [1, 1], "x": 1, "y": 1},
                {"matrix": [1, 2], "x": 1, "y": 2},
                // main droite
                {"matrix": [1, 3], "x": 1, "y": 3},
                {"matrix": [1, 4], "x": 1, "y": 4},
                {"matrix": [1, 5], "x": 1, "y": 5},


                // ligne 2 (add on)
                // main gauche
                {"matrix": [2, 0], "x": 2, "y": 0},
                {"matrix": [2, 1], "x": 2, "y": 1},
                {"matrix": [2, 2], "x": 2, "y": 2},
                // main droite
                {"matrix": [2, 3], "x": 2, "y": 3},
                {"matrix": [2, 4], "x": 2, "y": 4},
                {"matrix": [2, 5], "x": 2, "y": 5}


qmk compile -kb glp_split_3x2_rasp_pi_pico_pedale -km default
qmk flash -kb glp_split_3x2_rasp_pi_pico_pedale -km default
 
Make example for this keyboard (after setting up your build environment):

    make glp_split_3x2_rasp_pi_pico_pedale:default

Flashing example for this keyboard:

    make glp_split_3x2_rasp_pi_pico_pedale:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

enfoncer le bouton quand on branche le calbe usb :o


"layouts": {
        "LAYOUT": {
            "layout": [ // << c'est un fucking tableau, 1er valeur = 1er valeur de la macro LAYOUT et 
                        // la 2em moitié du clavier est des ligne suplémentaire, donc dans mon cas la "fin de ma 1er ligne (2em main) est en row : 2 ( car row 0 et 1 c'est la main gauche )
            
                {"matrix": [0, 0], "y": 0 , "x": 0  }, {"matrix": [0, 1], "y": 0 , "x": 0  }, {"matrix": [0, 2], "y": 0 , "x": 0  },           {"matrix": [2, 0], "y": 0 , "x": 0  }, {"matrix": [2, 1], "y": 0 , "x": 0  }, {"matrix": [2, 2], "y": 0 , "x": 0  },

                {"matrix": [1, 0], "y": 0 , "x": 0  }, {"matrix": [1, 1], "y": 0 , "x": 0  }, {"matrix": [1, 2], "y": 0 , "x": 0  },           {"matrix": [3, 0], "y": 0 , "x": 0  }, {"matrix": [3, 1], "y": 0 , "x": 0  }, {"matrix": [3, 2], "y": 0 , "x": 0  }
            ]
        }
    },