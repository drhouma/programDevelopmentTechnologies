#ifndef CONVERTER_H
#define CONVERTER_H
#include <string>
#include <stdexcept>
#include <cmath>

char convert(int num);
std::string From_Dec_To_R(long double flDec, int Radix, int amountOfSign);
long double From_R_To_Dec(std::string rNum, int radix);
std::string remove_trailing_zeros(const std::string& input);

class Converter {

    private:
    std::string input_number;
    int input_R = 2;
    int output_R = 2;

    public:
        Converter() {};
        Converter(std::string num, int inp_R, int out_R) : input_number(num), input_R(inp_R), output_R(out_R)
        {
            if (input_R < 2 || input_R > 16 || output_R < 2 || output_R > 16) {
                throw std::invalid_argument("������: ������������ ������� ���������.");
            }

            for (char c : input_number) {
                if (c >= '0' && c <= '9') {
                    if (c - '0' >= input_R) throw std::invalid_argument("������: ����� �� ������������� ������� ���������.");
                }
                else if (c >= 'A' && c <= 'F') {
                    if (c - 'A' + 10 >= input_R) throw std::invalid_argument("������: ����� �� ������������� ������� ���������.");
                }
                else if (c == '.') continue;
            }



        };

        void set_input_number(std::string num) { input_number = num; }
        void set_input_radix(double input_radix) { input_R = input_radix; }
        void set_output_radix(double output_radix) { output_R = output_radix; }

        std::string get_input_number() { return input_number; }
        double get_input_radix() { return input_R; }
        double get_output_radix() { return output_R; }

        std::string Convert();
        std::string Convert(int output_ss);
};


#endif // CONVERTER_H
