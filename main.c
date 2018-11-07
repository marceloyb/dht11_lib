#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>
#include <stdbool.h>
#include "include/setpin.h"
#include "include/uart.h"

#define swt_bit(reg, pos) (reg ^= (1 << pos))	// mudança de estado
#define clr_bit(reg, pos) (reg &= ~(1 << pos))	// limpar os bits de uma pos
#define set_bit(reg, pos) (reg |= (1 << pos))	// setar bits 
#define isset_bit(reg, pos) (reg & (1 << pos)) // check if bit set

#define input 0
#define output 1



int main(void){	
	uart_init();

	

	return 0;
}
