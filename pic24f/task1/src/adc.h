#ifndef _ADC_
#define _ADC_

#define channel  7
#define ainputs  0xFFFF

/*
 * Инициализация АЦП
 */
void initADC(int adcmask);

/*
 * Функция оцифровки 1 значения с АЦП
 * возвращает оцифрованное значение
 */
int readADC(int ch);

#endif
