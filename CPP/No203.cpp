/**
 * Created by Xiaozhong on 2020/8/20.
 * Copyright (c) 2020/8/20 Xiaozhong. All rights reserved.
 */

#include "simple_node.h"
#include "iostream"

using namespace std;

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *sentinel = new ListNode(0);
        sentinel->next = head;

        ListNode *prev = sentinel, *current = head, *to_delete = nullptr;
        while (current) {
            if (current->val == val) {
                prev->next = current->next;
                to_delete = current;
            } else prev = current;
            current = current->next;
            if (to_delete) {
                delete to_delete;
                to_delete = nullptr;
            }
        }

        ListNode *ans = sentinel->next;
        delete sentinel;
        return ans;
    }
};