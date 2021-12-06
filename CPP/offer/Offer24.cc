/*
 * Created by Xiaozhong on 12/4/2021.
 * Copyright (c) 12/4/2021 Xiaozhong. All rights reserved.
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
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) return nullptr;
        else {
            ListNode* ans = reverseList(head, head->next);
            head->next = nullptr;
            return ans;
        }
    }

private:
    ListNode *reverseList(ListNode *prev, ListNode *curr) {
        if (curr == nullptr) return prev;
        ListNode *next = curr->next;
        curr->next = prev;
        return reverseList(curr, next);
    }
};

int main() {
    Solution s;
    ListNode *l1 = new ListNode(1), *l2 = new ListNode(2), *l3 = new ListNode(3), *l4 = new ListNode(
            4), *l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    s.reverseList(l1);
}