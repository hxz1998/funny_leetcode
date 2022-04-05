/**
 * Created by Xiaozhong on 2022/3/24.
 * Copyright (c) 2022/3/24 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

class Node {
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node *insert(Node *head, int insertVal) {
        if (head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        // 可能有一个节点，也可能有两个节点，也可能有三个节点
        Node *prev = head, *curr = head->next;
        if (prev == curr) {
            head->next = new Node(insertVal);
            head->next->next = head;
            return head;
        }
        while (!(curr->val >= insertVal && prev->val < insertVal) &&
                curr != head &&
                !(curr->val >= insertVal && prev->val > curr->val) &&
                !(curr->val < insertVal && prev->val <= insertVal && curr->val < prev->val)) {
            curr = curr->next;
            prev = prev->next;
        }
        prev->next = new Node(insertVal);
        prev->next->next = curr;
        return head;
    }
};