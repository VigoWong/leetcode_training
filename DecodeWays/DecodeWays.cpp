//
// Created by Vigo Wong on 14/5/20.
//
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())return 1;
        if(s.size()==1)return 1;
        else{
            int deci =  s[0] - '0';
            int one = s[1] - '0';
            if(deci >= 3 || deci == 0 || (deci == 2 && one > 6)){
                return numDecodings(s.substr(1, s.size()-1));
            }else{
                return numDecodings(s.substr(1, s.size()-1)) + numDecodings(s.substr(2, s.size()-1));
            }
        }

    }
};

int main(int argc, char const *argv[]){
    string s = "16";
    Solution so = Solution();
    cout << so.numDecodings(s);
    return 0;
}
