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
    bool recur(string s, unordered_set<string> m,vector<string> wordDict ){
        if (m.count(s)) return true;
        for(int i = 0; i <= s.size();i++){
            auto a = find(wordDict.begin(), wordDict.end(), s.substr(0, i));
            if(m.count(s.substr(0, i)) && recur(s.substr(i, s.size()),m,wordDict)) return true;
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        return recur(s, m, wordDict);
    }
};


int main(int argc, char const *argv[]){
    string s = "catsanddog";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    Solution a = Solution();
    string flag = a.wordBreak(s, wordDict) ? "true" : "false";
    cout << flag;
    return 0;
}