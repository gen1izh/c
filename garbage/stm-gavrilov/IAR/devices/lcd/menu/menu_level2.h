#ifndef _MENU_LEVEL2 
#define _MENU_LEVEL2

/*
 * �������� ������� ���� ( ������� ������ ������ )
 */
  #define nastroika_s1      "���������"
  #define nastroika_s2      "������"
  
  #define kolvo_pkts_s1     "����������"
  #define kolvo_pkts_s2     "�������"
  
  #define pop_nagrev_s1     "����������"
  #define pop_nagrev_s2     "������"
  
  #define prod_nagrev_s1    "����������"
  #define prod_nagrev_s2    "������"

   
  #define TOTAL_SIZE_ITEMS_BY_LEVEL2_MENU 4
/*
 * ����� �� ����� ������� ������ ����
 */
void print_level2_menu();

/*
 * ����� �� ����� pos ����� ������ ���� ��������
 */
void print_level2_text_menu_by_position(unsigned char pos);

#endif  // _MENU_LEVEL2 
