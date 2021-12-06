/**
 * Created by Xiaozhong on 2021/12/4.
 * Copyright (c) 2021/12/4 Xiaozhong. All rights reserved.
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
    ListNode *getKthFromEnd(ListNode *head, int k) {
        ListNode *right = head, *left = head;
        while (k-- > 0) right = right->next;
        while (right != nullptr) {
            right = right->next;
            left = left->next;
        }
        return left;
    }
};