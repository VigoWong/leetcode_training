//
// Created by Vigo Wong on 29/5/20.
//

#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        // resolving by dp
        int ret = nums[0];
        vector<int> minLS = nums;
        vector<int> maxLS = nums;
        for (int i = 1; i < nums.size(); i++) {
            maxLS[i] = max(max(maxLS[i - 1] * maxLS[i], minLS[i - 1] * maxLS[i]), maxLS[i]);
            minLS[i] = min(min(minLS[i - 1] * minLS[i], maxLS[i - 1] * minLS[i]), minLS[i]);
            ret = max(maxLS[i], ret);
        }
        return ret;
    }
};

int main(int argc, char const *argv[]){
    vector<int> v = {-2,0,-1};
    Solution s = Solution();
    cout << s.maxProduct(v);
    return 0;
}