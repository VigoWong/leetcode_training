//
// Created by Vigo Wong on 17/5/20.
//
//  Definition for a binary tree node.
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    void recur(vector<vector<int>> &ret, int count, TreeNode *cur) {
        if (!cur) return;
        else {
            if (count + 1 <= ret.size()) {
                ret[count].push_back(cur->val);
            } else {
                vector<int> a;
                ret.push_back(a);
                ret[count].push_back(cur->val);
            }
            recur(ret, count + 1, cur->left);
            recur(ret, count + 1, cur->right);
        }

    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        int count = 0;
        vector<vector<int>> ret(0);
        if (!root)return ret;
        else recur(ret, count, root);
        for(int i = 0; i < ret.size(); i++){
            if(i %2){
                reverse(ret[i].begin(), ret[i].end());
            }
        }
        return ret;
    }
};