//
// Created by Vigo Wong on 13/5/20.
//
using namespace std;

#include "vector"
#include "iostream"
#include "stack"
#include "algorithm"

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int res = 0;
        vector<int> height;
        for (int i = 0; i < matrix.size(); ++i) {
            height.resize(matrix[i].size());
            for (int j = 0; j < matrix[i].size(); ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }

    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> s;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (s.empty() || height[s.top()] <= height[i]) s.push(i);
            else {
                int tmp = s.top();
                s.pop();
                res = max(res, height[tmp] * (s.empty() ? i : (i - s.top() - 1)));
                --i;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();

    vector <vector<char>> aa = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };
    cout << s.maximalRectangle(aa);

    return 0;
}
