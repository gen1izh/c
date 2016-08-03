#include "stm8s.h"
#include "stm8s_gpio.h"

struct button {
  GPIO_TypeDef*       GPIOx;    /* Порт */
  GPIO_Pin_TypeDef    GPIO_Pin; /* Ножка порта */
  unsigned char       Push;     /* Событие нажатия */ 
  unsigned int        Delay;    /* Задержка */
};


/**
 *  Инициализация кнопок пульта управления
 */
extern void InitButton(struct button BUTTON);

/**
 * Сброс кнопки
 */
extern void ResetButton(struct button *BUTTON);

/**
  * @brief  Configures the external pull-up on GPIOx pins.
  * @param  GPIOx : Select the GPIO peripheral number (x = A to I).
  * @param  GPIO_Pin : Specifies the pin number
  * @param  NewState : The new state of the pull up pin.
  * @retval None
  */
extern void GPIO_ExternalInterruptConfig(GPIO_TypeDef* GPIOx, 
                                         GPIO_Pin_TypeDef GPIO_Pin, 
                                         FunctionalState NewState);