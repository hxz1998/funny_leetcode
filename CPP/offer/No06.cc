/*
 * Created by Xiaozhong on 12/1/2021.
 * Copyright (c) 12/1/2021 Xiaozhong. All rights reserved.
 */

#include <vector>
#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

class Solution {
public:
    vector<int> reversePrint(ListNode *head) {
        vector<int> ans;
        backtrace(head, ans);
        return ans;
    }

private:
    void backtrace(ListNode *head, vector<int> &ans) {
        if (head == nullptr) return;
        backtrace(head->next, ans);
        ans.emplace_back(head->val);
    }
};

int main() {
    
}