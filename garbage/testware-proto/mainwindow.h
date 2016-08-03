#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "protothread.h"
#include <QSerialPort>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

  enum{
    ELOG,
    WLOG,
    ILOG
  };

  QSerialPort *port;

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  protoThread *prt;

  void comPortLister();

public slots:
  void log(int type, QString msg);

  void recievePacket(unsigned char channel, double value);
private slots:
  void on_startButton_clicked();

  void on_stopButton_clicked();

  void on_debugBox_toggled(bool checked);

  void on_initButton_clicked();

signals:
  void setDebugMode(bool state);
  void setConnectedState(bool state);

  void setPort(QSerialPort *port);
private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
