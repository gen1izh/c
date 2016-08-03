#include "stm8s_uart2.h"

/* Функция отправки данных по uart */
void uart_Transmit( unsigned char *cmd ) {
  while( !(UART2->SR & UART2_FLAG_TC/*UART2_SR_TC*/) );
  UART2->DR = cmd[0];  /* отправка преамбулы */               
  while( !(UART2->SR & UART2_FLAG_TC/*UART2_SR_TC*/) );
  UART2->DR = cmd[1];  /* отправка преамбулы */      
  while( !(UART2->SR & UART2_FLAG_TC/*UART2_SR_TC*/) );
  UART2->DR = (uint8_t)(cmd[2]);  /* отправка данных */      
  while( !(UART2->SR & UART2_FLAG_TC/*UART2_SR_TC*/) );
  UART2->DR = (uint8_t)(cmd[3]);  /* отправка данных */      
  while( !(UART2->SR & UART2_FLAG_TC/*UART2_SR_TC*/) );
  UART2->DR = cmd[4];  /* отправка команды */      
}
