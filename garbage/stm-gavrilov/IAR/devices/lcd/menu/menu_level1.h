#ifndef _MENU_LEVEL1 
#define _MENU_LEVEL1
#include "LCDDefine.h"

/*
 * �������� ������� ���� ( ������� � �������� ������ ��������)
 */
  #define blokirovka    "����������"
  #define product       "�������"
  #define sirena        "������"
  #define naladka       "�������"
  #define dozator       "�������"
  #define vverh         "�����"
  #define vakuum        "������"
  #define obduv         "�����"
  #define transporter   "�����������"
  #define prijim_pop    "������ �������"
  #define prijim_prod   "������ ����"
  #define nagrev_pop    "������ �������"
  #define nagrev_prod   "������ ����"
  
  #define TOTAL_SIZE_ITEMS_BY_LEVEL1_MENU 13
  
/*
 * ������������� ���� ����� �� ����� ������ ������ ����
 */
void print_level1_menu();


/*
 * ����� �� ����� pos ����� ������ ����
 */
void print_level1_text_menu_by_position(unsigned char pos);


#endif  // _MENU_LEVEL1 
