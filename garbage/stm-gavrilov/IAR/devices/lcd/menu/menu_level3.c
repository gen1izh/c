#include "data.h"
#include "string.h"
#include "menu_level1.h"
#include "LCDDefine.h"
#include "stm8s.h"
#include "menu_level3.h"
/*
 * ��������� ��������
 */
extern CommandSettings settingsState;

/*
* ���������� �������
*/
extern int tuned_packages;

/*
* ��� ����������� �������
*/
extern int tuned_heat_transv;

/*
* ��� ����������� �������
*/
extern int tuned_heat_long;

/* itoa:  ������������ n � ������� � s */
void itoa(int n, unsigned char s[])
{
    int i, j, len;
    char c;
  
    i = 0;
    do {       /* ���������� ����� � �������� ������� */
        s[i++] = n % 10 + '0';   /* ����� ��������� ����� */
    } while ((n /= 10) > 0);     /* ������� */
    s[i] = '\0';
    len = i;
    
    for (i = 0, j = len-1; i<j; i++, j--) {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
    }
}

/*
 * ����� �� ����� ������� ������  ����
 */
void print_level3_menu() {
  ClearDisplay();
  OUT1( blokirovka );
  if ( settingsState.stateword.a0 == 1 ) {
    OUT2( "[���.] ����." );
  }
  else {
    OUT2( "���. [����.]" );
  }

}


/*
 * ����� �� ����� pos ����� ������ ����
 */
void print_level3_text_menu_by_position(unsigned char pos) {
  ClearDisplay();
  switch (pos) {
    case 1:
      OUT1( blokirovka );
      if ( settingsState.stateword.a0 == 1 ) {
        OUT2( "[���.] ����." );
      }
      else {
        OUT2( "���. [����.]" );
      }
      break;
    case 2:
      OUT1( product );
      if ( settingsState.stateword.a1 == 1 ) {
        OUT2( "[���.] ����." );
      }
      else {
        OUT2( "���. [����.]" );
      }
      break;
    case 3:
      OUT1( sirena );
      if ( settingsState.stateword.a2 == 1 ) {
        OUT2( "[���.] ����." );
      }
      else {
        OUT2( "���. [����.]" );
      }
      break;
    case 4:
      OUT1( naladka );
      if ( settingsState.stateword.a3 == 1 ) {
        OUT2( "[���.] ����." );
      }
      else {
        OUT2( "���. [����.]" );
      }
      break;
    case 5:
      OUT1( dozator );
      if ( settingsState.stateword.a4 == 1 ) {
        OUT2( "[���.] ����." );
      }
      else {
        OUT2( "���. [����.]" );
      }
      break;
    case 6:
      OUT1( vverh );
      if ( settingsState.stateword.a5 == 1 ) {
        OUT2( "[���.] ����." );
      }
      else {
        OUT2( "���. [����.]" );
      }
      break;
    case 7:
      OUT1( vakuum );
      if ( settingsState.stateword.a6 == 1 ) {
        OUT2( "[���.] ����." );
      }
      else {
        OUT2( "���. [����.]" );
      }
      break;
    case 8:
      OUT1( obduv );
      if ( settingsState.stateword.a7 == 1 ) {
        OUT2( "[���.] ����." );
      }
      else {
        OUT2( "���. [����.]" );
      }
      break;
    case 9:
      OUT1( transporter );
      if ( settingsState.stateword.a8 == 1 ) {
        OUT2( "[���.] ����." );
      }
      else {
        OUT2( "���. [����.]" );
      }
      break;
    case 10:
      OUT1( prijim_pop );
      if ( settingsState.stateword.a9 == 1 ) {
        OUT2( "[���.] ����." );
      }
      else {
        OUT2( "���. [����.]" );
      }
      break;
    case 11:
      OUT1( prijim_prod );
      if ( settingsState.stateword.a10 == 1 ) {
        OUT2( "[���.] ����." );
      }
      else {
        OUT2( "���. [����.]" );
      }
      break;
    case 12:
      OUT1( nagrev_pop );
      if ( settingsState.stateword.a11 == 1 ) {
        OUT2( "[���.] ����." );
      }
      else {
        OUT2( "���. [����.]" );
      }
      break;
    case 13:
      OUT1( nagrev_prod );
      if ( settingsState.stateword.a12 == 1 ) {
        OUT2( "[���.] ����." );
      }
      else {
        OUT2( "���. [����.]" );
      }
      break;
  }
}
      
/*
* ����� �� ����� ��������� "���������� �������"
*/
void print_level3_tuning_packages(void){
  unsigned char temp[LEN];
  ClearDisplay();
  OUT1(kolvo_pkts);
  itoa(tuned_packages, temp);
  OUT2_mod(temp);
}

/*
* ����� �� ����� ��������� "����������� ����������� �������"
*/
void print_level3_tuning_heat_transv(void){
  unsigned char temp[LEN];
  ClearDisplay();
  OUT1(pop_nagrev);
  itoa(tuned_heat_transv, temp);
  OUT2_mod(temp);
}

/*
* ����� �� ����� ��������� "����������� ����������� �������"
*/
void print_level3_tuning_heat_long(void){
  unsigned char temp[LEN];
  ClearDisplay();
  OUT1(prod_nagrev);
  itoa(tuned_heat_long, temp);
  OUT2_mod(temp);
}