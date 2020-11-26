/**
 * Created by Xiaozhong on 2020/11/26.
 * Copyright (c) 2020/11/26 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        vector<ListNode *> ans;
        ListNode *cur = root;
        int n = 0;
        // 首先统计有多少个节点
        while (cur) {
            ++n;
            cur = cur->next;
        }
        // width 代表每一个新的链表块至少有多少个元素
        // remainder 代表从前往后有多少个元素需要多放一个元素进来
        int width = n / k, remainder = n % k;
        cur = root;
        // 从前往后挨个创建
        for (int i = 0; i < k; ++i) {
            // head 是伪头部节点，writer 是用来更新节点的
            ListNode *head = new ListNode(0), *writer = head;
            for (int j = 0; j < width + (i < remainder ? 1 : 0); ++j) {
                writer = writer->next = new ListNode(cur->val);
                if (cur != nullptr) cur = cur->next;
            }
            ans.emplace_back(head->next);
        }
        return ans;
    }
};