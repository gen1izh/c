#ifndef  _MODULE_PORT_H
#define  _MODULE_PORT_H

#include "init.h"
#include "proto.h"

#define  DDRPORT

/**
 *  Структура статистики обращений к портам
 */
 typedef struct {
  unsigned long int portA_use_cnt;
  unsigned long int portB_use_cnt;
  unsigned long int portC_use_cnt;
  unsigned long int portD_use_cnt;
}_stats_struct;

/**
 *  Структура конфигурации портов
 *  Порт работает на вход или выход
 */
typedef struct {
  char portA_mode;
  char portB_mode;
  char portC_mode;
  char portD_mode;
  char value_portA;
  char value_portB;
  char value_portC;
  char value_portD;
}_config_struct;


extern _stats_struct Port_stats_struct;
extern _config_struct Port_config_struct;

/**
*  Выполнение команд с кодом команд 0x01
*/
void proto_Port_router(_cmd_struct *in);

#endif