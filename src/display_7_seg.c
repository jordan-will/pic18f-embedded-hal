/*
 * File:   display_7_seg.c
 * Author: Jorfsn Willian Marques Pereira
 *
 * Created on 21 de Janeiro de 2026, 09:40
 */
#include "config.h"
#include "display7_seg.h"
#include "io.h"
#include <xc.h>

//DISP1 TO DISP4 -> ACTIVE ON HIGH

typedef struct {
    io_port_t port;
    uint8_t pin;
} display_pin_t;

//select accoding to displays on PICGenios board
static const display_pin_t display_pins[DISPLAY_7_DIGITS] = {
    {PORT_A, 2}, //DISP1
    {PORT_A, 3}, //DISP2
    {PORT_A, 4}, //DISP3
    {PORT_A, 5}//DISP4
};

//internal buffer
static uint8_t display_buffer[DISPLAY_7_DIGITS];

//segments table (LED active HIGH)
static const uint8_t seg_table[128] = {
    ['0'] = 0b00111111,
    ['1'] = 0b00000110,
    ['2'] = 0b01011011,
    ['3'] = 0b01001111,
    ['4'] = 0b01100110,
    ['5'] = 0b01101101,
    ['6'] = 0b01111101,
    ['7'] = 0b00000111,
    ['8'] = 0b01111111,
    ['9'] = 0b01101111,

    [' '] = 0b00000000,
    ['-'] = 0b01000000,
    ['E'] = 0b01111001,
    ['r'] = 0b01010000
};

void display_7_init(void) {

    //all ANx pins as digital
    //ADCON1 = 0x0F;
    uint8_t i;

    //set segment as output
    uint8_t s;
    for (s = 0; s < 8; s++) {
        pinMode(PORT_D, s, OUTPUT);
    }

    LATD = 0x00; //all leds start  off

    //display as output (high activated)
    for (i = 0; i < DISPLAY_7_DIGITS; i++) {
        pinMode(display_pins[i].port, display_pins[i].pin, OUTPUT);
        digitalWrite(display_pins[i].port, display_pins[i].pin, LOW);
        display_buffer[i] = ' ';
    }
}

void display_7_setchar(uint8_t digit, char c) {
    if (digit >= DISPLAY_7_DIGITS) return;
    display_buffer[digit] = c;
}

void display_7_setnumber(uint16_t value) {
    uint8_t i;
    for (i = 0; i < DISPLAY_7_DIGITS; i++) {
        display_buffer[DISPLAY_7_DIGITS - 1 - i] = (value % 10) + '0';
        value /= 10;
    }
}

void display_7_update(void) {
    uint8_t i, d;

    for (i = 0; i < DISPLAY_7_DIGITS; i++) {
        //turn off all displays 
        for (d = 0; d < DISPLAY_7_DIGITS; d++) {
            digitalWrite(display_pins[d].port,
                    display_pins[d].pin,
                    LOW);
        }

        //update the segments
        //LATD = seg_table[display_buffer[i]];
        char c = display_buffer[i];
        LATD = (c < 128) ? seg_table[(uint8_t) c] : 0x00;


        //turn on the current display (active on high))
        digitalWrite(display_pins[i].port, display_pins[i].pin, HIGH);

        //simulates multiple. 
        //It will be refatored later to use timer
        __delay_ms(6);

        /* any pin still on outside */
        for (d = 0; d < DISPLAY_7_DIGITS; d++) {
            digitalWrite(display_pins[d].port,
                    display_pins[d].pin,
                    LOW);
        }

    }

}