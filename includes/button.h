/*
 * File:   main.c
 * Author: Jordan Willian Marques Pereira
 *
 * Created on 18 de Janeiro de 2026, 17:38
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>

/* ================= CONFIG ================= */

/* 1 = button active on HIGH | 0 = button active on LOW */
#define BUTTON_ACTIVE_HIGH   0

/* ================================================= */

void button_init(uint8_t mask);
uint8_t button_raw(uint8_t pin);

#endif
