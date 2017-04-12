#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MCULIB/gsmlib.h"
#include "QDebug"
#include "QThread"
#include "QElapsedTimer"

#define NeedCom

void dprint (const char* s) {
    qDebug(s);
}
void delay100ms () {
    //dprint("delay100ms");
    QElapsedTimer t;
    t.start();
    while (t.elapsed() < 100) {
        //QCoreApplication::processEvents();
    }
}
void MainWindow::read_Com() {
    QByteArray temp = serial.readAll();
    for (int i=0; i<temp.length(); ++i) {
        GSM_input(temp.at(i));
        //add new here
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
#ifdef NeedCom
    serial.setPortName(COM); //like "COM6"
    serial.setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);
    serial.setDataBits(QSerialPort::Data8);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.close();
    if(serial.open(QIODevice::ReadWrite))
    {
        connect(&serial,SIGNAL(readyRead()), this, SLOT(read_Com()));
        dprint("start OK");
    } else {
        dprint("start ERROR");
        QMessageBox::warning(this, "串口打开错误",
                "请检查mainwindow.h文件下的配置");
    }
#endif
    GSM_dprint = dprint;
    GSM_delay100ms = delay100ms;
}

MainWindow::~MainWindow()
{
    delete ui;
    serial.close();
}

void MainWindow::on_pushButton_GSM_ConnectToServer_clicked()
{
    GSM_Initial();
}
