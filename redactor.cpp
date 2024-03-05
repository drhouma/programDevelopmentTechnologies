#include "redactor.h"
#include <map>

const std::string ss_2 = "01";
const std::string ss_3 = "012";
const std::string ss_4 = "0123";
const std::string ss_5 = "01234";
const std::string ss_6 = "012345";
const std::string ss_7 = "0123456";
const std::string ss_8 = "01234567";
const std::string ss_9 = "012345678";
const std::string ss_10 = "0123456789";
const std::string ss_11 = "0123456789A";
const std::string ss_12 = "0123456789AB";
const std::string ss_13 = "0123456789ABC";
const std::string ss_14 = "0123456789ABCD";
const std::string ss_15 = "0123456789ABCDE";
const std::string ss_16 = "0123456789ABCDEF";

std::map<int, std::string> valid_symbols;

Redactor::Redactor(QLineEdit *ptr) : input(ptr)
{
    valid_symbols[2] = ss_2;
    valid_symbols[3] = ss_3;
    valid_symbols[4] = ss_4;
    valid_symbols[5] = ss_5;
    valid_symbols[6] = ss_6;
    valid_symbols[7] = ss_7;
    valid_symbols[8] = ss_8;
    valid_symbols[9] = ss_9;
    valid_symbols[10] = ss_10;
    valid_symbols[11] = ss_11;
    valid_symbols[12] = ss_12;
    valid_symbols[13] = ss_13;
    valid_symbols[14] = ss_14;
    valid_symbols[15] = ss_15;
    valid_symbols[16] = ss_16;

}

void Redactor::setValidator(int new_ss) {
    std::string tmp = "[" + valid_symbols[new_ss] + "]+";
    QString src_req = QString::fromStdString(tmp + "\\.?" + tmp);
    QRegularExpression req(src_req);
    QRegularExpressionValidator validator(req);
    input->setValidator(new QRegularExpressionValidator(req));
}

bool Redactor::can_type(char input, int cur_ss)
{
    if (input <= '9' && input >= '0') {
        if (input  < cur_ss + '0') {
            return true;
        }
    } else {
        if (input < char(cur_ss + 'A' - 10)) {
            return true;
        }
    }
    return false;
}

std::string Redactor::get_current_number()
{
    return input->text().toStdString();
}

void Redactor::delete_last_char()
{
    auto text = input->text().toStdString();
    text.pop_back();
    input->setText(QString::fromStdString(text));
}

void Redactor::add_symbol(char symbol, int input_ss)
{
    if (can_type(symbol, input_ss)) input->setText(input->text() + symbol);
}
