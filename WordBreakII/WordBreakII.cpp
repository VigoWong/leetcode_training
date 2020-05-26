//
// Created by Vigo Wong on 25/5/20.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void recur(string s, string cur, unordered_set<string> m,  vector<string> &ret) {
        if (s.empty()) {
            ret.push_back(cur);
            return;
        }
        for (int i = 0; i <= s.size(); i++) {
            if (m.count(s.substr(0, i))) {
                string temp = cur;
                if(!cur.empty())temp += " ";
                temp = temp + s.substr(0, i);
                recur(s.substr(i, s.size()), temp, m, ret);
            }
        }
        cur.clear();
    }

    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        vector<string> ret;
        string temp = s;
        recur(temp, "", m, ret);
        return ret;
    }
};


int main(int argc, char const *argv[]) {
    string s = "catsandog";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    Solution a = Solution();
    vector<string> ret = a.wordBreak(s, wordDict);
    for(auto r:ret){
        cout << r;
        cout << endl;
    }
    return 0;
}