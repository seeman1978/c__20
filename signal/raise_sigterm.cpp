//
// Created by wq on 2022/5/4.
//

#include <csignal>
#include <iostream>
#include <unistd.h>

void signal_handler(int signal)
{
    std::cout << "Received signal " << signal << '\n';
}

int main()
{
    // Install a signal handler
    std::signal(SIGTERM, signal_handler);

    std::cout << "Sending signal " << SIGTERM << '\n';
    //std::raise(SIGTERM);
    kill(getpid(), SIGTERM);
    sleep(3);
    std::cout << "Finish gracefully.\n";
}