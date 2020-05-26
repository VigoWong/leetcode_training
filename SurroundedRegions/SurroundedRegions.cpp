//
// Created by Vigo Wong on 23/5/20.
//
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visit, int i, int j) {
        visit[i][j] = true;
        board[i][j] = '1';
        if (i != 0 && !visit[i - 1][j])dfs(board, visit, i - 1, j);
        if (i != board.size() - 1 && !visit[i + 1][j])dfs(board, visit, i + 1, j);
        if (j != 0 && !visit[i][j - 1])dfs(board, visit, i, j - 1);
        if (i != board[0].size() - 1 && !visit[i][j + 1])dfs(board, visit, i, j + 1);
    }

    void solve(vector<vector<char>> &board) {
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        int height = board.size();
        int width = board[0].size();
        for (int i = 0; i < width; i++) {
            if (board[0][i] == 'O' && !visit[0][i])dfs(board, visit, 0, i);
        }
        for (int i = 0; i < width; i++) {
            if (board[height-1][i] == 'O' && !visit[height-1][i])dfs(board, visit, height-1, i);
        }

        for (int i = 0; i < height; i++) {
            if (board[i][0] == 'O' && !visit[i][0])dfs(board, visit, i, 0);
        }
        for (int i = 0; i < height; i++) {
            if (board[i][width-1] == 'O' && !visit[i][width-1])dfs(board, visit, i, width-1);
        }

        for (int i = 0; i < height; i++) {
            for(int j =0; j<width; j++){
                if(board[i][j] == '1')board[i][j] = 'O';
                else if(board[i][j] == 'O')board[i][j] = 'X';
            }
        }
    }
};

int main(int argc, char const *argv[]){

    return 0;
}