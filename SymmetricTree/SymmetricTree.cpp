//
// Created by Vigo Wong on 18/5/20.
//

#include <algorithm>
#include <iostream>
#include <vector>

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
    bool recur(TreeNode *l, TreeNode *r) {
        if (!l && r || l && !r) return false;
        if (!l && !r) return true;
        if (l->val != r->val) return false;
        else {
            if (!recur(l->left, r->right) || !recur(l->right, r->left)) return false;
            return true;
        }
    }


    bool isSymmetric(TreeNode *root) {
        return recur(root->left, root->right);
    }
};


int main(int argc, char const *argv[]) {

    return 0;
}