#include "ports.h"
#include "stm8s_it.h"
#include "stm8s_TIM4.h"
#include "MyLib.h"
#include "data.h"
#include "LCDDefine.h"

/* Код актуальной нажатой кнопки */
extern unsigned char  actual_button;

/* Признак того что кнопка была нажата */
extern bool           is_pressed;

INTERRUPT_HANDLER(TLI_IRQHandler, 0)
{
  ;
}

INTERRUPT_HANDLER(AWU_IRQHandler, 1)
{
  ;
}

INTERRUPT_HANDLER(CLK_IRQHandler, 2)
{
  ;
}

INTERRUPT_HANDLER(EXTI_PORTA_IRQHandler, 3)
{
  ;
}

INTERRUPT_HANDLER(EXTI_PORTB_IRQHandler, 4)
{
  ;
}

INTERRUPT_HANDLER(EXTI_PORTC_IRQHandler, 5)
{
  ;
}

INTERRUPT_HANDLER(EXTI_PORTD_IRQHandler, 6)
{
  switch(GPIO_ReadInputData(GPIO_BUT1) & 0x9C) // 0x9C (10011100) - маска кнопок
  {
    case 0x8C: // Нажата кнопка SB1
    {
      GPIO_WriteLow(GPIO_LED, PIN_LED);
      // GPIO_WriteHigh(GPIO_LT, PIN_LT);
     
      if ( is_pressed != TRUE ) {
        actual_button = BUTTON1_CODE;
        is_pressed    = TRUE;
      }
      
      break;
    }
    case 0x94: // Нажата кнопка SB2
    {
      GPIO_WriteHigh(GPIO_LED, PIN_LED);
      // GPIO_WriteLow(GPIO_LT, PIN_LT);
      if ( is_pressed != TRUE ) {
        actual_button = BUTTON2_CODE;
        is_pressed    = TRUE;
      }
      break;
    }
    case 0x98: // Нажата кнопка SB3
    {
      // GPIO_WriteHigh(GPIO_LT, PIN_LT);
      if ( is_pressed != TRUE ) {
        actual_button = BUTTON3_CODE;
        is_pressed    = TRUE;
      }
      break;
    }
    case 0x1C: // Нажата кнопка SB4
    {
      if ( is_pressed != TRUE ) {
        actual_button = BUTTON4_CODE;
        is_pressed    = TRUE;
      }
    }
  }
  GPIO_ExternalInterruptConfigPort(GPIO_BUT1, DISABLE);
  TIM4_Cmd(ENABLE);
}

INTERRUPT_HANDLER(EXTI_PORTE_IRQHandler, 7)
{
  ;
}

INTERRUPT_HANDLER(SPI_IRQHandler, 10)
{
  ;
}

INTERRUPT_HANDLER(TIM1_UPD_OVF_TRG_BRK_IRQHandler, 11)
{
  ;
}

INTERRUPT_HANDLER(TIM1_CAP_COM_IRQHandler, 12)
{
  ;
}

INTERRUPT_HANDLER(TIM2_UPD_OVF_BRK_IRQHandler, 13)
{
  TIM2_ClearITPendingBit(TIM2_IT_UPDATE);
}

INTERRUPT_HANDLER(TIM2_CAP_COM_IRQHandler, 14)
{
  ;
}

INTERRUPT_HANDLER(TIM3_UPD_OVF_BRK_IRQHandler, 15)
{
  TIM3_ClearITPendingBit(TIM3_IT_UPDATE);
}

INTERRUPT_HANDLER(TIM3_CAP_COM_IRQHandler, 16)
{
  ;
}

INTERRUPT_HANDLER(I2C_IRQHandler, 19)
{
  ;
}

INTERRUPT_HANDLER(UART2_TX_IRQHandler, 20)
{
  ;
}

INTERRUPT_HANDLER(UART2_RX_IRQHandler, 21)
{
  ;
}

INTERRUPT_HANDLER(ADC1_IRQHandler, 22)
{
  ;
}

INTERRUPT_HANDLER(TIM4_UPD_OVF_IRQHandler, 23)
{
  GPIO_ExternalInterruptConfigPort(GPIO_BUT1, ENABLE);
  TIM4_Cmd(DISABLE);
  TIM4_ClearITPendingBit(TIM4_IT_UPDATE);
}

INTERRUPT_HANDLER(EEPROM_EEC_IRQHandler, 24)
{
  ;
}
