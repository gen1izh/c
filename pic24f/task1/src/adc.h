#ifndef _ADC_
#define _ADC_

#define channel  7
#define ainputs  0xFFFF

/*
 * ������������� ���
 */
void initADC(int adcmask);

/*
 * ������� ��������� 1 �������� � ���
 * ���������� ������������ ��������
 */
int readADC(int ch);

#endif
