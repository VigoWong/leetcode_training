//
// Created by Vigo Wong on 26/5/20.
//

#include <iostream>
#include <algorithm>
// * Definition for singly-linked list.
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(slow -> next && fast->next && fast->next->next){
            slow = slow ->next;
            fast = fast ->next ->next;
            if(slow == fast) return true;
        }
        return false;
    }
};