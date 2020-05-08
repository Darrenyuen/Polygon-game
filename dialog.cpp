#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <QString>
#include <QtMath>

int count = 4;


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//    paintEvent();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *event)
{
//    Q_UNUSED(event);
//    QPainter painter(this);
//    painter.setPen(QPen(Qt::black, 4, Qt::DashDotLine, Qt::RoundCap));
//    painter.setPen(QPainter::Antialiasing);
    //绘制多边形
    qDebug() << "draw polygon";
//    painter.setBrush(Qt::NoBrush);
//    const static QPoint polygon[5] = {QPoint(100, 90), QPoint(100, 120), QPoint(220, 200), QPoint(430, 190), QPoint(620, 90)};
//    painter.drawPolygon(polygon, 5);
//    const static QPoint polygon[3] = {QPoint(100, 100), QPoint(200, 100), QPoint(150, 150)};
//    painter.drawPolygon(polygon, 3);

    /*
        * 绘制多边形 本例中直接写的六边形
        * int   count  多边形的边数
        * float radius 多边形半径
        */
//       int count = 4;
       int radius = 200;

       /*
        * 注意：l
        * 在使用QPainter绘图之前，必须先指定绘图设备。
        * 下方指定的是在本窗口中绘制。
        * 如果没有指定绘图设备，则在之后的绘图中将无效。
        * 指定绘图设备的方法还可以使用begin() end()组合。
        * QPainter在同一时刻，只能在一个设备上绘制，如果将其切换至另一个设备，将是无效的。
        */
       QPainter painter(this);

       //设置为抗锯齿,并且设置画笔颜色为浅灰
       painter.setRenderHint(QPainter::Antialiasing);
       painter.setPen(Qt::black);

       /*
        * 绘图设备的坐标原点(0,0)在左上角，水平向右增长，垂直向下增长。
        * 首先先平移坐标原点，让原点在绘图设备的中心
        */
       painter.translate(width()/2., height()/2.);

       //开始绘制多边形，并为每个区块上色
       for (int i = 0; i < count; ++i)
       {
           qDebug() << count;
           //设中心点到边的垂线与半径的夹角为degree=(360/count)/2即：
           float degree = 180./count;

           //先将坐标进行旋转，然后再绘制
           painter.rotate(2 * degree);

           //设边长的一半为wid,则wid = radius*sin(degree)
           //原点到边的距离为hei，则hei = radius*cos(degree)
           //在程序中三角函数都是以弧度为基准，所以要先将角度转化成弧度。
           //头文件要包含QtMath
           float radian = qDegreesToRadians(degree);
           float wid    = radius * qSin(radian);
           float hei    = radius * qCos(radian);

           //绘制该三角区块
           QPainterPath path;
           path.lineTo(-wid, -hei);
           path.lineTo(wid, -hei);
           path.lineTo(0, 0);
           painter.drawPath(path);
           if(i == 3) {
               qDebug() << wid;
               qDebug() << hei;
           }

           //并在该区域内绘制文字
           QFont font;
           font.setFamily("楷体");
           font.setBold(true);  //粗体
           font.setPointSize(9);  // 字体大小
           // 设置字体
           painter.setFont(font);
           // 绘制文本
           QString str = QString::number(i);
           if(count % 2 != 0) {
               painter.drawText(0, 0, wid, hei, Qt::AlignCenter,  str); //边序号
               path.addText(QPointF(30, hei + 30), font, "*");
//               painter.drawText(100, 0, wid, hei, Qt::AlignCenter, "A");
           } else {
               painter.drawText(0, 0, wid / 5, hei, Qt::AlignCenter, str);
               path.addText(QPointF(0, hei), font, "*"); //正确
//               painter.drawText(100, 0, wid / 5, hei, Qt::AlignCenter, "A");
           }
           path.addText(QPointF(-wid - 15, -hei + 10), font, "P");
           //随机生成一个颜色，作为该区块的颜色，并上色
           QColor color(qrand()%255, qrand()%255, qrand()%255, 150);
           painter.fillPath(path, color);
       }
}

void Dialog::on_end_clicked()
{
    this->close();
}

void Dialog::on_back_clicked()
{
//    MainWindow mainWindow;
//    mainWindow.show();
    count--;
    this->update();
}

void Dialog::on_sumbit_clicked()
{
//    QString input = this->ui->currentEdge->text();
    qDebug() << this->ui->currentEdge->text();
    count++;
    this->update();
}
