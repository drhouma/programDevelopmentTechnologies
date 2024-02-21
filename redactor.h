#ifndef REDACTOR_H
#define REDACTOR_H
#include <QLineEdit>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

class Redactor
{
public:
    Redactor(QLineEdit* ptr);
    void setValidator(int new_ss);
    bool can_type(char input, int cur_ss);
    std::string get_current_number();
    void delete_last_char();
    void add_symbol(char symbol, int input_ss);
    void setText(std::string text) {
        input->setText(QString::fromStdString(text));
    }

private:
    QLineEdit* input;
};

#endif // REDACTOR_H
