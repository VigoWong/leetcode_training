//
// Created by Vigo Wong on 18/4/20.
//

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#endif //DATA_STRUCTURE_STACK_H

#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "assert.h"

#define dataType char

typedef struct Stack stack, *stack_p;


dataType topStack(stack_p p);

dataType popStack(stack_p p);

void pushStack(stack_p p, dataType data);

stack_p initStack(int maxsize);

bool isEmptyStack(stack_p p);

bool ifFullStack(stack_p p);

void freeStack(stack_p);