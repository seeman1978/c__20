//
// Created by zhaoyue on 2020/11/4.
//
#include <sstream>
#include <iostream>

class null_filter_buf : public std::streambuf{
public:
    null_filter_buf(std::streambuf* buf) : src(buf){
        setg(&ch, &ch+1, &ch+1);    // buffer is initially full
    }
protected:
    int underflow(){
        traits_type::int_type i;
        while ((i = src->sbumpc()) == '\0'){
            ;   //skip zeroes
        }
        if (traits_type::not_eof(i)){
            ch = traits_type::to_char_type(i);
            setg(&ch, &ch, &ch+1);  // make one read position available
        }
        return i;
    }
private:
    std::streambuf *src;
    char ch;
};

void filtered_read(std::istream& in){
    std::streambuf* orig = in.rdbuf();
    null_filter_buf buf(orig);
    in.rdbuf(&buf);
    for(char c; in.get(c); ){
        std::cout << c;
    }
    in.rdbuf(orig);
}

int main(){
    char a[] = "This i\0s \0an e\0\0\0xample";
    std::istringstream in(std::string(std::begin(a), std::end(a)));
    filtered_read(in);
}