
#include <p24fj128ga010.h>
//_CONFIG1(JTAGEN_OFF&GCP_OFF&GWRP_OFF&BKBUG_OFF&COE_OFF&FWDTEN_OFF&FNOSC_PRI)
//_CONFIG2(FCKSM_CSDCMD&OSCIOFNC_ON&POSCMOD_HS)


_CONFIG1(ICS_PGx2&JTAGEN_OFF&GCP_OFF&GWRP_OFF&COE_OFF&FWDTEN_OFF)
_CONFIG2(FNOSC_PRIPLL&OSCIOFNC_OFF&FCKSM_CSDCMD&POSCMOD_HS)

#define LCDDATA 1
#define LCDCMD  0

#define PMDATA  PMDIN1
#define busyLCD() (readLCD (LCDCMD ) & 0x80)
#define addrLCD() (readLCD (LCDCMD) & 0x7f)
#define getLCD()  (readLCD (LCDDATA))
#define putLCD(d) writeLCD (LCDDATA, (d))
#define cmdLCD(c) writeLCD (LCDCMD, (c))
#define homeLCD() writeLCD (LCDCMD, 2)
#define clrLCD()  writeLCD (LCDCMD, 1)

void lcdWait (int timeout) {
    TMR1 = 0; 
    while (TMR1 < timeout){}
}

void init_lcd() {
    // PMP initialization
    PMCON   = 0x83bf; // enable PMP with long waits
    PMMODE  = 0x3ff;  // master mode 1
    PMAEN   = 0x0001; // PMA0 enable
    // init timer 1
    T1CON   = 0x8030; // Fosc/2, 1:256, 16us/tick
    lcdWait (2000); // wait for > 30ms
    // setup for 8 bit mode
    PMADDR  = LCDCMD;
    PMDATA  = 0x0011000;
    // Wait for > 40us so the LCD can do its thing
    TMR1    = 0;
    lcdWait (3);
    PMDATA  = 0b00001100;   // ON, cursor off, blink off
    lcdWait (3);
    PMDATA  = 00000001;      // clear display
    lcdWait (100);
    PMDATA  = 0b00000110;    // increment cursor, no shift
    lcdWait(100);  
}

char readLCD (int addr) {
    int dummy;
    while (PMMODEbits.BUSY);
    PMADDR = addr;
    dummy  = PMDATA;
    while (PMMODEbits.BUSY);
    return (PMDATA);
}

void writeLCD(int addr, char c) {
    while (busyLCD());
    while (PMMODEbits.BUSY);
    PMADDR = addr;
    PMDATA = c;
}

void write_to_lcd(const char *s) {
    while (*s)
        putLCD(*s++);
}

int main(void) {
    init_lcd();
    write_to_lcd("Try LCD!!!");
    while (1){}
    return 0;
}