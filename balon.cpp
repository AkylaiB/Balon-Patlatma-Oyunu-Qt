#include "balon.h"

balon::balon(QWidget *parrent):QPushButton(parrent)
{
    patladi = false;    //patlayip patlamadigi kontrolu icin
    patlayan = false;   //patlayanin ekranda kalma suresi bitip bitmedigi kontrolu icin
    connect(this,&QPushButton::clicked,this,&balon::patla);
}

void balon::patla()
{
    this->setStyleSheet("border-image:url(:/img/images/patlama.jpg);");
    patladi = true;
    QTimer *timer=new QTimer(this);
    timer->start(500); //0.5sn ekranda kalsin
    connect(timer,&QTimer::timeout,this,&balon::patlat);

}

void balon::patlat()
{
    patlayan = true; //ekranda kalma suresi bitti mi = true
}

