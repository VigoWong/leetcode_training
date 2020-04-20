//
// Created by Vigo Wong on 20/4/20.
//
#include "stdlib.h"
#include "stdbool.h"
#include "../data_structure/stack/stack.h"

bool checkValidString(char *s) {
    stack_p new = initStack(100);
    int star = 0;
    while (*s) {
        if (*s == '(') {
            pushStack(new, *s);
        } else if (*s == ')') {
            if (isEmptyStack(new)) {
                if (star == 0)return false;
                else star--;
            } else {
                popStack(new);
            }
        } else if (*s == '*') {
            star++;
        }
        s++;
    }
    while (!isEmptyStack(new)) {
        popStack(new);
        if (star == 0)return false;
        else star--;
    }
    return true ;

}


int main(int argc, char const *argv[]) {
    char str[10] = "*(((*))";
    printf("%d", checkValidString(str));
    return 0;
}