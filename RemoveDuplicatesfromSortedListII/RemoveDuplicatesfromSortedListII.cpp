//
// Created by Vigo Wong on 29/4/20.
//
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *RecurDeleteDuplicates(ListNode *head) {
        if (!head) return head;
        if (head->next && head->val == head->next->val) {
            while (head->next && head->val == head->next->val) {
                head = head->next;
            }
            return RecurDeleteDuplicates(head->next);
        }
        head->next = RecurDeleteDuplicates(head->next);
        return head;
    }


    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next)return head;
        ListNode *ret = new ListNode(-1, head);
        ListNode *a = ret;
        ListNode *temp = a;
        while (a->next) {
            ListNode *cur = a->next;
            while (cur->next && cur->next->val == cur->val) {
                cur = cur->next;
            }
            if (cur != a->next) a->next = cur->next;
            else a = a->next;
        }
        return ret->next;
    }
};