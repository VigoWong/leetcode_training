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

    int minCut(string s) {
        vector<int> ls( s.size(), -1);
        vector<int> cutPos( s.size(), -1);

        for(int i=0; i<s.size(); i++){
            string temp = s.substr(0, i+1);
            if(isPalindrome(temp)){
                ls[i] = 0;
                cutPos[i] = i;
            }
            else{
                if(isPalindrome(temp.substr(cutPos[i-1],temp.size()-1))){
                    ls[i] = ls[i-1];
                    cutPos[i] = cutPos[i-1];
                }else{
                    ls[i] = ls[i-1] + 1;
                    cutPos[i] = i;
                }

            }
        }
        return ls[s.size()-1];
    }
};


int main(int argc, char const *argv[]){
    string s = "aabaabcc";
    Solution a = Solution();
    cout << a.minCut(s);
    return 0;
}