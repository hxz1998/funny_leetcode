/*
 * Created by Xiaozhong on 2/25/2022.
 * Copyright (c) 2/25/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA, *ptrB = headB;
        if (headA == headB) return headA;
        while (ptrA->next != nullptr || ptrB->next != nullptr) {
            ptrA = ptrA->next == nullptr ? headB : ptrA->next;
            ptrB = ptrB->next == nullptr ? headA : ptrB->next;
            if (ptrA == ptrB) return ptrA;
        }
        return nullptr;
    }
};

int main() {
    Solution s;
    ListNode *headA = new ListNode(3);
    ListNode *headB = new ListNode(2);
    headB->next = headA;
    cout << s.getIntersectionNode(headA, headB)->val << endl;
}