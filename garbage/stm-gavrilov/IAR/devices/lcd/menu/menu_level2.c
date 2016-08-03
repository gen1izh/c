#include "data.h"
#include "string.h"
#include "menu_level2.h"
#include "LCDDefine.h"
#include "stm8s.h"
/*
 * Состояние настроек
 */
extern CommandSettings settingsState;

/*
 * Вывод на экран первого пункта меню
 */
void print_level2_menu() {
  ClearDisplay();
  /* Вывод первого пункта меню */
  OUT1( nastroika_s1 );
  OUT2( nastroika_s2 );
}

/*
 * Вывод на экран pos номер пункта меню настроек
 */
void print_level2_text_menu_by_position(unsigned char pos) {
  ClearDisplay();
  switch (pos) {
    case 1:
      OUT1( nastroika_s1 );
      OUT2( nastroika_s2 );
      break;
    case 2:
      OUT1( kolvo_pkts_s1 );
      OUT2( kolvo_pkts_s2 );
      break;
    case 3:
      OUT1( pop_nagrev_s1 );
      OUT2( pop_nagrev_s2 );
      break;
    case 4:
      OUT1( prod_nagrev_s1 );
      OUT2( prod_nagrev_s2 );
      break;
    default:
      break;
  }
}
