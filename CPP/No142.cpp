/**
 * Created by Xiaozhong on 2020/8/13.
 * Copyright (c) 2020/8/13 Xiaozhong. All rights reserved.
 */

#include "simple_node.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        //　找到第一次相遇的地方，找到第一次相遇的地方
        while (true) {
            if (fast == nullptr || fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        // 将 fast 指针从新放到头部，开始定位环的入口
        fast = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};