//I2CinC.h

#ifdef __cplusplus
extern "C" {
#endif

#ifndef I2CinC_h
#define I2CinC_h
	
#define READ  0x01
#define WRITE 0x00

#define SDA	A4
#define SCL	A5

void I2C_init(void);
void I2C_start(void);
void I2C_restart(void);
uint8_t I2C_writeData(uint8_t data);
uint8_t I2C_writeAddress(uint8_t address);
uint8_t I2C_read_nack(void);
uint8_t I2C_read_ack(void);
void I2C_stop(void);

#endif

#ifdef __cplusplus
} // extern "C"
#endif
