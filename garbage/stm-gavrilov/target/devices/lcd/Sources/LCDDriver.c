#include "LCDDriverMTC_S16204X.h"
#include "LCDDefine.h"
//#include "LCDDriver.h"
struct position 
{
  unsigned char X;
  unsigned char Y;
};

unsigned char stas=0;
void OUT1(unsigned char *Text);
void OUT2(unsigned char *Text);
void GOTO(struct position *Position);
void ShowText(unsigned char *Text,struct position *Position);
/**************************************************************
        Инициализация дисплея  
        void InitDisplay(void)
***************************************************************/
void InitDisplay(void)
{
  InitDataPortsOut();
  
  RES_out;
  E_WR_out;
  K_out;
  RES_0;
  RD_WR_out;
  K_0;
  
  FunctionSet(1,1,0);
  ClearDisplay();
  EntryModeSet(1,0);
  DisplayONOFControlBit(1,0,0);
  ClearDisplay();
  CursorOrDisplayShift(0,1);  
  OUT1("0123456789ABCDEF");
  OUT2("0123456789ABCDEF");
  /*SetDDRAMAddress(0x00);//В начало первой строки
  WriteDataToRam('0');
  WriteDataToRam('1');
  WriteDataToRam('2');
  WriteDataToRam('3');
  WriteDataToRam('4');
  WriteDataToRam('5');
  WriteDataToRam('6');
  WriteDataToRam('7');
  WriteDataToRam('8');
  WriteDataToRam('9');
  WriteDataToRam('A');
  WriteDataToRam('B');
  WriteDataToRam('C');
  WriteDataToRam('D');
  WriteDataToRam('E');
  WriteDataToRam('F');*/
  /*SetDDRAMAddress(0x40);//В начало второй строки
  WriteDataToRam('0');
  WriteDataToRam('1');
  WriteDataToRam('2');
  WriteDataToRam('3');
  WriteDataToRam('4');
  WriteDataToRam('5');
  WriteDataToRam('6');
  WriteDataToRam('7');
  WriteDataToRam('8');
  WriteDataToRam('9');
  WriteDataToRam('A');
  WriteDataToRam('B');
  WriteDataToRam('C');
  WriteDataToRam('D');
  WriteDataToRam('E');
  WriteDataToRam('F');*/
}
/*
OUT1
*/
void OUT1(unsigned char *Text)
{
  unsigned char i=0;
  SetDDRAMAddress(0x00);
  while(*(Text+i))
  {
    if(i<16)
    {
      WriteDataToRam(Text[i]);
    }
    else
    {return;}
    i++;
  }
}
/*
OUT2
*/
void OUT2(unsigned char *Text)
{
  unsigned char i=0;
  SetDDRAMAddress(0x40);
  while(*(Text+i))
  {
    if(i<16)
    {
      WriteDataToRam(Text[i]);
    }
    else
    {return;}
    i++;
  }
}

/*
void GOTO(struct position *Position)
*/
void GOTO(struct position *Position)
{
  if(Position->Y>0)
  {
    if(Position->X<16)
    {
      SetDDRAMAddress(0x40||Position->X);
    }
    else
    {
      SetDDRAMAddress(0x40);
    }
  }
  else
  {
    if(Position->X<16)
    {
      SetDDRAMAddress(0x00||Position->X);
    }
    else
    {
      SetDDRAMAddress(0x00);
    }
  }  
}
/*
  void ShowText(unsigned char *Text,struct position *Position)
*/
void ShowText(unsigned char *Text,struct position *Position)
{
  GOTO(Position);
  
}
