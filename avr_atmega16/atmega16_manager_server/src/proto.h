#ifndef _PROTO_H
#define _PROTO_H

#include "init.h"
#include "module_port.h"


// Заголовок команды
#define   HEADER_LEN         0x2

// Основные коды команд
#define   READ_COMMAND         0x1
#define   WRITE_COMMAND        0x2
#define   CONFIG_COMMAND       0x3
#define   GET_STATS_COMMAND    0x4
#define   GET_CONFIG_COMMAND   0x5
#define   CLEAR_STATS_COMMAND  0x6
#define   GET_STATE_COMMAND    0x7

  /**
   *   Разбор полученной команды
   *   приведение ее в структурный вид
   */
void extract_inpack(char *buf, _cmd_struct *in);


  /**
   *   Отправки ответа
   */
void send_pack( _cmd_struct *out );


  /**
   *   Формирование ответа
   */
void create_outpack( _cmd_struct *out, char *buf );


  /**
   *   Маршрутизация команды в
   *   определенный модуль для исполнения
   */
void proceed_cmd( _cmd_struct *in );


  /**
   *   Копирование пакетов
   */
void copy_in_pack( _cmd_struct *in, _cmd_struct *out, char *state, int len );


#endif