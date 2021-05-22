//
// Created by zhaoyue on 2021/5/19.
//

#include <array>
#include <random>
#include <iostream>
template<typename T1, typename T2>
void matrix_sort(const T1& source, const T2& index, T1& dest){
    auto pos = dest.begin();

    for (auto x:index) {
        auto posSource = source.begin();
        std::advance(posSource, 10*x);
        std::copy(posSource, std::next(posSource, 10), pos);
        std::advance(pos, 10);
    }
}

int main(){
    std::array<int, 10> index{0,1,2,3,4,5,6,7,8,9};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(index.begin(), index.end(), g);

    std::copy(index.begin(), index.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    std::vector<int> data(100);
    auto pos = data.begin();
    std::uniform_int_distribution<> dis(1, 9);
    for (int i = 0; i < 10; ++i) {
        data[i*10] = i;
        std::generate(std::next(pos), std::next(pos, 10), [&]{return dis(g);});
        std::advance(pos, 10);
    }

    for (int i = 0; i < data.size(); ++i) {
        if (i!=0 && i%10 == 0){
            std::cout << '\n';
        }
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
    std::cout << '\n';
    std::vector<int> dest(100);
    matrix_sort(data, index, dest);
    for (int i = 0; i < dest.size(); ++i) {
        if (i!=0 && i%10 == 0){
            std::cout << '\n';
        }
        std::cout << dest[i] << ' ';
    }
}