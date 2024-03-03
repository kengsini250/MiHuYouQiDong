#include "settingform.h"
#include "ui_settingform.h"
#include <QFileDialog>
#include "FilePath.h"

SettingForm::SettingForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SettingForm)
{
    ui->setupUi(this);

    //Star Rail
    connect(ui->pushButton_StarRailSelect,&QPushButton::clicked,this,[this]{
        Path::StarRailGamePath = QFileDialog::getOpenFileName(this,tr("game launcher"), "/", tr("launcher(*.exe)"));
        if(Path::StarRailGamePath.isNull() == false){
            ui->lineEdit_StarRailPath->setText(Path::StarRailGamePath);
        }
    });
    connect(ui->pushButton_StarRailSetting,&QPushButton::clicked,this,[this]{
        emit updateGamePath();
    });
    connect(ui->pushButton_StarRailSelect_2,&QPushButton::clicked,this,[this]{
    Path::StarRailImagePath = QFileDialog::getOpenFileName(this,tr("Image File"), "/", tr("image(*.jpg *.png *.jpeg)"));
    if(Path::StarRailImagePath.isNull() == false){
        ui->lineEdit_StarRailPath_2->setText(Path::StarRailImagePath);
    }
    });
    connect(ui->pushButton_StarRailSetting_2,&QPushButton::clicked,this,[this]{
        emit updateImagePath();
    });

    //Genshin

    connect(ui->pushButton_GenshinSelect,&QPushButton::clicked,this,[this]{
        Path::GenshinGamePath = QFileDialog::getOpenFileName(this,tr("game launcher"), "/", tr("launcher(*.exe)"));
        if(Path::GenshinGamePath.isNull() == false){
            ui->lineEdit_GenshinPath->setText(Path::GenshinGamePath);
        }
    });
    connect(ui->pushButton_GenshinSetting,&QPushButton::clicked,this,[this]{
        emit updateGamePath();
    });
    connect(ui->pushButton_GenshinSelect_2,&QPushButton::clicked,this,[this]{
    Path::GenshinImagePath = QFileDialog::getOpenFileName(this,tr("Image File"), "/", tr("image(*.jpg *.png *.jpeg)"));
    if(Path::GenshinImagePath.isNull() == false){
        ui->lineEdit_GenshinPath_2->setText(Path::StarRailImagePath);
    }
    });
    connect(ui->pushButton_GenshinSetting_2,&QPushButton::clicked,this,[this]{
        emit updateImagePath();
    });

    //ZZZ

    //HK3rd
}

SettingForm::~SettingForm()
{
    delete ui;
}
