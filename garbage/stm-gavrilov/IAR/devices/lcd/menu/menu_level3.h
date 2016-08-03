#ifndef _MENU_LEVEL3 
#define _MENU_LEVEL3

#include "LCDDriverMTC_S16204X.h"

/*
* Названия пунктов меню ( третьего уровня значений настроек и четвертый для команды Настройка )
*/
#define vkl_param     "ВКЛ."
#define otkl_param    "ОТКЛ."
#define kolvo_pkts    "ПАКЕТОВ:"
#define pop_nagrev    "ПОПЕР. НАГРЕВ:"
#define prod_nagrev   "ПРОД. НАГРЕВ:"

/*
* Пределы регулировки
*/
#define MIN_PACKAGES    20      /* Минимальное количество пакетов/мин */
#define MAX_PACKAGES    30      /* Максимальное количество пакетов/мин */
#define MIN_HEAT        0       /* Минимальное значение регулировки ШИМ % */
#define MAX_HEAT        100     /* Максимальное значение регулировки ШМИ % */

#define LEN 10  /* Длина преобразуемой строки(КОСТЫЛЬ ВЕЛОСИПЕД) */

/*
* Шаги регулировки
*/
#define PACKAGES_TUNE_STEP      1       /* Шаг регулировки количества пакетов */
#define HEAT_TRANSV_TUNE_STEP   1       /* Шаг регулировки поперечного нагрева */
#define HEAT_LONG_TUNE_STEP     1       /* Шаг регулировки продольного нагрева */
   
/*
 * Инициализация меню вывод на экран первые пункты меню
 */
void print_level3_menu();

/*
 * Вывод на экран pos номер пункта меню
 */
void print_level3_text_menu_by_position(unsigned char pos);

/*
* Вывод на экран настройки "КОЛИЧЕСТВО ПАКЕТОВ"
*/
void print_level3_tuning_packages(void);

/*
* Вывод на экран настройки "РЕГУЛИРОВКА ПОПЕРЕЧНОГО НАГРЕВА"
*/
void print_level3_tuning_heat_transv(void);

/*
* Вывод на экран настройки "РЕГУЛИРОВКА ПОПЕРЕЧНОГО НАГРЕВА"
*/
void print_level3_tuning_heat_long(void);

#endif  // _MENU_LEVEL3 
