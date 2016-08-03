#include "stm8s.h"
#include "HD44780.h"

int main(void) 
{
	InitLcd(GPIOB, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_LNIB);

	Out(0, "DareDen&STM8 for");
	Out(1, "easyelectronics.");

	while(1)
		;
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{ 
  while (1)
  {
  }
}
#endif
