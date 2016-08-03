#include "data.h"
#include "menu_level1.h"
#include "menu_level2.h"
#include "menu_level3.h"
#include "menu_level4.h"

/* Код актуальной нажатой кнопки */
unsigned char  actual_button;

/* Признак того что кнопка была нажата */
/* INFO: Пока этот флаг не сбросится, actual_button не установится в новое значение */
/* Сброс должен быть осуществлен в теле основной функции менеджера контрольной панели */
bool           is_pressed;

/*
 * Текущий уровень меню
 */
unsigned char current_menu_level;

/*
 * Текущий пункт меню
 */
unsigned char current_menu_item;


/*
 * Признак того что мы находимся в данный момент в меню настроек
 */
unsigned char  is_settings_menu_entered = 0;

/*
* Признак того, что мы находимся в данный момент в регулировке количества пакетов
*/
unsigned char is_tuning_packages = 0;

/*
* Признак того, что мы находимся в данный момент в регулировке поперечного нагрева
*/
unsigned char is_tuning_heat_transv = 0;

/*
* Признак того, что мы находимся в данный момент в регулировке продольного нагрева
*/
unsigned char is_tuning_heat_long = 0;

/*
 * Состояние настроек
 */
CommandSettings settingsState;

/*
 * Текущая позиция на меню уровня 1
 */
unsigned char cur_position_on_level1 = 1;

/*
 * Текущая позиция на меню уровня 2
 */
unsigned char cur_position_on_level2 = 1;

/*
 * Текущая позиция на меню уровня 3
 */
unsigned char cur_position_on_level3 = 1;

/*
 * Текущая позиция на меню уровня 4
 */
unsigned char cur_position_on_level4 = 1;

/*
* Переменная состояния регулировки пакетов
* инициализируется минимлаьным значением
*/
int tuned_packages = MIN_PACKAGES;

/*
* Переменная состояния регулировки поперечного нрагрева
* инициализируется минимлаьным значением
*/
int tuned_heat_transv = MIN_HEAT;

/*
* Переменная состояния регулировки продольного нрагрева
* инициализируется минимлаьным значением
*/
int tuned_heat_long = MIN_HEAT;


/* флаг для переключения пуск\стоп */
bool start_stop_toggle = FALSE;

/*
 * Инициализация переменных модуля cpm
 */
void init_cpm_variables() {
  /* Сбросили сигнал нажатия на кнопку */
  actual_button      = 0;
  is_pressed         = TRUE;//FALSE;
  /* При инициализации уровень LEVEL1_CODE */
  current_menu_level = LEVEL1_CODE;
  /* При инициализации должен быть выбран первый пункт меню */
  current_menu_item  = MENU_ITEM1_CODE;
}

/*
 * Маршрутизатор первого уровня меню
 */
/*inline*/ void level1_switch() {

  switch (actual_button) {
    case BUTTON1_CODE:
      if (start_stop_toggle) {
        /* отправка команды "пуск" */
        start_stop_toggle = FALSE;
      }
      else {
        /* отправка команды "стоп" */
        start_stop_toggle = TRUE;
      }
     /* выдача команды пуск\стоп */
      break;
    case BUTTON2_CODE:
     /* перемотка вверх меню */
      cur_position_on_level1++;
      if (  cur_position_on_level1 > TOTAL_SIZE_ITEMS_BY_LEVEL1_MENU ) {
        cur_position_on_level1 = 1;
      }        
      print_level1_text_menu_by_position(cur_position_on_level1);  
      break;
    case BUTTON3_CODE:
     /* перемотка вниз меню */
      cur_position_on_level1--;
      if ( cur_position_on_level1 == 0 ) {
        cur_position_on_level1 = TOTAL_SIZE_ITEMS_BY_LEVEL1_MENU;
      }
      print_level1_text_menu_by_position(cur_position_on_level1);
      break;
    case BUTTON4_CODE:
     /* в меню настроек */
      print_level2_menu();
      current_menu_level = LEVEL2_CODE;
      break;
    default:
      break;
  }
}

/*
 * Маршрутизатор второго уровня меню
 */
/*inline*/ void level2_switch() {
  switch (actual_button) {
    case BUTTON1_CODE:
     /* возврат в меню уровня 1 */
      current_menu_level  = LEVEL1_CODE;
      cur_position_on_level2 = 1;
      print_level1_menu();
      cur_position_on_level1 = 1;
      break;
    case BUTTON2_CODE:
     /* перемотка вверх меню */
       cur_position_on_level2++;
       if (  cur_position_on_level2 > TOTAL_SIZE_ITEMS_BY_LEVEL2_MENU ) {
         cur_position_on_level2 = 1;
       } 
       print_level2_text_menu_by_position(cur_position_on_level2);
       current_menu_item = cur_position_on_level2; // ???
      break;
    case BUTTON3_CODE:
     /* перемотка вниз меню */
      cur_position_on_level2--;
      if ( cur_position_on_level2 == 0 ) {
        cur_position_on_level2 = TOTAL_SIZE_ITEMS_BY_LEVEL2_MENU;
      }
      print_level2_text_menu_by_position(cur_position_on_level2);
      
      current_menu_item  = cur_position_on_level2; // ???
      break;
    case BUTTON4_CODE:
     /* в меню настроек */
      current_menu_level = LEVEL3_CODE;
      /*Если выбрали меню настроек*/
      if (cur_position_on_level2 == 1) {
        print_level3_menu();
        is_settings_menu_entered = 1;
      }
      /* Если выбран пункт "КОЛИЧЕСТВО ПАКЕТОВ" */
      if (cur_position_on_level2 == 2) {
        print_level3_tuning_packages();
        is_tuning_packages = 1;
      }
      /* Если выбран пункт "РЕГУЛИРОВКА ПОПЕРЕЧНОГО НАГРЕВА" */
      if (cur_position_on_level2 == 3){
        print_level3_tuning_heat_transv();
        is_tuning_heat_transv = 1;
      }
      /* Если выбран пункт "РЕГУЛИРОВКА ПРОДОЛЬНОГО НАГРЕВА" */
      if (cur_position_on_level2 == 4){
        is_tuning_heat_long = 1;
        print_level3_tuning_heat_long();
      }
      is_pressed = TRUE;
      break;
    case BUTTON5_CODE:
     /* Отправить команду по uart */
     /* Отправка на основании cur_position_on_level2 */
      break;
    default:
      break;
  }
}


/*
 * Маршрутизатор третьего уровня меню
 */
/*/inline*/ void level3_switch() {
  if ( is_settings_menu_entered == 1 ) {
    //  настройки
    switch (actual_button) {
      case BUTTON1_CODE:
       /* возврат в меню уровня 1 */
        current_menu_level       = LEVEL1_CODE;
        cur_position_on_level2   = 1;
        is_settings_menu_entered = 0;
        print_level1_menu();
        cur_position_on_level1 = 1;
        break;
      case BUTTON2_CODE:
       /* перемотка вверх меню */
         cur_position_on_level3++;
         if (  cur_position_on_level3 > TOTAL_SIZE_ITEMS_BY_LEVEL1_MENU /*такое же количество как и меню 1 уровня*/ ) {
           cur_position_on_level3 = 1;
         } 
         print_level3_text_menu_by_position(cur_position_on_level3);
         current_menu_item = cur_position_on_level3; // ???
        break;
      case BUTTON3_CODE:
       /* перемотка вниз меню */
        cur_position_on_level3--;
        if (  cur_position_on_level3 == 0 ) {
          cur_position_on_level3 = TOTAL_SIZE_ITEMS_BY_LEVEL1_MENU;/*такое же количество как и меню 1 уровня*/
        } 
        print_level3_text_menu_by_position(cur_position_on_level3);
        current_menu_item  = cur_position_on_level3; // ???
       
        break;
      case BUTTON4_CODE:
       /* в меню настроек */
        print_level4_menu();
        current_menu_level = LEVEL4_CODE;
        is_pressed = TRUE;
        break;
      default:
        break;
    }
  }
  // 3 остальные пункта меню
  /* Регулировка количества пакетов */
  if (is_tuning_packages){
    print_level3_tuning_packages();
    switch (actual_button) {
      case BUTTON1_CODE:
       /* возврат в меню уровня 1 */
        current_menu_level       = LEVEL1_CODE;
        cur_position_on_level2   = 1;
        is_tuning_packages = 0;
        print_level1_menu();
        cur_position_on_level1 = 1;
        break; 
      case BUTTON2_CODE:
        tuned_packages -= PACKAGES_TUNE_STEP;
        if(tuned_packages < MIN_PACKAGES)
          tuned_packages = MAX_PACKAGES;
        break;
      case BUTTON3_CODE:
        tuned_packages += PACKAGES_TUNE_STEP;
        if(tuned_packages > MAX_PACKAGES)
          tuned_packages = MIN_PACKAGES;
        break;
      case BUTTON4_CODE:
        current_menu_level       = LEVEL2_CODE;
        cur_position_on_level2   = 2;
        is_tuning_packages       = 0;
        print_level2_menu();
        break;
      case BUTTON5_CODE:
        /* Поидее отправка по UART команды и возврат на меню уровня 2 */
        break;
      default:
        break;
    }
  }
  /* Регулировка поперечного нагрева */
  if (is_tuning_heat_transv){
    print_level3_tuning_heat_transv();
    switch (actual_button) {
      case BUTTON1_CODE:
       /* возврат в меню уровня 1 */
        current_menu_level       = LEVEL1_CODE;
        cur_position_on_level2   = 1;
        is_tuning_heat_transv = 0;
        print_level1_menu();
        cur_position_on_level1 = 1;
        break;
      case BUTTON2_CODE:
        tuned_heat_transv -= HEAT_TRANSV_TUNE_STEP;
        if(tuned_heat_transv < MIN_HEAT)
          tuned_heat_transv = MAX_HEAT;
        break;
      case BUTTON3_CODE:
        tuned_heat_transv += HEAT_TRANSV_TUNE_STEP;
        if(tuned_heat_transv > MAX_HEAT)
          tuned_heat_transv = MIN_HEAT;
        break;
      case BUTTON4_CODE:
        current_menu_level       = LEVEL2_CODE;
        cur_position_on_level2   = 3;
        is_tuning_heat_transv    = 0;
        print_level2_menu();
        break;
      case BUTTON5_CODE:
        /* Поидее отправка по UART команды и возврат на меню уровня 2 */
        break;
      default:
        break;
    }
  }
  /* Регулировка продольного нагрева */
  if (is_tuning_heat_long){
    print_level3_tuning_heat_long();
    switch (actual_button) {
      case BUTTON1_CODE:
       /* возврат в меню уровня 1 */
        current_menu_level       = LEVEL1_CODE;
        cur_position_on_level2   = 1;
        is_tuning_heat_long = 0;
        print_level1_menu();
        cur_position_on_level1 = 1;
        break;
      case BUTTON2_CODE:
        tuned_heat_long -= HEAT_LONG_TUNE_STEP;
        if(tuned_heat_long < MIN_HEAT)
          tuned_heat_long = MAX_HEAT;
        break;
      case BUTTON3_CODE:
        tuned_heat_long += HEAT_LONG_TUNE_STEP;
        if(tuned_heat_long > MAX_HEAT)
          tuned_heat_long = MIN_HEAT;
        break;
      case BUTTON4_CODE:
        current_menu_level       = LEVEL2_CODE;
        cur_position_on_level2   = 4;
        is_tuning_heat_long      = 0;
        print_level2_menu();
        break;
      case BUTTON5_CODE:
        /* Поидее отправка по UART команды и возврат на меню уровня 2 */
        break;
      default:
        break;
    }
  }
      
}

/*
 * Маршрутизатор четвертого уровня меню
 */
 void level4_switch() {
    //  настройки
    switch (actual_button) {
      case BUTTON1_CODE:
       /* возврат в меню уровня 1 */
        current_menu_level       = LEVEL1_CODE;
        print_level1_menu();
        cur_position_on_level1 = 1;
        //cur_position_on_level2   = 1;    
        break;
      case BUTTON2_CODE:
       /* перемотка вверх меню */
        cur_position_on_level4++;
        if (  cur_position_on_level4 == 3 ) {
          cur_position_on_level4 = 1; /* вкл, откл */
        } 
        print_level4_text_menu_by_position(cur_position_on_level4);
        break;
      case BUTTON3_CODE:
       /* перемотка вниз меню */
        cur_position_on_level4--;
        if (  cur_position_on_level4 == 0 ) {
          cur_position_on_level4 = 2; /* вкл, откл */
        } 
        print_level4_text_menu_by_position(cur_position_on_level4);
        break;
      case BUTTON4_CODE:
       /* в меню настроек */
        print_level3_menu();
        current_menu_level = LEVEL3_CODE;
        break;
      default:
        break;
    }
}

void SomeDelay()
{
  for (unsigned long delay_count=0; delay_count<300000; delay_count++);
};

/* Основная функция менеджера контрольной панели */
void main_cpm_routine() {

  settingsState.value = 0; /* Очистка  состояния настроек, сброс из в ОТКЛ. */
  print_level1_menu();     /* Прорисовка меню первого уровня */

  while (1) {
    if (is_pressed == TRUE) {

      /* тут поверяется код нажатой кнопки и на основании этого прорисовывается
         меню. Также должен происходить сброс is_pressed */
      switch (current_menu_level) {
        case LEVEL1_CODE:
          level1_switch();
          break;
        case LEVEL2_CODE:
          level2_switch();
          break;
        case LEVEL3_CODE:
          level3_switch();
          break;
        case LEVEL4_CODE:
          /* на уровне 4, только настройки команды COMM_SETTING_CMD */
          level4_switch();
          break;
        default:
          break;
      }

      SomeDelay();
      
      is_pressed = FALSE;
      
      
    }
  }
}
