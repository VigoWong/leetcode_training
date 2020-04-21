//
// Created by Vigo Wong on 21/4/20.
//
#include "stdlib.h"
#include "stdio.h"
#include "assert.h"


typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} *Tree;

Tree newNode(int val) {
    Tree new = malloc(sizeof(struct TreeNode));
    assert(new != NULL);
    new->val = val;
    new->left = new->right = NULL;
    return new;
}


Tree insertTree(Tree root, int val) {
    if (root == NULL) {
        Tree new = newNode(val);
        return new;
    } else if (root->val > val) root->right = insertTree(root->right, val);
    else if (root->val < val)root->left = insertTree(root->left, val);
    return root;
}


struct TreeNode *bstFromPreorder(int *preorder, int preorderSize) {
    Tree root = NULL;
    root = insertTree(root, preorder[0]);
    for (int i = 1; i < preorderSize; i++) {
        root = insertTree(root, preorder[i]);
    }
    return root;
}

int main(int argc, char const *argv[]) {
    int preorder[] = {8, 5, 1, 7, 10, 12};
    bstFromPreorder(preorder, 6);
    return 0;
}