//
// Created by Vigo Wong on 10/5/20.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int pos = 0;
        bool point = false;
        bool e = false;
        bool num = false;
        bool minus = false;
        bool space = false;
        while (pos != s.size()) {
            if (s[pos] == '-' || s[pos] == '+') {
                if (minus) return false;
                if (e && s[pos - 1] != 'e') return false;
//                if (!e && !num) return false;
                minus = true;
            } else if (s[pos] == '.' ) {
                if (point || e) return false;
                if (!num) return false;
                point = true;
            } else if (s[pos] == 'e') {
                if (e) return false;
                if (!num) return false;
                e = true;
                num = false;
                minus = false;
                point = true;
            } else if ('0' <= s[pos] && s[pos] <= '9') {
                if (s[pos] == '0' && !num) {
                    if (pos != s.size() - 1 && s[pos + 1] != '.')return false;
                }
                num = true;
            } else if (s[pos] == ' ') {
                if (!space) {
                    while (s[pos] == ' ')
                        pos++;
                    space = true;
                    continue;
                } else {
                    if (pos < s.size()-1 && s[pos + 1] != ' ')return false;
                }
            } else return false;
            pos++;
        }
        return num;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    string string1 = " -90e3   ";
    s.isNumber(string1) ? cout << "true" : cout << "false";
    return 0;
}