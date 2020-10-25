//
// Created by wq on 2020/10/25.
//

#include <vector>
#include <iostream>
#include <iterator>

int main()
{
    using namespace std;
    {
        std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        std::fill(v.begin(), v.end(), -1);

        for (auto elem : v) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }
    {
        vector<int> v{0,1,2,3,4,5,6,7,8,9};
        fill_n(v.begin()+8, 4, -1);
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        cout << '\n';
    }
}