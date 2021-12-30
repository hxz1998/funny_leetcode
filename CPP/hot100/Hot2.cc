/*
 * Created by Xiaozhong on 12/30/2021.
 * Copyright (c) 12/30/2021 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans = new ListNode(0);
        ListNode *curr = ans;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int val1 = l1 == nullptr ? 0 : l1->val;
            int val2 = l2 == nullptr ? 0 : l2->val;
            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            auto *node = new ListNode(sum % 10);
            curr->next = node;
            curr = curr->next;
        }
        if (carry != 0) curr->next = new ListNode(carry);
        return ans->next;
    }
};