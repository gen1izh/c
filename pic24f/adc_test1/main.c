#include <p24fj128ga010.h>

/*
 * ������������ ���������� ��� ���������� ����� 
 * �������� ������� �� Explore16
 */
_CONFIG1(JTAGEN_OFF&GCP_OFF&GWRP_OFF&BKBUG_OFF&COE_OFF&FWDTEN_OFF&FNOSC_PRI)
_CONFIG2(FCKSM_CSDCMD&OSCIOFNC_ON&POSCMOD_HS)

#define channel  7
#define ainputs  0x0

unsigned int bReq = 0;

/*
 * ���������� ���������� �� INT3
 */
void __attribute__ ((interrupt)) _INT3Interrupt(void) {
  bReq    = 1;
  _INT3IF = 0;
}

/*
 * ������������� ���
 */
void initADC(int adcmask){
  AD1PCFG = adcmask;   // ������ ������������ ������� ����� B (�� ������ ����� ���)
  AD1CON1 = 0;         // ������� �������������� �������������� �������
  AD1CSSL = 0;         // �� ����� ����������� ���������������� ������������ ���������� ������� �����
  AD1CON2 = 0;         // �������� ������������� MUXA, � �������� �������� ����������
                       // ���������� ���������� �������
  AD1CON3 = 0x1F02;    // �������� �������������� � ������ ������������
  
  AD1CON1bits.ADON = 1; // �������� ���
}

/*
 * ������� ��������� 1 �������� � ��� 
 * ���������� ������������ ��������
 */
int readADC(int ch) {

  AD1CHS            = ch; // �������������  ����� ������������ ������
  AD1CON1bits.SAMP  = 1;       // �������� ������� ������� �������� �������
  

// ����������� ��������� ������� ������ 6.25 ��� ��� 8000000 ��� �������� �������
  T1CONbits.TON = 1;
  TMR1          = 0;
  while (TMR1 < 100);
  

  AD1CON1bits.SAMP = 0;       // �������� ������ �������������� �������

  while (!AD1CON1bits.DONE);  // �������� ����� ���������������
  
  return ADC1BUF0;            // ���������� �������� ��������������
}

/*
 * ���� �������� ���������
 */
void main(void) {
  int   a1;
  float res;
  
  TRISA               = 0xff00;
  INTCON2bits.INT3EP  = 1;  //  ���������� ��������� �� �����
  
  _INT3IF = 0;
  _INT3IP = 4;
  _INT3IE = 1;
  
  initADC(ainputs);
  
  while (1) {
    if (bReq == 1){
      a1    = readADC( channel );
      res   = 5.0 / 1024.0 * a1;
      bReq  = 0;
    }
  }
  return;
}
