//
// Created by 王强 on 2020/11/7.
//
#include <iostream>
#include <memory>


struct french_bool : std::numpunct<char>{
    french_bool()=default;
    [[nodiscard]] string_type do_truename() const override{
        return "vrai";
    }
    [[nodiscard]] string_type do_falsename() const override{
        return "faux";
    }
};

struct my_numpunct : public std::numpunct<char>{
    explicit my_numpunct(size_t r=0):std::numpunct<char>(r){

    }

protected:
    [[nodiscard]] char do_thousands_sep() const override{
        return '_';
    }
    [[nodiscard]] std::string do_grouping() const override{
        return "\004";
    }
};

int main(){
    std::cout << "default locale: "
        << std::boolalpha << true << ", " << false << '\n';
    std::unique_ptr<french_bool> pFrenchBool = std::make_unique<french_bool>();

    std::cout.imbue(std::locale(std::cout.getloc(), pFrenchBool.release()));    //内存释放由imbue来执行
    std::cout << "locale with modified numpunct: "
              << std::boolalpha << true << ", " << false << '\n';

    std::cout << "style C:" << 12345678
        << " *** " << 1234567.8
        << " *** " << std::fixed << 1234567.8 << '\n';

    std::cout << std::defaultfloat; //重设浮点数格式
    std::unique_ptr<my_numpunct> pMyNumPunct = std::make_unique<my_numpunct>();
    std::cout.imbue(std::locale(std::cout.getloc(), pMyNumPunct.release()));    //内存释放由imbue来执行，释放上一个指针的内存
    std::cout << "Style Customize:" << 12345678
        << " *** " << 1234567.8
        << " *** " << std::fixed << 1234567.8 << '\n';
}