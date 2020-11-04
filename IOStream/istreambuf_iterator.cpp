//
// Created by zhaoyue on 2020/11/4.
//

#include <sstream>
#include <vector>
#include <iostream>

int main(){
    using namespace std;
    {
        // typical use case: an input stream represented as a pair of iterators
        std::istringstream in("Hello, world");
        std::vector<char> v((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
        std::cout << "v has " << v.size() << " bytes. ";
        v.push_back('\0');
        std::cout << "it holds \"" << &v[0] << "\"\n";

        // demonstration of the single-pass nature
        std::istringstream s{"abc"};
        std::istreambuf_iterator<char> i1{s}, i2{s};
        std::cout << "i1 returns " << *i1 << '\n';
        std::cout << "i2 returns " << *i2 << '\n';

        ++i1;
        std::cout << "after incrementing i1, but not i2\n"
                  << "i1 returns " << *i1 << '\n'
                  << "i2 returns " << *i2 << '\n';

        ++i2; // this makes the apparent value of *i2 to jump from 'a' to 'c'
        std::cout << "after incrementing i2, but not i1\n"
                  << "i1 returns " << *i1 << '\n'
                  << "i2 returns " << *i2 << '\n';
    }
    {
        // A range is defined by the istreambuf_iterator to the current position and
        // the end-of-stream iterator, but since all non-end-of stream iterators are
        // equivalent under the equal member function, it is not possible to define
        // any subranges using
        cout << "(Try the example: 'Hello world!'\n"
             << " then an Enter key to insert into the output,\n"
             << " & use a ctrl-Z Enter key combination to exit): ";

        istreambuf_iterator<char> charReadIn1 ( cin );
        istreambuf_iterator<char> charReadIn2 ( cin );

        bool b1 = charReadIn1.equal ( charReadIn2 );

        if (b1)
            cout << "The iterators are equal." << endl;
        else
            cout << "The iterators are not equal." << endl;
    }
}