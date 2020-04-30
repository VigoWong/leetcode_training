//
// Created by Vigo Wong on 29/4/20.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> p;
        // setting the boundary
        int u = 0, d = matrix.size()-1;
        int l = 0, r = matrix[0].size()-1;
        char direction = 'r';
        int cur_x = 0, cur_y = 0;
        while (u <= d && l <= r) {
            switch (direction) {
                case 'r':
                    for (int i = l; i <= r; i++) {
                        p.push_back(matrix[u][i]);
                    }
                    u++;
                    direction = 'd';
                    continue;
                case 'd':
                    for (int i = u; i <= d; i++) {
                        p.push_back(matrix[i][r]);
                    }
                    r--;
                    direction = 'l';
                    continue;
                case 'l':
                    for (int i = r; i >= l; i--) {
                        p.push_back(matrix[d][i]);
                    }
                    d--;
                    direction = 'u';
                    continue;
                case 'u':
                    for (int i = d; i >= u; i--) {
                        p.push_back(matrix[i][l]);
                    }
                    l++;
                    direction = 'r';
                    continue;
            }
        }
        for (auto c:p) { cout << c << ' '; }
        return p;
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int> > newOne(3, vector<int>(4, 0));
    newOne[0][0] = 1;
    newOne[0][1] = 2;
    newOne[0][2] = 3;
    newOne[0][3] = 4;
    newOne[1][0] = 5;
    newOne[1][1] = 6;
    newOne[1][2] = 7;
    newOne[1][3] = 8;
    newOne[2][0] = 9;
    newOne[2][1] = 10;
    newOne[2][2] = 11;
    newOne[2][3] = 12;
//    newOne[3][0] = 13;
//    newOne[3][1] = 14;
//    newOne[3][2] = 15;
//    newOne[3][3] = 16;
    Solution c;
    c.spiralOrder(newOne);
    return 0;
}

