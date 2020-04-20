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
    returnSize = (int *)malloc(numsSize * sizeof(int));
}

int main(int argc, char const *argv[]) {
    int arr[] = {1, 2, 3, 4};
    int *a = NULL;
    productExceptSelf(arr, 4, a);
    int b;
    return 0;
}


