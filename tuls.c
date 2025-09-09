// Project 1 Extra Credit 3207

// gcc -o tuls tuls.c -Wall -Werror
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int lsDirectory(char * directory, int onlyFiles, char * spaces);

int main(int argc, char *argv[]){
    char * directory = ".";
    int differentDirectory = (argc == 2);

    if(differentDirectory){
        directory = argv[argc - 1];
    }

    if(differentDirectory){
        printf("[[%s]]\n", directory);
    }
    int status = lsDirectory(directory, 0, " ");
    if(status == 1){return 1;}
    
    if(differentDirectory){
        lsDirectory(".", 1, "");
    }

    return 0;
}

int lsDirectory(char * directory, int onlyFiles, char * spaces){

    struct dirent ** nameList;
    int n;
    n = scandir(directory, &nameList, NULL, alphasort);
    // printf("Number files %d\n", n);

    if(n == -1){
        perror("scandir");
        exit(EXIT_FAILURE);
    }
    while(n--){
        char * name = nameList[n]->d_name;
        int type = nameList[n]->d_type;
        
        if(type == DT_DIR){
            if(onlyFiles == 0){
                if(strcmp(name, "..") == 0 || strcmp(name, ".") == 0){
                    printf("%s%s\n", spaces, name);
                }
                else{
                    printf("%s[[%s]]\n", spaces, name);
                }
            }
        }
        else{
            printf("%s->%s\n", spaces, name);
        }

        free(nameList[n]);
    }

    return 0;
}
