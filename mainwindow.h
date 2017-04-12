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
    QSerialPort serial;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_GSM_ConnectToServer_clicked();
    void read_Com();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
