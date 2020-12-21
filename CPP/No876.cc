/**
 * Created by Xiaozhong on 2020/12/21.
 * Copyright (c) 2020/12/21 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        // 快慢指针，fast指向下一个的下一个，slow指向下一个
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 直接返回慢指针指向的位置
        return slow;
    }
};