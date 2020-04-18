//
// Created by Vigo Wong on 21/2/20.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char *extractStr(char *s, int i, int j, char *cur) {
    int len = j - i + 1;
    char temp[len];
    int count = 0;
    for (int a = 0; a < len; a++) {
        temp[a] = s[i + count];
        count++;
    }
    strcpy(cur, temp);
    return cur;
}


char *longestPalindrome(char *s) {
    unsigned int length = strlen(s);
    if(length == 1 || length == 0){
        return s;
    }
    int max = 0;
    char new[length];
    char cur[length];
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            int start = i;
            int end = j;
            while (s[start] == s[end] && start < end) {
                start++;
                end--;
            }
            if (start >= end && (j - i + 1) >= max) {
                max = j - i + 1;
                extractStr(s, i, j, cur);
                strcpy(new, cur);
            }
        }
    }
    return new;
}

int main(int argc, char const *argv[]) {
    char a[1000] = "fdafgdgsfgsasaf";
    printf("%s", longestPalindrome(a));
    return 0;
}
