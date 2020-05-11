//
// Created by Vigo Wong on 11/5/20.
//
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size()-1;
        for(int i = 0; i<=blue; i++){
            if(nums[i] == 0){
                swap(nums[i], nums[red++]);
            }else if(nums[i] == 2){
                swap(nums[i--], nums[blue--]);
            }
        }
    }
};

int main(int argc, char const *argv[]){
    vector<int> arr = {2,0,2,1,1,0};
    Solution a = Solution();
    a.sortColors(arr);
    for (auto i:arr){
        cout << i;
    }
    return 0;
}