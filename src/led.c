/*
 * File:   main.c
 * Author: Jordan Willian Marques Pereira
 *
 * Created on 18 de Janeiro de 2026, 17:38
 */

#include "led.h"
#include "bit_ops.h"
#include <xc.h>

void led_init(void) {
    TRISD = 0x00;

    #if LED_ACTIVE_HIGH
        #if LED_START_ON
            LATD = 0xFF;
        #else
            LATD = 0x00;
        #endif
    #else
        #if LED_START_ON
            LATD = 0x00;
        #else
            LATD = 0xFF;
        #endif
    #endif
}

void led_on(uint8_t led) {
    #if LED_ACTIVE_HIGH
        set_bit(&LATD, led);
    #else
        clear_bit(&LATD, led);
    #endif
}

void led_off(uint8_t led) {
    #if LED_ACTIVE_HIGH
        clear_bit(&LATD, led);
    #else
        set_bit(&LATD, led);
    #endif
}

void led_toggle(uint8_t led) {
    toggle_bit(&LATD, led);
}
