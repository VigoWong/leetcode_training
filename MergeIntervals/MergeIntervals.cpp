//
// Created by Vigo Wong on 30/4/20.
//

#include <algorithm>
#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        auto i = intervals.begin();
        ret.push_back(*i);

        for (i = i + 1; i != intervals.end(); ++i) {
            vector<int> a = ret.back();
            if ((*i)[0] <= a[1]) {
                ret.pop_back();
                a[1] = (*i)[1];
                ret.push_back(a);
                continue;
            } else {
                ret.push_back(*i);
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution c = Solution();

    vector<vector<int>> a = {{1,4},{4,5}};
    vector<vector<int>> ret = c.merge(a);

    for (auto i:ret) {
        for (auto b:i) {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}