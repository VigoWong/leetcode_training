//
// Created by Vigo Wong on 26/5/20.
//

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *getLast(ListNode *head) {
        if (head->next->next && head->next)return getLast(head->next);
        ListNode *temp = head->next;
        head->next = nullptr;
        temp ->next = nullptr;
        return temp;
    }


    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        ListNode *cur = head;
        while (cur && cur->next && cur->next->next) {
            ListNode *temp = cur->next;
            cur->next = getLast(cur);
            cur->next->next = temp;
            cur = temp;
        }
    }
};

int main(int argc, char const *argv[]){
    ListNode *n1 =new ListNode(1);
    ListNode *n2 =new ListNode(2);
    ListNode *n3 =new ListNode(3);
    ListNode *n4 =new ListNode(4);
    ListNode *n5 =new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    Solution a = Solution();
    a.reorderList(n1);
    ListNode *head = n1;
    return 0;
}