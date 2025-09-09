// Project 1 Extra Credit 3207

// gcc -o tucp tucp.c -Wall -Werror
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[]){
    char * directory = ".";
    if(argc == 2){directory = argv[argc - 1];}
    
    struct dirent * dp;
    DIR * dir = opendir(directory);

    while(dir){
        dp = readdir(dir);
        printf("%s\n", dp->d_name);
    }

    return 0;
}

