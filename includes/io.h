#ifndef IO_H
#define IO_H

#include <stdint.h>
#include <xc.h>

#define INPUT 1
#define OUTPUT 0

#define LOW 0
#define HIGH 1

typedef enum {
    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E
} io_port_t;

void pinMode(io_port_t port, uint8_t pin, uint8_t mode);
void digitalWrite(io_port_t port, uint8_t pin, uint8_t value);
uint8_t digitalRead(io_port_t port, uint8_t pin);

#endif