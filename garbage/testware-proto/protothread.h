#ifndef PROTOTHREAD_H
#define PROTOTHREAD_H
#include <QThread>
#include <QSerialPort>

class protoThread : public QThread
{

  Q_OBJECT
  enum{
    ELOG,
    WLOG,
    ILOG
  };

  bool isdebug;

  bool isconnected;

  QSerialPort *_port;

signals:
  void sendlog(int type,QString msg);
  void sendpacket(unsigned char numchan,double value);

public:
  protoThread();
  ~protoThread();

protected:
    void run();

public slots:
    void setDebugMode(bool state);
    void setConnectedState(bool state);

    void setPort(QSerialPort* port);
};

#endif // PROTOTHREAD_H
