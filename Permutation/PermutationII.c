//
// Created by Vigo Wong on 24/4/20.
//

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

//int comp(const void* a, const void* b) {
//    return *(int*)a - *(int*)b;
//}
//void dfs(int*** result, int* size, int* nums, int n, int* before, int bef, bool* flag) {
//    if(bef == n) {
//
//        (*size)++;
//        result[0] = (int**)realloc(result[0], *size * sizeof(int*));
//        result[0][*size - 1] = (int*)malloc(n * sizeof(int));
//        memcpy(result[0][*size - 1], before, n * sizeof(int));
//        return;
//    }
//    int i = 0;
//    for(i = 0; i < n; i++) {
//        if(flag[i])
//            continue;
//        // if (i > 0 && nums[i] == nums[i - 1] && !flag[i - 1])
//        //    continue; 	//可以把下边的while循环换成这两句话。
//        flag[i] = true;
//        before[bef] = nums[i];
//        dfs(result, size, nums, n, before, bef + 1, flag);
//        flag[i] = false;
//        while(i + 1 < n && nums[i] == nums[i + 1])
//            i++;
//    }
//}
//int** permuteUnique(int* nums, int numsSize, int* returnSize) {
//    qsort(nums, numsSize, sizeof(int), comp);
//    int** result = NULL;
//    int* before = (int*)malloc(numsSize * sizeof(int));
//    bool* flag = (bool*)calloc(numsSize, sizeof(bool));
//    dfs(&result, returnSize, nums, numsSize, before, 0, flag);
//    free(before);
//    free(flag);
//    return result;
//}




int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
void dfs(int*** result, int* size, int* nums, int n, int start) {
    //recursion
    // terminal condition, when the start equals to numsSize
    if(start + 1 == n) {
        (*size)++;
        result[0] = (int**)realloc(result[0], *size * sizeof(int*));
        result[0][*size - 1] = (int*)malloc(n * sizeof(int));
        memcpy(result[0][*size - 1], nums, n * sizeof(int));
        return;
    }
    int i = 0;
    // init a temporary array to store the new sequence with a init value of the type-in array
    int* temp = (int*)malloc(n * sizeof(int));
    memcpy(temp, nums, n * sizeof(int));
    qsort(nums + start, n - start, sizeof(int), comp);
    for(i = start; i < n; i++) {
        int t = nums[start];
        nums[start] = nums[i];
        nums[i] = t;
        dfs(result, size, nums, n, start + 1);
        nums[i] = nums[start];
        nums[start] = t;
        while(i + 1 < n && nums[i] == nums[i + 1])
            i++;
    }
    memcpy(nums, temp, n * sizeof(int));
    free(temp);
}

int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    // sort the nums
    qsort(nums, numsSize, sizeof(int), comp);
    int** result = NULL;
    dfs(&result, returnSize, nums, numsSize, 0);
    return result;
}

