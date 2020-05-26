//
// Created by Vigo Wong on 25/5/20.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* helper(Node* head, unordered_map<Node*, Node*> &m){
        if(!head) return NULL;
        if(!m.count(head)) return m[head];
        else{
            Node *clone = new Node(head->val);
            m[head] = clone;
            clone->next = helper(head->next, m);
            clone->random = helper(head->random, m);
            return clone;
        }
    }


    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        return helper(head, m);
    }
};