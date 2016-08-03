#include "stm8s.h"
#include "stm8s_gpio.h"

struct button {
  GPIO_TypeDef*       GPIOx;    /* ���� */
  GPIO_Pin_TypeDef    GPIO_Pin; /* ����� ����� */
  unsigned char       Push;     /* ������� ������� */ 
  unsigned int        Delay;    /* �������� */
};


/**
 *  ������������� ������ ������ ����������
 */
extern void InitButton(struct button BUTTON);

/**
 * ����� ������
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