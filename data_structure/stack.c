//
// Created by Vigo Wong on 18/4/20.
//

#include "stack.h"


struct Stack {
    int maxsize;
    int top;
    dataType *arr;
};


dataType topStack(stack_p p) {
    return p->arr[p->top - 1];
}

dataType popStack(stack_p p) {
    return p->arr[p->top-- - 1];
}

void pushStack(stack_p p, dataType data) {
    p->arr[p->top++] = data;
}

stack_p initStack(int maxsize) {
    assert(maxsize > 0);
    stack_p s = malloc(sizeof(stack));
    if (s != NULL) {
        s->top = 0;
        s->maxsize = maxsize;
        s->arr = malloc(sizeof(dataType) * maxsize);
        assert(s->arr != NULL);
        return s;
    }
    fprintf(stdout, "insufficient memory\n");
    return s;
}

bool isEmptyStack(stack_p p) {
    return (p->top == 0);
}

bool ifFullStack(stack_p p) {
    return (p->top == p->maxsize);
}

void freeStack(stack_p p){
    assert(p!=NULL);
    free(p ->arr);
    free(p);
}