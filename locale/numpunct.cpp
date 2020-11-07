//
// Created by 王强 on 2020/11/7.
//
#include <iostream>
#include <memory>


struct french_bool : std::numpunct<char>{
    french_bool()=default;
    string_type do_truename() const override{
        return "vrai";
    }
    string_type do_falsename() const override{
        return "faux";
    }
};

struct my_numpunct : public std::numpunct<char>{
    explicit my_numpunct(size_t r=0):std::numpunct<char>(r){

    }

protected:
    char do_thousands_sep() const override{
        return '_';
    }
    std::string do_grouping() const override{
        return "\004";
    }
};

int main(){
    std::cout << "default locale: "
        << std::boolalpha << true << ", " << false << '\n';
    std::unique_ptr<french_bool> pFrenchBool = std::make_unique<french_bool>();

    std::cout.imbue(std::locale(std::cout.getloc(), pFrenchBool.get()));
    std::cout << "locale with modified numpunct: "
              << std::boolalpha << true << ", " << false << '\n';

    std::cout << "style C:" << 12345678
        << " *** " << 1234567.8
        << " *** " << std::fixed << 1234567.8 << '\n';

    std::cout << std::defaultfloat; //重设浮点数格式
    std::unique_ptr<my_numpunct> pMyNumPunct = std::make_unique<my_numpunct>();
    std::cout.imbue(std::locale(std::cout.getloc(), pMyNumPunct.get()));
    std::cout << "Style Customize:" << 12345678
        << " *** " << 1234567.8
        << " *** " << std::fixed << 1234567.8 << '\n';
}