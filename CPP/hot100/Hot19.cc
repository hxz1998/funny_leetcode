/*
 * Created by Xiaozhong on 2/21/2022.
 * Copyright (c) 2/21/2022 Xiaozhong. All rights reserved.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = head, *slow = dummy;
        while (n-- > 0) fast = fast->next;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

int main() {
    /*ListNode *l1 = new ListNode(1), *l2 = new ListNode(2);
    l1->next = l2;*/
    ListNode *l1 = new ListNode(1), *l2 = new ListNode(2), *l3 = new ListNode(3), *l4 = new ListNode(4),
            *l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    Solution s;
    cout << s.removeNthFromEnd(l1, 5) << endl;
}