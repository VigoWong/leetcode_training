//
// Created by Vigo Wong on 18/4/20.
//

#include "stdio.h"
#include "../data_structure/stack.h"

void moveZeroes1(int *nums, int numsSize) {
    stack_p s = initStack(numsSize);

    for (int i = numsSize-1; i > 0; i--) {
        pushStack(s, nums[i]);
    }

    int index = 0;
    int num;
    while (!isEmptyStack(s)){
        if ((num = popStack(s))!=0){
            nums[index++] = num;
        }
    }
    for(index = index; index<numsSize; index++){
        nums[index] = 0;
    }
    free(s);
}


void moveZeroes2(int *nums, int numsSize) {
    int *p = NULL;
    for(int i=0; i<numsSize;i++){
        if(nums[i] == 0){
            p = &nums[i+1];
            while ( *p == 0){
                p++;
            }
            if(p > &nums[numsSize-1]) break;
            nums[i] = *p;
            *p = 0;
        }
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {0, 1, 0, 3, 12};
    moveZeroes2(arr, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}




