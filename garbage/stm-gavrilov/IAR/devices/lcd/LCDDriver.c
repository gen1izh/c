#include "LCDDriverMTC_S16204X.h"
#include "LCDDefine.h"
//#include "LCDDriver.h"

unsigned char stas=0;

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
  OUT1("ПРОШИВКА");
  OUT2("ЗАПУЩЕНА...");
  
  /*
  SetDDRAMAddress(0x00);//В начало первой строки
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
  WriteDataToRam('F');
  SetDDRAMAddress(0x40);//В начало второй строки
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
  
unsigned char Decode2Rus[255-192+1]= { 
0x41,0xA0,0x42,0xA1,0xE0,0x45,0xA3,0xA4, 
0xA5,0xA6,0x4B,0xA7,0x4D,0x48,0x4F,0xA8, 
0x50,0x43,0x54,0xA9,0xAA,0x58,0xE1,0xAB, 
0xAC,0xE2,0xAD,0xAE,0xAD,0xAF,0xB0,0xB1, 
0x61,0xB2,0xB3,0xB4,0xE3,0x65,0xB6,0xB7, 
0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0x6F,0xBE, 
0x70,0x63,0xBF,0x79,0xE4,0x78,0xE5,0xC0, 
0xC1,0xE6,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7 
};

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
      unsigned char ch = Text[i];
      if(ch>=192) ch = Decode2Rus[ch-192]; 
      WriteDataToRam(ch);
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
      unsigned char ch = Text[i];
      if(ch>=192) ch = Decode2Rus[ch-192]; 
      WriteDataToRam(ch);
    }
    else
    {return;}
    i++;
  }
}

void OUT2_mod(unsigned char *Text)
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
