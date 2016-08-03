#include "proto.h"

#include <avr/io.h>

  /**
   *   Разбор полученной команды
   *   приведение ее в структурный вид
   */
void extract_inpack(char *buf, _cmd_struct *in) {

  int i;

  in->major   =  0x0F & (buf[0] >> 4);
  in->minor   =  0x0F & (buf[0]);
  in->opcode  =  buf[1];
  in->size    =  buf[2];

  for ( i = 0; i < in->size; i++ )
    in->_data[i] = buf[i+3];

  in->crc16 = (int)( (int)( buf[ HEADER_LEN + in->size + 1 ] << 8) |
                     ( ((int)buf[HEADER_LEN + in->size + 2])  ) );
}

  /**
   *   Копирование пакетов
   */
void copy_in_pack( _cmd_struct *in, _cmd_struct *out, char *state, int len ) {
  int i;
  out->major   = in->major;
  out->minor   = in->minor;
  out->opcode  = in->opcode;
  out->size    = len;
  for ( i = 0; i < len; i++ )
    out->_data[i] = state[i];
  out->crc16   = in->crc16;
}


  /**
   *   Отправки ответа
   */
void send_pack( _cmd_struct *out ) {
  int i;
  memset( (char *)&Private_data.buffer[0], 0, 100 );
  create_outpack( out, (char *)&Private_data.buffer[0] );
  while ( !(UCSRA & (1<<UDRE)) ); //Ожидание опустошения буфера приема

  USART_Transmit( Private_data.buffer[0] ); // major , minor
  USART_Transmit( Private_data.buffer[1] ); // opcode
  USART_Transmit( Private_data.buffer[2] ); // size

  for ( i = 0; i < Private_data.buffer[2]; i++ )
	  USART_Transmit( Private_data.buffer[i + HEADER_LEN + 1] );

  USART_Transmit( Private_data.buffer[i + HEADER_LEN + 1] );  // crc16
  USART_Transmit( Private_data.buffer[i + HEADER_LEN + 2] );

  memset( out, 0, sizeof( _cmd_struct ));
}


  /**
   *   Формирование ответа
   */
void create_outpack( _cmd_struct *out, char *buf ) {
  int i;

  buf[0]   =  ( out->major ) << 4;
  buf[0]   =  buf[0] | (0x0F & out->minor);
  buf[1]   =  out->opcode;
  buf[2]   =  out->size;

  for ( i = 0; i < out->size; i++ )
    buf[ i + HEADER_LEN + 1 ] = out->_data[i];

  buf[ HEADER_LEN + out->size + 1 ]  = (char)(out->crc16 >> 8);
  buf[ HEADER_LEN + out->size + 2 ]  = (char)(out->crc16) ;
}


  /**
   *   Маршрутизация команды в
   *   определенный модуль для исполнения
   */
void proceed_cmd( _cmd_struct *in ) {
  char state[4];

  switch (in->major) {
    case 1:  // Порты ввода\вывода
      proto_Port_router( in );
      break;
    case 2:  // Работа с памятью
      state[0] = OPERATION_NOT_IMPLEMENTED;
      copy_in_pack( (_cmd_struct *)&Private_data.inpack, (_cmd_struct *)&Private_data.outpack, (char *)&state[0], 4 );
      send_pack( (_cmd_struct *)&Private_data.outpack );
      break;
    case 3:
      state[0] = OPERATION_NOT_IMPLEMENTED;
      copy_in_pack( (_cmd_struct *)&Private_data.inpack, (_cmd_struct *)&Private_data.outpack, (char *)&state[0], 4 );
      send_pack( (_cmd_struct *)&Private_data.outpack );
      break;
    default:
      state[0] = OPERATION_NOT_IMPLEMENTED;
      copy_in_pack( (_cmd_struct *)&Private_data.inpack, (_cmd_struct *)&Private_data.outpack, (char *)&state[0], 4 );
      send_pack( (_cmd_struct *)&Private_data.outpack );
      break;
  };
}
