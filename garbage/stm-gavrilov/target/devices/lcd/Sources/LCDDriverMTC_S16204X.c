#include "LCDDefine.h"
//#include "LCDDriverMTC_S16204X.h"
void delay(unsigned int uS);

void InitDataPortsOut(void);

void InitDataPortsIN(void);

void load_byte_to_pin(unsigned char x);

void WriteCMD(unsigned char DATA, unsigned char RS);

unsigned char ReadCMD(unsigned char RS);



void ClearDisplay(void);
void ReturnHome(void);
void EntryModeSet(unsigned char ID,unsigned char SH);
void DisplayONOFControlBit(unsigned char D,unsigned char C,unsigned char B);
void CursorOrDisplayShift(unsigned char SC,unsigned char RL);
void FunctionSet(unsigned char DL,unsigned char N,unsigned char F);
void SetCGRAMAddress(unsigned char AC);
void SetDDRAMAddress(unsigned char AC);
unsigned char ReadBusyFlagAndAddress(void);
void WriteDataToRam(unsigned char Data);
unsigned char ReadDataFromRam(void);


/****************************************************************************
*
* Задержка
*
****************************************************************************/
void delay(unsigned int uS)
{ 
  unsigned int Delay=16*uS;
   while(Delay--);
}
/****************************************************************************
*
* Инициализация портов данных на выход
*
****************************************************************************/
void InitDataPortsOut()
{
  db0_out;
  db1_out;
  db2_out;
  db3_out;
  db4_out;
  db5_out;
  db6_out;
  db7_out;
  db0_0;
  db1_0;
  db2_0;
  db3_0;
  db4_0;
  db5_0;
  db6_0;
  db7_0;
}
/****************************************************************************
*
* Инициализация портов данных на вход
*
****************************************************************************/
void InitDataPortsIN()
{
  db0_in;
  db1_in;
  db2_in;
  db3_in;
  db4_in;
  db5_in;
  db6_in;
  db7_in;
 /* db0_0;
  db1_0;
  db2_0;
  db3_0;
  db4_0;
  db5_0;
  db6_0;
  db7_0; */
}
/****************************************************************************
*
* Запись данных на шину данных
*
****************************************************************************/
void load_byte_to_pin(unsigned char x)
{
    	 int i=0;	
	 InitDataPortsOut();
	 for(i=0;i<8;i++)
	 {
	  	  switch(i)
		  {
		  	 case(0):{
			 if(x&(1<<i))
			 {db0_1;}
			 else{db0_0;}
			 break;}
			 case(1):{
			 if(x&(1<<i))
			 {db1_1;}
			 else{db1_0;}
			 break;}
			 case(2):{
			 if(x&(1<<i))
			 {db2_1;}
			 else{db2_0;}
			 break;}
			 case(3):{
			 if(x&(1<<i))
			 {db3_1;}
			 else{db3_0;}
			 break;}
			 case(4):{
			 if(x&(1<<i))
			 {db4_1;}
			 else{db4_0;}
			 break;}
			 case(5):{
			 if(x&(1<<i))
			 {db5_1;}
			 else{db5_0;}
			 break;}
			 case(6):{
			 if(x&(1<<i))
			 {db6_1;}
			 else{db6_0;}
			 break;}
			 case(7):{
			 if(x&(1<<i))
			 {db7_1;}
			 else{db7_0;}
			 break;}
		  }
	 }
}
/****************************************************************************
*
* Запись данных на дисплей
*
****************************************************************************/
void WriteCMD(unsigned char DATA, unsigned char RS)
{
   InitDataPortsOut();
   if(RS)
   {
     RES_1;
   }
   else
   {
     RES_0;
   }
     RD_WR_0;
   delay(10);
   E_WR_1;
   load_byte_to_pin(DATA);
   delay(1000); 
   E_WR_0;
   delay(10); 
   RD_WR_0;
   InitDataPortsIN();
}
/****************************************************************************
*
* Чтение данных с дисплея
*
****************************************************************************/
unsigned char ReadCMD(unsigned char RS)
{
   unsigned char temp=0;
   InitDataPortsIN();
   if(RS)
   {
     RES_1;
   }
   else
   {
     RES_0;
   }
   RD_WR_1;
   delay(10);
   E_WR_1;
   delay(1000);
   temp|=(db0_in_1|db1_in_1|db2_in_1|db3_in_1|db4_in_1|db5_in_1|db6_in_1|db7_in_1); 
   E_WR_0;
   delay(10);
   return temp;
}
/****************************************************************************

* Очистить дисплей
*
****************************************************************************/
void ClearDisplay(void)
{
  WriteCMD(1, 0);
}
/****************************************************************************

* Вернуть указатель в начало DDRAM
*
****************************************************************************/
void ReturnHome(void)
{
  WriteCMD(2, 0);
}
/****************************************************************************

* Настройка
*
****************************************************************************/
void EntryModeSet(unsigned char ID,unsigned char SH)
{
  unsigned char temp=4;
  if(ID)
  {temp|=(1<<1);}
  if(SH)
  {temp|=(1<<0);}
  WriteCMD(temp, 0);
}
/****************************************************************************

* Настройка
*
****************************************************************************/
void DisplayONOFControlBit(unsigned char D,unsigned char C,unsigned char B)
{
  unsigned char temp=8;
  if(D)
  {temp|=(1<<2);}
  if(C)
  {temp|=(1<<1);}
  if(B)
  {temp|=(1<<0);}
  WriteCMD(temp, 0);
}
/****************************************************************************

* Настройка
*
****************************************************************************/
void CursorOrDisplayShift(unsigned char SC,unsigned char RL)
{
  unsigned char temp=16;
  if(SC)
  {temp|=(1<<3);}
  if(RL)
  {temp|=(1<<2);}
  WriteCMD(temp, 0);
}
/****************************************************************************
*
* Настройка
*
****************************************************************************/
void FunctionSet(unsigned char DL,unsigned char N,unsigned char F)
{
  unsigned char temp=32;
  if(DL)
  {
    temp|=(1<<4);
  }
  if(N)
  {
    temp|=(1<<3);
  }
  if(F)
  {
    temp|=(1<<2);
  }
  WriteCMD(temp, 0);
}
/****************************************************************************
*
* Установить указатель CGRAM
*
****************************************************************************/
void SetCGRAMAddress(unsigned char AC)
{
  unsigned char temp=64;
  temp|=AC;
  WriteCMD(temp, 0);
}
/****************************************************************************
*
* Установить указатель DDRAM
*
****************************************************************************/
void SetDDRAMAddress(unsigned char AC)
{
  unsigned char temp=128;
  temp|=AC;
  WriteCMD(temp, 0);
}
/****************************************************************************
*
* Считать флаг состояния и адрес указателя
*
****************************************************************************/
unsigned char ReadBusyFlagAndAddress(void)
{
   return ReadCMD(0);
}
/****************************************************************************
*
* Дапишем данные в RAM
*
****************************************************************************/
void WriteDataToRam(unsigned char Data)
{
   WriteCMD(Data, 1);
}
/****************************************************************************
*
* Считаем данные из RAM
*
****************************************************************************/
unsigned char ReadDataFromRam(void)
{
  return ReadCMD(1);
}
