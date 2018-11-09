#include "dht11.h"

void sensor_read(sensor *dht11){

	uint8_t i;
	// 5 bytes of data [16 h, 16 t, 8 chcksum]
	uint8_t data[5];
	uint8_t bits[40];

	//  set sensor power and wait
	setpinmode(1, dht11->pin);
	setpinvalue(1, dht11->pin);
	_delay_ms(2000);

	//	send start signal
	//	set low and wait 20ms

	setpinvalue(0, dht11->pin);
	_delay_ms(20);

	//	set high and wait 40us

	setpinvalue(1, dht11->pin);
	_delay_us(40); 

	// wait 80us then 80us again and data transfer start

	_delay_us(80);

	_delay_us(80);

	// read 40 bits of data

	for(i = 0; i < 40; i++){
		// 50 us start of transmission (low)
		while (issetbit(dht11->pin) == 0);

		// after 50us in low, read data (if <30us transmission length is 0 bit, else 1 bit)
		
		if (sensor_read(dht11->pin) > 30){
			bits[i] = 1;
		}
		else 
			bits[i] = 0;
	}

}