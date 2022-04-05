/**
 * Created by Xiaozhong on 2022/3/23.
 * Copyright (c) 2022/3/23 Xiaozhong. All rights reserved.
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

using namespace std;

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
public:
    Node *flatten(Node *head) {
        stack<Node *> stk;
        Node *curr = head, *prev = nullptr;
        while (curr != nullptr || !stk.empty()) {
            if (curr == nullptr) {
                curr->next = stk.top();
                stk.pop();
                prev->next = curr;
                curr->prev = prev;
            }
            if (curr->child != nullptr) {
                if (curr->next != nullptr) stk.push(curr->next);
                curr->next = curr->child;
                curr->child = nullptr;
                curr->next->prev = curr;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};