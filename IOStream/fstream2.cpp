//
// Created by 王强 on 2021/1/11.
//

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

void writeStringToFile(const std::string& filename){
    using namespace std;
    ofstream file(filename);
    if (!file){
        cerr << "can't open output file \"" << filename << "\"" << '\n';
        exit(EXIT_FAILURE);
    }
    for (int i = 32; i < 56; ++i) {
        file << "value: " << setw(3) << i << "   ." << "char:  " << static_cast<char>(i) << '\n';
    }
}

void outputFile(const std::string& filename){
    using namespace std;
    ifstream file(filename);
    if (!file){
        cerr << "can't open input file \"" << filename << "\"" << '\n';
        exit(EXIT_FAILURE);
    }
    std::cout << file.rdbuf();
    file.seekg(0);
    ostringstream ss;
    ss << file.rdbuf(); // reading data
    string str = ss.str();
}


int main(){
    writeStringToFile("charset.out");
    outputFile("charset.out");
}