#include "widget.h"
#include "./ui_widget.h"
#include "FilePath.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->SettingPage,&SettingForm::updateGamePath,this,&Widget::updateGamePath);
    ui->page->setBackgroundImage(":/Img/img/starrail.png");

    ui->page_2->setBackgroundImage(":/Img/img/GenShin.jpg");
    ui->page_2->setGamePath("D:\\Genshin Impact\\launcher.exe");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateGamePath()
{
    ui->page->setGamePath(Path::StarRailGamePath);
}
