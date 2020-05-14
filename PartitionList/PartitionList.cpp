//
// Created by Vigo Wong on 13/5/20.
//

// Definition for singly-linked list.
#include <iostream>

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
    void printN(ListNode *head){
        if(!head)return;
        else{
            cout << head->val << " ";
            printN(head->next);
        }
    }


    ListNode *appendNode(ListNode *head, ListNode *n) {
        if (!head) return n;
        else {
            head->next = appendNode(head->next, n);
        }
        return head;
    }


    void recur(ListNode *ls, ListNode *ls1, ListNode *ls2, int x) {
        if (!ls) return ;
        else {
            ListNode *temp = ls->next;
            ls->next = nullptr;
            if (ls->val >= x) {
                ls1 = appendNode(ls1, ls);
            } else {
                ls2 = appendNode(ls2, ls);
            }
            recur(temp, ls1, ls2, x);
            return;
        }
    }


    ListNode *partition(ListNode *head, int x) {
        ListNode h1 = ListNode(0);
        ListNode h2 = ListNode(0);
        recur(head, &h1, &h2 , x);
        head = appendNode(h2.next, h1.next);
        return head;
    }
};

int main(int argc, char const *argv[]) {
    ListNode a6 = ListNode(2);
    ListNode a5 = ListNode(5, &a6);
    ListNode a4 = ListNode(2, &a5);
    ListNode a3 = ListNode(3, &a4);
    ListNode a2 = ListNode(4, &a3);
    ListNode a1 = ListNode(1, &a2);

    Solution s = Solution();
    ListNode *head = s.partition(&a1, 3);
    s.printN(head);
    return 0;
}