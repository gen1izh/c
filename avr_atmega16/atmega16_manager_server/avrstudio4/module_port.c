#include "module_port.h"

#include <avr/io.h>

_stats_struct Port_stats_struct;

_config_struct Port_config_struct;

/**
 *  Команда 0x1. Чтение значения порта
 */
void Port_Read_cmd( _cmd_struct *in ){
  char value;
  char state[4];

  if ( in->minor == 1 ) { value = PINA;  Port_stats_struct.portA_use_cnt++; }
  if ( in->minor == 2 ) { value = PINB;  Port_stats_struct.portB_use_cnt++; }
  if ( in->minor == 3 ) { value = PINC;  Port_stats_struct.portC_use_cnt++; }
  if ( in->minor == 4 ) { value = PIND;  Port_stats_struct.portD_use_cnt++; }
//  if ( in->minor >= 5 ) {
//    state[0] = 0; state[1] = 0; state[2] = 0;
//    state[3] = INCORRECT_DEVICE_NUM;
//    copy_in_pack( (_cmd_struct *)&Private_data.inpack,
//            (_cmd_struct *)&Private_data.outpack, (char *)&state[0], 4 );
//    send_pack( (_cmd_struct *)&Private_data.outpack );
//  }

  copy_in_pack( (_cmd_struct *)&Private_data.inpack, 
                (_cmd_struct *)&Private_data.outpack, &value, 1 );
  
  send_pack( (_cmd_struct *)&Private_data.outpack );
}

/**
 *  Команда 0x2. Запись значения в порт
 */
void Port_Write_cmd( _cmd_struct *in ){
  char state[4];

  if ( in->minor == 1 ) { PORTA = in->_data[0];  Port_stats_struct.portA_use_cnt++; }
  if ( in->minor == 2 ) { PORTB = in->_data[0];  Port_stats_struct.portB_use_cnt++; }
  if ( in->minor == 3 ) { PORTC = in->_data[0];  Port_stats_struct.portC_use_cnt++; }
  if ( in->minor == 4 ) { PORTD = in->_data[0];  Port_stats_struct.portD_use_cnt++; }

  state[0] = 0; state[1] = 0; state[2] = 0;
  state[3] = SUCCESSFUL;
  copy_in_pack( (_cmd_struct *)&Private_data.inpack, (_cmd_struct *)&Private_data.outpack,
                      (char *)&state[0], 4 );
  send_pack( (_cmd_struct *)&Private_data.outpack );
}

/**
 *  Команда 0x3. Конфигуриование порта
 */
void Port_Config_cmd( _cmd_struct *in ){
  char state[4];
  if ( in->minor == 1 ) { DDRA  = in->_data[0]; Port_config_struct.portA_mode = in->_data[0]; }
  if ( in->minor == 2 ) { DDRB  = in->_data[0]; Port_config_struct.portB_mode = in->_data[0]; }
  if ( in->minor == 3 ) { DDRC  = in->_data[0]; Port_config_struct.portC_mode = in->_data[0]; }
  if ( in->minor == 4 ) { DDRD  = in->_data[0]; Port_config_struct.portD_mode = in->_data[0]; }
  
  state[0] = 0; state[1] = 0; state[2] = 0;
  state[3] = SUCCESSFUL;
  copy_in_pack( (_cmd_struct *)&Private_data.inpack, (_cmd_struct *)&Private_data.outpack,
                      (char *)&state[0], 4 );
  send_pack( (_cmd_struct *)&Private_data.outpack );
}
   
void big_to_little_4( char *in ) {
  char tmp;
  tmp = in[3]; in[3] = in[0]; in[0] = tmp;
  tmp = in[2]; in[2] = in[1]; in[1] = tmp;
}
        
  /**
   *  Команда 0x4. Запрос статистики
   */
void Port_Get_stats_cmd( _cmd_struct *in ){
  unsigned long int value[4];

  value[0]  = Port_stats_struct.portA_use_cnt;
  value[1]  = Port_stats_struct.portB_use_cnt;
  value[2]  = Port_stats_struct.portC_use_cnt;
  value[3]  = Port_stats_struct.portD_use_cnt;
  
  big_to_little_4((char *)&value[0]);
  big_to_little_4((char *)&value[1]);
  big_to_little_4((char *)&value[2]);
  big_to_little_4((char *)&value[3]);
  
  copy_in_pack( (_cmd_struct *)&Private_data.inpack, 
                (_cmd_struct *)&Private_data.outpack, (char *)&value[0], 16 );
  
  send_pack( (_cmd_struct *)&Private_data.outpack );
}


  /**
   *  Команда 0x5. Запрос конфигурации
   */
void Port_Get_config_cmd( _cmd_struct *in ){
  char state[4];

  if ( in->minor == 1 ) { state[0] = Port_config_struct.portA_mode; }
  if ( in->minor == 2 ) { state[0] = Port_config_struct.portB_mode; }
  if ( in->minor == 3 ) { state[0] = Port_config_struct.portC_mode; }
  if ( in->minor == 4 ) { state[0] = Port_config_struct.portD_mode; }
  
  copy_in_pack( (_cmd_struct *)&Private_data.inpack, 
                (_cmd_struct *)&Private_data.outpack, (char *)&state[0], 1 );
  send_pack( (_cmd_struct *)&Private_data.outpack );
}


  /**
   *  Команда 0x6. Очистка статистики
   */
void Port_Clear_stats_cmd( _cmd_struct *in ){
  char state[4];
  
  Port_stats_struct.portA_use_cnt = 0;
  Port_stats_struct.portB_use_cnt = 0;
  Port_stats_struct.portC_use_cnt = 0;
  Port_stats_struct.portD_use_cnt = 0;

  state[0] = SUCCESSFUL;
  copy_in_pack( (_cmd_struct *)&Private_data.inpack, 
                (_cmd_struct *)&Private_data.outpack, (char *)&state[0], 4 );
  send_pack( (_cmd_struct *)&Private_data.outpack );
}

  /**
   *  Команда 0x7. Запрос состояния последней выполненой операции
   */
void Port_Get_state_cmd( _cmd_struct *in ){
  char state[4];

  state[0] = SUCCESSFUL;
  copy_in_pack( (_cmd_struct *)&Private_data.inpack, 
                (_cmd_struct *)&Private_data.outpack, (char *)&state[0], 4 );
  send_pack( (_cmd_struct *)&Private_data.outpack );
}


/**
 *   Обработчик команд работы с портами
 */
void proto_Port_router( _cmd_struct *in ) {
  char state[4];

  switch ( in->opcode ) {
    case READ_COMMAND:              // 0x1
      Port_Read_cmd( in );
      break;
    case WRITE_COMMAND:             // 0x2
      Port_Write_cmd( in );
      break;
    case CONFIG_COMMAND:            // 0x3
      Port_Config_cmd( in );
      break;
    case GET_STATS_COMMAND:         // 0x4
      Port_Get_stats_cmd( in );
      break;
    case GET_CONFIG_COMMAND:        // 0x5
      Port_Get_config_cmd( in );
      break;
    case CLEAR_STATS_COMMAND:       // 0x6
      Port_Clear_stats_cmd( in );
      break;
    case GET_STATE_COMMAND:         // 0x7
      Port_Get_state_cmd( in );
      break;
    default:
      state[0] = INCORRECT_OPCODE;
      copy_in_pack( (_cmd_struct *)&Private_data.inpack, 
                    (_cmd_struct *)&Private_data.outpack, (char *)&state[0], 4 );
      send_pack( (_cmd_struct *)&Private_data.outpack );
      break;
  };
}
