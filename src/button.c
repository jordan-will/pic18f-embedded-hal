/*
 * File:   main.c
 * Author: Jordan Willian Marques Pereira
 *
 * Created on 18 de Janeiro de 2026, 17:38
 */

#include "button.h"
#include <xc.h>

void button_init(uint8_t mask) {
    TRISB |= mask;
    INTCON2bits.RBPU = 0;
}

uint8_t button_raw(uint8_t pin) {
    #if BUTTON_ACTIVE_HIGH
        return (PORTB & (1 << pin)) != 0;
    #else
        return (PORTB & (1 << pin)) == 0;
    #endif
}