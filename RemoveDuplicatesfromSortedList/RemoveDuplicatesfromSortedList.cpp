//
// Created by Vigo Wong on 13/5/20.
//

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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;
        else {
            ListNode *cur = head;
            ListNode *next = head->next;
            if (!next) return head;
            else {
                while (next) {
                    if (cur->val == next->val) {
                        int curval = next->val;
                        while (next && next->val == curval) {
                            next = next->next;
                        }
                        cur->next = next;
                        if (next) next = next->next;
                    } else {
                        cur = next;
                        next = next->next;
                    }
                }
            }
            return head;
        }
    }
};


int main(int argc, char const *argv[]) {
    Solution s = Solution();

    return 0;
}