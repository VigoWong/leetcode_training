//
// Created by Vigo Wong on 12/5/20.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
//    vector<vector<int>> recur(vector<vector<int>> ret, vector<int> cur, vector<int> left) {
//        if (left.empty()) {
//            ret.push_back(cur);
//            return ret;
//        } else {
//            int curpos = left.back();
//            left.pop_back();
//            ret = recur(ret, cur, left);
//            cur.insert(cur.begin(),curpos);
//            ret = recur(ret, cur, left);
//        }
//        return ret;
//    }
//
//    vector<vector<int>> subsets(vector<int> &nums) {
//        vector<int> left = nums;
//        vector<int> cur;
//        vector<vector<int>> ret;
//        ret = recur(ret, cur, left);
//        for (auto a:ret) {
//            cout << "[ ";
//            for (auto b:a) {
//                cout << b << " ";
//            }
//            cout << "]," << endl;
//        }
//        return ret;
//    }
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ret(1);
        for (int i = 0; i < S.size(); i++) {
            int cur = ret.size();
            for (int j = 0; j < cur; j++) {
                ret.push_back(ret[j]);
                ret.back().push_back(S[i]);
            }
        }
        return ret;
    }

};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    vector<int> ls = {1, 2, 3};
    vector<vector<int> > ret = s.subsets(ls);
    for (auto a:ret) {
        for (auto b:a) {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}