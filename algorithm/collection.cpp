//
// Created by 王强 on 2020/10/26.
//

#include <vector>
#include <iostream>

/*template<typename T>
void print(const T& a){
    for (const auto &i : a) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}*/

constexpr auto print = [](const auto& v, const char* end = "\n") {
    std::cout << "{ ";
    for (auto i : v) {
        std::cout << i << ' ';
    }
    std::cout << "} " << end;
};

struct Order // a struct with some interesting data
{
    int order_id;
};

std::ostream& operator<<(std::ostream& os, const Order& ord)
{
    return os << ord.order_id << ',';
}

int main(){
    using namespace std;
    {//并集
        vector<int> v1{1, 2, 3, 4, 5};
        vector<int> v2{      3, 4, 5, 6, 7};
        std::vector<int> dest1;
        set_union(v1.begin(), v1.end(),
                  v2.begin(), v2.end(),
                  back_inserter(dest1));
        print(dest1);
    }
    {//交集元素只出现一次
        std::vector<int> v1{1, 2, 3, 4, 5, 5, 5};
        std::vector<int> v2{      3, 4, 5, 6, 7};
        std::vector<int> dest1;

        std::set_union(v1.begin(), v1.end(),
                       v2.begin(), v2.end(),
                       std::back_inserter(dest1));

        print(dest1);
    }
    {
        std::vector<int> v1{1,2,3,4,5,6,7,8};
        std::vector<int> v2{        5,  7,  9,10};
        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());

        std::vector<int> v_intersection;

        std::set_intersection(v1.begin(), v1.end(),
                              v2.begin(), v2.end(),
                              std::back_inserter(v_intersection));
        print(v_intersection);
    }
    {
        const std::vector<int> v1 {1, 2, 5, 5, 5, 9};
        const std::vector<int> v2 {2, 5, 7};
        std::vector<int> diff;

        std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
                            std::inserter(diff, diff.begin()));
        print(v1, "∖ ");
        print(v2, "= ");
        print(diff, "\n");

        // we want to know which orders "cut" between old and new states:
        std::vector<Order> old_orders { {1}, {2}, {5}, {9} };
        std::vector<Order> new_orders { {2}, {5}, {7} };
        std::vector<Order> cut_orders;

        std::set_difference(old_orders.begin(), old_orders.end(),
                            new_orders.begin(), new_orders.end(),
                            std::back_inserter(cut_orders),
                            [](auto& a, auto& b) { return a.order_id < b.order_id; });

        std::cout << "old orders = "; print(old_orders, "\n");
        std::cout << "new orders = "; print(new_orders, "\n");
        std::cout << "cut orders = "; print(cut_orders, "\n");
    }
    {
        std::vector<int> v1{1,2,3,4,5,6,7,8     };
        std::vector<int> v2{        5,  7,  9,10};
        std::sort(v1.begin(), v1.end());
        std::sort(v2.begin(), v2.end());

        std::vector<int> v_symDifference;

        std::set_symmetric_difference(
                v1.begin(), v1.end(),
                v2.begin(), v2.end(),
                std::back_inserter(v_symDifference));

        print(v_symDifference);
    }
}