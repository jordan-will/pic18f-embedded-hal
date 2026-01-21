/*
 * File:   io.c
 * Author: Jordan Willian Marques Pereira
 *
 * Created on 21 de Janeiro de 2026, 07:11
 */

#include "io.h"
#include "bit_ops.h"

//INPUT AND OUTPUT -> TRISX

void pinMode(io_port_t port, uint8_t pin, uint8_t mode) {
    switch (port) {
        case PORT_A:
            (mode == INPUT) ? set_bit(&TRISA, pin) : clear_bit(&TRISA, pin);
            break;
        case PORT_B:
            (mode == INPUT) ? set_bit(&TRISB, pin) : clear_bit(&TRISB, pin);
            break;
        case PORT_C:
            (mode == INPUT) ? set_bit(&TRISC, pin) : clear_bit(&TRISC, pin);
            break;
        case PORT_D:
            (mode == INPUT) ? set_bit(&TRISD, pin) : clear_bit(&TRISD, pin);
            break;
        case PORT_E:
            (mode == INPUT) ? set_bit(&TRISE, pin) : clear_bit(&TRISE, pin);
            break;

    }
}

//WRITE -> LATX

void digitalWrite(io_port_t port, uint8_t pin, uint8_t value) {
    switch (port) {
        case PORT_A:
            (value == HIGH) ? set_bit(&LATA, pin) : clear_bit(&LATA, pin);
            break;
        case PORT_B:
            (value == HIGH) ? set_bit(&LATB, pin) : clear_bit(&LATB, pin);
            break;
        case PORT_C:
            (value == HIGH) ? set_bit(&LATC, pin) : clear_bit(&LATC, pin);
            break;
        case PORT_D:
            (value == HIGH) ? set_bit(&LATD, pin) : clear_bit(&LATD, pin);
            break;
        case PORT_E:
            (value == HIGH) ? set_bit(&LATE, pin) : clear_bit(&LATE, pin);
            break;
    }
}

uint8_t digitalRead(io_port_t port, uint8_t pin) {
    switch (port) {
        case PORT_A:
            return read_bit(&PORTA, pin);
        case PORT_B:
            return read_bit(&PORTB, pin);
        case PORT_C:
            return read_bit(&PORTC, pin);
        case PORT_D:
            return read_bit(&PORTD, pin);
        case PORT_E:
            return read_bit(&PORTE, pin);
    }
}