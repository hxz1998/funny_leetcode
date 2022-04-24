/**
 * Created by Xiaozhong on 2022/4/24.
 * Copyright (c) 2022/4/24 Xiaozhong. All rights reserved.
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
#include <list>
#include <random>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *solve(vector<ListNode *> &a) {
        int n = static_cast<int>(a.size());
        vector<int> arr;
        ListNode *curr = a[0];
        unordered_set<int> visited;
        int ms = INT32_MAX;
        int offset = -1;
        while (curr != nullptr) {
            arr.push_back(curr->val);
            visited.insert(curr->val);
            if (ms > curr->val) {
                ms = curr->val;
                offset = arr.size() - 1;
            }
            curr = curr->next;
        }
        unordered_set<int> used;
        used.insert(0);
        while (used.size() < n) {
            for (int idx = 0; idx < n; ++idx) {
                if (used.find(idx) != used.end() || visited.find(a[idx]->val) == visited.end()) continue;
                used.insert(idx);
                curr = a[idx];
                while (visited.find(curr->val) != visited.end()) curr = curr->next;
                while (curr != nullptr) {
                    arr.push_back(curr->val);
                    if (ms > curr->val) {
                        ms = curr->val;
                        offset = arr.size() - 1;
                    }
                    curr = curr->next;
                }
            }
        }
        ListNode *dummyHead1 = new ListNode(1), *curr1 = dummyHead1;
        ListNode *dummyHead2 = new ListNode(2), *curr2 = dummyHead2;
        for (int idx = 0; idx < arr.size(); ++idx) {
            int index = (idx + offset) % arr.size();
            curr1->next = new ListNode(arr[index]);
            curr1 = curr1->next;
        }
        for (int idx = 0; idx < arr.size(); ++idx) {
            int index = (offset - idx + arr.size()) % arr.size();
            curr2->next = new ListNode(arr[index]);
            curr2 = curr2->next;
        }
        curr1 = dummyHead1->next;
        curr2 = dummyHead2->next;
        for (int idx = 0; idx < arr.size(); ++idx) {
            if (curr1->val < curr2->val) return dummyHead1->next;
            else if (curr1->val > curr2->val) return dummyHead2->next;
        }
        return dummyHead1->next;
    }
};

int main() {
    ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(3);

    ListNode *h2 = new ListNode(2);
    h2->next = new ListNode(3);
    h2->next->next = new ListNode(4);

    ListNode *h3 = new ListNode(3);
    h3->next = new ListNode(4);

    vector<ListNode *> lists = {h2, h3, h1};
    Solution s;
    s.solve(lists);
}