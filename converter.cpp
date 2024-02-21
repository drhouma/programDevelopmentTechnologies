#include "converter.h"

std::string Converter::Convert() {
    double dec_num = From_R_To_Dec(this->input_number, this->input_R);
    std::string res = From_Dec_To_R(dec_num, this->output_R, 10);
    res = remove_trailing_zeros(res);
    return res;
}

std::string Converter::Convert(int output_ss)
{
    double dec_num = From_R_To_Dec(this->input_number, this->input_R);
    std::string res = From_Dec_To_R(dec_num, output_ss, 10);
    res = remove_trailing_zeros(res);
    return res;
}


char convert(int num)
{
    std::string out = "0123456789ABCDEF";
    return out[num];
}


std::string From_Dec_To_R(long double flDec, int Radix, int amountOfSign)
{
    long double float_ostat;
    std::string new_num;

    float_ostat = flDec - (int)flDec;

    if ((int)flDec / Radix != 0) {

        // ���� ������� ������, ������� �������� ������ ������.
        while ((int)flDec / Radix != 0)
        {
            new_num = convert((int)flDec % Radix) + new_num;
            flDec = (int)flDec / Radix;
        }
        new_num = convert((int)flDec) + new_num; // ��������� ������� �������.
    }
    else new_num = convert((int)flDec);


    //For floating part of DEC number.
    if (float_ostat > 0.0 && amountOfSign > 0)
    {
        int count = 0;
        new_num += ".";
        while (count < amountOfSign)
        {
            float_ostat *= Radix;
            new_num += convert((int)float_ostat); //����� ����� ������� � ���������� �����.

            float_ostat = float_ostat - (int)float_ostat; //���������� �� ����� ����� � ���������� �������� ������.
            count += 1;
        }
    }

    return new_num;
}

long double From_R_To_Dec(std::string rNum, int radix)
{
    int cToInt = 0;
    bool Point = false;
    long double floatDec = 0, decNum = 0;
    int step = 1;

    for (int i = 0; i < rNum.length(); i++)
    {

        if (rNum[i] == '.') {
            Point = true; i += 1;
        }

        if (!Point)
        {

            if (rNum[i] >= '0' && rNum[i] <= '9') cToInt = rNum[i] - '0';
            else if (rNum[i] >= 'A' && rNum[i] <= 'Z') cToInt = rNum[i] - 'A' + 10;
            decNum = radix * decNum + cToInt;
        }
        else
        {
            if (rNum[i] >= '0' && rNum[i] <= '9') floatDec += (rNum[i] - '0') / pow(radix, step);
            else if (rNum[i] >= 'A' && rNum[i] <= 'Z') floatDec += (rNum[i] - 'A' + 10) / pow(radix, step);
            step += 1;

        }

    }

    return decNum + floatDec;
}

std::string remove_trailing_zeros(const std::string& input) {
    std::string result = input;
    std::size_t found = input.find('.');
    if (found != std::string::npos) {
        //находим последний индекс символа в строке result, который не является нулем. Далее со следующего символа удаляем все символы (нули)
        result.erase(result.find_last_not_of('0') + 1, std::string::npos);
        //если точка осталась, то удалим
        if (result.back() == '.') {
            result.pop_back();
        }
        return result;
    }
    else {
        return input;
    }

}
