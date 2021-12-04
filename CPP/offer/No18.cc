/**
 * Created by Xiaozhong on 2021/12/4.
 * Copyright (c) 2021/12/4 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *curr = head, *prev = dummyHead;
        while (curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
                delete curr;
                return dummyHead->next;
            }
            curr = curr->next;
            prev = prev->next;
        }
        return dummyHead->next;
    }
};

int main() {
    ListNode *l1 = new ListNode(-3), *l2 = new ListNode(5), *l3 = new ListNode(-99);
    l1->next = l2;
    l2->next = l3;
    Solution solution;
    solution.deleteNode(l1, -3);
}