//
// Created by Vigo Wong on 22/5/20.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool neighbor(string s1, string s2) {
        int count = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i])count++;
        }
        return (s1.size()-count) <= 1;
    }

    int recur(int distance, string cur, string target, vector<bool> visit, vector<string> &wordList) {
        if(neighbor(cur, target))return distance+1;
        else{
            int max = 0;
            for(int i = 0; i < wordList.size(); i++){
                if(neighbor(cur, wordList[i]) && !visit[i]){
                    int curmax;
                    visit[i] = true;
                    curmax = recur(distance+1, wordList[i], target, visit, wordList);
                    if(curmax > max)  max  = curmax;
                }
            }
            return max;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        auto a = find(wordList.begin(), wordList.end(), endWord);
        if(a==wordList.end())return 0;
        vector<bool> visit(wordList.size(), false);
        return recur(0, beginWord, endWord, visit, wordList);

    }
};

int main(int argc, char const *argv[]){
    Solution a = Solution();
    string beginWord = "hit",  endWord = "cog" ;
    vector<string> wordList = {"hot","dot","dog","lot","log"};
    cout << a.ladderLength(beginWord, endWord, wordList);
    return 0;
}