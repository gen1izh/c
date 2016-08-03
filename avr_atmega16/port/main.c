/*
 * main.c
 *
 *  Created on: 07.05.2013
 *      Author: zalogix
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRB=0xFF;
	while(1) {
		_delay_ms(2000);
		PORTB=0xFF;
		_delay_ms(2000);
		PORTB=0x0;
	}
}
