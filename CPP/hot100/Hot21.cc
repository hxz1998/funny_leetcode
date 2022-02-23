/*
 * Created by Xiaozhong on 2/21/2022.
 * Copyright (c) 2/21/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode(0), *curr = dummy;
        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                curr->next = new ListNode(list2->val);
                list2 = list2->next;
            } else if (list2 == nullptr) {
                curr->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                if (list1->val < list2->val) {
                    curr->next = new ListNode(list1->val);
                    list1 = list1->next;
                } else {
                    curr->next = new ListNode(list2->val);
                    list2 = list2->next;
                }
            }
        }
        return dummy->next;
    }
};