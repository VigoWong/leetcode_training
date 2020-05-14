//
// Created by Vigo Wong on 12/5/20.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int i = 0;
        while (i < nums.size() - 2) {
            int last = nums[i];
            int next = nums[i + 1];
            if (last != next) {
                i++;
                continue;
            } else {
                int start = i + 2;
                int end = i + 2;
                if(nums[start] == last){
                    while (nums[end] == next && end < nums.size()) {
                        end++;
                    }
                    nums.erase(nums.begin() + start, nums.begin() + end);
                }
                i = start;
            }
        }
        return nums.size();
    }
};

int main(int argc, char const *argv[]) {
    vector<int> ls = {0,0,0,1,1,1,1,2,2,2,3,3,3,3};
    Solution s = Solution();
    int num = s.removeDuplicates(ls);
    cout << num << endl;
    for (auto p:ls) {
        cout << p;
    }
    return 0;
}