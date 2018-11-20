#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>
#include <string.h>
#include "include/setpin.h"
#include "include/dht11.h"
#include "include/LCD.h"
#include "include/bitop.h"

#define input 0
#define output 1


const char temperatura[] PROGMEM = 	"Temp:\0"; 	//mensagem armazenada na memória flash
const char umidade[] PROGMEM = 		"Umid:\0"; 

int main(void){	
	char tem[3], umi[4];

	DDRD = 0xFF; //PORTD como saída
    DDRB = 0xFF; //PORTB como saída

	inic_LCD_4bits(); //inicializa o LCD

	SENSOR sensor;
	sensor.pin = 10;

	while(1){
		sensor_read(&sensor);
		
		// transforma os valores lidos do sensor em string
		itos(sensor.value.temp, tem);
		itos(sensor.value.hum, umi);

		strcat(tem, "\337C");
		strcat(umi, "%");
		
	    cmd_LCD(0x01,0); 	// limpa display
	    cmd_LCD(0x80,0); 	// posiciona cursor na primeira posição

		escreve_LCD_Flash(temperatura);
		
		cmd_LCD(0x8C,0);	// alinha os valores
		escreve_LCD(tem);

		cmd_LCD(0xC0,0); 	//desloca cursor para a segunda linha
		escreve_LCD_Flash(umidade);
	    
		cmd_LCD(0xCD,0);	// alinha os valores

		_delay_ms(1000);
	}

	return 0;
}
