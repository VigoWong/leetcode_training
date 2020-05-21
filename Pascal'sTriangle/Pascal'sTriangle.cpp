//
// Created by Vigo Wong on 21/5/20.
//


#include <algorithm>
#include <vector>
#include <iostream>

// Definition for a Node.
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows, vector<int>(1, 1));
        for (int i = 1; i < numRows; i++) {
            ret[i].resize(i+1, 1);
        }
        if (numRows == 1 || numRows == 2)return ret;
        for (int i = 2; i < numRows; i++) {
            for (int j = 1; j < i; j++) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    vector<vector<int>> a = s.generate(6);
    for(auto i:a){
        for (auto j:i){
            cout << j;
        }
        cout << endl;
    }
    return 0;
}