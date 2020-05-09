#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
//#include "mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
//    void drawPolygon();
    void paintEvent(QPaintEvent *event);
//    MainWindow *mainwindow;

private slots:
    void on_end_clicked();

    void on_back_clicked();

    void on_sumbit_clicked();

    void receiveData(QString sumOfNodes, QString valueOfNodes, QString opCharsOfEdge);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
