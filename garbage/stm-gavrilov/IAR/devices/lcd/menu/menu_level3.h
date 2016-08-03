#ifndef _MENU_LEVEL3 
#define _MENU_LEVEL3

#include "LCDDriverMTC_S16204X.h"

/*
* �������� ������� ���� ( �������� ������ �������� �������� � ��������� ��� ������� ��������� )
*/
#define vkl_param     "���."
#define otkl_param    "����."
#define kolvo_pkts    "�������:"
#define pop_nagrev    "�����. ������:"
#define prod_nagrev   "����. ������:"

/*
* ������� �����������
*/
#define MIN_PACKAGES    20      /* ����������� ���������� �������/��� */
#define MAX_PACKAGES    30      /* ������������ ���������� �������/��� */
#define MIN_HEAT        0       /* ����������� �������� ����������� ��� % */
#define MAX_HEAT        100     /* ������������ �������� ����������� ��� % */

#define LEN 10  /* ����� ������������� ������(������� ���������) */

/*
* ���� �����������
*/
#define PACKAGES_TUNE_STEP      1       /* ��� ����������� ���������� ������� */
#define HEAT_TRANSV_TUNE_STEP   1       /* ��� ����������� ����������� ������� */
#define HEAT_LONG_TUNE_STEP     1       /* ��� ����������� ����������� ������� */
   
/*
 * ������������� ���� ����� �� ����� ������ ������ ����
 */
void print_level3_menu();

/*
 * ����� �� ����� pos ����� ������ ����
 */
void print_level3_text_menu_by_position(unsigned char pos);

/*
* ����� �� ����� ��������� "���������� �������"
*/
void print_level3_tuning_packages(void);

/*
* ����� �� ����� ��������� "����������� ����������� �������"
*/
void print_level3_tuning_heat_transv(void);

/*
* ����� �� ����� ��������� "����������� ����������� �������"
*/
void print_level3_tuning_heat_long(void);

#endif  // _MENU_LEVEL3 
