/**
 * Created by Xiaozhong on 2020/8/13.
 * Copyright (c) 2020/8/13 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "map"

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    map<Node *, Node *> mapper;
public:
    Node *copyRandomList(Node *head) {
        if (!head) return nullptr;
        if (mapper.count(head)) return mapper[head];
        Node *clone = new Node(head->val);
        mapper[head] = clone;
        clone->next = copyRandomList(head->next);
        clone->random = copyRandomList(head->random);
        return clone;
    }
};