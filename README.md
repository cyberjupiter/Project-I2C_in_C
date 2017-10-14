# Project I2C_in_C

This is a library that can be used with AVR-GCC compiler. This library works directly with Arduino UNO and should work with other Arduino that shares the same SDA and SCL pins. This library also works with AVR microcontrollers, but with slight modification in I2CinC.h.

To port it to AVR microcontroller, and simply redefine this lines I2CinC.h 
```
#define SDA A4
#define SCL A5
```
to your AVR's SDA and SCL pins.
