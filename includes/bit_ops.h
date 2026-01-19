/*
 * File:   main.c
 * Author: Jordan Willian Marques Pereira
 *
 * Created on 16 de Janeiro de 2026, 17:38
 */

#ifndef BIT_OPS_H
#define BIT_OPS_H

#include <stdint.h>

/*  bit on */
static inline void set_bit(volatile uint8_t *reg, uint8_t bit)
{
    *reg |= (uint8_t)(1U << bit);
}

/* bit off */
static inline void clear_bit(volatile uint8_t *reg, uint8_t bit)
{
    *reg &= (uint8_t)~(1U << bit);
}

/*  bit toggle */
static inline void toggle_bit(volatile uint8_t *reg, uint8_t bit)
{
    *reg ^= (uint8_t)(1U << bit);
}

/* read bit (0 ou 1) */
static inline uint8_t read_bit(volatile uint8_t *reg, uint8_t bit)
{
    return (uint8_t)((*reg >> bit) & 1U);
}

#endif
