/**
 * Created by Xiaozhong on 2020/9/2.
 * Copyright (c) 2020/9/2 Xiaozhong. All rights reserved.
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head) {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int ans = head->val;    // 记录当前第一个元素的值
        int count = 1;          // 记录它的位置
        ListNode *cur = head;
        while (cur!=nullptr) {
            // 取一个随机数，当它是 count 的倍数时，记录当前 count 指向的数
            if (rand() % count == 0) ans = cur->val;
            cur = cur->next;
            ++count;
        }
        return ans;
    }

private:
    ListNode *head;
};