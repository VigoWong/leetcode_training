//
// Created by Vigo Wong on 26/4/20.
//
#include "stdio.h"


//1 4 3 -1  //


int firstMissingPositie(int* nums, int numsSize){
    for(int i = 0; i<numsSize;i++){
        if(nums[i] > 0 && nums[i]<numsSize){
            int temp = nums[i];
            int index = nums[i] -1;
            nums[i] = nums[index];
            nums[index] = temp;
        }
    }
    for(int i = 0; i<numsSize; i++){
        printf("%d ", nums[i]);
    }
    for(int i = 0; i<numsSize; i++){
        if(nums[i]!=(i+1))return (i+1);
    }
    return numsSize;
}

int main(int argc, char const *argv[]){
    int arr[] = {1,2,0};
    printf("%d", firstMissingPositie(arr, 3));
    return 0;
}



