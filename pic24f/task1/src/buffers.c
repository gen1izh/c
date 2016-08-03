#include "buffers.h"
#include <stdlib.h>
#include <limits.h>

int buf_count 		  = 0; // ���������� �������� ������� �� ������� ������
int buf_id_number 	= 0; // ������������� ������

buffer_marker buffers[BUF_CNT];

/*
 * ������� ����� �� ��������������
 */
void delete_buf( int id ) {
  int i;
  for ( i = 0; i < buf_count-1; i++ ) {
    if ( i >= id ) {
      buffers[i].buf_id   = buffers[i+1].buf_id;
	  buffers[i].ptr_buf  = buffers[i+1].ptr_buf;
	  buffers[i].state    = buffers[i+1].state;
	}
  }
  buf_count--;
}

/*
 * ������� ����� � ���������� id ���
 */
int create_buf(void) {
  if ( buf_count < BUF_CNT  ) {
    buffers[buf_count].buf_id 	= buf_id_number;			// ����� ������, �������������
    buffers[buf_count].ptr_buf 	= (int)((int*) malloc(BUF_SIZE));  // �������� ������
    buffers[buf_count].state 	  = FILLING_BUFFER_STATE;     // ��������� ������
    buffers[buf_count].indx     = 0;
    buf_id_number++;
    buf_count++;
	return buffers[buf_count-1].buf_id;
  }
  return -1;
}

/*
 * ���������� id ������� ����������� ������ � �������
 * �������������� ������ ������ � ������� ������ �������
 */
int get_id_current_buf(void) {
  int i;
  for ( i = 0; i < buf_count; i++ ) {
    if ( buffers[i].state == FILLING_BUFFER_STATE ) {
	  return buffers[i].buf_id;
	}
  }
  return -1;
}
/*
 * ���������� id ������ ��� �������� � ������
 * ������ ���������� ������� ���
 */
int get_id_current_calculating_rms_buf(void) {
  int i;
  for ( i = 0; i < buf_count; i++ ) {
    if ( buffers[i].state == CALCULATE_RMS_STATE ) {
    return buffers[i].buf_id;
  }
  }
  return -1;
}

/*
 * ���������� id ������ ������� ��� �������� �������������� ���
 */
int get_id_waiting_rms_buf(void) {
  int i;
  for ( i = 0; i < buf_count; i++ ) {
    if ( buffers[i].state == CALCULATE_RMS_STATE ) {
	  return buffers[i].ptr_buf;
	}
  }
  return -1;
}

/*
 * ���������� ��������� �� ����� �� id
 */
int get_ptr_buf( int id ) {
  int i;
  for ( i = 0; i < buf_count; i++ ) {
    if ( buffers[i].buf_id == id ) {
	  return buffers[i].ptr_buf;
	}
  }
  return -1;
}

/*
 * ���������� ��������� ������ �� id
 */
int get_state_buf( int id ) {
  int i;
  for ( i = 0; i < buf_count; i++ ) {
    if ( buffers[i].buf_id == id ) {
	  return buffers[i].state;
	}
  }
  return -1;
}

/*
 * ���������� ���������� �������� � ������ �� ������� ������
 */
int get_elements_num_buf( int id ) {
  int i;
  for ( i = 0; i < buf_count; i++ ) {
    if ( buffers[i].buf_id == id ) {
	  return buffers[buf_count].indx;
	}
  }
  return -1;
}


/*
 * ��������� �������� � ����� �������� ������
 */
int add_element_in_current_buffer( int value ) {
  int i;
  for ( i = 0; i < buf_count; i++ ) {
    if ( buffers[i].state == FILLING_BUFFER_STATE ) {
      if ( buffers[i].indx >= BUF_SIZE ) {
        return -1;
      }
      else {
        *((int *)(buffers[i].ptr_buf)) = value;
        buffers[i].ptr_buf++;
        buffers[i].indx++;
      }
	  }
  }
  return 0;
}

int has_some_waiting_buffers() {
  int i;
  for ( i = 0; i < buf_count; i++ ) {
    if ( buffers[i].state == CALCULATE_RMS_STATE ) {
      return 1;
    }
    if ( buffers[i].state == WAIT_CALCULATE_RMS_ROUTINE_STATE ) {
      return 1;
    }
  }
  return 0;
}

/*
 * ������� ��������� ���������� ������
 * �������� ��� �������� ���
 */
void set_active_buffer_wait_calc_rms_state(void) {
  int i, j;

  int min = INT_MAX;

  /*
   * ��������� � ������� �������, ��������� �����
   * ������� ��� �������� ���, ���� ��������� �������
   * ������, ������� ������������� ��� �� ������ ������.
   */
  for ( i = 0; i < buf_count; i++ ) {
    if ( buffers[i].state == FILLING_BUFFER_STATE ) {

      buffers[i].state = CALCULATE_RMS_STATE;

      for ( j = 0; j < buf_count; j++ ) {
        if ( (( buffers[j].state == CALCULATE_RMS_STATE ) && ( i!=j) ) ||
            ( buffers[j].state == WAIT_CALCULATE_RMS_ROUTINE_STATE ) ){
          buffers[i].state = WAIT_CALCULATE_RMS_ROUTINE_STATE;
          break;
        }
      }
      break;
    }
  }

  /*
   * ���� � ������� ������� ��������� �������, ������� ���� ������, ��
   * ������������� ����������� id - ������� ���� ��� ����� ��� ������ ������
   * � ������ � ��������� � ���� ����
   */
  for ( i = 0; i < buf_count; i++ ) {
    if ( ( buffers[i].buf_id < min ) && ( buffers[i].state == WAIT_CALCULATE_RMS_ROUTINE_STATE ) ) {
      min = buffers[i].buf_id;
    }
  }

  /*
   * ����� ����������� ������������������� ������, � ���� ��������������� ���������
   * ���������� �������� ���
   */
  for ( i = 0; i < buf_count; i++ ) {
    if ( ( buffers[i].buf_id == min ) && ( buffers[i].state == WAIT_CALCULATE_RMS_ROUTINE_STATE ) ) {
      buffers[i].state = CALCULATE_RMS_STATE;
    }
  }

  return;
}


/*
 * ������� ��� ������
 */
void free_all_buffers() {
  buf_count = 0;
}
