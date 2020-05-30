//
// Created by Vigo Wong on 28/5/20.
//

//  Definition for singly-linked list.

#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *insert(ListNode *head, ListNode *newNode) {
        if (head->val >= newNode->val) {
            newNode->next = head;
            return newNode;
        } else if (head->val < newNode->val) {
            head->next = insert(head->next, newNode);
        }
        return head;
    }

    ListNode *insertionSortList(ListNode *head) {
        ListNode *newNode = head->next;
        head->next = nullptr;
        while (newNode) {
            ListNode *temp = newNode->next;
            newNode->next = nullptr;
            head = insert(head, newNode);
            newNode = temp;
        }
        return head;
    }
};

int main(int argc, char const *argv[]) {
    ListNode *n1 = new ListNode(4);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(1);
    ListNode *n4 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    Solution a = Solution();
    n1 = a.insertionSortList(n1);
    int b = 1;
    return 0;
}