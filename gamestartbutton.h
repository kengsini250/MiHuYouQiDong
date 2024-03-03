#ifndef GAMESTARTBUTTON_H
#define GAMESTARTBUTTON_H

#include <QPushButton>

class GameStartButton : public QPushButton
{
    Q_OBJECT
public:
    GameStartButton(QWidget*p=nullptr);
    GameStartButton(int w,int h,QWidget*p=nullptr);
    void setBackgroundImg(const QString&path);
private:
    QPixmap img;
protected:
    void paintEvent(QPaintEvent *) override;
};

#endif // GAMESTARTBUTTON_H
