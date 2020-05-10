//
// Created by Vigo Wong on 10/5/20.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 2) return 2;
        else if(n == 1) return 1;
        else{
            return climbStairs(n -1) + climbStairs(n -2);
        }
    }
};

int main(int argc, char const *argv[]){
    Solution s = Solution();
    cout << s.climbStairs(5);
    return 0;
}