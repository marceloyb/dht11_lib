#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>
#include <string.h>
#include "include/setpin.h"
#include "include/dht11.h"
#include "include/LCD.h"
#include "include/bitop.h"

int main(void){	

	inic_LCD_4bits(); // inicializa o LCD

	SENSOR sensor;
	sensor.pin = 10; // seta o pino de dados do sensor

	while(1){
		sensor_read(&sensor);
				
		show_on_LCD(sensor.value.temp,sensor.value.hum); // com a leitura do sensor, faz-se a escrita no lcd

		_delay_ms(1000);
	}

	return 0;
}
