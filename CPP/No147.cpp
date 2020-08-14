/**
 * Created by Xiaozhong on 2020/8/14.
 * Copyright (c) 2020/8/14 Xiaozhong. All rights reserved.
 */
#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *dummay_head = new ListNode(0);    // 伪头部节点
        dummay_head->next = head;
        ListNode *tail = head, *sort = head->next;     // tail 指向排好序的最后一个节点，sort 指向待排序的节点
        while (sort) {
            if (sort->val < tail->val) {
                ListNode *pos = dummay_head;            // 遍历定位交换节点
                while (pos->next->val < sort->val) pos = pos->next;
                tail->next = sort->next;
                sort->next = pos->next;
                pos->next = sort;
                sort = tail->next;
            } else {
                sort = sort->next;
                tail = tail->next;
            }
        }
        return dummay_head->next;
    }
};