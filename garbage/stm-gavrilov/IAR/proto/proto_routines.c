#include <stdbool.h>
#include "uart.h"
/* Структура пакета*/
struct Packet {
  unsigned char start_byte_header1;   /* преамбула первый байт */
  unsigned char start_byte_header2;   /* преамбула второй байт */
  short         data;                 /* 2-а байта данных */
  unsigned char cmd;                  /* команда */
};

/* Командный пакет */
struct Packet command_packet;

/* Признак того что пакет готов к отправке */
bool   is_packet_ready = false;

/* Создание пакета */
void create_packet( short data, unsigned char cmd ) {
  command_packet.start_byte_header1 = 0xAC;
  command_packet.start_byte_header2 = 0xE2; 
  command_packet.data               = data;
  command_packet.cmd                = cmd;
  is_packet_ready                   = true;
}

/* Отправка пакета пакета */
void send_packet() {
  uart_Transmit( (unsigned char *)&command_packet );
}

/* Прием  пакета */
void recieve_packet() {
  // TODO: Пока не предусматривается
}