#ifndef _PROTO_H
#define _PROTO_H

#include "init.h"
#include "module_port.h"


// ��������� �������
#define   HEADER_LEN         0x2

// �������� ���� ������
#define   READ_COMMAND         0x1
#define   WRITE_COMMAND        0x2
#define   CONFIG_COMMAND       0x3
#define   GET_STATS_COMMAND    0x4
#define   GET_CONFIG_COMMAND   0x5
#define   CLEAR_STATS_COMMAND  0x6
#define   GET_STATE_COMMAND    0x7

  /**
   *   ������ ���������� �������
   *   ���������� �� � ����������� ���
   */
void extract_inpack(char *buf, _cmd_struct *in);


  /**
   *   �������� ������
   */
void send_pack( _cmd_struct *out );


  /**
   *   ������������ ������
   */
void create_outpack( _cmd_struct *out, char *buf );


  /**
   *   ������������� ������� �
   *   ������������ ������ ��� ����������
   */
void proceed_cmd( _cmd_struct *in );


  /**
   *   ����������� �������
   */
void copy_in_pack( _cmd_struct *in, _cmd_struct *out, char *state, int len );


#endif