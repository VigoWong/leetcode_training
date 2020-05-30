//
// Created by Vigo Wong on 30/5/20.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int l = 0;
        int r = nums.size() - 1;
        int mid = (l + r) / 2;;
        while (l < r) {
            mid = (l + r) / 2;
            if ((mid == 0 || nums[mid] >= nums[mid - 1]) &&
                (mid == n - 1 || nums[mid] >= nums[mid + 1]))
                return mid;
            else if (mid > 0 && nums[mid - 1] > nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return mid;
    }
};

int main(int argc, char const *argv[]){
    vector<int> a = {1,2,1,3,5,6,4};
    Solution s  = Solution();
    cout << s.findPeakElement(a);
    return 0;
}