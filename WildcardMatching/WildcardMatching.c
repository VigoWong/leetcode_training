//
// Created by Vigo Wong on 25/4/20.
//
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"


bool isMatch(char *s, char *p) {
    char *sp = s;
    char *pp = p;
    int len_s = strlen(s) - 1;
    int len_p = strlen(p) - 1;
    while (pp <= &p[len_p]) {
        if (*pp == '*') {
            if (pp == &p[len_p]) return true;
            char *temp = pp;
            while (*temp == '*')temp++;
            while (sp <= &s[len_s]) {
                if (*sp == *temp) {
                    if (isMatch(sp, temp)) return true;
                }
                sp++;
            }
            return false;
        } else if (*pp == '?') {
            if (sp > &s[len_s]) return false;
            else {
                pp++;
                sp++;
                continue;
            }
        } else {
            if (sp > &s[len_s] || *pp != *sp)return false;
            else {
                pp++;
                sp++;
            }
        }
    }
    return (sp > &s[len_s]);
}


int main(int argc, char const *argv[]) {
    char s[] = "cb";
    char p[] = "?a";
    printf("match: %d", isMatch(s, p));
    return 0;
}

