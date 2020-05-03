//
// Created by Vigo Wong on 1/5/20.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0)return 0;
        if((m==1) || (n==1)) return 1;
        int **matrix = new int *[n];
        for(int i = 0; i<n;i++){
            matrix[i] = new int[m];
        }
        for(int i= m-1; i >= 0; i--){
            matrix[n-1][i] = 1;
        }
        for(int i= n-1; i >= 0; i--){
            matrix[i][m-1] = 1;
        }
        for(int i = n-2; i>=0; i--){
            for(int j = m-2; j>= 0; j--){
                matrix[i][j] = matrix[i+1][j] + matrix[i][j+1];
            }
        }
        return matrix[0][0];
    }
};

int main(int argc, char const *argv[]){
    Solution a = Solution();
    cout << a.uniquePaths(7,3);
    return 0;
}