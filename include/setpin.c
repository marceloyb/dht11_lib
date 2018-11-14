#include "setpin.h"

uint8_t finalpos(uint8_t position){
	uint8_t finalpin;
	finalpin = position % 8;
	return finalpin;
}

void setpinmode(uint8_t mode, uint8_t position){
	// input = clr
	// output = set
	uint8_t pin;


	pin = finalpos(position);

	if (position >= 8){
		// input
		if (mode == 0){
			clr_bit(DDRB, pin);
		}
		// output
		if (mode == 1){
			set_bit(DDRB, pin);
		}

		// pullup

		if(mode == 2){
			clr_bit(DDRB, pin);
			set_bit(PORTB, pin);
		}
	}
	if (position < 8){
		// input
		if (mode == 0){
			clr_bit(DDRD, pin);
		}
		// output
		if (mode == 1){
			set_bit(DDRD, pin);
		}

		// pullup
		if(mode == 2){
			clr_bit(DDRD, pin);
			set_bit(PORTD, pin);
		}
	}

}

void setpinvalue(uint8_t value, uint8_t position){
	// input = clr
	// output = set
	uint8_t pin;


	pin = finalpos(position);

	if (position >= 8){
		// value
		if (value == 0){
			clr_bit(PORTB, pin);
		}
		// high
		if (value == 1){
			set_bit(PORTB, pin);
		}
	}
	if (position < 8){
		// low
		if (value == 0){
			clr_bit(PORTD, pin);
		}
		// high
		if (value == 1){
			set_bit(PORTD, pin);
		}

	}

}

uint8_t issetbit(uint8_t position){
	uint8_t pin;
	// uint8_t returnvalue = 0;
	pin = finalpos(position);


	if (isset_bit(*pin_map[position].PIN, pin)){
		return 1;
	}

	return 0;
}


uint32_t read_data(uint8_t value, uint8_t position){
	
	uint32_t time = 0;


	while (issetbit(position) == value){
		time++;
		_delay_us(1);
	}

	return time;

}