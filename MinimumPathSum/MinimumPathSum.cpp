//
// Created by Vigo Wong on 3/5/20.
//
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


class Solution {
public:
    static int min(int &a, int &b) {
        return (a > b) ? b : a;
    }

    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (m <= 0 || n <= 0)return 0;
        if ((m == 1) || (n == 1)) return 1;
        vector<vector<int>> matrix(n, vector<int>(m, 0));

        matrix[n-1][m-1] = grid[n-1][m-1];

        for (int i = m - 2; i >= 0; i--) {
            matrix[n - 1][i] = matrix[n - 1][i + 1] + grid[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--) {
            matrix[i][m - 1] = matrix[i + 1][m - 1] + grid[i][m - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                matrix[i][j] = grid[i][j] + min(matrix[i][j + 1], matrix[i + 1][j]);
            }
        }
        return matrix[0][0];
    }
};

int main(int argc, char const *argv[]){
    vector<vector<int>> ob = {
            {1,3,1},
            {1,5,1},
            {4,2,1}
    };
    Solution a = Solution();
    cout << a.minPathSum(ob);
    return 0;
}