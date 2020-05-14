//
// Created by Vigo Wong on 14/5/20.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ret(1);
        for (int i = 0; i < nums.size(); i++) {
            if (i== nums.size() - 1 || nums[i] != nums[i + 1]) {
                int curSize = ret.size();
                for (int j = 0; j < curSize; j++) {
                    ret.push_back(ret[j]);
                    ret.back().push_back(nums[i]);
                }
            } else {
                int num = nums[i];
                int count = 1;
                int index = i;
                while (i < nums.size() && nums[++i] == num) {
                    count++;
                }
                vector<int> cur(1, num);
                int curSize = ret.size();
                for (int j = 0; j < count; j++) {
                    cur.resize(j + 1, 2);
                    for (int k = 0; k < curSize; k++) {
                        ret.push_back(ret[k]);
                        ret.back().insert(ret.back().end(), cur.begin(), cur.end());
                    }
                }
                i--;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    vector<int> ls = {1, 2, 2, 3};
    vector<vector<int> > ret = s.subsetsWithDup(ls);
    for (auto a:ret) {
        for (auto b:a) {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}