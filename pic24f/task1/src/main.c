#include <p24fj128ga010.h>
#include "buffers.h"
#include "tgt_kvant_stats_routine.h"
#include "main.h"
#include "lcd.h"
#include "adc.h"
#include <stdio.h>

/*
 * Макрос включает в код printf.
 * Для отладочных целей.
 */
#define  __DEBUG_MODE

#include "tracer.h"

_CONFIG1(JTAGEN_OFF&GCP_OFF&GWRP_OFF&BKBUG_OFF&COE_OFF&FWDTEN_OFF&FNOSC_PRI)
_CONFIG2(FCKSM_CSDCMD&OSCIOFNC_ON&POSCMOD_HS)

// флаг необходимости рассчета ско
int need_calculate_rms;

/*
 * Обработчик прерывания по нажатию на кнопку
 * TODO: Нужно предусмотреть критические секции
 */
void __attribute__ ((__interrupt__)) _CNInterrupt(void) {
  int id;
  _CNIF = 0;

  if ( PORTDbits.RD7 == 1 ) {
  // устанавливаем флаг рассчета ско
    need_calculate_rms = 1;
    set_active_buffer_wait_calc_rms_state();
    id = create_buf();
    if ( id == -1) {
      _tracer_error_("CNInterrupt", "Can not create buffer ", NO_MEMORY );
    }
  }
}


/*
 * Обработчик прерывания по таймеру
 * TODO: Нужно предусмотреть критические секции
 */
void __attribute__ ((__interrupt__)) _T1Interrupt(void) {
  int   state;
  int   value;
  float res;
  int   a1;

  _T1IF = 0;

   // добавляем элемент
  a1    = readADC( channel );
  res   = 5.0 / 1024.0 * a1;

  /*
   * TODO: После приема с АЦП, происходит рассчет
   * в результате значение становится вещественым.
   * Поэтому value = res временное решение
   */
  value = (int) res;
  state = add_element_in_current_buffer( value );
  if ( state == -1) {
   _tracer_error_("T1Interrupt", "Buffer is full", NO_MEMORY );
  }
}


/*
 *  инициализация ЖКИ
 */
void initLcd(void) {
  init_lcd();
}

/*
 *  инициализация АЦП
 */
void initAdc(void) {
  initADC(ainputs);
}

/*
 *  инициализация тоаймер 1
 */
void initT1(void) {
  // сбрасывает флаг прерывания по таймеру
  _T1IF = 0;
  // разрешает прерывание
  _T1IE = 1;

  // задается предельное значение ( 0.1 секунды )
  /*
   * TODO: магическое число. нужно более подробно расписать
   */
  PR1 = 15625*0.1;
  TMR1 = 0; // обнуление счетчика таймера

  /*
   * TODO: магическое число. нужно более подробно расписать
   */
  T1CON  = 0x8030; // конфигурирование таймера
}

/*
 *  инициализация обработчика прерывания на CN
 */
void initCN(void) {
  // настройка порта D для ввода
  TRISD = 0xFFFF;
  // сбрасывает флаг прерывания
  _CNIF = 0;
  // разрешает прерывание
  _CN16IE = 1;
  // разрешает прерывание
  _CNIE = 1;

  _CNIP = 0x4;
}


//Основная программы
void main(void) {

  char _text[50];

  int rms_value;  // значение ско
  int id;         // идентификатор буфера
  // t1, t2 временные границы.
  int t2,t1;      //Необходимы для засечки времени за которое рассчитывается ско

  // инициализация Adc
  initAdc();

  // инициализация CN обработчика прерывания
  initCN();

  // инициализация таймера T1
  initT1();

  // устанавливаем флаг необходимости рассчета ско по данным буфера
  need_calculate_rms = 0;

  // создание буфера
  /**
   * TODO: если прерывание произошло раньше, то эту функцию 
   * вызывать не стоит
   */
  id = create_buf();

  if ( id == -1) {
    _tracer_error_( "main", "Can not create buffer ", NO_MEMORY );
  }

  while(1) {
    if ( need_calculate_rms == 1 ) {
      need_calculate_rms = 0;
      /*
       * получить идентификатор буфера который ожидает рассчета ско
       */
      id = get_id_waiting_rms_buf();
      if ( id == -1 ) {
        _tracer_error_("main", "Can not find waitng buffer", UNKNOWN_ERROR );
      }
      else {
        /*
         * TODO: возможно t1 как int будет мало
         * возможно необходимо будет long int сделать
         */
//        t1 = get_current_time();
        /*
         * TODO: ско считается как целочисленное.
         * Но по уму нужно чтобы вещественное было.
         */
       rms_value = KVANT_RMS_int_value( (int *)(get_ptr_buf( id )),
                                          get_elements_num_buf( id ) );

//        t2 = get_current_time();

      sprintf( _text, "rms=%d; time=%d" , rms_value, t2 - t1  );

        /*
         * Вывод на экран ско, времени рассчета ско ...
         */
       write_to_lcd( _text );

       /*
        * Освободить буфер
        * TODO: возможно нужно анализировать результат
        */
        id = get_id_current_calculating_rms_buf();
        delete_buf( id );

        /*
         * если имеется еще ожидающий буфер,
         * то происходит выборка его
         */
        if ( has_some_waiting_buffers() ) {
          need_calculate_rms = 1;
          set_active_buffer_wait_calc_rms_state();
        }

      }
    }
  }
  return;
}
