/**
 * Created by Xiaozhong on 2022/2/26.
 * Copyright (c) 2022/2/26 Xiaozhong. All rights reserved.
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
private:
    ListNode *helper(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *newHead = helper(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

public:
    ListNode *reverseList(ListNode *head) {
        ListNode *ret = helper(head);
        return ret;
    }
};