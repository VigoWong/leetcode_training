//
// Created by Vigo Wong on 28/4/20.
//
#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(auto i = nums.begin(); i!= nums.end();){
            if(*i == val){
                i = nums.erase(i);
            } else{
                ++i;
            }
        }
        return nums.size();
    }
};




int main(int argc, char const *argv[]){
    vector<int> ls = {0,12,12,4,135,25,2,1231};
    Solution c = Solution();
    cout << c.removeElement(ls, 2) <<endl;
    for (auto i = ls.begin(); i != ls.end(); i++) {
        cout << *i << " ";
    }
    return 0;
}