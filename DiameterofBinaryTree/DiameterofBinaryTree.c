/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int height(struct TreeNode *root) {
    if (root == NULL)return 0;
    int lh = height(root->left) + 1;
    int rh = height(root->right) + 1;
    return lh > rh ? lh : rh;
}


int diameterOfBinaryTree(struct TreeNode *root) {
    int lh = height(root->left);
    int rh = height(root->right);
    return lh + rh;
}
