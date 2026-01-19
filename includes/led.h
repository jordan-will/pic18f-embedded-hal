/*
 * File:   main.c
 * Author: Jordan Willian Marques Pereira
 *
 * Created on 18 de Janeiro de 2026, 17:38
 */

#ifndef LED_H
#define LED_H

#include <stdint.h>

/* ================= CONFIG ================= */

/* 1 = LED active on  HIGH | 0 = led active on LOW */
#define LED_ACTIVE_HIGH   1

/* 1 = LEDs start on | 0 = LEDs start off */
#define LED_START_ON      0

/* ================================================= */

void led_init(void);
void led_on(uint8_t led);
void led_off(uint8_t led);
void led_toggle(uint8_t led);

#endif
