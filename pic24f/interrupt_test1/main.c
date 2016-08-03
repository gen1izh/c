#include <p24fj128ga010.h>
#include <stdio.h>
#include "tracer.h"

_CONFIG2(FCKSM_CSDCMD&OSCIOFNC_ON&POSCMOD_HS&FNOSC_PRI)
 
// Обработчик прерывания
void __attribute__ ((__interrupt__)) _INT3Interrupt(void) {
  _tracer_fn_enter_("_INT3Interrupt");
  _INT3IF = 0;
  PORTAbits.RA2 = ~PORTAbits.RA2;
  _tracer_debug_("_INT3Interrupt", " PORTA2 = ", PORTAbits.RA2);
}
 
//Основная программы
void main(void) {
 _tracer_fn_enter_("main");
  // настройка порта А для вывода
  TRISA = 0xfff0;
  PORTAbits.RA2 = 1;
   
  // сбрасывает флаг прерывания 
  _INT3IF = 0;
  // разрешает прерывание
  _INT3IE = 1;
   
  while(1){}
}