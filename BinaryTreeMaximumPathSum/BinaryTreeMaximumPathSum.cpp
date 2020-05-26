//
// Created by Vigo Wong on 22/5/20.
//

// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int getForwardPathMax(TreeNode *root) {
        if (!root) {
            return 0;
        } else {
            int lmax = root->val + getForwardPathMax(root->left);
            int rmax = root->val + getForwardPathMax(root->right);
            return lmax > rmax ? lmax : rmax;
        }
    }


    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        int lpath = root->left ? getForwardPathMax(root->left) : 0;
        int rpath = root->right ? getForwardPathMax(root->right):0;
        int lmax = root->left ? maxPathSum(root->left):0;
        int rmax = root->right ? maxPathSum(root->right):0;
        return max((lmax +rmax) + root->val , max(lmax, rmax));
    }
};

int main(int argc, char const *argv[]){

    return 0;
}