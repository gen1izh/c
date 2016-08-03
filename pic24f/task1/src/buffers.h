#ifndef _BUFFERS_
#define _BUFFERS_
/*
 * Состояния в которых могут находится буферы
 */
enum {
 FILLING_BUFFER_STATE,              // Происходит заполнение буфера
 CALCULATE_RMS_STATE,               // Происходит рассчет СКО буфера
 OVERFLOW_SIZE_BUFFER_STATE,        // Произошло переполнение буфера
 WAIT_CALCULATE_RMS_ROUTINE_STATE   // Буфер ожидает, когда СКО для другого буфера будет рассчитано
};

/*
 * Описатель буфера
 */
typedef struct {
  int   buf_id;   // идентификатор буфера. Также отвечает за приоритет
  //( чем больше id, тем ниже у него приоритет)
  int   state;    // состояние в котором находится буфер
  int   ptr_buf;  // указатель на буфер (TODO: возможно нужно будет переделать в float)
  int   indx;     // счетчик значений в буфере
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
 * Возвращает количество значений в буфере на текущий момент
 */
int get_elements_num_buf( int id );

/*
 * Добавляет значение в конец текущего буфера
 */
int add_element_in_current_buffer( int value );

/*
 * Функция установки ожидающего буфера
 * активным для рассчета ско
 */
void set_active_buffer_wait_calc_rms_state(void);



/*
 * Добавляет значение в конец текущего буфера
 */
int add_element_in_current_buffer( int value );

int has_some_waiting_buffers(void);

/*
 * Возвращает id буфера который для которого рассчитывается ско
 */
int get_id_waiting_rms_buf(void);


/*
 * Возвращает id буфера для которого в данный
 * момент происходит рассчет ско
 */
int get_id_current_calculating_rms_buf(void);

/*
 * Удаляет все буферы
 */
void free_all_buffers();

#endif
