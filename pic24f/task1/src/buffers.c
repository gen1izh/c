#include "buffers.h"
#include <stdlib.h>
#include <limits.h>

int buf_count 		  = 0; // количество активных буферов на текущий момент
int buf_id_number 	= 0; // идентификатор буфера

buffer_marker buffers[BUF_CNT];

/*
 * Удаляет буфер по идентификатору
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
 * Создает буфер и возвращает id его
 */
int create_buf(void) {
  if ( buf_count < BUF_CNT  ) {
    buffers[buf_count].buf_id 	= buf_id_number;			// Номер буфера, идентификатор
    buffers[buf_count].ptr_buf 	= (int)((int*) malloc(BUF_SIZE));  // Создание буфера
    buffers[buf_count].state 	  = FILLING_BUFFER_STATE;     // Состояние буфера
    buffers[buf_count].indx     = 0;
    buf_id_number++;
    buf_count++;
	return buffers[buf_count-1].buf_id;
  }
  return -1;
}

/*
 * Возвращает id первого попавшегося буфера в который
 * осуществляется запись данных в текущий момент времени
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
 * Возвращает id буфера для которого в данный
 * момент происходит рассчет ско
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
 * Возвращает id буфера который для которого рассчитывается ско
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
 * Возвращает указатель на буфер по id
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
 * Возвращает состояние буфера по id
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
 * Возвращает количество значений в буфере на текущий момент
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
 * Добавляет значение в конец текущего буфера
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
 * Функция установки ожидающего буфера
 * активным для рассчета ско
 */
void set_active_buffer_wait_calc_rms_state(void) {
  int i, j;

  int min = INT_MAX;

  /*
   * Добавляем в очередь буферов, очередной буфер
   * готовый для рассчета ско, либо ожидающий другого
   * буфера, который рассчитыватся ско на данный момент.
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
   * Если в очереди буферов несколько буферов, которые ждут другой, то
   * определеяется минимальный id - признак того что буфер был создан раньше
   * а значит и приоритет у него выше
   */
  for ( i = 0; i < buf_count; i++ ) {
    if ( ( buffers[i].buf_id < min ) && ( buffers[i].state == WAIT_CALCULATE_RMS_ROUTINE_STATE ) ) {
      min = buffers[i].buf_id;
    }
  }

  /*
   * После определения высокоприоритетного буфера, у него устанавливается состояние
   * готовности рассчете ско
   */
  for ( i = 0; i < buf_count; i++ ) {
    if ( ( buffers[i].buf_id == min ) && ( buffers[i].state == WAIT_CALCULATE_RMS_ROUTINE_STATE ) ) {
      buffers[i].state = CALCULATE_RMS_STATE;
    }
  }

  return;
}


/*
 * Удаляет все буферы
 */
void free_all_buffers() {
  buf_count = 0;
}
