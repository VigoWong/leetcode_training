//
// Created by Vigo Wong on 1/5/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        char direction = 'r';
        int l, r, d, u;
        l = 0;
        r = n - 1;
        d = n - 1;
        u = 0;
        int count = 0;
        while (l <= r && u <= d) {
            switch (direction) {
                case 'r':
                    for (int i = l; i <= r; i++) {
                        ret[u][i] = ++count;
                    }
                    u++;
                    direction = 'd';
                    continue;
                case 'd':
                    for (int i = u; i <= d; i++) {
                        ret[i][r] = ++count;
                    }
                    direction = 'l';
                    r--;
                    continue;
                case 'l':
                    for (int i = r; i >= l; i--) {
                        ret[d][i] = ++count;
                    }
                    direction = 'u';
                    d--;
                    continue;

                case 'u':
                    for (int i = d; i >= u; i--) {
                        ret[i][l] = ++count;
                    }
                    direction = 'r';
                    l++;
                    continue;
            }
        }
        for (auto c:ret) {
            for (auto a:c) {
                cout << a << " ";
            }
            cout << endl;
        }
    }
};


int main(int argc, char const *argv[]) {
    int n = 3;
    Solution a = Solution();
    a.generateMatrix(n);
    return 0;
}