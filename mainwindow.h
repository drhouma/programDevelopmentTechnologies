#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "history.h"
#include "converter.h"
#include "redactor.h"
#include "spravka.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_convert_clicked();

    void on_button_number_clicked();

    void on_input_ss_valueChanged(int arg1);

    void on_button_backspace_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    History* history;
    Converter converter;
    Redactor* redactor;
    Spravka* spravka;

};
#endif // MAINWINDOW_H
