//
// Created by Vigo Wong on 18/4/20.
//
#include "stdio.h"

// simply do a xor operation on all numbers,
// the positions of number appear   twice would be set to 0 and only those appear once left
int singleNumber(int* nums, int numsSize){
    unsigned char a = 0;
    for (int i=0; i < numsSize; i ++){
        a ^= nums[i];
    }
    return a;
}


int main(int argc, char const *argv[]){
    int arr[] = {2,2,33 };
    printf("%d",singleNumber(arr, 3));
    return 0;
}