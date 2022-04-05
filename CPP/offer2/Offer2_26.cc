/**
 * Created by Xiaozhong on 2022/3/21.
 * Copyright (c) 2022/3/21 Xiaozhong. All rights reserved.
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
    void reorderList(ListNode *head) {
        queue<ListNode *> q;
        stack<ListNode *> stk;
        ListNode *curr = head;
        int sz = 0;
        while (curr != nullptr) {
            q.push(curr);
            stk.push(curr);
            curr = curr->next;
            sz++;
        }
        if (sz == 1) return;
        int stkRemain = (sz + 1) / 2;
        int qRemain = sz / 2;
        q.pop();
        curr = head;
        while (true) {
            curr->next = stk.top();
            stk.pop();
            curr = curr->next;
            curr->next = nullptr;
            if (q.size() == qRemain && stk.size() == stkRemain) {
                curr->next = nullptr;
                return;
            }
            curr->next = q.front();
            curr = curr->next;
            curr->next = nullptr;
            q.pop();
            if (q.size() == qRemain && stk.size() == stkRemain) {
                curr->next = nullptr;
                return;
            }
        }
    }
};