#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>
#include <QByteArray>
#include <QString>

const QString COM = "COM6";

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    static QSerialPort serial;
    QString hexStr;
    QString textStr;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static void serial_send(const char* s, int length);

private slots:
    void on_pushButton_GSM_ConnectToServer_clicked();
    void read_Com();

    void on_pushButton_GSM_Disconnect_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
