//
// Created by Vigo Wong on 20/5/20.
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

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    TreeNode *recur(vector<int> &inorder, vector<int> &postorder, int i1, int i2, int pos1, int pos2) {
        if (pos1 > pos2)
            return nullptr;
        int num = postorder[pos2];
        auto *cur = new TreeNode(num);
        int i = i1;
        for (; i < i2; i++) {
            if (inorder[i] == num)
                break;
        }
        cur->left = recur(inorder, postorder, i1, i - 1, pos1, pos1 + i - i1 - 1);
        cur->right = recur(inorder, postorder, i + 1, i2, pos1 + i - i1 , pos2 - 1);
        return cur;

    }


    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        TreeNode *tree = recur(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
        return tree;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    Solution a = Solution();
    TreeNode *tree = a.buildTree(inorder, postorder);
    int c = 1;
    return 0;
}