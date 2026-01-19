/*
 * File:   main.c
 * Author: Jordan Willian Marques Pereira
 *
 * Created on 17 de Janeiro de 2026, 17:38
 */

#include "debounce.h"

#define DEBOUNCE_LIMIT 5

void debounce_init(debounce_t *btn){
    btn->stable_count = 0;
    btn->pressed = 0;
}

uint8_t debounce_update(debounce_t *btn, uint8_t raw_state){
    if(!raw_state){//btn pressed (0 -> active)
        if(btn->stable_count < DEBOUNCE_LIMIT){
            btn->stable_count++;
        }
        else if(!btn->pressed){
            btn->pressed = 1;
            return 1;
        }
    }
    else{
        btn->stable_count = 0;
        btn->pressed = 0;
    }
    
    return 0;
}