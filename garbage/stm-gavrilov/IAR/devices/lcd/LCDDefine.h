#ifndef _LCD_DEFINE 
#define _LCD_DEFINE

#include "stm8s.h"
#include "stm8s_gpio.h"

//ќпределени€ (Ўина данных)
//GPIOB, GPIO_PIN_6
//DB0 -
#define db0_0    GPIO_WriteLow(GPIOB, GPIO_PIN_0)
#define db0_1    GPIO_WriteHigh(GPIOB, GPIO_PIN_0)
#define db0_out  GPIO_Init(GPIOB, GPIO_PIN_0, GPIO_MODE_OUT_PP_LOW_FAST)
#define db0_in   GPIO_Init(GPIOB, GPIO_PIN_0, GPIO_MODE_IN_FL_NO_IT)
#define db0_in_1 GPIO_ReadInputPin(GPIOB, GPIO_PIN_0)
//DB1 - 
#define db1_0    GPIO_WriteLow(GPIOB, GPIO_PIN_1)
#define db1_1    GPIO_WriteHigh(GPIOB, GPIO_PIN_1)
#define db1_out  GPIO_Init(GPIOB, GPIO_PIN_1, GPIO_MODE_OUT_PP_LOW_FAST)
#define db1_in   GPIO_Init(GPIOB, GPIO_PIN_1, GPIO_MODE_IN_FL_NO_IT)
#define db1_in_1 GPIO_ReadInputPin(GPIOB, GPIO_PIN_1)
//DB2 - 
#define db2_0    GPIO_WriteLow(GPIOB, GPIO_PIN_2)
#define db2_1    GPIO_WriteHigh(GPIOB, GPIO_PIN_2)
#define db2_out  GPIO_Init(GPIOB, GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_FAST)
#define db2_in   GPIO_Init(GPIOB, GPIO_PIN_2, GPIO_MODE_IN_FL_NO_IT)
#define db2_in_1 GPIO_ReadInputPin(GPIOB, GPIO_PIN_2)
//DB3 - 
#define db3_0    GPIO_WriteLow(GPIOB, GPIO_PIN_3)
#define db3_1    GPIO_WriteHigh(GPIOB, GPIO_PIN_3)
#define db3_out  GPIO_Init(GPIOB, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST)
#define db3_in   GPIO_Init(GPIOB, GPIO_PIN_3, GPIO_MODE_IN_FL_NO_IT)
#define db3_in_1 GPIO_ReadInputPin(GPIOB, GPIO_PIN_3)
//DB4 - 
#define db4_0    GPIO_WriteLow(GPIOC, GPIO_PIN_4)
#define db4_1    GPIO_WriteHigh(GPIOC, GPIO_PIN_4)
#define db4_out  GPIO_Init(GPIOC, GPIO_PIN_4, GPIO_MODE_OUT_PP_LOW_FAST)
#define db4_in   GPIO_Init(GPIOC, GPIO_PIN_4, GPIO_MODE_IN_FL_NO_IT)
#define db4_in_1 GPIO_ReadInputPin(GPIOC, GPIO_PIN_4)
//DB5 - 

#define db5_0    GPIO_WriteLow(GPIOC, GPIO_PIN_5)
#define db5_1    GPIO_WriteHigh(GPIOC, GPIO_PIN_5)
#define db5_out  GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST)
#define db5_in   GPIO_Init(GPIOC, GPIO_PIN_5, GPIO_MODE_IN_FL_NO_IT)
#define db5_in_1 GPIO_ReadInputPin(GPIOC, GPIO_PIN_5)

//DB6 - 
#define db6_0    GPIO_WriteLow(GPIOC, GPIO_PIN_6)
#define db6_1    GPIO_WriteHigh(GPIOC, GPIO_PIN_6)
#define db6_out  GPIO_Init(GPIOC, GPIO_PIN_6, GPIO_MODE_OUT_PP_LOW_FAST)
#define db6_in   GPIO_Init(GPIOC, GPIO_PIN_6, GPIO_MODE_IN_FL_NO_IT)
#define db6_in_1 GPIO_ReadInputPin(GPIOC, GPIO_PIN_6)

//DB7 -
#define db7_0    GPIO_WriteLow(GPIOC, GPIO_PIN_7)
#define db7_1    GPIO_WriteHigh(GPIOC, GPIO_PIN_7)
#define db7_out  GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_OUT_PP_LOW_FAST)
#define db7_in   GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_IN_FL_NO_IT)
#define db7_in_1 GPIO_ReadInputPin(GPIOC, GPIO_PIN_7)

//ќпределени€ (Ўина данных)

//ќпределени€ (”правл€ющие выводы)

#define RD_WR_0    GPIO_WriteLow(GPIOC, GPIO_PIN_2)
#define RD_WR_1    GPIO_WriteHigh(GPIOC, GPIO_PIN_2)
#define RD_WR_out  GPIO_Init(GPIOC, GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_FAST)
#define RD_WR_in   GPIO_Init(GPIOC, GPIO_PIN_2, GPIO_MODE_IN_FL_NO_IT)
#define RD_WR_in_1 GPIO_ReadInputPin(GPIOC, GPIO_PIN_2)

#define RES_0    GPIO_WriteLow(GPIOC, GPIO_PIN_3)
#define RES_1    GPIO_WriteHigh(GPIOC, GPIO_PIN_3)
#define RES_out  GPIO_Init(GPIOC, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST)
#define RES_in   GPIO_Init(GPIOC, GPIO_PIN_3, GPIO_MODE_IN_FL_NO_IT)
#define RES_in_1 GPIO_ReadInputPin(GPIOC, GPIO_PIN_3)

#define E_WR_0    GPIO_WriteLow(GPIOC, GPIO_PIN_1)
#define E_WR_1    GPIO_WriteHigh(GPIOC, GPIO_PIN_1)
#define E_WR_out  GPIO_Init(GPIOC, GPIO_PIN_1, GPIO_MODE_OUT_PP_LOW_FAST)
#define E_WR_in   GPIO_Init(GPIOC, GPIO_PIN_1, GPIO_MODE_IN_FL_NO_IT)
#define E_WR_in_1 GPIO_ReadInputPin(GPIOC, GPIO_PIN_1)

#define K_0    GPIO_WriteLow(GPIOD, GPIO_PIN_0)
#define K_1    GPIO_WriteHigh(GPIOD, GPIO_PIN_0)
#define K_out  GPIO_Init(GPIOD, GPIO_PIN_0, GPIO_MODE_OUT_PP_LOW_FAST)
#define K_in   GPIO_Init(GPIOD, GPIO_PIN_0, GPIO_MODE_IN_FL_NO_IT)
#define K_in_1 GPIO_ReadInputPin(GPIOD, GPIO_PIN_0)

struct position 
{
  unsigned char X;
  unsigned char Y;
};
void InitDisplay(void);
void OUT1(unsigned char *Text);
void OUT2(unsigned char *Text);
void OUT2_mod(unsigned char *Text);
void GOTO(struct position *Position);
void ShowText(unsigned char *Text,struct position *Position);

//ќпределени€ (”правл€ющие выводы)

#endif // _LCD_DEFINE