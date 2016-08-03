#ifndef _MENU_LEVEL2 
#define _MENU_LEVEL2

/*
 * Названия пунктов меню ( второго уровня команд )
 */
  #define nastroika_s1      "НАСТРОЙКА"
  #define nastroika_s2      "РАБОТЫ"
  
  #define kolvo_pkts_s1     "КОЛИЧЕСТВО"
  #define kolvo_pkts_s2     "ПАКЕТОВ"
  
  #define pop_nagrev_s1     "ПОПЕРЕЧНЫЙ"
  #define pop_nagrev_s2     "НАГРЕВ"
  
  #define prod_nagrev_s1    "ПРОДОЛЬНЫЙ"
  #define prod_nagrev_s2    "НАГРЕВ"

   
  #define TOTAL_SIZE_ITEMS_BY_LEVEL2_MENU 4
/*
 * Вывод на экран первого пункта меню
 */
void print_level2_menu();

/*
 * Вывод на экран pos номер пункта меню настроек
 */
void print_level2_text_menu_by_position(unsigned char pos);

#endif  // _MENU_LEVEL2 
