//
// Created by Vigo Wong on 10/5/20.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int pos = 0;
        string ret = "";
        while (pos != path.size()) {
            if (path[pos] == '/') {
                if (ret.empty() || (!ret.empty() && ret[ret.size() - 1] != '/'))
                    ret += '/';

            } else if (path[pos] == '.') {
                if (path[pos + 1] == '.') {
                    pos = pos + 2;
                    if (ret.length() > 2)
                        ret = ret.substr(0, ret.size()-2);
                    continue;
                }
            } else{
                ret += path[pos];
            }
            pos++;
        }
        if(ret[ret.size()-1] == '/' && ret.size() != 1)ret = ret.substr(0, ret.size()-1);
        return ret;
    }
};


int main(int argc, char const *argv[]){
    Solution s = Solution();
    cout << s.simplifyPath("/a/./b/../../c/");
    return 0;
}