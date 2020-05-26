//
// Created by Vigo Wong on 24/5/20.
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
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node *helper(Node *cur,unordered_map <Node *, Node *> &m){
        if(!cur) return NULL;
        if(m.count(cur)) return m[cur];
        Node *clone = new Node(cur->val);
        m[cur] = clone;
        for(Node *neighbor:cur->neighbors){
            clone ->neighbors.push_back(helper(neighbor, m));
        }
        return clone;
    }

    Node *cloneGraph(Node *node) {
        unordered_map <Node *, Node *> m;
        return helper(node, m);
    }
};