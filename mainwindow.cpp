#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <map>
#include <QRegularExpressionValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    redactor = new Redactor(ui->number_input);
    history = new History();
    spravka = new Spravka();
    QAction *historyWindowAction = new QAction("history", history);
    QAction *spravkaWindowAction = new QAction("help", spravka);
    QObject::connect(historyWindowAction, &QAction::triggered, [this]() {
        history->show();
        spravka->hide();
    });
    QObject::connect(spravkaWindowAction, &QAction::triggered, [this]() {
        spravka->show();
        history->hide();
    });
    ui->menubar->addAction(historyWindowAction);
    ui->menubar->addAction(spravkaWindowAction);
    redactor->setValidator(2);
    connect(ui->button_1, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_2, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_3, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_4, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_5, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_6, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_7, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_8, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_9, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_0, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_A, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_B, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_C, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_D, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_E, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));
    connect(ui->button_F, SIGNAL(clicked()), this, SLOT(on_button_number_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete history;
    delete spravka;
}




void MainWindow::on_button_convert_clicked()
{
    int input_ss = ui->input_ss->value();
    int output_ss = ui->output_ss->value();
    auto tmp = QString::fromStdString(redactor->get_current_number());
    std::string number = redactor->get_current_number();
    Converter converter(number, input_ss, output_ss);
    QString res = QString::fromStdString(converter.Convert());
    ui->result_label->setText(res);
    history->AddNote(input_ss, output_ss, tmp, res);

}

void MainWindow::on_button_number_clicked() {
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    auto val = ui->input_ss->value();
    redactor->add_symbol(buttonSender->text().toStdString()[0], val);
}

void MainWindow::on_input_ss_valueChanged(int arg1)
{
    redactor->setValidator(arg1);
    std::string number = redactor->get_current_number();
    converter.set_output_radix(arg1);
    converter.set_input_number(number);
    auto text = converter.Convert();
    converter.set_output_radix(ui->output_ss->value());
    converter.set_input_radix(arg1);
    redactor->setText(text);
}


void MainWindow::on_button_backspace_clicked()
{
    auto text = ui->number_input->text().toStdString();
    if (!text.empty()) text.pop_back();
    redactor->setText(text);
}


void MainWindow::on_pushButton_clicked()
{
    redactor->setText("");
}

