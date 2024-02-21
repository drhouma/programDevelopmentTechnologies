#ifndef SPRAVKA_H
#define SPRAVKA_H

#include <QMainWindow>

namespace Ui {
class Spravka;
}

class Spravka : public QMainWindow
{
    Q_OBJECT

public:
    explicit Spravka(QWidget *parent = nullptr);
    ~Spravka();

private:
    Ui::Spravka *ui;
};

#endif // SPRAVKA_H
