//
// Created by Vigo Wong on 21/5/20.
//

#include <algorithm>
#include <vector>
#include <iostream>

// Definition for a Node.
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *findLeftMost(Node *root){
        if(root ->left)return root->left;
        if(root ->right) return root->right;
        return nullptr;
    }

    Node *connect(Node *root) {
        if (!root || (!root->left && !root->right)) return root;
        if(root ->left && root ->right){
            root->left->next = root->right;
            if (root->next) {
                root->right->next = findLeftMost(root->next);
            }
            connect(root->left);
            connect(root->right);
        } else if (root->left){
            if (root->next) {
                root->left->next = findLeftMost(root->next);
            }
            connect(root->left);
        } else if(root->right){
            if (root->next) {
                root->right->next = findLeftMost(root->next);
            }
            connect(root->right);
        }
        return root;
    }
};