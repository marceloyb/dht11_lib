#include "setpin.h"
#include "bitop.h"


typedef struct{
	uint8_t pin;

	struct {
		uint8_t temp;
		uint8_t hum;
	} value;

} sensor;

void sensor_read(sensor *dht11);