#include "gamestartbutton.h"
#include <QPainter>
#include <QPixmap>

GameStartButton::GameStartButton(QWidget*p):QPushButton(p)
{}

GameStartButton::GameStartButton(int w, int h,QWidget*p):QPushButton(p)
{
    setGeometry(0,0,w,h);
}

void GameStartButton::setBackgroundImg(const QString &path)
{
    img = QPixmap(path);
    update();
}

void GameStartButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,img);
}
