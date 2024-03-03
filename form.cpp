#include "form.h"
#include "ui_form.h"
#include <QProcess>
#include "gamestartbutton.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    myButton = new GameStartButton(800,458,this);
    connect(myButton,&QPushButton::clicked,this,&Form::startGame);
}

Form::~Form()
{
    delete ui;
}

void Form::setGamePath(const QString &path)
{
    GamePath = path;
}

void Form::setBackgroundImage(const QString &path)
{
    myButton->setBackgroundImg(path);
}

void Form::startGame()
{
    if(GamePath == "") {

    }else {
        QProcess *pro = new QProcess;
        pro->setProgram(GamePath);
        pro->startDetached();
    }

}
