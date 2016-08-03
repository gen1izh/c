#include "LCDDefine.h"
//#include "LCDDriverMTC_S16204X.h"
void ClearDisplay(void);
void ReturnHome(void);
void EntryModeSet(unsigned char ID,unsigned char SH);
void DisplayONOFControlBit(unsigned char D,unsigned char C,unsigned char B);
void CursorOrDisplayShift(unsigned char SC,unsigned char RL);
void FunctionSet(unsigned char DL,unsigned char N,unsigned char F);
void SetCGRAMAddress(unsigned char AC);


