
#ifndef _ATMS_H_
#define _ATMS_H_
  
#define _BOOL   int
#define _TRUE   1
#define _FALSE  0

// Состояние успешного выполнения операции
#define  SUCCESSFUL                             0

// Состояния ошибочных состояний автомата
#define  INCORRECT_DEVICE                       1
#define  INCORRECT_MINOR_DEV                    2
#define  INCORRECT_OPCODE                       3
#define  INCORRECT_CRC16                        4
// Ошибки модуля портов ввода\вывода
#define  INCORRECT_DEVICE_NUM                   5
#define  OPERATION_NOT_IMPLEMENTED              10

// Состояния автомата
#define  AUTOMAT_WAIT_DEVICE_INFO               0
#define  AUTOMAT_WAIT_OPCODE_INFO               1
#define  AUTOMAT_WAIT_DATA_LENGTH_INFO          2
#define  AUTOMAT_WAIT_DATA_AND_CRC16            3
#define  AUTOMAT_ERROR                          20


#define  BUFFER_SIZE  100
  
typedef struct {
  int major;
  int minor;
  int opcode;
  int size;
  char _data[BUFFER_SIZE];
  int crc16;
}_cmd_struct;

typedef struct {
_cmd_struct inpack;
_cmd_struct outpack;
 char  buffer[BUFFER_SIZE];
}_app_Private;


typedef struct {
  int           state;
  int           len;
  int           pos;
  char          buffer[BUFFER_SIZE];
}_automat_data;


extern _automat_data automat_data;
extern _app_Private Private_data;


void UART1_Init( unsigned int ubrr);

void USART_Transmit( unsigned char data );

unsigned char USART_Receive( void );
      
#endif
