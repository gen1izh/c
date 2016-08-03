/*
 * main.c
 *
 *  Created on: 10.05.2013
 *      Author: zalogix
 */
#include <avr/io.h>
#include <util/delay.h>

typedef enum {
	SUCCESFULL,
	ADC_NO_DATA
} ADC_STATES;

void ADC_set_prescaler(int prescaler) {
ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

void ADC_set_reference() {
ADMUX |= (1<<ADLAR);
}

void ADC_start() {
	ADCSRA |= (1 << ADATE);
	ADCSRA |= (1 << ADIE);
	ADCSRA |=(1<<ADEN);
	ADCSRA |=(1<<ADSC);
}

int ADC_read(int *data) {
	if (ADCSRA&(1<<ADIF)) {
		ADCSRA|=(1<<ADIF);
		*data =(int) ((int)(ADCH<<8) + (int)(0xFF & ADCL));
	return SUCCESFULL;
	}
return ADC_NO_DATA;
}

int main() {
	ADC_set_prescaler(124);
	ADC_set_reference();
	ADC_start();

	ADC_STATES status;

	DDRB=0xFF;
	int data;
	while (1) {
	   status = ADC_read(&data);
	   if (status == SUCCESFULL) {
		  PORTB = (unsigned char) data;
		  _delay_ms(2000);
	   }
	}

	return 0;
}
