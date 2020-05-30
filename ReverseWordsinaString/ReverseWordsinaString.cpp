//
// Created by Vigo Wong on 29/5/20.
//
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//class Solution {
//public:
//    string reverseWords(string s) {
//        int pos = 0;
//        vector<string> ret;
//        int size = s.size();
//        while (pos < s.size()) {
//            while (s[pos] == ' ') pos++;
//            if (pos >= size) break;
//            int end = pos;
//            while (s[end] != ' ' && end < size) end++;
//            string temp = s.substr(pos, end-pos);
//            ret.push_back(s.substr(pos, end-pos));
//            if (end >= size) break;
//            pos = end;
//        }
//        string res = "";
//        for(auto a = ret.end()-1; a >= ret.begin(); a--){
//            res+=*a;
//            a != ret.begin()?res+=" ":res+="";
//        }
//        return res;
//    }
//};
//
//int main(int argc, char const *argv[]){
//    string s = "the sky is blue";
//    Solution a = Solution();
//    cout << a.reverseWords(s);
//    return 0;
//}


/* can you solve it with O(1) extra space? */

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int curIndex = 0;
        int size = s.size();
        for(int i=0; i<size; i++){
            if(s[i]!=' '){
                int j = i;
                if(curIndex!=0)s[curIndex++] = ' ';
                while(j < size && s[j]!=' '){
                    s[curIndex++] = s[j++];
                }
                reverse(s.begin()+curIndex-(j-i), s.begin()+curIndex);
                i = j;
            }
        }
        s.resize(curIndex);
        return s;
    }
};

int main(int argc, char const *argv[]){
    string s = "a good   example";
    Solution a = Solution();
    cout << a.reverseWords(s);
    return 0;
}