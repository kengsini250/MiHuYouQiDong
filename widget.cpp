#include "widget.h"

#include <qfile.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qstringlist.h>

#include "./ui_widget.h"
#include "form.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("启动！");

    QFile config("config.json");
    QByteArray jsonData;
    if(config.open(QIODevice::ReadOnly)) {
        jsonData = config.readAll();
        config.close();
    }
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData);
    if(jsonDocument.isObject()) {
        QJsonObject root = jsonDocument.object();

        qDebug()<<"--"<<root.value("StarRail_img").toString();
        ui->StarRail->setGamePath(root.value("StarRail").toString());
        ui->StarRail->setBackgroundImage(root.value("StarRail_img").toString());

        ui->Genshin->setGamePath(root.value("Genshin").toString());
        ui->Genshin->setBackgroundImage(root.value("Genshin_img").toString());

        ui->ZZZ->setGamePath(root.value("ZZZ").toString());
        ui->ZZZ->setBackgroundImage(root.value("ZZZ_img").toString());

        ui->HK3->setGamePath(root.value("HK3").toString());
        ui->HK3->setBackgroundImage(root.value("HK3_img").toString());
    }



}

Widget::~Widget()
{
    delete ui;
}
