//
// Created by qiangwang on 2021/9/2.
//


#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


int main(int argc, char **argv)
{
    int opt = -1;
    while (-1 != (opt = getopt(argc, argv, "c:")))
    {
        switch (opt)
        {
            case 'c':
                printf("Option a has arg: %s\n", optarg);
                break;
            case 'o':
                printf("Option b has arg: %s\n", optarg);
                break;
            case 'U':
                printf("Option X was provided\n");
                break;
        }
    }

    return 0;
}