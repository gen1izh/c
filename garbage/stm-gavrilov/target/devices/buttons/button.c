#include "BUTTON.h"
#include "stm8s_conf.h"
#include "stm8s_gpio.h"

/**
 *  Инициализация кнопок пульта управления
 */
void InitButton(struct button BUTTON) {
  /* Для кнопки с подтяжкой через резистор и с прерыванием */
  GPIO_Init(BUTTON.GPIOx, 
            BUTTON.GPIO_Pin, 
            GPIO_MODE_IN_PU_IT);
}

/**
 * Сброс кнопки
 */
void ResetButton(struct button *BUTTON) {
  BUTTON->Push  = 0;
  BUTTON->Delay = 0;
}

/**
  * @brief  Configures the external pull-up on GPIOx pins.
  * @param  GPIOx : Select the GPIO peripheral number (x = A to I).
  * @param  GPIO_Pin : Specifies the pin number
  * @param  NewState : The new state of the pull up pin.
  * @retval None
  */
void GPIO_ExternalInterruptConfig(GPIO_TypeDef* GPIOx, 
                                  GPIO_Pin_TypeDef GPIO_Pin, 
                                  FunctionalState NewState) {
  /* Check the parameters */
  assert_param(IS_GPIO_PIN_OK(GPIO_Pin));
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));

  if (NewState != DISABLE) /* External Pull-Up Set*/ {
    GPIOx->CR2 |= (uint8_t)GPIO_Pin;
  } else /* External Pull-Up Reset*/ {
    GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
  }
}


