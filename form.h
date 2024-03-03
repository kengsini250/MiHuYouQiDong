#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();


    void setGamePath(const QString& path);
    void setBackgroundImage(const QString& path);
private:
    QString GamePath="";
    class GameStartButton *myButton;
private slots:
    void startGame();
private:
    Ui::Form *ui;
};

#endif // FORM_H
