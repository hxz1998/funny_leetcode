/**
 * Created by Xiaozhong on 2020/9/22.
 * Copyright (c) 2020/9/22 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "stack"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> num1, num2;
        while (l1) {
            num1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            num2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode *ans = nullptr;
        while (!num2.empty() or !num1.empty() or carry) {
            int a = num1.empty() ? 0 : num1.top();
            int b = num2.empty() ? 0 : num2.top();
            if (!num1.empty()) num1.pop();
            if (!num2.empty()) num2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
            auto curNode = new ListNode(cur);
            curNode->next = ans;
            ans = curNode;
        }
        return ans;
    }
};
