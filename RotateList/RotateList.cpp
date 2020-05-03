//
// Created by Vigo Wong on 1/5/20.
//

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head)
            return head;

        ListNode *tail = head;
        int count = 1;
        while (tail->next) {
            tail = tail->next;
            count++;
        }
        ListNode *temp = head;
        count -= k;
        while (count-- != 1) {
            temp = temp->next;
        }
        ListNode *newHead = temp->next;
        temp->next = nullptr;
        tail->next = head;
        return newHead;
    }
};