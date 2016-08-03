#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  prt = new protoThread();

  connect(prt, SIGNAL(sendlog(int,QString)), this, SLOT(log(int,QString)));

  connect(this, SIGNAL(setDebugMode(bool)), prt, SLOT(setDebugMode(bool)));

  connect(this, SIGNAL(setPort(QSerialPort*)), prt, SLOT(setPort(QSerialPort*)));


  connect(this, SIGNAL(setConnectedState(bool)), prt, SLOT(setConnectedState(bool)));

  connect(prt, SIGNAL(sendpacket(unsigned char,double)), this, SLOT(recievePacket(unsigned char,double)));

  comPortLister();

}

void MainWindow::comPortLister() {
  // Очищаем список доступных для открытия портов.
  ui->comPortsBox->clear();

  if ( QSerialPortInfo::availablePorts().size() > 0 ) {
    // Добавляем в выпадающий список доступные для открытия порты.
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        if(!info.isBusy())
        {
            ui->comPortsBox->addItem(info.portName());
        }
    }
  } else {
    log(ELOG, "Ни один порт не доступен!");
  }

}


MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::log(int type, QString msg)
{
  switch (type) {
  case ILOG:
    ui->plainTextEdit->appendHtml("<font color='blue'> <b>[info]</b> : </font>"+msg);
    break;
  case WLOG:
    ui->plainTextEdit->appendHtml("<font color='magenta'><b>[warn]</b> : </font>"+msg);
    break;
  case ELOG:
    ui->plainTextEdit->appendHtml("<font color='red'><b>[err]</b> : </font>"+msg);
    break;
  default:
    ui->plainTextEdit->appendHtml("<font color='yellow'><b>[unknown]</b> : </font>"+msg);
    break;
  }

}

void MainWindow::on_startButton_clicked()
{
  if (!prt->isRunning()) {
    log(ILOG, "Запуск потока");
    prt->start();
  } else {
    log(WLOG, "Поток уже запущен!");
  }
}

void MainWindow::on_stopButton_clicked()
{
  if (prt->isRunning()) {
    log(ILOG, "Убийство потока");
    prt->terminate();
  } else {
    log(WLOG, "Поток уже убит!");
  }
}

void MainWindow::on_debugBox_toggled(bool checked)
{
    if (checked) {
      log(ILOG, "Включен отладочный режим");
    }
    else {
      log(ILOG, "Отключен отладочный режим");
    }

    emit setDebugMode(checked);
}


void MainWindow::recievePacket(unsigned char channel,double value)
{
  switch (channel) {
  case 0:
    ui->channel1Edit->setText( QString("%1").arg(value) );
    break;
  case 1:
    ui->channel2Edit->setText( QString("%1").arg(value) );
    break;
  case 2:
    ui->channel3Edit->setText( QString("%1").arg(value) );
    break;
  case 3:
    ui->channel4Edit->setText( QString("%1").arg(value) );
    break;
  case 4:
    ui->channel5Edit->setText( QString("%1").arg(value) );
    break;
  case 5:
    ui->channel6Edit->setText( QString("%1").arg(value) );
    break;
  case 6:
    ui->channel7Edit->setText( QString("%1").arg(value) );
    break;
  case 7:
    ui->channel8Edit->setText( QString("%1").arg(value) );
    break;
  case 8:
    ui->channel9Edit->setText( QString("%1").arg(value) );
    break;
  case 9:
    ui->channel10Edit->setText( QString("%1").arg(value) );
    break;
  case 10:
    ui->channel11Edit->setText( QString("%1").arg(value) );
    break;
  case 11:
    ui->channel12Edit->setText( QString("%1").arg(value) );
    break;

  default:
    log(ELOG, "Не корректный канал");
    break;
  }

}


void MainWindow::on_initButton_clicked()
{
  log(ILOG, "Инициализация порта");
  QSerialPortInfo info(ui->comPortsBox->currentText());
  port = new QSerialPort(/*info*/);
  port->setPortName(ui->comPortsBox->currentText());
  port->setBaudRate(QSerialPort::Baud9600);
  port->setDataBits(QSerialPort::Data8);
  port->setParity(QSerialPort::NoParity);
  port->setStopBits(QSerialPort::OneStop);
  port->setFlowControl(QSerialPort::NoFlowControl);
  port->open(QSerialPort::ReadWrite);

  log(ILOG, "Передача порта потоку");
  emit setPort(port);

  log(ILOG, "Установка состояния законнектен");
  setConnectedState(true);
}
