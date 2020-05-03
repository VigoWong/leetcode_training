//
// Created by Vigo Wong on 3/5/20.
//

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (m <= 0 || n <= 0)return 0;
        if ((m == 1) || (n == 1)) return 1;
        int **matrix = new int *[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[m];
        }
        int flag = 1;
        for (int i = m - 1; i >= 0; i--) {
            if (obstacleGrid[n - 1][i] == 1) { flag = 0; }
            matrix[n - 1][i] = flag;
        }
        flag = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (obstacleGrid[i][m - 1] == 1) { flag = 0; }
            matrix[i][m - 1] = flag;
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    matrix[i][j] = 0;
                    continue;
                }
                matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];
            }
        }
        return matrix[0][0];
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> ob = {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
    };
    Solution s = Solution();
    cout << s.uniquePathsWithObstacles(ob);
    return 0;
}