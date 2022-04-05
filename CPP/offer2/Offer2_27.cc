/**
 * Created by Xiaozhong on 2022/3/16.
 * Copyright (c) 2022/3/16 Xiaozhong. All rights reserved.
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
    bool isPalindrome(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast == slow) return true;

        // 偶数
        bool isEven = fast == nullptr ? true : false;
        if (!isEven) slow = slow->next;
        ListNode *newHead = reverseList(slow);
        ListNode *curr = head, *currNewHead = newHead;
        while (currNewHead != nullptr) {
            if (curr->val != currNewHead->val) return false;
            currNewHead = currNewHead->next;
            curr = curr->next;
        }
        reverseList(newHead);
        return true;
    }

private:
    ListNode *reverseList(ListNode *head) {
        ListNode *curr = head->next;
        ListNode *prev = head;
        prev->next = nullptr;
        while (curr != nullptr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    Solution s;
    cout << s.isPalindrome(head) << endl;
}