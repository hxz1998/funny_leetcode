/*
 * Created by Xiaozhong on 3/7/2022.
 * Copyright (c) 3/7/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode *mergeTwoLists(ListNode *lhs, ListNode *rhs) {
        if (lhs == nullptr || rhs == nullptr) return lhs == nullptr ? rhs : lhs;
        ListNode head, *curr = &head;
        while (lhs != nullptr && rhs != nullptr) {
            if (lhs->val < rhs->val) {
                curr->next = lhs;
                lhs = lhs->next;
            } else {
                curr->next = rhs;
                rhs = rhs->next;
            }
            curr = curr->next;
        }
        if (lhs != nullptr) curr->next = lhs;
        else curr->next = rhs;
        return head.next;
    }

    ListNode *merge(vector<ListNode *> &lists, int left, int right) {
        if (left == right) return lists[left];
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        ListNode *ans = mergeTwoLists(lists[0], lists[1]);
        for (int idx = 2; idx < lists.size(); ++idx) ans = mergeTwoLists(ans, lists[idx]);
        return ans;
    }
};