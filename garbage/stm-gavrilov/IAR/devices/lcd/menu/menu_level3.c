#include "data.h"
#include "string.h"
#include "menu_level1.h"
#include "LCDDefine.h"
#include "stm8s.h"
#include "menu_level3.h"
/*
 * Состояние настроек
 */
extern CommandSettings settingsState;

/*
* Количество пакетов
*/
extern int tuned_packages;

/*
* ШИМ поперечного нагрева
*/
extern int tuned_heat_transv;

/*
* ШИМ продольного нагрева
*/
extern int tuned_heat_long;

/* itoa:  конвертируем n в символы в s */
void itoa(int n, unsigned char s[])
{
    int i, j, len;
    char c;
  
    i = 0;
    do {       /* генерируем цифры в обратном порядке */
        s[i++] = n % 10 + '0';   /* берем следующую цифру */
    } while ((n /= 10) > 0);     /* удаляем */
    s[i] = '\0';
    len = i;
    
    for (i = 0, j = len-1; i<j; i++, j--) {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
    }
}

/*
 * Вывод на экран первого пункта  меню
 */
void print_level3_menu() {
  ClearDisplay();
  OUT1( blokirovka );
  if ( settingsState.stateword.a0 == 1 ) {
    OUT2( "[ВКЛ.] ОТКЛ." );
  }
  else {
    OUT2( "ВКЛ. [ОТКЛ.]" );
  }

}


/*
 * Вывод на экран pos номер пункта меню
 */
void print_level3_text_menu_by_position(unsigned char pos) {
  ClearDisplay();
  switch (pos) {
    case 1:
      OUT1( blokirovka );
      if ( settingsState.stateword.a0 == 1 ) {
        OUT2( "[ВКЛ.] ОТКЛ." );
      }
      else {
        OUT2( "ВКЛ. [ОТКЛ.]" );
      }
      break;
    case 2:
      OUT1( product );
      if ( settingsState.stateword.a1 == 1 ) {
        OUT2( "[ВКЛ.] ОТКЛ." );
      }
      else {
        OUT2( "ВКЛ. [ОТКЛ.]" );
      }
      break;
    case 3:
      OUT1( sirena );
      if ( settingsState.stateword.a2 == 1 ) {
        OUT2( "[ВКЛ.] ОТКЛ." );
      }
      else {
        OUT2( "ВКЛ. [ОТКЛ.]" );
      }
      break;
    case 4:
      OUT1( naladka );
      if ( settingsState.stateword.a3 == 1 ) {
        OUT2( "[ВКЛ.] ОТКЛ." );
      }
      else {
        OUT2( "ВКЛ. [ОТКЛ.]" );
      }
      break;
    case 5:
      OUT1( dozator );
      if ( settingsState.stateword.a4 == 1 ) {
        OUT2( "[ВКЛ.] ОТКЛ." );
      }
      else {
        OUT2( "ВКЛ. [ОТКЛ.]" );
      }
      break;
    case 6:
      OUT1( vverh );
      if ( settingsState.stateword.a5 == 1 ) {
        OUT2( "[ВКЛ.] ОТКЛ." );
      }
      else {
        OUT2( "ВКЛ. [ОТКЛ.]" );
      }
      break;
    case 7:
      OUT1( vakuum );
      if ( settingsState.stateword.a6 == 1 ) {
        OUT2( "[ВКЛ.] ОТКЛ." );
      }
      else {
        OUT2( "ВКЛ. [ОТКЛ.]" );
      }
      break;
    case 8:
      OUT1( obduv );
      if ( settingsState.stateword.a7 == 1 ) {
        OUT2( "[ВКЛ.] ОТКЛ." );
      }
      else {
        OUT2( "ВКЛ. [ОТКЛ.]" );
      }
      break;
    case 9:
      OUT1( transporter );
      if ( settingsState.stateword.a8 == 1 ) {
        OUT2( "[ВКЛ.] ОТКЛ." );
      }
      else {
        OUT2( "ВКЛ. [ОТКЛ.]" );
      }
      break;
    case 10:
      OUT1( prijim_pop );
      if ( settingsState.stateword.a9 == 1 ) {
        OUT2( "[ВКЛ.] ОТКЛ." );
      }
      else {
        OUT2( "ВКЛ. [ОТКЛ.]" );
      }
      break;
    case 11:
      OUT1( prijim_prod );
      if ( settingsState.stateword.a10 == 1 ) {
        OUT2( "[ВКЛ.] ОТКЛ." );
      }
      else {
        OUT2( "ВКЛ. [ОТКЛ.]" );
      }
      break;
    case 12:
      OUT1( nagrev_pop );
      if ( settingsState.stateword.a11 == 1 ) {
        OUT2( "[ВКЛ.] ОТКЛ." );
      }
      else {
        OUT2( "ВКЛ. [ОТКЛ.]" );
      }
      break;
    case 13:
      OUT1( nagrev_prod );
      if ( settingsState.stateword.a12 == 1 ) {
        OUT2( "[ВКЛ.] ОТКЛ." );
      }
      else {
        OUT2( "ВКЛ. [ОТКЛ.]" );
      }
      break;
  }
}
      
/*
* Вывод на экран настройки "КОЛИЧЕСТВО ПАКЕТОВ"
*/
void print_level3_tuning_packages(void){
  unsigned char temp[LEN];
  ClearDisplay();
  OUT1(kolvo_pkts);
  itoa(tuned_packages, temp);
  OUT2_mod(temp);
}

/*
* Вывод на экран настройки "РЕГУЛИРОВКА ПОПЕРЕЧНОГО НАГРЕВА"
*/
void print_level3_tuning_heat_transv(void){
  unsigned char temp[LEN];
  ClearDisplay();
  OUT1(pop_nagrev);
  itoa(tuned_heat_transv, temp);
  OUT2_mod(temp);
}

/*
* Вывод на экран настройки "РЕГУЛИРОВКА ПОПЕРЕЧНОГО НАГРЕВА"
*/
void print_level3_tuning_heat_long(void){
  unsigned char temp[LEN];
  ClearDisplay();
  OUT1(prod_nagrev);
  itoa(tuned_heat_long, temp);
  OUT2_mod(temp);
}