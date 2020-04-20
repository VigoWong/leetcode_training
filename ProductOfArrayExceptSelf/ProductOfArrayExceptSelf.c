//
// Created by Vigo Wong on 20/4/20.
//
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
    int *ret = malloc(sizeof(int) * numsSize);
    ret[0] = 1;
    for(int i=1; i<numsSize;i++){
        ret[i] = ret[i-1] * nums[i-1];
    }
    int temp[numsSize];
    temp[numsSize - 1] = 1;
    for(int i=numsSize-2; i>=0;i--){
        temp[i] = temp[i+1] * nums[i+1];
    }
    for(int i=0; i<numsSize;i++){
        ret[i] = ret[i] * temp[i];
    }

    return ret;
}

int main(int argc, char const *argv[]) {
    int arr[] = {1, 2, 3, 4};
    int *a = NULL;
    int *b = productExceptSelf(arr, 4, a);
    for(int i = 0; i < 4; i++){
        printf("%d ", b[i]);
    }
    return 0;
}


