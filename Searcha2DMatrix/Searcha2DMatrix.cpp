//
// Created by Vigo Wong on 11/5/20.
//
using namespace std;

#include <vector>
#include <iostream>

class Solution {
public:
    int binSearch(vector<vector<int>> &matrix, int target) {
        int start = 0;
        int end = matrix.size() - 1;
        if (target > matrix[end][0])return end;
        if (target >= matrix[start][0] && target < matrix[start + 1][0]) return start;
        while (end > start) {
            int mid = (start + end) / 2;
            if (target >= matrix[mid][0] && target < matrix[mid + 1][0]) return mid;
            else if (target == matrix[mid + 1][0])return mid + 1;
            else if (target < matrix[mid][0]) end = mid;
            else if (target > matrix[mid + 1][0]) start = mid;
        }
    }


    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = binSearch(matrix, target);
        int start = 0;
        int end = matrix[row].size() - 1;
        if (target == matrix[row][0]) return true;
        if (target == matrix[row][end]) return true;
        if(target > matrix[row][end] || target < matrix[row][0])
            return false;

        int mid = (start + end) / 2;
        while (end > start) {
            if(mid == start || mid == end) break;
            if (target == matrix[row][mid]) return true;
            else if (target < matrix[row][mid]) {
                end = mid;
            } else if (target > matrix[row][mid]) {
                start = mid;
            }
            mid = (start + end) / 2;
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    vector <vector<int>> matrix = {
            {1,   3,  5,  7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
    };
    Solution s = Solution();
    string ret;
    s.searchMatrix(matrix, 60)?ret="true": ret= "false";
    cout << ret;
    return 0;
}