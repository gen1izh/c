#include <stdbool.h>
#include "uart.h"
/* ��������� ������*/
struct Packet {
  unsigned char start_byte_header1;   /* ��������� ������ ���� */
  unsigned char start_byte_header2;   /* ��������� ������ ���� */
  short         data;                 /* 2-� ����� ������ */
  unsigned char cmd;                  /* ������� */
};

/* ��������� ����� */
struct Packet command_packet;

/* ������� ���� ��� ����� ����� � �������� */
bool   is_packet_ready = false;

/* �������� ������ */
void create_packet( short data, unsigned char cmd ) {
  command_packet.start_byte_header1 = 0xAC;
  command_packet.start_byte_header2 = 0xE2; 
  command_packet.data               = data;
  command_packet.cmd                = cmd;
  is_packet_ready                   = true;
}

/* �������� ������ ������ */
void send_packet() {
  uart_Transmit( (unsigned char *)&command_packet );
}

/* �����  ������ */
void recieve_packet() {
  // TODO: ���� �� �����������������
}