//
// Created by wq on 2020/11/8.
//

#include <locale>
#include <iostream>
#include <iomanip>

struct space_out : std::moneypunct<char>{
    pattern do_pos_format() const override{
        return { {value, none, none, none} };
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
};

int main(){
    std::cout.imbue(std::locale("en_US.UTF-8"));
    std::cout << "Americal locale: " << std::showbase
        << std::put_money(12345678.0) << '\n';

    std::unique_ptr<space_out> myMoney = std::make_unique<space_out>();
    std::cout.imbue(std::locale(std::cout.getloc(), myMoney.get()));
    std::cout << "locale with modified moneypunct: "
              << std::put_money(12345678.0)<< '\n';
}