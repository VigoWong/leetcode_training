//
// Created by Vigo Wong on 20/5/20.
//

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void recur(TreeNode *root, int sum, int cur, vector<int> ls, vector<vector<int>> &ret) {
        if (!root)return;

        ls.push_back(root->val);
        if ((cur+root->val) == sum && !root->left && !root->right) {
            ret.push_back(ls);
        }
        recur(root->left, sum, cur + root->val, ls, ret);
        recur(root->right, sum, cur + root->val, ls, ret);
    }


    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> ls;
        recur(root, sum, 0, ls, ret);
        return ret;
    }

};