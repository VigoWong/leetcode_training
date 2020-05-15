//
// Created by Vigo Wong on 15/5/20.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == nullptr)
            return head;
        ListNode *start = head;
        int count = 1;
        while (count + 1 < m) {
            if (start == nullptr)
                return head;
            start = start->next;
            count++;
        }

        ListNode *fir = start->next;
        if (!fir) return head;
        ListNode *sed = fir->next;
        while (count + 1 < n) {
            count++;
            ListNode *temp = sed->next;
            sed->next = fir;
            fir = sed;
            sed = temp;
        }
        start->next->next = sed;
        start->next = fir;
        return head;
    }
};