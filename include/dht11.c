#include "dht11.h"

void sensor_read(SENSOR *dht11){

	uint8_t i;
	uint8_t j;
	uint8_t byte;
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

	// set pull up
	setpinmode(2, dht11->pin);

	// wait 80us then 80us again and data transfer start

	_delay_us(80);

	_delay_us(80);

	// read 40 bits of data

	for(i = 0; i < 40; i++){
		// 50 us start of transmission (low)
		while (issetbit(dht11->pin) == 0);

		// after 50us in low, read data (if <30us transmission length = 0 bit, else 1 bit)
		
		if (read_data(1, dht11->pin) > 30){
			bits[i] = 1;
		}
		else 
			bits[i] = 0;
	}

	// puts the data in the array of 5 bytes

	for (i = 0; i < 5; i++){
		byte = 0;
		// set bytes with the bits received from dht11
		for (j = 0; j < 8; j++){
			byte |= bits[i * 8 + j] << (7 - j);
		}
		data [i] = byte;
	}

	// sets the data value in the sensor
	// first 16 bits = humidity
	// next 16 bits = temperature
	// not using the checksum

	dht11->value.hum = data[0];
	dht11->value.temp = data[2];

}