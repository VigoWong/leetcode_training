//
// Created by Vigo Wong on 29/5/20.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[end]) {
                start = mid+1;
                continue;
            } else if (nums[mid] < nums[start]){
                end = mid-1;
                continue;
            } else if (nums[start] <= nums[mid] && nums[mid] <= nums[end])
                return nums[start];
        }
        return nums[end];
    }
};

int main(int argc, char const *argv[]){
    vector<int> arr = {1,2,2,2,0};
    Solution s = Solution();
    cout << s.findMin(arr);
    return 0;
}