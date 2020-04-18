#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int t1=0;
    int t2=0;
    int sum = nums1Size + nums2Size;
    int arr[nums1Size + nums2Size];
    int count = 0;

    while(count < sum ){
        if(nums1[t1] > nums2[t2] || t1 == nums1Size){
            arr[count] = nums2[t2];
            t2++;
        }else if(nums1[t1] <= nums2[t2] || t2 == nums2Size){
            arr[count] = nums1[t1];
            t1++;
        }
        count++;
    }
    if(sum %2 == 0){
        return (double)((arr[sum/2-1] + arr[sum/2])/2.0);
    }else{
        return (double)(arr[sum/2]);
    }
}

int main(int argc, char const *argv[]){
    double answer;
    int nums1[2] = {1,2};
    int nums2[2] = {3,4};
    answer = findMedianSortedArrays(nums1,2,nums2,2);
    printf("%f", answer);
    return 0;
}
