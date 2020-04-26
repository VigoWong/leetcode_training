//
// Created by Vigo Wong on 26/4/20.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int trap(int *height, int heightSize) {
    int start = 0;
    int sum = 0;
    int last = heightSize-1;
    while(height[last-1] > height[last])last--;
    while (start != last) {
        while (height[start] <= height[start + 1]) {
            start++;
            if (start == last)return sum;
        }
        int end = start + 1;
        int temp_sum = 0;
        int highest = 0;
        int width = 0;
        int minus = 0;
        while (height[end] < height[start]) {
            width++;
            minus += height[end];
            if(height[end] > highest)
                highest = height[end];
            end++;
            if(end> last){
                temp_sum = width * highest - minus;
                sum += temp_sum;
                return sum;
            }
        }
        temp_sum =  width * height[start] - minus;
        sum+=temp_sum;
        start = end;
    }
    return sum;
}

int main(int argc, char const *argv[]){
    int heights[] = {0,1,0,2,1,0,1,3,2,1,2  ,3};
    printf("%d", trap(heights, 12));
    return 0;
}