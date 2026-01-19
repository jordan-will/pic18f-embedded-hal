/*
 * File:   main.c
 * Author: Jordan Willian Marques Pereira
 *
 * Created on 17 de Janeiro de 2026, 17:38
 */

#ifndef DEBOUNCE_H
#define DEBOUNCE_H
#include <stdint.h>

typedef struct{
    uint8_t stable_count;
    uint8_t pressed;
} debounce_t;

void debounce_init(debounce_t *btn);

//raw_state directly read of pin
//return 1 if the event of pressing
uint8_t debounce_update(debounce_t *btn, uint8_t raw_state);

#endif