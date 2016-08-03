#include <p24fj128ga010.h>

_CONFIG2(FCKSM_CSDCMD&OSCIOFNC_ON&POSCMOD_HS&FNOSC_PRI)

// Обработчик прерывания
void __attribute__ ((__interrupt__)) _T1Interrupt(void) {
	_T1IF = 0;
	PORTAbits.RA2 = ~PORTAbits.RA2;
}

//Основная программы
void main(void) {
	// настройка порта А для вывода
	TRISA = 0xfff0;
	PORTAbits.RA2 = 1;
	
	// сбрасывает флаг прерывания по теймеру
	_T1IF = 0;
	// разрешает прерывание
	_T1IE = 1;
	
	// задается предельное значение ( 3 секунды )
	PR1 = 15625*3;
	TMR1 = 0; // обнуление счетчика таймера
	T1CON  = 0x8030; // конфигурирование таймера
	
	while(1){}
}