//
// Created by Vigo Wong on 24/4/20.
//
#include "stdio.h"
#include "stdlib.h"


int subarraySum(int *nums, int numsSize, int k) {
    int start = 0;
    int end = 0;
    int sum = nums[0];
    if (sum == k)return 1;
    while (start != numsSize) {
        while (sum < k && end < numsSize) {
            end++;
            sum += nums[end];
            if (sum == k) return (end - start + 1);
        }
        while (start < end && sum >= k) {
            sum -= nums[start];
            start++;
            if (sum == k) return (end - start + 1);
        }
    }
    return -1;
}


int main(int argc, char const *argv[]) {
    int nums[] = {1, 1, 1, 4, 5, 2, 4, 3, 2, 2, 6};
    int numsize = 11;
    int k =11;
    printf("%d", subarraySum(nums, numsize, k));
    return 0;
}
