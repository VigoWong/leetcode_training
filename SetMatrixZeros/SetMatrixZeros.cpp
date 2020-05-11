//
// Created by Vigo Wong on 11/5/20.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        vector<int> row(matrix.size());
        vector<int> col(matrix[0].size());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (!matrix[i][j]) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int r = 0; r < row.size(); r++) {
            if (row[r]) {
                for (int i = 0; i < matrix[0].size(); i++) {
                    matrix[r][i] = 0;
                }
            }
        }
        for (int c = 0; c < col.size(); c++) {
            if (col[c]) {
                for (int i = 0; i < matrix.size(); i++) {
                    matrix[i][c] = 0;
                }
            }
        }
    }
};


int main(int argc, char const *argv[]) {
    vector<vector<int>> matrix = {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
    };

    Solution s = Solution();
    s.setZeroes(matrix);

    for (auto a:matrix) {
        for (auto b:a) {
            cout << b;
        }
        cout << endl;
    }
    return 0;
}
