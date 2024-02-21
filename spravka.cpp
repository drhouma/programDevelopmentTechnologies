#include "spravka.h"
#include "ui_spravka.h"

Spravka::Spravka(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Spravka)
{
    ui->setupUi(this);
}

Spravka::~Spravka()
{
    delete ui;
}
