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

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *current = head;
        while (current && current->next) {
            if (current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};

int main() {
    Solution s;

    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(1);
    ListNode *l3 = new ListNode(2);
    ListNode *l4 = new ListNode(3);
    ListNode *l5 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    ListNode *head = s.deleteDuplicates(l1);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}