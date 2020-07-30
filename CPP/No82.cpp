/**
 * Created by Xiaozhong on 2020/7/29.
 * Copyright (c) 2020/7/29 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) return nullptr;        // 判断特殊情况
        ListNode *m_ptr = new ListNode(0);          // 负责修改的结点指针
        ListNode *new_head = m_ptr;                 // 记录待返回来的头结点指针
        m_ptr->next = head;
        ListNode *s_ptr = head;
        while (s_ptr != nullptr && s_ptr->next != nullptr) {
            if (s_ptr->val == s_ptr->next->val) {
                int val = s_ptr->val;
                // 一直扫描到节点数值不同为止
                while (s_ptr && s_ptr->val == val) {
                    s_ptr = s_ptr->next;
                }
                // 更新节点过来
                m_ptr->next = s_ptr;
            } else {
                // 没有扫描到一样的节点，那就一起往后走
                m_ptr = m_ptr->next;
                s_ptr = s_ptr->next;
            }
        }
        return new_head->next;
    }
};

int main() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(3);
    ListNode *l5 = new ListNode(4);
    ListNode *l6 = new ListNode(4);
    ListNode *l7 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    Solution s;
    ListNode *head = s.deleteDuplicates(l1);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}