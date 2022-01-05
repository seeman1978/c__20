/**
* @file
* @brief
* @details
* @author		qiangwang
* @date		    2022/1/5
* @par Copyright(c): 	2022 mega. All rights reserved.
*/

template <typename T>
class list {
private:

    class node {
    public:
        T value;
        node()=default;
        ~node()=default;
    };

public:
    node *H; // <<<<<<
    list()=default;
    ~list()=default;
};


int main(){
    list<int> mylist{};

}