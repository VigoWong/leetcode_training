//
// Created by Vigo Wong on 1/5/20.
//

//1 2 3 4
//1 2 4 3
//1 3 2 4
//1 3 4 2
//


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    void dfs(vector<int> &cur, vector<bool> &visit, vector<string> &answer, int n) {
        if (cur.size() == n) {
            stringstream ss;
            for (int i = 0; i < cur.size(); i++) { ss << cur[i]; }
            answer.push_back(ss.str());
        } else {
            for (int i = 0; i < n; i++) {
                if (!visit[i]) {
                    visit[i] = true;
                    vector<int> newCur = cur;
                    newCur.push_back(i + 1);
                    dfs(newCur, visit, answer, n);
                    visit[i] = false;
                }
            }
        }
    }


    string getPermutation(int n, int k) {
        vector<bool> visit(n, false);
        vector<string> answer;
        vector<int> cur;
        dfs(cur, visit, answer, n);
        return answer[k - 1];
    }
};


int main(int argc, char const *argv[]) {
    Solution a = Solution();
    cout << a.getPermutation(3, 2);
    return 0;
}