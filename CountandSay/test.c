//
// Created by Vigo Wong on 27/4/20.
//
#include "stdlib.h"
#include "stdio.h"


int main(int argc, char const *argv[]){
    char word[3];
    word[0] = '0' + 1;
    word[1] = '1';
    word[2] = '\0';
    printf("%s", word);
    return 0;
}