//
// Created by Vigo Wong on 27/4/20.
//

#include "stdlib.h"
#include "stdio.h"
#include "string.h"


char * countAndSay(int n){
    if(n == 1){
        char *ret = (char*)malloc(2 * sizeof(char));
        strcpy(ret, "1");
        return ret;
    }

    char *ret = (char*)malloc(10000 * sizeof(char));
    char *temp = (char*)malloc(10000 * sizeof(char));
    ret[0] = '1';
    ret[1] = '\0';

    int time = 1;
    while(time != n){
        char *p = ret;
        unsigned int len = strlen(ret);

        while(p <= &ret[len-1]){
            char cur = *p;
            int count = 0;
            while(*p == cur && p <= &ret[len-1]){
                p++;count++;
            }
            char word[3];
            word[0] = '0' + count;
            word[1] = cur;
            word[2] = '\0';
            strcat(temp, word);
        }
        strcpy(ret, temp);
        strcpy(temp, "");
        time++;
    }
    free(temp);
    return ret;
}

int main(int argc, char const *argv[]){
    printf("%s", countAndSay(3));
    return 0;
}
