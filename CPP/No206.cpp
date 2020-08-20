/**
 * Created by Xiaozhong on 2020/8/20.
 * Copyright (c) 2020/8/20 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "simple_node.h"

using namespace std;

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *p_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = p_next;
        }
        return prev;
    }
};