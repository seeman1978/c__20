//
// Created by wq on 22-8-26.
//

#include <string>
#include <climits>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>

std::string get_process_path() {
    // using the id, find the name of this process
    char current_process_name[PATH_MAX];
    char path[PATH_MAX];
    sprintf(path, "/proc/%d/cmdline", getpid());    // /proc/%d/exefile in qnx
    memset(current_process_name, 0, sizeof(current_process_name));

    std::cout << "a:" << path << "\n";

    int pinfo = open(path, O_RDONLY);
    if (pinfo)
    {
        // Read process name from file descriptor pinfo
        // http://linux.die.net/man/2/read
        size_t r = read(pinfo, current_process_name, PATH_MAX);
        if (r <= 0)
        {
            std::cout << "b:Could not read process name." << path << "\n";

        }
        else{
            std::cout << "c:" << current_process_name << "\n";

        }
        close(pinfo);
    }
    else
    {
        std::cout << "c:Failed to open" << path;

    }
    std::string str(current_process_name);
    if (!str.empty()){
        std::string::size_type n_pos = str.rfind('/');
        if (n_pos == std::string::npos) {
            std::cout << "d:Not found / in" << str;

        } else {
            str = str.substr(0, n_pos);
        }
    }
    std::cout << "e:" << str << "\n";
    return str;
}

int main(){
    std::string s = get_process_path();
    std::cout << s << "\n";
}