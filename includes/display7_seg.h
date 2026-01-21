#ifndef DISPLAY_7_SEG_H
#define DISPLAY_7_SEG_H

#include <stdint.h>

//quantity of displays
#define DISPLAY_7_DIGITS 4

//init ports, buffer and states
void display_7_init(void);

//write a characterr on specific digit (buffer)
void display_7_setchar(uint8_t, char c);

//write a integer number on buffer
void display_7_setnumber(uint16_t value);

//update the display (multiplex))
void display_7_update(void);

#endif