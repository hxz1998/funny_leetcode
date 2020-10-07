/**
 * Created by Xiaozhong on 2020/8/23.
 * Copyright (c) 2020/8/23 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        vector<int> list;
        while (head) {  // 将数据存到数组里面
            list.push_back(head->val);
            head = head->next;
        }
        int left = 0, right = list.size() - 1;
        while (left < right) {  // 对数组进行遍历检查
            if (list[left++] != list[right--]) return false;
        }
        return true;
    }
};
