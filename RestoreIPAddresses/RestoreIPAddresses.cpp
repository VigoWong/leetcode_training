//
// Created by Vigo Wong on 15/5/20.
//
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    bool isvalid(string a){
        if(a.size() > 1 && a[0] == '0')return false;
        int num = stoi(a);
        return num <= 255;
    }


    void recur(string cur, int num, string left, vector<string> &ret) {
        if (left.empty() || num >= 4)ret.push_back(cur.substr(1, cur.size() - 1));
        if (left.size() > (4 - num) * 3) return;
        if(num == 3){
            if(isvalid(left))
                recur(cur + "." + left, num+1, "", ret);
            return;
        }else{
            for(int len = 1 ; len < 4; ++len){
                if(left.size()>=len && isvalid(left.substr(0, len))){
                    string temp = left.substr(0, len);
                    recur(cur + "." + temp, num+1, left.substr(len, left.size() - 1), ret);
                }
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        string cur = "";
        string left = s;
        vector<string> ret;
        int num = 0;
        recur(cur, num, left, ret);
        return ret;
    }
};


int main(int argc, char const *argv[]) {
    Solution s = Solution();
    string input = "25525511135";
    vector<string> ret = s.restoreIpAddresses(input);
    for(auto a:ret){
        cout << a << endl;
    }
    return 0;
}
