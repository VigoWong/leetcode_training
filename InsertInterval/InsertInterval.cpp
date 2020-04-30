//
// Created by Vigo Wong on 30/4/20.
//


#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newIn(intervals);
        newIn.push_back(newInterval);
        sort(newIn.begin(), newIn.end());

        vector<vector<int>> ret;
        auto i = newIn.begin();
        ret.push_back(*i);

        for (i = i + 1; i != newIn.end(); ++i) {
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