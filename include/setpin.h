#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>
#include "bitop.h"

#ifndef _setpin_h
#define _setpin_h

#define input 0
#define output 1
#define pullup 2

#define low 0
#define high 1

uint8_t finalpos(uint8_t position);

void setpinmode(uint8_t mode, uint8_t position);

void setpinvalue(uint8_t value, uint8_t position);

uint8_t issetbit(uint8_t position);

uint32_t read_data(uint8_t value, uint8_t position);

#endif

