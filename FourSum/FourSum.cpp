//
// Created by Vigo Wong on 29/4/20.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>

using namespace std;


class Solution {
public:

    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        vector<bool> visit;
        for (auto c:nums) {
            cout << c << " ";
        }
        vector<vector<int> > newOne(10, vector<int>(10, 0));
        return newOne;
    }
};

int main(int argc, char const *argv[]) {
    Solution c = Solution();
    vector<int> p = {1, 0, -1, 0, -2, 2};
    int target = 0;
    c.fourSum(p, target);
    return 0;
}