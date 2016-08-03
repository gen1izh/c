#include "data.h"
#include "menu_level1.h"
#include "menu_level2.h"
#include "menu_level3.h"
#include "menu_level4.h"

/* ��� ���������� ������� ������ */
unsigned char  actual_button;

/* ������� ���� ��� ������ ���� ������ */
/* INFO: ���� ���� ���� �� ���������, actual_button �� ����������� � ����� �������� */
/* ����� ������ ���� ����������� � ���� �������� ������� ��������� ����������� ������ */
bool           is_pressed;

/*
 * ������� ������� ����
 */
unsigned char current_menu_level;

/*
 * ������� ����� ����
 */
unsigned char current_menu_item;


/*
 * ������� ���� ��� �� ��������� � ������ ������ � ���� ��������
 */
unsigned char  is_settings_menu_entered = 0;

/*
* ������� ����, ��� �� ��������� � ������ ������ � ����������� ���������� �������
*/
unsigned char is_tuning_packages = 0;

/*
* ������� ����, ��� �� ��������� � ������ ������ � ����������� ����������� �������
*/
unsigned char is_tuning_heat_transv = 0;

/*
* ������� ����, ��� �� ��������� � ������ ������ � ����������� ����������� �������
*/
unsigned char is_tuning_heat_long = 0;

/*
 * ��������� ��������
 */
CommandSettings settingsState;

/*
 * ������� ������� �� ���� ������ 1
 */
unsigned char cur_position_on_level1 = 1;

/*
 * ������� ������� �� ���� ������ 2
 */
unsigned char cur_position_on_level2 = 1;

/*
 * ������� ������� �� ���� ������ 3
 */
unsigned char cur_position_on_level3 = 1;

/*
 * ������� ������� �� ���� ������ 4
 */
unsigned char cur_position_on_level4 = 1;

/*
* ���������� ��������� ����������� �������
* ���������������� ����������� ���������
*/
int tuned_packages = MIN_PACKAGES;

/*
* ���������� ��������� ����������� ����������� ��������
* ���������������� ����������� ���������
*/
int tuned_heat_transv = MIN_HEAT;

/*
* ���������� ��������� ����������� ����������� ��������
* ���������������� ����������� ���������
*/
int tuned_heat_long = MIN_HEAT;


/* ���� ��� ������������ ����\���� */
bool start_stop_toggle = FALSE;

/*
 * ������������� ���������� ������ cpm
 */
void init_cpm_variables() {
  /* �������� ������ ������� �� ������ */
  actual_button      = 0;
  is_pressed         = TRUE;//FALSE;
  /* ��� ������������� ������� LEVEL1_CODE */
  current_menu_level = LEVEL1_CODE;
  /* ��� ������������� ������ ���� ������ ������ ����� ���� */
  current_menu_item  = MENU_ITEM1_CODE;
}

/*
 * ������������� ������� ������ ����
 */
/*inline*/ void level1_switch() {

  switch (actual_button) {
    case BUTTON1_CODE:
      if (start_stop_toggle) {
        /* �������� ������� "����" */
        start_stop_toggle = FALSE;
      }
      else {
        /* �������� ������� "����" */
        start_stop_toggle = TRUE;
      }
     /* ������ ������� ����\���� */
      break;
    case BUTTON2_CODE:
     /* ��������� ����� ���� */
      cur_position_on_level1++;
      if (  cur_position_on_level1 > TOTAL_SIZE_ITEMS_BY_LEVEL1_MENU ) {
        cur_position_on_level1 = 1;
      }        
      print_level1_text_menu_by_position(cur_position_on_level1);  
      break;
    case BUTTON3_CODE:
     /* ��������� ���� ���� */
      cur_position_on_level1--;
      if ( cur_position_on_level1 == 0 ) {
        cur_position_on_level1 = TOTAL_SIZE_ITEMS_BY_LEVEL1_MENU;
      }
      print_level1_text_menu_by_position(cur_position_on_level1);
      break;
    case BUTTON4_CODE:
     /* � ���� �������� */
      print_level2_menu();
      current_menu_level = LEVEL2_CODE;
      break;
    default:
      break;
  }
}

/*
 * ������������� ������� ������ ����
 */
/*inline*/ void level2_switch() {
  switch (actual_button) {
    case BUTTON1_CODE:
     /* ������� � ���� ������ 1 */
      current_menu_level  = LEVEL1_CODE;
      cur_position_on_level2 = 1;
      print_level1_menu();
      cur_position_on_level1 = 1;
      break;
    case BUTTON2_CODE:
     /* ��������� ����� ���� */
       cur_position_on_level2++;
       if (  cur_position_on_level2 > TOTAL_SIZE_ITEMS_BY_LEVEL2_MENU ) {
         cur_position_on_level2 = 1;
       } 
       print_level2_text_menu_by_position(cur_position_on_level2);
       current_menu_item = cur_position_on_level2; // ???
      break;
    case BUTTON3_CODE:
     /* ��������� ���� ���� */
      cur_position_on_level2--;
      if ( cur_position_on_level2 == 0 ) {
        cur_position_on_level2 = TOTAL_SIZE_ITEMS_BY_LEVEL2_MENU;
      }
      print_level2_text_menu_by_position(cur_position_on_level2);
      
      current_menu_item  = cur_position_on_level2; // ???
      break;
    case BUTTON4_CODE:
     /* � ���� �������� */
      current_menu_level = LEVEL3_CODE;
      /*���� ������� ���� ��������*/
      if (cur_position_on_level2 == 1) {
        print_level3_menu();
        is_settings_menu_entered = 1;
      }
      /* ���� ������ ����� "���������� �������" */
      if (cur_position_on_level2 == 2) {
        print_level3_tuning_packages();
        is_tuning_packages = 1;
      }
      /* ���� ������ ����� "����������� ����������� �������" */
      if (cur_position_on_level2 == 3){
        print_level3_tuning_heat_transv();
        is_tuning_heat_transv = 1;
      }
      /* ���� ������ ����� "����������� ����������� �������" */
      if (cur_position_on_level2 == 4){
        is_tuning_heat_long = 1;
        print_level3_tuning_heat_long();
      }
      is_pressed = TRUE;
      break;
    case BUTTON5_CODE:
     /* ��������� ������� �� uart */
     /* �������� �� ��������� cur_position_on_level2 */
      break;
    default:
      break;
  }
}


/*
 * ������������� �������� ������ ����
 */
/*/inline*/ void level3_switch() {
  if ( is_settings_menu_entered == 1 ) {
    //  ���������
    switch (actual_button) {
      case BUTTON1_CODE:
       /* ������� � ���� ������ 1 */
        current_menu_level       = LEVEL1_CODE;
        cur_position_on_level2   = 1;
        is_settings_menu_entered = 0;
        print_level1_menu();
        cur_position_on_level1 = 1;
        break;
      case BUTTON2_CODE:
       /* ��������� ����� ���� */
         cur_position_on_level3++;
         if (  cur_position_on_level3 > TOTAL_SIZE_ITEMS_BY_LEVEL1_MENU /*����� �� ���������� ��� � ���� 1 ������*/ ) {
           cur_position_on_level3 = 1;
         } 
         print_level3_text_menu_by_position(cur_position_on_level3);
         current_menu_item = cur_position_on_level3; // ???
        break;
      case BUTTON3_CODE:
       /* ��������� ���� ���� */
        cur_position_on_level3--;
        if (  cur_position_on_level3 == 0 ) {
          cur_position_on_level3 = TOTAL_SIZE_ITEMS_BY_LEVEL1_MENU;/*����� �� ���������� ��� � ���� 1 ������*/
        } 
        print_level3_text_menu_by_position(cur_position_on_level3);
        current_menu_item  = cur_position_on_level3; // ???
       
        break;
      case BUTTON4_CODE:
       /* � ���� �������� */
        print_level4_menu();
        current_menu_level = LEVEL4_CODE;
        is_pressed = TRUE;
        break;
      default:
        break;
    }
  }
  // 3 ��������� ������ ����
  /* ����������� ���������� ������� */
  if (is_tuning_packages){
    print_level3_tuning_packages();
    switch (actual_button) {
      case BUTTON1_CODE:
       /* ������� � ���� ������ 1 */
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
        /* ������ �������� �� UART ������� � ������� �� ���� ������ 2 */
        break;
      default:
        break;
    }
  }
  /* ����������� ����������� ������� */
  if (is_tuning_heat_transv){
    print_level3_tuning_heat_transv();
    switch (actual_button) {
      case BUTTON1_CODE:
       /* ������� � ���� ������ 1 */
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
        /* ������ �������� �� UART ������� � ������� �� ���� ������ 2 */
        break;
      default:
        break;
    }
  }
  /* ����������� ����������� ������� */
  if (is_tuning_heat_long){
    print_level3_tuning_heat_long();
    switch (actual_button) {
      case BUTTON1_CODE:
       /* ������� � ���� ������ 1 */
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
        /* ������ �������� �� UART ������� � ������� �� ���� ������ 2 */
        break;
      default:
        break;
    }
  }
      
}

/*
 * ������������� ���������� ������ ����
 */
 void level4_switch() {
    //  ���������
    switch (actual_button) {
      case BUTTON1_CODE:
       /* ������� � ���� ������ 1 */
        current_menu_level       = LEVEL1_CODE;
        print_level1_menu();
        cur_position_on_level1 = 1;
        //cur_position_on_level2   = 1;    
        break;
      case BUTTON2_CODE:
       /* ��������� ����� ���� */
        cur_position_on_level4++;
        if (  cur_position_on_level4 == 3 ) {
          cur_position_on_level4 = 1; /* ���, ���� */
        } 
        print_level4_text_menu_by_position(cur_position_on_level4);
        break;
      case BUTTON3_CODE:
       /* ��������� ���� ���� */
        cur_position_on_level4--;
        if (  cur_position_on_level4 == 0 ) {
          cur_position_on_level4 = 2; /* ���, ���� */
        } 
        print_level4_text_menu_by_position(cur_position_on_level4);
        break;
      case BUTTON4_CODE:
       /* � ���� �������� */
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

/* �������� ������� ��������� ����������� ������ */
void main_cpm_routine() {

  settingsState.value = 0; /* �������  ��������� ��������, ����� �� � ����. */
  print_level1_menu();     /* ���������� ���� ������� ������ */

  while (1) {
    if (is_pressed == TRUE) {

      /* ��� ���������� ��� ������� ������ � �� ��������� ����� ���������������
         ����. ����� ������ ����������� ����� is_pressed */
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
          /* �� ������ 4, ������ ��������� ������� COMM_SETTING_CMD */
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
