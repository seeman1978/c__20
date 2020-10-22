
//
// Created by zhaoyue on 2020/10/14.
//

#include <tuple>
#include <iostream>
#include <stdexcept>

std::tuple<double, char, std::string> get_student(int id){
    if (id == 0){
        return std::make_tuple(3.8, 'A', "Lisa");
    }
    throw std::invalid_argument("id");
}

int main(){
    auto student0 = get_student(0);

    std::cout << "id 0, "
              << "GPA:" << std::get<0>(student0);
    std::cout << ", grade:" << std::get<1>(student0);
    std::cout << ", name:" << std::get<2>(student0) << std::endl;

    double gpa1;
    char grade1;
    std::string name1;
    std::tie(gpa1, grade1, name1) = get_student(0);
    std::cout << "id 0, "
              << "GPA:" << gpa1;
    std::cout << ", grade:" << grade1;
    std::cout << ", name:" << name1 << std::endl;

    auto [gpa2, grade2, name2] = get_student(0);
    std::cout << "id 0, "
              << "GPA:" << gpa2;
    std::cout << ", grade:" << grade2;
    std::cout << ", name:" << name2 << std::endl;

}