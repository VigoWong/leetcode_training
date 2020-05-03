//
// Created by Vigo Wong on 30/4/20.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<sstream>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        string str(s);
        int i = str.length() - 1;

        while (i >= 0 && str[i] == ' ') {
            --i;
        }

        int length = 0;
        while (i >= 0 && str[i] != ' ') {
            ++length;
            --i;
        }

        return length;


    }
};