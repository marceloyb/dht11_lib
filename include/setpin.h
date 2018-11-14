#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>
#include "bitop.h"
#include "uart.h"

#ifndef _setpin_h
#define _setpin_h

#define input 0
#define output 1
#define pullup 2

#define low 0
#define high 1

static const struct {
  volatile uint8_t *DDR;
  volatile uint8_t *PORT;
  volatile uint8_t *PIN;
} pin_map[] = {
    {&DDRD, &PORTD, &PIND}, // 0
    {&DDRD, &PORTD, &PIND}, // 1
    {&DDRD, &PORTD, &PIND}, // 2
    {&DDRD, &PORTD, &PIND}, // 3
    {&DDRD, &PORTD, &PIND}, // 4
    {&DDRD, &PORTD, &PIND}, // 5
    {&DDRD, &PORTD, &PIND}, // 6
    {&DDRD, &PORTD, &PIND}, // 7
    {&DDRB, &PORTB, &PINB}, // 8
    {&DDRB, &PORTB, &PINB}, // 9
    {&DDRB, &PORTB, &PINB}, // 10
    {&DDRB, &PORTB, &PINB}, // 11
    {&DDRB, &PORTB, &PINB}, // 12
    {&DDRB, &PORTB, &PINB}, // 13
    {&DDRB, &PORTB, &PINB}, // 14
    {&DDRB, &PORTB, &PINB}, // 15
};

uint8_t finalpos(uint8_t position);

void setpinmode(uint8_t mode, uint8_t position);

void setpinvalue(uint8_t value, uint8_t position);

uint8_t issetbit(uint8_t position);

uint32_t read_data(uint8_t value, uint8_t position);

#endif

