/**
 * Created by Xiaozhong on 2020/7/22.
 * Copyright (c) 2020/7/22 Xiaozhong. All rights reserved.
 */

#include <iostream>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr) return head;


        ListNode *current = head;
        int n = 1;
        while (current->next != nullptr) {
            current = current->next;
            n++;
        }
        current->next = head;   // 连接成环
        ListNode *new_head = head;
        ListNode *new_tail = head;
        for (int i = 0; i < n - k % n - 1; ++i) {
            new_tail = new_tail->next;
        }
        new_head = new_tail->next;
        new_tail->next = nullptr;
        return new_head;
    }
};

int main() {
    ListNode listNode1(1);
    ListNode listNode2(2);
    ListNode listNode3(3);
    ListNode listNode4(4);
    ListNode listNode5(5);
    listNode1.next = &listNode2;
    listNode2.next = &listNode3;
    listNode3.next = &listNode4;
    listNode4.next = &listNode5;
    listNode5.next = nullptr;
    Solution s;
    ListNode *head = s.rotateRight(&listNode1, 2);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}