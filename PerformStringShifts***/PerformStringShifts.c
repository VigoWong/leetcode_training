//
// Created by Vigo Wong on 23/4/20.
//
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

char *stringShift(char *s, int *shift[2], int shiftSize, int *shiftColSize) {
    int len = strlen(s);
    char *word = malloc(sizeof(char) * strlen(s));

    int pos = 0;
    for (int i = 0; i < shiftSize; i++) {
        if (shift[i][0] == 0) pos -= shift[i][1];
        else if (shift[i][0] == 1) pos += shift[i][1];
    }
    pos = pos % len;
    strcpy(word, &s[pos]);
    s[pos] = '\0';
    strcat(word, s);
    return word;
}

int main(int argc, char const *argv[]) {
    int shift[2][2] = {{0, 1},
                     {1, 2}};
    int shiftSize = 2;
    int shiftColSize[] = {2, 2};
    char s[10] = "abc";
    char *a =NULL;
    a = stringShift(s, shift, shiftSize, shiftColSize);
    printf("%s", a);
    return 0;
}
