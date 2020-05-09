#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Dialog *dialog;

private slots: //槽函数的声明
    void begin();
    void reset();
    void exit();

private:
    Ui::MainWindow *ui;

signals:
    void sendData(QString, QString, QString);
};
#endif // MAINWINDOW_H
