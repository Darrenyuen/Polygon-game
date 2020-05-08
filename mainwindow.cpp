#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QDebug>
#include <QString>
#include <QSplashScreen>
#include <QElapsedTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(谁，发出来什么信号，谁，执行什么操作);
//    connect(this->ui->resetData, SIGNAL(clicked(bool)), this, SLOT(changeName()));
    connect(this->ui->reset, SIGNAL(clicked(bool)), this, SLOT(reset()));
    connect(this->ui->begin, SIGNAL(clicked(bool)), this, SLOT(begin()));
    connect(this->ui->exit, SIGNAL(clicked(bool)), this, SLOT(exit()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset()
{
    qDebug() << "reset";
    this->ui->sumOfNode->setText("");
    this->ui->valuesOfNodes->setText("");
    this->ui->opCharsOfEdge->setText("");
}

void MainWindow::begin()
{
    qDebug() << "begin";
    QString sumOfNode = ui->sumOfNode->text();
    QString valuesOfNodes = ui->valuesOfNodes->text();
    QString opCharsOfEdge = ui->opCharsOfEdge->text();
    qDebug() << sumOfNode + " " + valuesOfNodes + " " + opCharsOfEdge;
    //判断输入的数据是否有误
    // 显示处理提示界面
//        QSplashScreen splash(QPixmap("images/progress.png"));
    if(sumOfNode == "") {
        QSplashScreen splash(QString("输入有误"));
        splash.setDisabled(true); // 禁用用户的输入事件响应
        splash.show();

        splash.showMessage(QObject::tr("正在进行分析1..."),Qt::AlignCenter|Qt::AlignBottom,Qt::white);
        // 停留5s
        QElapsedTimer t1;
        t1.start();
        while(t1.elapsed()<3000)
        {
            QCoreApplication::processEvents();
        }

        splash.showMessage(QObject::tr("正在进行分析2..."),Qt::AlignCenter|Qt::AlignBottom,Qt::white);
        QElapsedTimer t2;
        t2.start();
        while(t2.elapsed()<3000)
        {
            QCoreApplication::processEvents();
        }

        // 处理完成
        splash.close();
    } else {
        Dialog dialog;
        dialog.show();
        this->close();
        dialog.exec();
    }
}

void MainWindow::exit()
{
    this->close();
}

