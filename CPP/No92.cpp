/**
 * Created by Xiaozhong on 2020/7/30.
 * Copyright (c) 2020/7/30 Xiaozhong. All rights reserved.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {};
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *node = new ListNode(0);
        node->next = head;
        ListNode *guard = node;
        ListNode *point = head;
        for (int i = 0; i < m - 1; i++)
            guard = guard->next;
        point = guard->next;

        for (int i = m; i < n; i++) {
            ListNode *remove = point->next;
            point->next = point->next->next;
            remove->next = guard->next;
            guard->next = remove;
        }
        return node->next;
    }
};

