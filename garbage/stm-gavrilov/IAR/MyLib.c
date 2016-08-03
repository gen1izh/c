#include "stm8s_gpio.h"

/*
void GPIO_ExternalInterruptConfig(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, FunctionalState NewState)
{
  // Check the parameters
  assert_param(IS_GPIO_PIN_OK(GPIO_Pin));
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));
  if (NewState != DISABLE) // External Pull-Up Set
  {
    GPIOx->CR2 |= (uint8_t)GPIO_Pin;
  }
  else // External Pull-Up Reset
  {
    GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
  }
}
*/

void GPIO_ExternalInterruptConfigPort(GPIO_TypeDef* GPIOx, FunctionalState NewState)
{
  if (NewState != DISABLE) // External Pull-Up Set
  {
    GPIOx->CR2 = 0xFF;
  }
  else // External Pull-Up Reset
  {
    GPIOx->CR2 = 0x00;
  }
}

void assert_failed(uint8_t* file, uint32_t line)
{
  while (1);
}