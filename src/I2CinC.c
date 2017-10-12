//I2CinC.c

#include <avr/io.h>
#include <compat/twi.h>

#include "Arduino.h"

#include "I2CinC.h"

void I2C_init(void)
{
	pinMode(SDA, OUTPUT);
	pinMode(SCL, OUTPUT);
	digitalWrite(SDA, 1);
	digitalWrite(SCL, 1);
	TWBR = 72;
}

void I2C_start(void) // transmit address
{
	// reset TWI control register
	TWCR = 0;
	// transmit START condition 
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	
	// check if the start condition was successfully transmitted
	if((TWSR & 0xF8) != TW_START){ return 1; }
	
	return 0;
}

void I2C_restart(void)
{ 
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	
	if( (TWSR & 0xF8) != TW_REP_START ){ return 1; }
	
	return 0;
}

uint8_t I2C_read_nack(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( !(TWCR & (1<<TWINT)) );
	
	return TWDR;
}

uint8_t I2C_read_ack(void)
{
	// start TWI module and acknowledge data after reception
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA); 
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	// return received data from TWDR
	return TWDR;
}

uint8_t I2C_writeAddress(uint8_t address)
{
	// load data into data register
	TWDR = address;
	// start transmission of data
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	
	if( (TWSR & 0xF8) != TW_MT_SLA_ACK ){ return 1; }
	
	return 0;
}

uint8_t I2C_writeData(uint8_t data)
{
	// load data into data register
	TWDR = data;
	// start transmission of data
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	
	if( (TWSR & 0xF8) != TW_MT_DATA_ACK ){ return 1; }
	
	return 0;
}

void I2C_stop(void)
{
	// transmit STOP condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	while(TWCR & (1<<TWSTO));
}
