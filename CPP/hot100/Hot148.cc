/*
 * Created by Xiaozhong on 2/25/2022.
 * Copyright (c) 2/25/2022 Xiaozhong. All rights reserved.
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
    ListNode *sortList(ListNode *head) {
        int length = 0;
        ListNode *curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            length++;
        }
        ListNode *dummy = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            curr = dummy->next;
            ListNode *prev = dummy;
            while (curr != nullptr) {
                ListNode *head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; ++i) curr = curr->next;

                ListNode *head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; ++i) curr = curr->next;
                ListNode *next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode *merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) prev = prev->next;
                curr = next;
            }
        }
        return dummy->next;
    }

private:
    ListNode *merge(ListNode *node1, ListNode *node2) {
        // 合并两个无序链表
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val <= node2->val) {
                curr->next = node1;
                node1 = node1->next;
            } else {
                curr->next = node2;
                node2 = node2->next;
            }
            curr = curr->next;
        }
        if (node1 != nullptr) curr->next = node1;
        else if (node2 != nullptr) curr->next = node2;
        return dummy->next;
    }
};