#include <p24fj128ga010.h>

_CONFIG2(FCKSM_CSDCMD&OSCIOFNC_ON&POSCMOD_HS&FNOSC_PRI)

// ���������� ����������
void __attribute__ ((__interrupt__)) _T1Interrupt(void) {
	_T1IF = 0;
	PORTAbits.RA2 = ~PORTAbits.RA2;
}

//�������� ���������
void main(void) {
	// ��������� ����� � ��� ������
	TRISA = 0xfff0;
	PORTAbits.RA2 = 1;
	
	// ���������� ���� ���������� �� �������
	_T1IF = 0;
	// ��������� ����������
	_T1IE = 1;
	
	// �������� ���������� �������� ( 3 ������� )
	PR1 = 15625*3;
	TMR1 = 0; // ��������� �������� �������
	T1CON  = 0x8030; // ���������������� �������
	
	while(1){}
}