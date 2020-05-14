//
// Created by Vigo Wong on 12/5/20.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:

    bool
    dfsSearching(vector<vector<bool>> visit, map<char, int> mp, int i, int j, vector<vector<char>> board, string word) {
        if (mp.empty()) return true;
        else {
            visit[i][j] = true;
            if (word.find(board[i][j])!=word.npos) {
                mp[board[i][j]] -= 1;
                if (mp[board[i][j]] == 0) mp.erase(board[i][j]);
            } else {
                return false;
            }
            if(i > 0 && !visit[i-1][j]){if (dfsSearching(visit, mp, i -1, j, board, word)) return true;}
            if(j > 0 && !visit[i][j-1]){if (dfsSearching(visit, mp, i, j-1, board, word)) return true;}
            if(i < board.size() -1 && !visit[i+1][j]){if (dfsSearching(visit, mp, i + 1, j, board, word)) return true;}
            if(j < board[0].size()-1 && !visit[i][j+1]){if (dfsSearching(visit, mp, i, j+1, board, word)) return true;}

        }
        return false;
    }


    bool exist(vector<vector<char>> &board, string word) {
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        map<char, int> mp;
        map<char, int>::iterator cur;
        for (int i = 0; i < word.size(); i++) {
            if ((cur = mp.find(word[i])) == mp.end()) {
                mp.insert(pair<char, int>(word[i], 1));
            } else {
                mp[word[i]] += 1;
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (!visit[i][j] && word.find(board[i][j])!=word.npos) {
                    if (dfsSearching(visit, mp, i, j, board, word)) return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    string word = "ABCB";
    string flag = s.exist(board, word) ? "true" : "flase";
    cout << flag;
    return 0;
}