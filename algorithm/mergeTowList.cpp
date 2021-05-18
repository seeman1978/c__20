//
// Created by 王强 on 2021/5/18.
//

#include <list>
#include <random>
#include <c++/v1/iostream>

template<class T>
void merge(T& first, T second)
{
    auto firstPos=first.begin(), secondPos=second.begin();
    do {
        if (secondPos == second.end()){
            break;
        }
        else if (firstPos == first.end() || *firstPos >= *secondPos){
            first.emplace(firstPos, *secondPos);
            ++secondPos;
        }
        else if (*firstPos < *secondPos) {
            ++firstPos;
        }
    } while (true);
}

int main(){
    // fill the vectors with random numbers
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis(0, 9);

    std::list<int> v1(10), v2(10);
    std::generate(v1.begin(), v1.end(), [&]{return dis(mt);});
    std::generate(v2.begin(), v2.end(), [&]{return dis(mt);});

    // sort
    v1.sort();
    v2.sort();

    // output v1
    std::cout << "v1 : ";
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // output v2
    std::cout << "v2 : ";
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    // merge
    std::vector<int> dst;
    merge(v1, v2);

    // output
    std::cout << "dst: ";
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}