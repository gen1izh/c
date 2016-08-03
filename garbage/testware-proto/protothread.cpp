#include "protothread.h"
#include <QSerialPort>

protoThread::protoThread()
{
  isdebug = false;
  isconnected = false;
}

protoThread::~protoThread()
{

}

void protoThread::run()
{

  emit sendlog(ILOG,"Поток инициализирован.");

  int numRead = 0;
  unsigned char buffer[50];

  while (1) {

    msleep(100);

    if (isconnected) {
      numRead  = _port->read((char*)buffer, 3 /* размер пакета */);


      if (isdebug) {
        emit sendlog(ILOG,QString("Дамп = %1 %2 %3").arg(buffer[0],2,16,QChar('0'))
                                                    .arg(buffer[1],2,16,QChar('0'))
                                                    .arg(buffer[2],2,16,QChar('0')));
        emit sendlog(ILOG,QString("Кол-во байт=%1").arg(numRead));
        emit sendlog(ILOG,QString("Код канала=%1").arg(buffer[0],2,16,QChar('0')));
      }

      if (numRead == 3 && !_port->waitForReadyRead(100)) {

        double value = (double) ( (buffer[1]<<8) | buffer[2] );

        if (isdebug) {
          emit sendlog(ILOG,QString("Значение после сдвигов=").arg(value));
        }

        value = (value*5000)/1024;

        if (isdebug) {
          emit sendlog(ILOG,QString("Значение после преобразования=").arg(value));
        }

        emit sendpacket(buffer[0],value);

        memset(&buffer[0],0,sizeof(buffer[50]));
      }
    }
    else {
      emit sendlog(ELOG,"Нет подключения к устройству");
    }
  }
}

void protoThread::setDebugMode(bool state)
{
  isdebug = state;
}

void protoThread::setConnectedState(bool state)
{
  isconnected = state;
}

void protoThread::setPort(QSerialPort *port)
{
  _port = port;
}
