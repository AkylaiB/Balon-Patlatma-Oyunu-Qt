#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPalette>
#include <QTimer>
#include "balon.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void BalonUret();
    void hareket();
    int gecensure = 0, vurulan = 0, kacan = 0;


private:
    Ui::MainWindow *ui;
    QList<balon*> balonlar;

};
#endif // MAINWINDOW_H
