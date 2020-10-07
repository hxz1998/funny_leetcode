/**
 * Created by Xiaozhong on 2020/8/13.
 * Copyright (c) 2020/8/13 Xiaozhong. All rights reserved.
 */

#include "simple_node.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !(head->next)) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};