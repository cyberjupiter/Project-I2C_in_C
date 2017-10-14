# Project I2C_in_C

This is a I2C/TwoWire library that can be used with AVR-GCC compiler. This library works directly with Arduino UNO and should work with other Arduino that shares the same SDA and SCL pins. This library also works with 8-bit AVR microcontrollers, but with slight modification in I2CinC.h.

To port it to AVR microcontroller, simply redefine this lines in I2CinC.h 
```
#define SDA A4
#define SCL A5
```
to your AVR's SDA and SCL pins.

## Credit

Thanks to Peter Fleury for his polling function [Peter Fleury I2C-master-lib](http://homepage.hispeed.ch/peterfleury/i2cmaster.zip).
