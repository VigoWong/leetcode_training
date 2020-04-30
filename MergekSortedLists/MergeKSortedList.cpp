//
// Created by Vigo Wong on 28/4/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto cmp = [](ListNode *&a, ListNode *&b) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp);
        for (auto node:lists) {
            if (node) q.push(node);
        }
        auto *head = new ListNode(-1);
        ListNode *cur = head;
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            cur->next = t;
            cur = t;
            if (t->next)q.push(t->next);
        }
        return head->next;
    }
};