//
// Created by wq on 2020/11/8.
//

#include <locale>
#include <iostream>
#include <iomanip>

struct space_out : std::moneypunct<char>{
    pattern do_pos_format() const override{
        return { {symbol, sign, value, none} };
    }
    int do_frac_digits() const override{    //小数点后面0位
        return 0;
    }
    char_type do_thousands_sep() const override{
        return ' ';
    }
    string_type do_grouping() const override{
        return "\002";
    }

    string_type do_curr_symbol() const override{
        return "USD";
    }
    string_type do_positive_sign() const override{
        return "+";
    }
};

int main(){
    std::cout.imbue(std::locale("en_US.UTF-8"));

    std::cout << "Americal locale: " << std::showbase   //The showbase flag affects the behavior of integer output ,monetary input and monetary output
        << std::put_money(12345678.9) << '\n';      //default /100

    std::unique_ptr<space_out> myMoney = std::make_unique<space_out>();

    std::cout.imbue(std::locale(std::cout.getloc(), myMoney.release()));
    std::cout << "locale with modified moneypunct: "
              << std::put_money(12345678.9)<< '\n';
}