#ifndef _LCD_
#define _LCD_

/*
 *
 */
void lcdWait ( int timeout );

/*
 * инициализация жки дисплея
 */
void init_lcd();


char readLCD ( int addr );

void writeLCD( int addr, char c );

/*
 * запись на жки дисплей
 */
void write_to_lcd( const char *s );

#endif
