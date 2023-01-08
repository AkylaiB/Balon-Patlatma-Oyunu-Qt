#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widget->setStyleSheet("background-color: rgb(240, 245, 245);");

    QPixmap img(":/img/images/arkaplan.jpg");
    img = img.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette backgnd;
    backgnd.setBrush(QPalette::Window, img);
    this->setPalette(backgnd);

    QTimer *timer=new QTimer(this);
    timer->start(1000);
    connect(timer,&QTimer::timeout,this,&MainWindow::BalonUret);
    QTimer *timer2=new QTimer(this);
    timer2->start(10);
    connect(timer2,&QTimer::timeout,this,&MainWindow::hareket);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::BalonUret()
{
    gecensure++;
    ui->lbl_sure->setText(QString::number(gecensure));

    int x = rand()%(725-50)+50;
    balon *b=new balon(this);
    b->setGeometry(x,50,50,50);
    int img = rand()%6;
    b->setStyleSheet("border-image:url(:/img/images/"+QString::number(img)+".jpg);");
    balonlar.push_back(b);
    b->show();
}

void MainWindow::hareket()
{
    for(int i=0; i<balonlar.size(); i++)
    {
        if(balonlar[i]->patladi==false) //patlamissa artik kaydirmiyorum
        {
            balonlar[i]->setGeometry(balonlar[i]->x(),balonlar[i]->y()+1,balonlar[i]->width(), balonlar[i]->height());
            if(balonlar[i]->y()==480)
            {
                kacan++;
                ui->lbl_kacan->setText(QString::number(kacan));
            }
        }
        if(balonlar[i]->patlayan==true) //patlayan yeterli sure ekranda kaldiysa siliyorum
        {
            vurulan++;
            ui->lbl_vurulan->setText(QString::number(vurulan));
            balonlar[i]->setParent(0);
            balonlar.remove(i);
        }
    }
}


