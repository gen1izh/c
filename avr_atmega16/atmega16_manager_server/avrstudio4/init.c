 /**
  *  init v0.1.avr.18812813
  */


#include "init.h"
#include "proto.h"
#include <util/delay.h>

#include <avr/io.h>

#define FOSC 8000000// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void UART1_Init( unsigned int ubrr) {
	/* Set baud rate */
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}

void USART_Transmit( unsigned char data )
{
/* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<UDRE)) )
;
/* Put data into buffer, sends the data */
UDR = data;
}

unsigned char USART_Receive( void )
{
/* Wait for data to be received */
while ( !(UCSRA & (1<<RXC)) )
;
/* Get and return received data from buffer */
return UDR;
}

// Структура автомата для приема команды
_automat_data automat_data;

// Переменная для внутреннего описания
// командного модуля программы
_app_Private Private_data;

   
// байт данных принятый по UART
unsigned char uart_receive_data_byte;

/**
*  Функция выполняющая маршрутизацию команды
*/
void proto_cmd_route() {
// Маршрутизировать выполнение команды определенной функции
}

/**
 *  Функция инициализации автомата
 */
void automat_initialize() {
  automat_data.state = AUTOMAT_WAIT_DEVICE_INFO;
  automat_data.pos   = 0;
  automat_data.len   = 1;
  memset( (char *)&automat_data.buffer[0], 0, BUFFER_SIZE - 1);

}


/*
  Name  : CRC-16 CCITT
  Poly  : 0x1021    x^16 + x^12 + x^5 + 1
  Init  : 0xFFFF
  Revert: false
  XorOut: 0x0000
  Check : 0x29B1 ("123456789")
*/
unsigned short Crc16(unsigned char *pcBlock, unsigned short len) {
  unsigned short crc = 0xFFFF;
  unsigned char i;
  while ( len-- ) {
    crc ^= *pcBlock++ << 8;
    for (i = 0; i < 8; i++)
    crc = crc & 0x8000 ? (crc << 1) ^ 0x1021 : crc << 1;
  }
  return crc;
}

_BOOL prt_atm_packet_check_crc16(char *buf) {
   return _TRUE;
}

int Validate_device(char *buf) {
   return SUCCESSFUL;
}
                    
int Validate_cop(char *buf) {
   return SUCCESSFUL;
}

/**
 *  Главная функция
 */
void main() {

  int                             to_status;
  int                             atm_status;
  int                             read_size_cnt;
  char                            state[4];

  automat_initialize();

  UART1_Init( MYUBRR );                              // Инициализация модуля UART

  _delay_ms(100);    // Ожидания стабилизации UART
  
  while (1) {
   //if ( UART1_Data_Ready() ) {
     uart_receive_data_byte =  USART_Receive();

      /**
      * Сборка команды и выолнение
      */
       if (automat_data.state == AUTOMAT_ERROR)
         automat_initialize();
                                   
        automat_data.buffer[automat_data.pos] = uart_receive_data_byte;
        
        automat_data.pos++;
          switch (automat_data.state) {
            case AUTOMAT_WAIT_DEVICE_INFO:
              atm_status = Validate_device(automat_data.buffer[AUTOMAT_WAIT_DEVICE_INFO]);
              if (SUCCESSFUL == atm_status) {
                automat_data.state = AUTOMAT_WAIT_OPCODE_INFO;
                automat_data.len   = 1;
              }
              else {
                automat_data.state  = AUTOMAT_ERROR;
              }
              break;
            case AUTOMAT_WAIT_OPCODE_INFO:
              atm_status = Validate_cop(automat_data.buffer[AUTOMAT_WAIT_OPCODE_INFO]);
              if (SUCCESSFUL == atm_status) {
                automat_data.state  = AUTOMAT_WAIT_DATA_LENGTH_INFO;
                automat_data.len    = 1;
              }
              else {
                automat_data.state = AUTOMAT_ERROR;
              }
              break;
            case AUTOMAT_WAIT_DATA_LENGTH_INFO:
                automat_data.state  = AUTOMAT_WAIT_DATA_AND_CRC16;
                automat_data.len    = automat_data.buffer[AUTOMAT_WAIT_DATA_LENGTH_INFO] + 2/*crc16*/;
                break;
            case AUTOMAT_WAIT_DATA_AND_CRC16:
              automat_data.len--;
              
              if ( automat_data.len <= 0 ) {
                extract_inpack( (char *)&automat_data.buffer[0], &Private_data.inpack );

                if ( _TRUE == prt_atm_packet_check_crc16(&automat_data.buffer[0])) {
                //Выполнение команды
                  proceed_cmd( (_cmd_struct *)&Private_data.inpack );
                }
                else {

                  automat_data.state  = AUTOMAT_ERROR;
                  state[0] = 0; state[1] = 0; state[2] = 0;
                  state[3] = INCORRECT_CRC16;
                  copy_in_pack( (_cmd_struct *)&Private_data.inpack, 
                                (_cmd_struct *)&Private_data.outpack, (char *)&state[0], 4 );

                  send_pack( (_cmd_struct *)&Private_data.outpack );


                }
                automat_initialize();
              }
              break;
            case AUTOMAT_ERROR:
             automat_initialize();
             break;
            default:
             break;
          }
    //}
  }
}
