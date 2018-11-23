# dht11 Libraries Pack

###### **This pack of libraries was made with the intention of making the life of atmega328p microcontroller programmers easier, when using the dht11 temp and hum sensor and wanting to show it on a LCD display**

-----------------

## The _dht11_ library
This library implements the DHT11 datasheet instructions, as to use the sensor and receive temp and hum informations. In the header is the declaration of the sensor, which is a struct where the pin connected in the arduino must be set. Also, this struct is where the temp and hum values are passed after the end of each "sensor_read" function, so it can be used by the programmer.

### sensor_read function:

The objective of this function is to read data with the sensor, as written in the DHT11 datasheet, and pass it to the SENSOR struct defined in the reader. 

To use it, one must declare the sensor, set the desired pin of the sensor, and pass it as argument to the function. To use the hum and temp values, just read it from the struct after the end of the sensor_read call.
