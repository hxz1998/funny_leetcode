/**
 * Created by Xiaozhong on 2020/8/23.
 * Copyright (c) 2020/8/23 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode *node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};