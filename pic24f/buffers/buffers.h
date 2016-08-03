#ifndef _BUFFERS_
#define _BUFFERS_

/*
 * Состояния в которых могут находится буферы
 */
enum {
 FILLING_BUFFER_STATE,  				// Происходит заполнение буфера
 CALCULATE_RMS_STATE,					// Происходит рассчет СКО буфера
 OVERFLOW_SIZE_BUFFER_STATE,			// Произошло переполнение буфера
 WAIT_CALCULATE_RMS_ROUTINE_STATE		// Буфер ожидает, когда СКО для другого буфера будет рассчитано 
};

/*
 * Описатель буфера
 */
typedef struct {
	int buf_id,
	int state,
	int	*ptr_buf
} buffer_marker;

#define BUF_CNT 		10
#define BUF_SIZE 		1000

int buf_count;
int buf_id_number;

buffer_marker buffers[BUF_CNT];

/*
 * Удаляет буфер по идентификатору 
 */
void delete_buf( int id );

/*
 * Создает буфер и возвращает id его
 */
int create_buf(void);

/*
 * Возвращает id буфера в который осуществляется запись данных 
 * в текущий момент времени
 */
int get_id_current_buf(void);

/*
 * Возвращает указатель на буфер по id
 */
int get_ptr_buf( int id );

/*
 * Возвращает состояние буфера по id
 */
int get_state_buf( int id );

/*
 * Удаляет все буферы
 */
void free_all_buffers(); 

#endif