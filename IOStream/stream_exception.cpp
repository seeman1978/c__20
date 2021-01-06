//
// Created by 王强 on 2021/1/6.
//

#include <istream>
#include <iostream>

double ProcessSum(std::istream& strm){
    using namespace std;
    double value, sum;

    ios::iostate oldException = strm.exceptions();

    strm.exceptions(ios::failbit | ios::badbit);
    try{
        sum = 0;
        while (strm >> value){
            sum += value;
        }
    }
    catch (...) {
        if (!strm.eof()){
            strm.exceptions(oldException);
            throw;
        }
    }
    strm.exceptions(oldException);
    return sum;
}

int main(){
    using namespace std;
    double sum;
    try {
        sum = ProcessSum(cin);
    }
    catch(const ios::failure& error){
        cerr << "I/O exception: " << error.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (const exception& error) {
        cerr << "standard exception: " << error.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...) {
        cerr << "Unknown exception" << '\n';
        return EXIT_FAILURE;
    }
    cout << "sum: " << sum << '\n';
}