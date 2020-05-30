//
// Created by Vigo Wong on 30/5/20.
//
#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // most inefficient
        if (!headA || !headB) return nullptr;
        ListNode *temp = headA;
        while (temp) {
            if (temp == headB)return headB;
            temp = temp->next;
        }
        temp = headB;
        while (temp) {
            if (temp == headA)return headA;
            temp = temp->next;
        }
        return getIntersectionNode(headA->next, headB->next);
    }

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }

    ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
        ListNode *temp = headA;
        int l1 = 0;
        while (temp) {
            l1++;
            temp = temp->next;
        }
        temp = headB;
        int l2 = 0;
        while (temp) {
            l2++;
            temp = temp->next;
        }
        if (l1 > l2) {
            for (int i = 0; i < l1 - l2; i++) {
                headA = headA->next;
            }
        } else {
            for (int i = 0; i < l2 - l1; i++) {
                headB = headB->next;
            }
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};