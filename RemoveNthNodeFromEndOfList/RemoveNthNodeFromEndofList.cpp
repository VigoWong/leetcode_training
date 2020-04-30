//
// Created by Vigo Wong on 29/4/20.
//

using namespace std;

#include <iostream>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    int NumofNode(ListNode *head) {
        if (!head)return 0;
        else {
            return 1 + NumofNode(head->next);
        }
    }

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int num = NumofNode(head);
        int count = num - n;
        ListNode *temp = head;
        while (count!=1){
            temp = temp ->next;
            count--;
        }
        ListNode *target = temp -> next;
        temp -> next = target ->next;
        target ->next = NULL;
        return target;
    }
};