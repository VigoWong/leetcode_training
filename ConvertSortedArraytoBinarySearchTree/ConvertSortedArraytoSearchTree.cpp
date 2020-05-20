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
    TreeNode *recur(vector<int> &nums, int start, int end){
        if(start > end) return nullptr;
        int mid = start + (start - end) / 2;
        auto *currentNode = new TreeNode(nums[mid]);
        currentNode ->left = recur(nums,start, mid-1);
        currentNode ->right = recur(nums, mid +1 , end);
        return currentNode;
    }


    TreeNode *sortedArrayToBST(vector<int> &nums) {
        int start = 0;
        int end = nums.size()-1;
        TreeNode *ret = recur(nums, start, end);
        return ret;
    }
};