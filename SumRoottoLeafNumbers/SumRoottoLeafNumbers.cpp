#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
// * Definition for a binary tree node.

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
    void pathMulti(TreeNode *root, int base, vector<int> &ret) {
        if (!root->left && !root->right) {
            ret.push_back(base + root->val);
        }
        if (root->left) {
            pathMulti(root->left, (base + root->val) *10, ret);
        }
        if (root->right)
            pathMulti(root->right, (base + root->val) *10, ret);
    }


    int sumNumbers(TreeNode *root) {
        vector<int> ret;
        pathMulti(root,0, ret);
        return accumulate(ret.begin(), ret.end(), 0);
    }
};