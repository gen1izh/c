#include <p24fj128ga010.h>

void Delay(void) {
  unsigned long cnt = 10000;
  while  ( cnt != 0 ) cnt--; 
}


void main(void) {
  TRISA = 0xFFFE;
  PORTAbits.RA0 = 1;

  while (1)
  {
	PORTAbits.RA0 = ~PORTAbits.RA0;
    Delay();
  }

}