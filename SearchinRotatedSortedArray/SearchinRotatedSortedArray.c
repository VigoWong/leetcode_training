//
// Created by Vigo Wong on 21/4/20.
//
#include "stdlib.h"
#include "stdio.h"



int search(int* nums, int numsSize, int target){
    int start = 0;
    int end = numsSize - 1;
    int mid = (numsSize-1) / 2;
    while(start != mid && end != mid && nums[mid] != target){
        if (target == nums[end]) return end;
        if (target == nums[start]) return start;
        if(target > nums[mid] && target >= nums[end]){
            end = mid;
            mid = (start + end) / 2;
        } else if (target > nums[mid] && target < nums[end]){
            start = mid;
            mid = (start+end) / 2;
        } else if (target < nums[mid] && target > nums[start]){
            end = mid;
            mid = (start + end) / 2;
        } else if (target < nums[mid] && target < nums[start]){
            start = mid;
            mid = (start+end) / 2;
        }
    }
    if(nums[mid] == target)return mid;
    else return -1;
}


int main(int argc, char const *argv[]){
    int arr[] = {4,5,6,7,0,1,2};
    printf("%d", search(arr, 7, 8));
    return 0;
}

