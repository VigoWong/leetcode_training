//
// Created by Vigo Wong on 14/5/20.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
//    vector<int> recur(int n, vector<int> &ret, bool reverse, int cur, int pos) {
//        if (!reverse) {
//            cur |= 1 << pos++;
//            ret.push_back(cur);
//            if (pos == n) {
//                reverse = true;
//                pos = 0;
//            }
//        } else {
//            cur &= ~(1 << pos++);
//            if (pos == n) {
//                return ret;
//            }
//            ret.push_back(cur);
//        }
//        return recur(n, ret, reverse, cur, pos);
//    }


//    vector<int> grayCode(int n) {
//        int cur = 1, pos = 0;
//        vector<int> ret = {0};
//        if (n == 0)
//            return ret;
//        bool flagReverse = false;
//        recur(n,ret, flagReverse, cur, pos );
//        return ret;
//    }
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < pow(2,n); ++i) {
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();

    vector<int> ret = s.grayCode(3);
    for (auto a:ret) {
        cout << a << " ";
    }
    return 0;
}