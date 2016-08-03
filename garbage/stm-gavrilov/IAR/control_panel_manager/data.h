/**
  ******************************************************************************
  * @file    data.h
  * @author  Zalogix Team
  * @version V1.0.0
  * @date    03-06-2015
  * @brief   Этот файл содержит глобальные переменные состояния
  ******************************************************************************
  */

#ifndef __CONTROL_PANEL_MANAGER_H
#define __CONTROL_PANEL_MANAGER_H

#include <stm8s.h>
    
/* Коды кнопок */
/* Info: Если is_pressed=TRUE и actual_button=BUTTON1_CODE, то считается,
         что нажата SB1 кнопка. */
enum {
  BUTTON1_CODE = 1,   
  BUTTON2_CODE = 2,
  BUTTON3_CODE = 3,
  BUTTON4_CODE = 4,
  BUTTON5_CODE = 5,
};

/* Коды уровней меню */
enum {
  LEVEL1_CODE = 1,
  LEVEL2_CODE = 2,
  LEVEL3_CODE = 3,
  LEVEL4_CODE = 4
};

/* Коды пунктов меню */
enum {
  MENU_ITEM1_CODE = 1,
  MENU_ITEM2_CODE = 2,
  MENU_ITEM3_CODE = 3,
  MENU_ITEM4_CODE = 4
};

/* Коды команд меню */
enum {
  COMM_ON_CMD,                  /* Пуск */
  COMM_OFF_CMD,                 /* Стоп */
  COMM_SETTING_CMD,             /* Настройка */  
  COMM_TUNING_PACK_CMD,         /* Регулировка количества пакетов */  
  COMM_TUNING_HEAT_TRANSV_CMD,  /* Регулировка поперечного нагрева */  
  COMM_TUNING_HEAT_LONG_CMD     /* Регулировка продольного нагрева */
};

/* Поле маски-настроек, данные для команды COMM_SETTING_CMD */
typedef union CommandData {

  unsigned short value; /* значение состояния */

  struct  {
    unsigned a0:  1;   /* блокировка */
    unsigned a1:  1;   /* продукт */
    unsigned a2:  1;   /* сирена */
    unsigned a3:  1;   /* наладка */
    unsigned a4:  1;   /* дозатор */
    unsigned a5:  1;   /* вверх */
    unsigned a6:  1;   /* вакуум */
    unsigned a7:  1;   /* обдув */
    unsigned a8:  1;   /* транспортер */
    unsigned a9:  1;   /* прижим попереч */
    unsigned a10: 1;   /* прижим прод */
    unsigned a11: 1;   /* нагрев попереч */
    unsigned a12: 1;   /* нагрев прод */
    unsigned a13: 3;   /* пусто */
  } stateword;
}CommandSettings;

#define MAIN_MENU

/* Основная функция менеджера панели управления */
void main_cpm_routine();

/* Инициализация переменных модуля cpm */
void init_cpm_variables();

#endif  // __CONTROL_PANEL_MANAGER_H
