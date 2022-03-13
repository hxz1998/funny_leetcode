/**
 * Created by Xiaozhong on 2022/3/13.
 * Copyright (c) 2022/3/13 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        stack<int> s1, s2;
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *ans = new ListNode;
        ListNode *curr = ans;
        int curry = 0;
        while (!s1.empty() || !s2.empty()) {
            int sum = (s1.empty() ? 0 : s1.top()) + (s2.empty() ? 0 : s2.top()) + curry;
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            ListNode *next = curr->next;
            curr->next = new ListNode(sum % 10);
            curr->next->next = next;
            curry = sum / 10;
            curr = ans;
        }
        if (curry != 0) {
            ListNode *next = ans->next;
            ans->next = new ListNode(curry);
            ans->next->next = next;
        }
        return ans->next;
    }
};