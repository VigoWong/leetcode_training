//
// Created by Vigo Wong on 27/4/20.
//
#include "stdio.h"
#include "string.h"


int longestCommonSubsequence(char * text1, char * text2){

    unsigned int l1 = strlen(text1);
    unsigned int l2 = strlen(text2);

    char *c1 = text1;
    char *c2 = text2;

    int count = 0;
    while(c1 <= &text1[l1-1] && c2 <= &text2[l2-1]){
        if(*c2 == *c1){
            c1++;
            c2++;
            count++;
        } else{
            c1++;
        }
    }
    if(c1 > &text1[l1-1] && c2 > &text2[l2-1]) return count;
    return 0;
}


int main(int argc, char const *argv[]){
    char text1[] = "abc";
    char text2[] = "abc";
    printf("%d", longestCommonSubsequence(text1, text2));
    return 0;
}