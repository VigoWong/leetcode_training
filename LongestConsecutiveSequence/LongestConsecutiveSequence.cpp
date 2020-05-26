//
// Created by Vigo Wong on 23/5/20.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int length = 0;
        unordered_set<int> a(nums.begin(), nums.end());
        for (int i:nums) {
            if (!a.count(i)) continue;
            a.erase(i);
            int next = i + 1;
            int last = i - 1;
            int curlen = 1;
            while(a.count(next))a.erase(next++);
            while(a.count(last))a.erase(last--);
            curlen = next - last -1;
            length = max(curlen, length);
        }
        return length;
    }
};