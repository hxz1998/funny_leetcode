/**
 * Created by Xiaozhong on 2020/8/14.
 * Copyright (c) 2020/8/14 Xiaozhong. All rights reserved.
 */
#include "iostream"

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
    // 先找到中间节点，然后反转，然后拼接
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        ListNode *fast = head, *slow = head;
        ListNode *half_head = find(fast, slow);
        ListNode *rev_head = reverse(half_head);
        while (rev_head) {
            ListNode *head_next = head->next, *half_next = rev_head->next;
            head->next = rev_head;
            rev_head->next = head_next;
            head = head_next;
            rev_head = half_next;
        }
    }

private:
    // 将链表翻转，返回回来的是反转过后新的头部
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // 使用快慢指针，去寻找链表的中间节点
    ListNode *find(ListNode *fast, ListNode *slow) {
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *new_head = slow->next;
        slow->next = nullptr;
        return new_head;
    }
};

int main() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    Solution s;
    s.reorderList(l1);
    ListNode *head = l1;
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}