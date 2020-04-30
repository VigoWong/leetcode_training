//
// Created by Vigo Wong on 28/4/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        if (nums.empty() || nums.size() == 1)
            return;
        else if (nums.size() == 2) {
            std::reverse(nums.begin(), nums.end());
        }
        vector<int>::iterator last= nums.end()-1;
        vector<int>::iterator head = nums.end() - 2;;
        while (*head >= *last) {
            last--;
            head--;
            if (head == nums.begin()) {
                if (*head >= *last){
                    std::reverse(nums.begin(), nums.end());
                    return;
                }
                else break;
            }
        }
        std::iter_swap(head, last);
    }
};


int main(int argc, char const *argv[]) {
//    vector<int> ls = {1,3454,5,346,45,6,7,567,43,524,214,314,25};
    vector<int> ls = {1,2,3};
    Solution c = Solution();
    cout << ls.back()<<endl;
    c.nextPermutation(ls);
    for (auto i = ls.begin(); i != ls.end(); i++) {
        cout << *i << " ";
    }
    return 0;
}