#include <iostream>

//
// Created by zhaoyue on 2020/11/17.
//

template<typename C>
void printClockData(){
    std::cout << "-precision:";
    using P = typename C::period;
    if (std::ratio_less_equal<P, std::milli>::value){
        using TT = typename std::ratio_multiply<P, std::kilo>::type;
        std::cout << std::fixed << double(TT::num)/TT::den << " milliseconds\n";
    }
    else{
        std::cout << std::fixed << double(P::num)/P::den << " seconds\n";
    }
    std::cout << "- is_steady:" << std::boolalpha << C::is_steady << '\n';
}


int main(){
    std::cout << "system clock:\n";
    printClockData<std::chrono::system_clock>();

    std::cout << "\nhigh_resolution_clock:\n";
    printClockData<std::chrono::high_resolution_clock>();

    std::cout << "\nsteady_clock\n" ;
    printClockData<std::chrono::steady_clock>();
}
