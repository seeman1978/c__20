//
// Created by wq on 2021/1/17.
//

#include <iostream>

int main()
{
    using namespace std;
    {
        try{
            cin.imbue(locale::classic()); //the same as locale()
            cout .imbue(locale("de_DE"));
            double value;
            if(cin >> value){
                cout << value << endl;
            }
        }
        catch (const std::exception& e) {
            cerr << "exception: " << e.what() << endl;
            return EXIT_FAILURE;
        }
    }
    {
        try{
            cin.imbue(locale(""));  //create the default locale from the user's environment
            cout .imbue(locale("de_DE"));
            double value;
            if(cin >> value){
                cout << value << endl;
            }
        }
        catch (const std::exception& e) {
            cerr << "exception: " << e.what() << endl;
            return EXIT_FAILURE;
        }
    }
    {
        try{
            locale::global(locale("de_DE"));
            cin.imbue(locale());
            cout .imbue(locale());
            double value;
            if(cin >> value){
                cout << value << endl;
            }
        }
        catch (const std::exception& e) {
            cerr << "exception: " << e.what() << endl;
            return EXIT_FAILURE;
        }
    }
}