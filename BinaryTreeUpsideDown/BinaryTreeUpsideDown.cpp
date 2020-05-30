//
// Created by Vigo Wong on 30/5/20.
//

#include <algorithm>
#include <vector>
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
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        // recursion
        if(!root || !root->right)
            return root;
        TreeNode *head = root ->left;
        TreeNode *temp = upsideDownBinaryTree(root->left);
        head -> left = root->right;
        head->right = root;
        root ->left = nullptr;
        root ->right = nullptr;
        return temp;
    }
};