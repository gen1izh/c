#include "stm8s_uart2.h"

/* ������� �������� ������ �� uart */
void uart_Transmit( unsigned char *cmd ) {
  while( !(UART2->SR & UART2_FLAG_TC/*UART2_SR_TC*/) );
  UART2->DR = cmd[0];  /* �������� ��������� */               
  while( !(UART2->SR & UART2_FLAG_TC/*UART2_SR_TC*/) );
  UART2->DR = cmd[1];  /* �������� ��������� */      
  while( !(UART2->SR & UART2_FLAG_TC/*UART2_SR_TC*/) );
  UART2->DR = (uint8_t)(cmd[2]);  /* �������� ������ */      
  while( !(UART2->SR & UART2_FLAG_TC/*UART2_SR_TC*/) );
  UART2->DR = (uint8_t)(cmd[3]);  /* �������� ������ */      
  while( !(UART2->SR & UART2_FLAG_TC/*UART2_SR_TC*/) );
  UART2->DR = cmd[4];  /* �������� ������� */      
}
