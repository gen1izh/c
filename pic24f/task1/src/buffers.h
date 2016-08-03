#ifndef _BUFFERS_
#define _BUFFERS_
/*
 * ��������� � ������� ����� ��������� ������
 */
enum {
 FILLING_BUFFER_STATE,              // ���������� ���������� ������
 CALCULATE_RMS_STATE,               // ���������� ������� ��� ������
 OVERFLOW_SIZE_BUFFER_STATE,        // ��������� ������������ ������
 WAIT_CALCULATE_RMS_ROUTINE_STATE   // ����� �������, ����� ��� ��� ������� ������ ����� ����������
};

/*
 * ��������� ������
 */
typedef struct {
  int   buf_id;   // ������������� ������. ����� �������� �� ���������
  //( ��� ������ id, ��� ���� � ���� ���������)
  int   state;    // ��������� � ������� ��������� �����
  int   ptr_buf;  // ��������� �� ����� (TODO: �������� ����� ����� ���������� � float)
  int   indx;     // ������� �������� � ������
} buffer_marker;

#define BUF_CNT 		10
#define BUF_SIZE 		1000

int buf_count;
int buf_id_number;

buffer_marker buffers[BUF_CNT];

/*
 * ������� ����� �� ��������������
 */
void delete_buf( int id );

/*
 * ������� ����� � ���������� id ���
 */
int create_buf(void);

/*
 * ���������� id ������ � ������� �������������� ������ ������
 * � ������� ������ �������
 */
int get_id_current_buf(void);

/*
 * ���������� ��������� �� ����� �� id
 */
int get_ptr_buf( int id );

/*
 * ���������� ��������� ������ �� id
 */
int get_state_buf( int id );

/*
 * ���������� ���������� �������� � ������ �� ������� ������
 */
int get_elements_num_buf( int id );

/*
 * ��������� �������� � ����� �������� ������
 */
int add_element_in_current_buffer( int value );

/*
 * ������� ��������� ���������� ������
 * �������� ��� �������� ���
 */
void set_active_buffer_wait_calc_rms_state(void);



/*
 * ��������� �������� � ����� �������� ������
 */
int add_element_in_current_buffer( int value );

int has_some_waiting_buffers(void);

/*
 * ���������� id ������ ������� ��� �������� �������������� ���
 */
int get_id_waiting_rms_buf(void);


/*
 * ���������� id ������ ��� �������� � ������
 * ������ ���������� ������� ���
 */
int get_id_current_calculating_rms_buf(void);

/*
 * ������� ��� ������
 */
void free_all_buffers();

#endif
