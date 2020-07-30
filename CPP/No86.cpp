/**
 * Created by Xiaozhong on 2020/7/29.
 * Copyright (c) 2020/7/29 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *before = new ListNode(0), *after = new ListNode(0);
        ListNode *before_bak = before, *after_bak = after;
        while (head) {
            ListNode *tmp = new ListNode(head->val);
            if (head->val < x) {
                before->next = tmp;
                before = before->next;
            } else {
                after->next = tmp;
                after = after->next;
            }
            head = head->next;
        }
        before->next = after_bak->next;
        after->next = nullptr;
        return before_bak->next;
    }
};

int main(int argc, char **args) {
    Solution s;
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(4);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(5);
    ListNode *l6 = new ListNode(2);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    ListNode *head = s.partition(l1, 3);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}