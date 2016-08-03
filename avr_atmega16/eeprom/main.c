/*
 * main.c
 *
 *  Created on: 09.05.2013
 *      Author: zalogix
 */

#include <avr/io.h>
#include <util/delay.h>

void EEPROM_write(unsigned int uiAddress, unsigned char ucData) {
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address and data registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
}


unsigned char EEPROM_read(unsigned int uiAddress) {
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}

int main() {
	DDRB=0xFF;
	unsigned int addr = 0x10;

	_delay_ms(2000);
	PORTB = EEPROM_read(addr);

	_delay_ms(2000);
	EEPROM_write(addr, 0x55);

	_delay_ms(2000);
	PORTB = EEPROM_read(addr);

	while(1) {}

	return 0;
}
