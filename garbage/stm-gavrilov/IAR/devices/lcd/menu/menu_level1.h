#ifndef _MENU_LEVEL1 
#define _MENU_LEVEL1
#include "LCDDefine.h"

/*
 * Названия пунктов меню ( первого и третьего уровня настроек)
 */
  #define blokirovka    "БЛОКИРОВКА"
  #define product       "ПРОДУКТ"
  #define sirena        "СИРЕНА"
  #define naladka       "НАЛАДКА"
  #define dozator       "ДОЗАТОР"
  #define vverh         "ВВЕРХ"
  #define vakuum        "ВАКУУМ"
  #define obduv         "ОБДУВ"
  #define transporter   "ТРАНСПОРТЕР"
  #define prijim_pop    "ПРИЖИМ ПОПЕРЕЧ"
  #define prijim_prod   "ПРИЖИМ ПРОД"
  #define nagrev_pop    "НАГРЕВ ПОПЕРЕЧ"
  #define nagrev_prod   "НАГРЕВ ПРОД"
  
  #define TOTAL_SIZE_ITEMS_BY_LEVEL1_MENU 13
  
/*
 * Инициализация меню вывод на экран первые пункты меню
 */
void print_level1_menu();


/*
 * Вывод на экран pos номер пункта меню
 */
void print_level1_text_menu_by_position(unsigned char pos);


#endif  // _MENU_LEVEL1 
