//
// Created by Vigo Wong on 17/5/20.
//

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
    TreeNode *recur(vector<int> &preorder, vector<int> &inorder, int lin, int rin, int lpre, int rpre) {
        if (lpre > rpre)
            return nullptr;
        TreeNode *nt = new TreeNode(preorder[lpre]);

        for (int i = lin; i < rin; i++) {
            if (preorder[lpre] == inorder[i]) {
                nt->left = recur(preorder, inorder, lin, i - 1, lpre + 1, lpre + i);
                nt->right = recur(preorder, inorder, i + 1, rin, lpre + i - lin + 1, rpre);
                break;
            }
        }
        return nt;
    }


    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return recur(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};

int main(int argc, char const *argv[]) {
    vector<vector<int>> ret;
    Solution a = Solution();

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *temp = a.buildTree(preorder, inorder);

    return 0;
}