//
// Created by Vigo Wong on 29/4/20.
//
#include <iostream>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swap(ListNode *fir, ListNode* sed){
        if(!fir && !sed) return fir;
        if(!sed) return fir;
        else{
            ListNode* next_fir = sed -> next;
            ListNode* next_sed = nullptr;
            if(next_fir) next_sed = next_fir -> next;
            sed -> next = fir;
            fir -> next = swap(next_fir, next_sed);

            return sed;
        }
    }

    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        else {
            ListNode *p = head;
            ListNode *q = head->next;
            if(!q) return p;
            return swap(p, q);
        }
    }
};