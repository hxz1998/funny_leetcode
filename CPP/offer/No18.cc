/*
 * Created by Xiaozhong on 12/3/2021.
 * Copyright (c) 12/3/2021 Xiaozhong. All rights reserved.
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
    ListNode *deleteNode(ListNode *head, int val) {
        ListNode *curr = head;
        while (curr != nullptr) {
            if (curr->val == val) break;
            else curr = curr->next;
        }
        while (curr->next != nullptr) {
            curr->val = curr->next->val;
        }
        curr->next = nullptr;
        return head;
    }
};