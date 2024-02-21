#include "history.h"
#include "ui_history.h"
#include <QLabel>

History::History(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
}

History::~History()
{
    delete ui;
}

void History::AddNote(int i_ss, int o_ss, QString i_number, QString o_number)
{
    QLabel *note = new QLabel();
    QString tStr = QString("%1(%2) -> %3(%4)")
        .arg(i_number).arg(i_ss).arg(o_number).arg(o_ss);
    note->setText(tStr);
    ui->verticalLayout->insertWidget(0, note);
}
