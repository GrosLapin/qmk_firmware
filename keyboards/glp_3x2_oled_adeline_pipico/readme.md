# glp_3x2_oled_adeline_pipico

La version no vial avec oled

dans config.h le choix des pin usart


## PCB

Pin : 
    col2 => gpio10
    col1 => gpio11
    col0 => gpio12
    
    row 0 => gpio21
    row 1 => gpio20

 I2C1_SCL_PIN GP3
 I2C1_SDA_PIN GP2


qmk compile -kb glp_3x2_oled_adeline_pipico -km default
qmk flash -kb glp_3x2_oled_adeline_pipico -km default
// poiur le debug
qmk console 
 

## Bootloader

enfoncer le bouton quand on branche le calbe usb :o
