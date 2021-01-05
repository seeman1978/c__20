#include <regex>
#include <iostream>
int main(){
    using namespace std;
    string data = "<person>\n<first>Nico</first>\n<last>Josuttis</last>\n</person>\n";
    {
        regex reg{R"(<(.*)>(.*)</(\1)>)"};
        cout << regex_replace(data, reg, R"(<$1 value="$2"/>)") << '\n';

        //same using sed syntax
        cout << regex_replace(data, reg, R"(<\1 value="\2"/>)", regex_constants::format_sed) << '\n';

        //use iterator interface
        string res2;
        regex_replace(back_inserter(res2), data.begin(), data.end(), reg, R"(<$1 value="$2"/>)", regex_constants::format_no_copy | regex_constants::format_first_only);
        cout << res2 << '\n';
    }
}