//
// Created by Vigo Wong on 24/5/20.
//
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 1)return true;
        int start = 0, end = s.size() - 1;
        while (start <= end) {
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void recur(vector<vector<string>> &ret, string leftS, vector<string> cur) {
        if (leftS.empty()) {
            ret.push_back(cur);
            return;
        }
        if(leftS.size()==1){
            cur.push_back(leftS);
            ret.push_back(cur);
            return;
        }
        for (int i = 1; i < leftS.size(); i++) {
            string temp = leftS.substr(0, i);

            if(isPalindrome(temp)){
                cur.push_back(temp);
                recur(ret, leftS.substr(i, leftS.size()-1), cur);
                cur.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> cur;
        recur(ret, s, cur);
        return ret;
    }
};



int main(int argc, char const *argv[]){
    string s = "aab";
    Solution a = Solution();
    cout << s;
    vector<vector<string>> ret = a.partition(s);
    for(auto b:ret){
        for(auto c:b){
            cout << c;
        }
        cout << endl;
    }
    return 0;
}
