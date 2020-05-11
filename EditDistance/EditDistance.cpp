//
// Created by Vigo Wong on 11/5/20.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int min(int a, int b) {
        return a > b ? b : a;
    }

    int minDistance(string word1, string word2) {
        int m = word1.size() + 1, n = word2.size() + 1;
        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; i++) { dp[i][0] = i; }
        for (int i = 0; i < n; i++) { dp[0][i] = i; }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]))+1;
                }
            }
        }
        return dp[m-1][n-1];
    }
};


int main(int argc, char const *argv[]){
    Solution s = Solution();
    cout << s.minDistance("intention", "execution");
    return 0;
}