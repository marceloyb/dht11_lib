#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>
#include <stdbool.h>
#include "include/setpin.h"
#include "include/uart.h"
#include "include/dht11.h"

#define swt_bit(reg, pos) (reg ^= (1 << pos))	// mudança de estado
#define clr_bit(reg, pos) (reg &= ~(1 << pos))	// limpar os bits de uma pos
#define set_bit(reg, pos) (reg |= (1 << pos))	// setar bits 
#define isset_bit(reg, pos) (reg & (1 << pos)) // check if bit set

#define input 0
#define output 1



int main(void){	
	uart_init();

	SENSOR sensor;
	sensor.pin = 10;

	while(1){
		sensor_read(&sensor);
		printf ("temperatura: %d\n", sensor.value.temp);
		printf ("humidade: %d\n", sensor.value.hum);
		_delay_ms(1000);
	}

	return 0;
}
