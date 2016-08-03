/**
  ******************************************************************************
  * @file main.c
  * @brief Adjustable LED blinking speed using STM8S-DISCOVERY touch sensing key
  * Application example.
  * @author STMicroelectronics - MCD Application Team
  * @version V2.0.0
  * @date 15-MAR-2011
  ******************************************************************************
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2008 STMicroelectronics</center></h2>
  * @image html logo.bmp
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "stm8s_tim3.h"
#include "stm8s_gpio.h"
#include "stm8s_clk.h"
#include "stm8s_adc1.h"
#include "stm8s_tim4.h"
#include "BUTTON.h"
void CLK_Configuration(void);
void GPIO_Configuration(void);
void PWM_Timer3_init(void);
void Init_ADC(void);
void Init_Timer4(void);
volatile struct button BUTTON_PORTB_6={GPIOB,GPIO_PIN_6,0,0};
extern volatile uint16_t PWM;
extern volatile unsigned char ADCOLDHIGH;
extern volatile unsigned char ADCNEWHIGH;



extern void InitDisplay(void);


/**
  ******************************************************************************
  * @brief Main function.
  * @par Parameters:
  * None
  * @retval void None
  * @par Required preconditions:
  * None
  ******************************************************************************
  */
void main(void)
{
  /* ��������� ������������ */
  CLK_Configuration();

  /* ��������� ������ */
  GPIO_Configuration();
  InitDisplay();
  
  PWM_Timer3_init();
  InitButton(BUTTON_PORTB_6);
  Init_ADC();
  Init_Timer4();
  __enable_interrupt();
 for (;;)
  {
    if(ADCOLDHIGH!=ADCNEWHIGH)
    {
      //if(ADCOLDHIGH>0)
      ADCOLDHIGH=ADCNEWHIGH;
        TIM3_Cmd(DISABLE);
      TIM3_PrescalerConfig(ADCOLDHIGH,
                          TIM3_PSCRELOADMODE_UPDATE);
      TIM3_Cmd(ENABLE);
    }
    /* User code */
    //PWM=ADC1_GetConversionValue();
    //TIM3_SetCompare2(PWM);
  //  GPIO_WriteReverse(GPIOD, GPIO_PIN_0);
  //  ExtraCode_StateMachine();
   
	  /* Main function of the Touch Sensing library */
  
  //  TSL_Action();

  }

}
/*******************************************************************************
PWM_Timer3
*******************************************************************************/
void PWM_Timer3_init()
{
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER3, ENABLE);//�������� ������������
 // TIM3_SetCompare1(0x00FF);
 // TIM3_SetCompare2(0x1FFF);
  TIM3_SetAutoreload(0xFFFF);
   TIM3_PrescalerConfig(TIM3_PRESCALER_1,
                          TIM3_PSCRELOADMODE_UPDATE);
  TIM3_OC2Init(TIM3_OCMODE_PWM2,
                   TIM3_OUTPUTSTATE_ENABLE,
                  0x3FFF,
                  TIM3_OCPOLARITY_HIGH );
 // TIM3_SelectOCxM(TIM3_CHANNEL_2, TIM3_OCMODE_PWM1);
//  TIM3->CCMR2 = 0x60;          // PWM mode1
//  TIM3->CCER1 = 0x30;          // enable OC2 output pin (TIM3_CH2), polarity active low (LED from Vdd)
/* 
  TIM3_PWMIConfig(TIM3_CHANNEL_2,
                     TIM3_ICPOLARITY_RISING,//�� �����������
                     0x00,//����������� ��� ������ �� �����
                     TIM3_ICPSC_DIV1,//��� ��������
                     0x00);//��� ��������*/
  //TIM3_ITConfig(TIM3_IT_UPDATE, ENABLE);//���������������� ��������
  //TIM3_ITConfig(TIM3_IT_CC1, ENABLE);//
  //TIM3_ITConfig(TIM3_IT_CC2, ENABLE);//
  TIM3_Cmd(ENABLE);
/*  TIM3->PSCR  = TIM3_PRESCALER_32;             // prescaller to 1
  TIM3->CCMR2 = 0x60;          // PWM mode1
  TIM3->CCER1 = 0x30;          // enable OC2 output pin (TIM3_CH2), polarity active low (LED from Vdd)
  TIM3->ARRH  = 0xFF;          // PWM period to 0xFFFF cycles  - #ifdef USE_ARC_TABLE is enabled in "dali_config.h"
  TIM3->ARRL  = 0xFF;
  TIM3->CCR1H = 0x00;          // duty cycle is light level - #ifdef USE_ARC_TABLE is enabled in "dali_config.h"
  TIM3->CCR1L = 0xFF; 
  TIM3->CCR2H = 0x1F;          // duty cycle is light level - #ifdef USE_ARC_TABLE is enabled in "dali_config.h"
  TIM3->CCR2L = 0xFF;
  TIM3->CR1  |= TIM3_CR1_CEN;  // enable PWM counter*/
}

/**
  ******************************************************************************
  * @brief ��������� ������������
  * @par Parameters:
  * None
  * @retval void None
  * @par Required preconditions:
  * None
  ******************************************************************************
  */
void CLK_Configuration(void)
{
 // CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
  CLK_HSECmd(ENABLE);//�������� ������������ ������� 
  CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSE, DISABLE, CLK_CURRENTCLOCKSTATE_ENABLE);// (��������� ����, ������� �����, ��������� ����������, HSI ���������)
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
  CLK_ClockSecuritySystemEnable();  
// CLK_CCOConfig(CLK_OUTPUT_HSE);
// CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
// CLK_SWIMConfig(CLK_SWIMDIVIDER_OTHER);
}

/**
  ******************************************************************************
  * @brief Configures GPIOs
  * @par Parameters:
  * None
  * @retval void None
  * @par Required preconditions:
  * None
  ******************************************************************************
  */
void GPIO_Configuration(void)
{
  /* GPIOD ���������� �� ��������� */
  GPIO_DeInit(GPIOD);
  /* ����������� PD0 (LED1) �� ����� push-pull nigh  */
  GPIO_Init(GPIOD, GPIO_PIN_0, GPIO_MODE_OUT_PP_LOW_FAST);//��� ���������� ��� ���
  GPIO_Init(GPIOB, GPIO_PIN_7, GPIO_MODE_IN_FL_NO_IT);//��� ADC ��� ��������
  GPIO_Init(GPIOB, GPIO_PIN_6, GPIO_MODE_IN_PU_IT);//��� ������ � ��������� ����� �������� � � �����������
 /* PB_DDR_bit.DDR6=0;        //PB6 - �� ����
  PB_CR1_bit.C16=1;         //PB6 - �������� � �������
  PB_CR2_bit.C26=0;         //PB6 - ������ ����������*/
}
/**
  ******************************************************************************
  * @brief ��������� ���
  * @par Parameters:
  * None
  * @retval void None
  * @par Required preconditions:
  * None
  ******************************************************************************
  */
void Init_ADC()
{
   CLK_PeripheralClockConfig(CLK_PERIPHERAL_ADC, ENABLE);//�������� ������������
   ADC1_Init(ADC1_CONVERSIONMODE_SINGLE,
             ADC1_CHANNEL_7,
             ADC1_PRESSEL_FCPU_D2,
             ADC1_EXTTRIG_TIM,
             DISABLE,
             ADC1_ALIGN_RIGHT,
             ADC1_SCHMITTTRIG_CHANNEL7,
             DISABLE);//��������
   ADC1_Cmd(ENABLE);//��������
   ADC1_ITConfig(ADC1_IT_EOCIE, ENABLE);//��������� ���������� �� 7 �����
   ADC1_StartConversion(); //�������� ���������������   
}
/**
  ******************************************************************************
  * @brief ��������� ���
  * @par Parameters:
  * None
  * @retval void None
  * @par Required preconditions:
  * None
  ******************************************************************************
  */
void Init_Timer4()
{
  CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4, ENABLE);//�������� �����
  TIM4_TimeBaseInit(TIM4_PRESCALER_128, 0xFF);//������������ � ������� ������
  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);//�������� ����������
  TIM4_UpdateRequestConfig(TIM4_UPDATESOURCE_REGULAR);//���������� �� ������������
  TIM4_Cmd(ENABLE);//�������� ������ 4
}
