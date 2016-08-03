// #include "stm8s.h"
// #include "stm8s_conf.h"

#include "ports.h"
#include "stm8s_gpio.h"
#include "stm8s_clk.h"
#include "stm8s_tim2.h"
#include "stm8s_tim3.h"
#include "stm8s_tim4.h"
#include "LCDDefine.h"
#include "data.h"

// #include "stm8s_it.h"

#define TIM2_PERIOD  (uint16_t) 0xFFFF
#define TIM3_PERIOD  (uint16_t) 0xFFFF
// #define TIM3_PULSE   (uint8_t) 0x7F
#define TIM4_PERIOD  (uint8_t) 0xFF

//static void CLK_Config();
//static void TIM2_Config();
//static void TIM3_Config();
//static void TIM4_Config();
//void GPIO_Config();


/*
 * Настройка clock
 */
void CLK_Config() {
  /* Источник тактирования внешний */
  CLK_HSECmd(ENABLE);
  /* (Настройка авто, Внешний кварц, Прерывания запретить, HSI не требуется): */
  CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO,
                        CLK_SOURCE_HSE,
                        DISABLE,
                        CLK_CURRENTCLOCKSTATE_DISABLE);

  CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV128);

  /*
  CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1);
  CLK_ClockSecuritySystemEnable(); // Включение CSS (Clock security system)
  */
}

/*
 *
 */
void TIM2_Config() {
  /* Включаем тактирование */
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER3,
                            ENABLE);
  /* Установка предделителя (TIM2_PSCR) и регистров TIM2_ARRH и ARRL */
  TIM2_TimeBaseInit(TIM2_PRESCALER_16,
                    TIM2_PERIOD);
  TIM2_ClearFlag(TIM2_FLAG_UPDATE);
  /* Update interrupt enabled (Бит UIE регистра TIM2_IER) */
  TIM2_ITConfig(TIM2_IT_UPDATE, ENABLE);
  /* Прерывание только по переполнению (TIM2_CR1_URS = 1) */
  TIM2_UpdateRequestConfig(TIM2_UPDATESOURCE_REGULAR);
  TIM2_Cmd(ENABLE);
}

/*
 *
 */
void TIM3_Config() {
  /* Включаем тактирование */
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER3, ENABLE);
  /* Установка предделителя (TIM3_PSCR) и регистров TIM3_ARRH и ARRL */
  TIM3_TimeBaseInit(TIM3_PRESCALER_16, TIM3_PERIOD);
  TIM3_ClearFlag(TIM3_FLAG_UPDATE);
  /* Update interrupt enabled (Бит UIE регистра TIM3_IER) */
  TIM3_ITConfig(TIM3_IT_UPDATE, ENABLE);
  /* Прерывание только по переполнению (TIM3_CR1_URS = 1) */
  TIM3_UpdateRequestConfig(TIM3_UPDATESOURCE_REGULAR);
  TIM3_Cmd(ENABLE);
}

/*
 *
 */
void TIM4_Config() {
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4, ENABLE);
  TIM4_TimeBaseInit(TIM4_PRESCALER_128, TIM4_PERIOD);
  TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
  /* Прерывание только по переполнению (TIM4_CR1_URS = 1) */
  TIM4_UpdateRequestConfig(TIM4_UPDATESOURCE_REGULAR);
  TIM4_Cmd(DISABLE);
}

/*
 *
 */
void GPIO_Config() {
  /* Вход, подвязка к питанию, внешнее прерывание вкл. */
  GPIO_Init(GPIO_BUT1, PIN_BUT1,  GPIO_MODE_IN_PU_IT);
  GPIO_Init(GPIO_BUT2, PIN_BUT2,  GPIO_MODE_IN_PU_IT);
  GPIO_Init(GPIO_BUT3, PIN_BUT3,  GPIO_MODE_IN_PU_IT);
  GPIO_Init(GPIO_BUT4, PIN_BUT4,  GPIO_MODE_IN_PU_IT);
  GPIO_Init(GPIO_BUT5, PIN_BUT5,  GPIO_MODE_IN_PU_IT);
  GPIO_Init(GPIO_LED, PIN_LED,    GPIO_MODE_OUT_PP_LOW_SLOW);
  GPIO_Init(GPIO_E, PIN_E,        GPIO_MODE_OUT_PP_LOW_SLOW);
  GPIO_Init(GPIO_RW, PIN_RW,      GPIO_MODE_OUT_PP_LOW_SLOW);
  GPIO_Init(GPIO_RS, PIN_RS,      GPIO_MODE_OUT_PP_LOW_SLOW);
  GPIO_Init(GPIO_LT, PIN_LT,      GPIO_MODE_OUT_PP_LOW_SLOW);
}

/*
 * Основная функция
 */
void main(void) {
  CLK_Config();                       /* настройка клока */
  TIM2_Config();                      /**/
  TIM3_Config();                      /**/
  TIM4_Config();                      /**/
  GPIO_Config();                      /**/
  GPIO_WriteHigh(GPIO_LED, PIN_LED);  /**/
  GPIO_WriteHigh(GPIO_LED, PIN_LED);  /**/
  enableInterrupts();                 /**/


 InitDisplay();            /* Инициализация дисплея */
 init_cpm_variables();     /* Инициализация переменных меню */

  main_cpm_routine();       /* Запуск основного цикла работы с cpm */
}
