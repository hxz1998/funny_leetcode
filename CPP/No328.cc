/**
 * Created by Xiaozhong on 2020/8/28.
 * Copyright (c) 2020/8/28 Xiaozhong. All rights reserved.
 */

#include "vector"
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
    ListNode *oddEvenList(ListNode *head) {
        // 当链表为空 [] 、只有一个 [1] 、或者只有两个 [1, 2] 时 ，不需要进行处理，直接返回
        if (!head || !head->next || !head->next->next) return head;
        /**
         * odd_head     记录奇数链表开始的地方，最后用来返回
         * odd          记录奇数链表最后一个位置，用来和下一个节点相连，以及奇偶链表拼接
         * even_head    记录偶数链表开始的地方，最后需要和 odd 进行连接
         * even         记录偶数链表最后一个位置，用来和下一个节点相连，以及最后需要补 nullptr，防止时间超限
         * curr         从头到尾遍历整个链表，表示待处理的节点
         */
        ListNode *odd_head = head, *odd = head;
        ListNode *even_head = head->next, *even = head->next;
        ListNode *curr = even_head->next;

        int count = 3;  // 表示当前链表节点的奇偶值
        while (curr) {
            if (count & 1) {        // 如果为奇数，那么就更新奇链表
                odd->next = curr;
                odd = odd->next;
            } else {                // 否则就更新偶链表
                even->next = curr;
                even = even->next;
            }
            count++;                // 更新节点计数器以及下个要处理的节点
            curr = curr->next;
        }
        odd->next = even_head;      // 奇偶拼接 + 偶链表末端补 nullptr
        even->next = nullptr;
        return odd_head;
    }
};