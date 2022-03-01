/*
 * Created by Xiaozhong on 2/28/2022.
 * Copyright (c) 2/28/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode *curr = nullptr;
    bool ans = true;
public:
    bool isPalindrome(ListNode *head) {
        curr = head;
        helper(head);
        return ans;
    }

private:
    void helper(ListNode *head) {
        if (!ans || head == nullptr) return;
        helper(head->next);
        if (head->val != curr->val) ans = false;
        curr = curr->next;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1), *l2 = new ListNode(2);
    head->next = l2;
    cout << s.isPalindrome(head);
}