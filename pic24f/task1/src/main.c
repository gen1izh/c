#include <p24fj128ga010.h>
#include "buffers.h"
#include "tgt_kvant_stats_routine.h"
#include "main.h"
#include "lcd.h"
#include "adc.h"
#include <stdio.h>

/*
 * ������ �������� � ��� printf.
 * ��� ���������� �����.
 */
#define  __DEBUG_MODE

#include "tracer.h"

_CONFIG1(JTAGEN_OFF&GCP_OFF&GWRP_OFF&BKBUG_OFF&COE_OFF&FWDTEN_OFF&FNOSC_PRI)
_CONFIG2(FCKSM_CSDCMD&OSCIOFNC_ON&POSCMOD_HS)

// ���� ������������� �������� ���
int need_calculate_rms;

/*
 * ���������� ���������� �� ������� �� ������
 * TODO: ����� ������������� ����������� ������
 */
void __attribute__ ((__interrupt__)) _CNInterrupt(void) {
  int id;
  _CNIF = 0;

  if ( PORTDbits.RD7 == 1 ) {
  // ������������� ���� �������� ���
    need_calculate_rms = 1;
    set_active_buffer_wait_calc_rms_state();
    id = create_buf();
    if ( id == -1) {
      _tracer_error_("CNInterrupt", "Can not create buffer ", NO_MEMORY );
    }
  }
}


/*
 * ���������� ���������� �� �������
 * TODO: ����� ������������� ����������� ������
 */
void __attribute__ ((__interrupt__)) _T1Interrupt(void) {
  int   state;
  int   value;
  float res;
  int   a1;

  _T1IF = 0;

   // ��������� �������
  a1    = readADC( channel );
  res   = 5.0 / 1024.0 * a1;

  /*
   * TODO: ����� ������ � ���, ���������� �������
   * � ���������� �������� ���������� �����������.
   * ������� value = res ��������� �������
   */
  value = (int) res;
  state = add_element_in_current_buffer( value );
  if ( state == -1) {
   _tracer_error_("T1Interrupt", "Buffer is full", NO_MEMORY );
  }
}


/*
 *  ������������� ���
 */
void initLcd(void) {
  init_lcd();
}

/*
 *  ������������� ���
 */
void initAdc(void) {
  initADC(ainputs);
}

/*
 *  ������������� ������� 1
 */
void initT1(void) {
  // ���������� ���� ���������� �� �������
  _T1IF = 0;
  // ��������� ����������
  _T1IE = 1;

  // �������� ���������� �������� ( 0.1 ������� )
  /*
   * TODO: ���������� �����. ����� ����� �������� ���������
   */
  PR1 = 15625*0.1;
  TMR1 = 0; // ��������� �������� �������

  /*
   * TODO: ���������� �����. ����� ����� �������� ���������
   */
  T1CON  = 0x8030; // ���������������� �������
}

/*
 *  ������������� ����������� ���������� �� CN
 */
void initCN(void) {
  // ��������� ����� D ��� �����
  TRISD = 0xFFFF;
  // ���������� ���� ����������
  _CNIF = 0;
  // ��������� ����������
  _CN16IE = 1;
  // ��������� ����������
  _CNIE = 1;

  _CNIP = 0x4;
}


//�������� ���������
void main(void) {

  char _text[50];

  int rms_value;  // �������� ���
  int id;         // ������������� ������
  // t1, t2 ��������� �������.
  int t2,t1;      //���������� ��� ������� ������� �� ������� �������������� ���

  // ������������� Adc
  initAdc();

  // ������������� CN ����������� ����������
  initCN();

  // ������������� ������� T1
  initT1();

  // ������������� ���� ������������� �������� ��� �� ������ ������
  need_calculate_rms = 0;

  // �������� ������
  /**
   * TODO: ���� ���������� ��������� ������, �� ��� ������� 
   * �������� �� �����
   */
  id = create_buf();

  if ( id == -1) {
    _tracer_error_( "main", "Can not create buffer ", NO_MEMORY );
  }

  while(1) {
    if ( need_calculate_rms == 1 ) {
      need_calculate_rms = 0;
      /*
       * �������� ������������� ������ ������� ������� �������� ���
       */
      id = get_id_waiting_rms_buf();
      if ( id == -1 ) {
        _tracer_error_("main", "Can not find waitng buffer", UNKNOWN_ERROR );
      }
      else {
        /*
         * TODO: �������� t1 ��� int ����� ����
         * �������� ���������� ����� long int �������
         */
//        t1 = get_current_time();
        /*
         * TODO: ��� ��������� ��� �������������.
         * �� �� ��� ����� ����� ������������ ����.
         */
       rms_value = KVANT_RMS_int_value( (int *)(get_ptr_buf( id )),
                                          get_elements_num_buf( id ) );

//        t2 = get_current_time();

      sprintf( _text, "rms=%d; time=%d" , rms_value, t2 - t1  );

        /*
         * ����� �� ����� ���, ������� �������� ��� ...
         */
       write_to_lcd( _text );

       /*
        * ���������� �����
        * TODO: �������� ����� ������������� ���������
        */
        id = get_id_current_calculating_rms_buf();
        delete_buf( id );

        /*
         * ���� ������� ��� ��������� �����,
         * �� ���������� ������� ���
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
