//
// Created by Vigo Wong on 18/4/20.
//
#include "stdio.h"



int maxSubArray(int *nums, int numsSize) {
    int sum = 0;
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum > max) max = sum;
        if (sum < 0){
            sum = 0;
            continue;
        }
    }
    return max;
}


int main(int argc, char const *argv[]){
    int nums[] = {-2,1,-3,4,-1,2,1,     5,1};
    printf("%d", maxSubArray(nums, 9));
    return 0;
}

