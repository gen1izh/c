#ifndef _LCD_
#define _LCD_

/*
 *
 */
void lcdWait ( int timeout );

/*
 * ������������� ��� �������
 */
void init_lcd();


char readLCD ( int addr );

void writeLCD( int addr, char c );

/*
 * ������ �� ��� �������
 */
void write_to_lcd( const char *s );

#endif
