//
// Created by Vigo Wong on 16/5/20.
//
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())return false;
        int n1 = s1.size() + 1, n2 = s2.size() + 1, n3 = s3.size();
        vector<vector<bool>> arr(n1, vector<bool>(n2, false));

        arr[0][0] = true;
        for (int i = 1; i < n1; i++){
            arr[i][0] = (arr[i-1][0] && (s3[i-1] == s1[i-1]));
        }
        for (int i = 1; i < n2; i++){
            arr[0][i] = (arr[0][i-1] && (s3[i-1] == s2[i-1]));
        }
        for(int i = 1; i < n1; i++){
            for(int j = 1; j < n2; j++){
                arr[i][j] = (arr[i-1][j] && s1[i-1] == s3[i-1+j]) || (arr[i][j-1] && s2[j-1] == s3[i-1+j]);
            }
        }
        return arr[n1-1][n2-1];
    }
};


int main(int argc, char const *argv[]){
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbbaccc";
    Solution s = Solution();
    string a = s.isInterleave(s1, s2, s3)?"true":"false";
    cout << a;
    return 0;
}