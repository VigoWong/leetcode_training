//
// Created by Vigo Wong on 5/5/20.
//
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> ret;
        int cur = 0;
        int last = 0;
        int left = maxWidth;
        int nums = 0;
        int space = 0;
        int extraSpace = 0;
        while (cur < words.size()) {
            last = cur;
            string cur_w = "";
            while ((left+1) >= 0 && cur <= words.size()) {
                left -= (words[cur].size() + 1);
                cur++;
            }
            cur--;
            if (cur == words.size()) {
                for (int i = last; i < cur; i++) {
                    cur_w += words[i];
                    cur_w += " ";
                }
                while (cur_w.size() < maxWidth){
                    cur_w+=" ";
                }
                ret.push_back(cur_w);
                break;
            }
            left += (words[cur].size() + 2);
            nums = cur - last;

            if (nums != 1) {
                space = left / (nums - 1);
                extraSpace = left - ((nums - 1) * space);
                for (int i = last; i < cur; i++) {
                    cur_w += words[i];
                    if (i != cur - 1) {
                        for (int j = 0; j <= space; j++) {
                            cur_w += " ";
                        }
                        if (extraSpace) {
                            cur_w += " ";
                            extraSpace--;
                        }
                    }
                }

            } else {
                cur_w += words[last];
                while (cur_w.size() != maxWidth) {
                    cur_w += " ";
                }
            }

            ret.push_back(cur_w);
            left = maxWidth;
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution a = Solution();
    vector<string> input = {"Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> ret = a.fullJustify(input, 20);

    for (auto b:ret) {
        cout <<"\""<< b << "\"" << endl;
    }
    return 0;
}