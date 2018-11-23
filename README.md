# dht11 Libraries Pack

###### **This pack of libraries was made with the intention of making the life of atmega328p microcontroller programmers easier, when using the dht11 temp and hum sensor and wanting to show it on a LCD display**

-----------------

## The _setpin_ library
This library intends to manipulate the I/O digital pins

### finalpos function:

The objective of this function is to return the position of the pin according to the position passed as argument.

### setpinmode function:

The objective of this function is to set a pin as input or output. The first argument of the function is the mode wanted (0 for input and 1 for output), and the second argument is the position of the pin in the arduino.

### setpinvalue function:

The objective of this function is to set a pin value as high or low. The first argument is the value (0 for low and 1 for high), and the second argument is the position of the pin in the arduino.

-----------------

## The _dht11_ library
This library implements the DHT11 datasheet instructions, as to use the sensor and receive temp and hum informations. In the header is the declaration of the sensor, which is a struct where the pin connected in the arduino must be set. Also, this struct is where the temp and hum values are passed after the end of each "sensor_read" function, so it can be used by the programmer.

### sensor_read function:

The objective of this function is to read data with the sensor, as written in the DHT11 datasheet, and pass it to the SENSOR struct defined in the reader. 

To use it, one must declare the sensor, set the desired pin of the sensor, and pass it as argument to the function. To use the hum and temp values, just read it from the struct after the end of the sensor_read call.

-----------------

## The _LCD_ library
This library intends to manipulate the 16x4 LCD with a 4 bits data interface

### the inic_LCD_4bits function

The objective of this function is to initialize the LCD display, by setting its pins and clearing the display and setting its cursor on the first position of the LCD

### the cmd_LCD function

The objective of this function is to control all operations on the LCD, it has 2 parameters the data that the function will work on and a flag that if its value is 0, it will just do an instruction (like positioning cursor, clearing it, turning it off, and more), if its value is 1, the function will know its data is a charater and it should be written.

### the show_on_LCD function

The objective of this function is to prepare the temperature and humidity values received by parameters called by the main function, by casting its values (int) to string, using itos function. In this function we write messagens stored on memorie and set the LCD cursor on the right position to write the values readed by the sensor.

### the write_LCD and write_LCD_FLASH function

The objective of these function is to iterate on the string desired to be written and call the cmd_LCD function. The main difference between write_LCD and write_LCD_FLASH function is where the string is stored, if in RAM memory or flash.

### the itos function

The objective of this function is similar to itoa function of string library in c, it casts an int value to a string so it can be used by the write_LCD and cmd_LCD functions
