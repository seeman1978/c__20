//
// Created by wq on 2020/11/8.
//

#include <string>
#include <sstream>
#include <iostream>

int main(){
    std::string de_double = "1.234.567,89";

    // parse using streams
    std::istringstream de_in(de_double);
    de_in.imbue(std::locale("de_DE.UTF-8"));

    double d1;
    de_in >> d1;

    std::istringstream us_in(de_double);
    us_in.imbue(std::locale("en_US.UTF-8"));
    double d2;
    us_in >> d2;

    std::cout << "Parsing " << de_double << " as double gives " << std::fixed
              << d1 << " in de_DE locale and " << d2 << " in en_US\n";

    // use the facet directly
    std::string us_double = "1,234,567.89";

    std::istringstream s3(us_double);
    s3.imbue(std::locale("en_US.UTF-8"));
    auto& f = std::use_facet<std::num_get<char>>(s3.getloc());
    std::istreambuf_iterator<char> beg(s3), end;
    double d3;
    std::ios::iostate err;
    f.get(beg, end, s3, err, d3);


    std::istringstream s4(us_double);
    s4.imbue(std::locale("de_DE.UTF-8"));
    auto& f_de = std::use_facet<std::num_get<char>>(s4.getloc());
    std::istreambuf_iterator<char> beg_de(s4), end_de;
    double d4;
    std::ios::iostate err_de;
    f_de.get(beg_de, end_de, s4, err_de, d4);

    std::cout << "parsing " << us_double
              << " as double using raw en_US facet gives " << d3
              << " as double using raw de_DE facet gives " << d4 << '\n';
}