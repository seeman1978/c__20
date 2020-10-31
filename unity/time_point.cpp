//
// Created by wq on 2020/10/31.
//
#include <chrono>
#include <iostream>
#include <ratio>
#include <iomanip>

void slow_motion()
{
    static int a[] {1,2,3,4,5};
    while (std::next_permutation(std::begin(a), std::end(a))) {

    }
}

int main(){
    using namespace std::chrono;
    {
        time_point<steady_clock, milliseconds> tp1(milliseconds{100});
        time_point<steady_clock, microseconds> tp2(microseconds{100*1000});
        //tp1 tp2;  //error,  mabey truncate
        tp2 = tp1;  //ok
        if(tp1 != tp2){
            std::cout << "Insane!\n";
        }
    }
    {
        auto tp = steady_clock::now();
        auto d1 = time_point_cast<hours>(tp).time_since_epoch().count()/24; //从纪元开始到现在的天数
        using days = duration<long, std::ratio<24*60*60, 1>>; // one day
        auto d2 = time_point_cast<days>(tp).time_since_epoch().count(); //从纪元开始到现在的天数
        if (d1 != d2){
            std::cout << "Impossible!\n";
        }
    }
    {
        using namespace std::literals; // enables the usage of 24h instead of std::chrono::hours(24)
        auto now = std::chrono::system_clock::now();
        auto t_c = std::chrono::system_clock::to_time_t(now - 24h);
        std::cout << "24 hours ago, the time was "
                  << std::put_time(std::localtime(&t_c), "%F %T") << '\n';

        auto start = std::chrono::steady_clock::now();
        slow_motion();
        auto end = std::chrono::steady_clock::now();
        std::cout
                << "Slow calculations took "
                << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
                << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms ≈ "
                << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << "s.\n";
    }
}