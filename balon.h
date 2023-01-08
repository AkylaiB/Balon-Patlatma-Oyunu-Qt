#ifndef BALON_H
#define BALON_H

#include <QPushButton>
#include <QTimer>

class balon: public QPushButton
{
public:
    balon(QWidget *parrent=0);
    bool patladi, patlayan;
public slots:
    void patla();
    void patlat();
};

#endif // BALON_H
