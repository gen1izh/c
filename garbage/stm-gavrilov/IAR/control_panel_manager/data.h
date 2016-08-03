/**
  ******************************************************************************
  * @file    data.h
  * @author  Zalogix Team
  * @version V1.0.0
  * @date    03-06-2015
  * @brief   ���� ���� �������� ���������� ���������� ���������
  ******************************************************************************
  */

#ifndef __CONTROL_PANEL_MANAGER_H
#define __CONTROL_PANEL_MANAGER_H

#include <stm8s.h>
    
/* ���� ������ */
/* Info: ���� is_pressed=TRUE � actual_button=BUTTON1_CODE, �� ���������,
         ��� ������ SB1 ������. */
enum {
  BUTTON1_CODE = 1,   
  BUTTON2_CODE = 2,
  BUTTON3_CODE = 3,
  BUTTON4_CODE = 4,
  BUTTON5_CODE = 5,
};

/* ���� ������� ���� */
enum {
  LEVEL1_CODE = 1,
  LEVEL2_CODE = 2,
  LEVEL3_CODE = 3,
  LEVEL4_CODE = 4
};

/* ���� ������� ���� */
enum {
  MENU_ITEM1_CODE = 1,
  MENU_ITEM2_CODE = 2,
  MENU_ITEM3_CODE = 3,
  MENU_ITEM4_CODE = 4
};

/* ���� ������ ���� */
enum {
  COMM_ON_CMD,                  /* ���� */
  COMM_OFF_CMD,                 /* ���� */
  COMM_SETTING_CMD,             /* ��������� */  
  COMM_TUNING_PACK_CMD,         /* ����������� ���������� ������� */  
  COMM_TUNING_HEAT_TRANSV_CMD,  /* ����������� ����������� ������� */  
  COMM_TUNING_HEAT_LONG_CMD     /* ����������� ����������� ������� */
};

/* ���� �����-��������, ������ ��� ������� COMM_SETTING_CMD */
typedef union CommandData {

  unsigned short value; /* �������� ��������� */

  struct  {
    unsigned a0:  1;   /* ���������� */
    unsigned a1:  1;   /* ������� */
    unsigned a2:  1;   /* ������ */
    unsigned a3:  1;   /* ������� */
    unsigned a4:  1;   /* ������� */
    unsigned a5:  1;   /* ����� */
    unsigned a6:  1;   /* ������ */
    unsigned a7:  1;   /* ����� */
    unsigned a8:  1;   /* ����������� */
    unsigned a9:  1;   /* ������ ������� */
    unsigned a10: 1;   /* ������ ���� */
    unsigned a11: 1;   /* ������ ������� */
    unsigned a12: 1;   /* ������ ���� */
    unsigned a13: 3;   /* ����� */
  } stateword;
}CommandSettings;

#define MAIN_MENU

/* �������� ������� ��������� ������ ���������� */
void main_cpm_routine();

/* ������������� ���������� ������ cpm */
void init_cpm_variables();

#endif  // __CONTROL_PANEL_MANAGER_H
