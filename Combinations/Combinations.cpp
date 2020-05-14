//
// Created by Vigo Wong on 12/5/20.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:

    vector<vector<int>> recur(vector<int> cur, vector<vector<int>> ret, vector<int> left, int k) {
        if (cur.size() == k) {
            ret.push_back(cur);
            return ret;
        }
        if (k - cur.size() == left.size()) {
            cur.insert(cur.end(), left.begin(), left.end());
            ret.push_back(cur);
            return ret;
        } else {
            int curpos = left.back();
            left.pop_back();
            ret = recur(cur, ret, left, k);
            cur.push_back(curpos);
            ret = recur(cur, ret, left, k);
        }
        return ret;
    }


    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] > b[0];
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> left;
        vector<int> cur;
        vector<vector<int>> ret;
        for (int i = 1; i <= n; i++) {
            left.push_back(i);
        }
        ret = recur(cur, ret, left, k);
        for (auto a:ret) {
            cout << "[ ";
            for (auto b:a) {
                cout << b << " ";
            }
            cout << "] " << endl;
        }
        sort(ret.begin(), ret.end(), cmp);
        return ret;

    }
};

int main(int argc, char const *argv[]) {
    Solution s = Solution();
    s.combine(4, 2);
    return 0;
}
