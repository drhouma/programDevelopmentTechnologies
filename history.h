#ifndef HISTORY_H
#define HISTORY_H

#include <QMainWindow>

namespace Ui {
class History;
}

class History : public QMainWindow
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = nullptr);
    ~History();

    void AddNote(int i_ss, int o_ss, QString inumber, QString onumber);

private:
    Ui::History *ui;
};

#endif // HISTORY_H
