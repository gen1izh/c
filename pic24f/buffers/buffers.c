#include "buffers.h"
#include <stdlib.h>

int buf_count 		= 0; // количество активных буферов на текущий момент
int buf_id_number 	= 0; // идентификатор буфера

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
    buffers[buf_count].ptr_buf 	= (int*) malloc(BUF_SIZE);  // Создание буфера 
    buffers[buf_count].state 	= FILLING_BUFFER_STATE;     // Состояние буфера
    buf_id_number++;
	return buffers[buf_count].buf_id;
  }
  retun -1;
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
 * Удаляет все буферы
 */
void free_all_buffers() {
  buf_count = 0;
}