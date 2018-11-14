#include "setpin.h"
#include "bitop.h"
#include "uart.h"


typedef struct{
	uint8_t pin;

	struct {
		uint8_t temp;
		uint8_t hum;
	} value;

} SENSOR;

void sensor_read(SENSOR *dht11);