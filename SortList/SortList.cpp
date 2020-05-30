//
// Created by Vigo Wong on 28/5/20.
//  Definition for singly-linked list.

#include <>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *twoWayMerge(ListNode *first, ListNode *sec) {
        if (!first)return sec;
        if (!sec)return first;
        if (first->val <= sec->val) {
            first->next = twoWayMerge(first->next, sec);
            return first;
        } else {
            sec->next = twoWayMerge(first, sec->next);
            return sec;
        }
    }


    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)return head;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        return twoWayMerge(sortList(head), sortList(slow));
    }
};