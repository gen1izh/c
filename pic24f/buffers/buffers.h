#ifndef _BUFFERS_
#define _BUFFERS_

/*
 * ��������� � ������� ����� ��������� ������
 */
enum {
 FILLING_BUFFER_STATE,  				// ���������� ���������� ������
 CALCULATE_RMS_STATE,					// ���������� ������� ��� ������
 OVERFLOW_SIZE_BUFFER_STATE,			// ��������� ������������ ������
 WAIT_CALCULATE_RMS_ROUTINE_STATE		// ����� �������, ����� ��� ��� ������� ������ ����� ���������� 
};

/*
 * ��������� ������
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
 * ������� ��� ������
 */
void free_all_buffers(); 

#endif