//
// Created by Vigo Wong on 25/4/20.
//
#include "stdio.h"

int dfs(int pos, int *nums, int target, int jumps){
    if(pos == target)return jumps;
    if(nums[pos] > (target - pos))return jumps+1;
    else{
        int min = target+1;
        for(int n=nums[pos]; n >0; n--){
            int next =  dfs(pos+n, nums, target, jumps+1);
            if(min >next){
                min = next;
            }
        }
        return min;
    }
}


int jump(int* nums, int numsSize){
    return dfs(0, nums, numsSize-1, 0);
}

int main(int argc, char const *argv[]){
    int arr[] = {2,3,1,1,4};
    printf("%d", jump(arr, 5));
    return 0;
}