extern void delay(unsigned int uS);

extern void InitDataPortsOut(void);

extern void InitDataPortsIN(void);

extern void load_byte_to_pin(unsigned char x);

extern void WriteCMD(unsigned char DATA, unsigned char RS);

extern unsigned char ReadCMD(unsigned char RS);



extern void ClearDisplay(void);
extern void ReturnHome(void);
extern void EntryModeSet(unsigned char ID,unsigned char SH);
extern void DisplayONOFControlBit(unsigned char D,unsigned char C,unsigned char B);
extern void CursorOrDisplayShift(unsigned char SC,unsigned char RL);
extern void FunctionSet(unsigned char DL,unsigned char N,unsigned char F);
extern void SetCGRAMAddress(unsigned char AC);
extern void SetDDRAMAddress(unsigned char AC);
extern unsigned char ReadBusyFlagAndAddress(void);
extern void WriteDataToRam(unsigned char Data);
extern unsigned char ReadDataFromRam(void);