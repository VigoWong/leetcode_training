//
// Created by Vigo Wong on 23/4/20.
//
#include "string.h"
#include "stdbool.h"
#include "stdio.h"

bool backspaceCompare(char *S, char *T) {
    char *s_p = &S[strlen(S) - 1];
    char *t_p = &T[strlen(T) - 1];
    int s_count = 0;
    int t_count = 0;

    while (s_p >= S || t_p >= T) {
        while (s_count) {
            s_p--;
            s_count--;
        }
        while (t_count) {
            t_p--;
            t_count--;
        }
        if (s_p < S || t_p < T) {
            while (t_p >= T) {
                if (*t_p != '#' && t_count == 0)
                    return false;
                else if (*t_p != '#' && t_count > 0) {
                    t_count--;
                    t_p--;
                } else {
                    t_count++;
                    t_p--;
                }
            }
            while (s_p >= S) {
                if (*s_p != '#' && s_count == 0)
                    return false;
                else if (*s_p != '#' && s_count > 0) {
                    s_count--;
                    s_p--;
                } else {
                    s_count++;
                    s_p--;
                }
            }
        }


        if (*s_p == '#' || *t_p == '#') {
            while (*s_p == '#') {
                s_count++;
                s_p--;
            }
            while (*t_p == '#') {
                t_count++;
                t_p--;
            }
            continue;
        }
        if (*s_p != *t_p)return false;
        else {
            s_p--;
            t_p--;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    char S[100] = "a#c";
    char T[100] = "b";
    printf("%d", backspaceCompare(S, T));
    return 0;
}



