//
// Created by Vigo Wong on 29/4/20.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> p;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)
            return p;
        for (int head = 0; head < nums.size() - 2; head++) {
            if (head > 0 && nums[head] == nums[head - 1])continue;
            if (nums[head] > 0)
                return p;
            int b = head + 1;
            int end = nums.size() - 1;
            while (b < end) {
                if (nums[head] + nums[b] + nums[end] == 0) {
                    vector<int> temp = {nums[head], nums[b], nums[end]};
                    p.push_back(temp);
                    while (nums[b] == nums[b + 1])b++;
                    while (nums[end] == nums[end - 1]) end--;
                    b++;
                    end--;
                } else if (nums[head] + nums[b] + nums[end] < 0) {
                    while (nums[b] == nums[b + 1])b++;
                    b++;
                } else if (nums[head] + nums[b] + nums[end] > 0) {
                    while (nums[end] == nums[end - 1]) end--;
                    end--;
                }
            }
        }
        for (const auto& a:p){
            for(auto b:a){
                cout << b << " ";
            }
            cout << endl;
        }
        return p;
    }
};

int main(int argc, char const *argv[]){
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    Solution b = Solution();
    b.threeSum(a);
    return 0;
}