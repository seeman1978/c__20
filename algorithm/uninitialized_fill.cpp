//
// Created by 王强 on 2020/10/25.
//
#include <string>
#include <iostream>

int main(){
    using namespace std;
    {
        string* p;
        size_t sz;
        tie(p, sz) = get_temporary_buffer<string>(4);
        uninitialized_fill(p, p+sz, "Example");
        for (string* i=p; i != p+sz; ++i){
            cout << *i << '\n';
            i->~basic_string<char>();
        }
        cout << '\n';
        return_temporary_buffer(p);
    }
    {
        string* p;
        size_t sz;
        tie(p, sz) = get_temporary_buffer<string>(4);
        uninitialized_fill_n(p, sz, "Example");
        for (string* i = p; i != p+sz; ++i) {
            cout << *i << '\n';
            i->~basic_string<char>();
        }
        cout << '\n';
        return_temporary_buffer(p);
    }
    {
        const char* v[]{"This", "is", "an", "example"};
        auto sz = size(v);
        if (void *pbuf=aligned_alloc(alignof(string), sizeof(string)*sz))
        {
            try {
                auto first = static_cast<string*>(pbuf);
                auto last = std::uninitialized_copy(begin(v), end(v), first);
                for (auto it = first; it!=last; ++it){
                    cout << *it << '_';
                }
                cout << '\n';
                destroy(first, last);
            }
            catch (...) {


            }
            free(pbuf);
        }
    }
    {
        const char* v[]{"This", "is", "an", "example"};
        auto sz = size(v);
        if (void *pbuf=aligned_alloc(alignof(string), sizeof(string)*sz))
        {
            try {
                auto first = static_cast<string*>(pbuf);
                auto last = std::uninitialized_copy_n(begin(v), sz, first);
                for (auto it = first; it!=last; ++it){
                    cout << *it << '_';
                }
                cout << '\n';
                destroy(first, last);
            }
            catch (...) {

            }
            free(pbuf);
        }
    }
}
