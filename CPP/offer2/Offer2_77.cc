/**
 * Created by Xiaozhong on 2022/4/2.
 * Copyright (c) 2022/4/2 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *dummyHead = new ListNode(0), *curr = dummyHead;
        ListNode *curr1 = new ListNode(0, head1);
        ListNode *curr2 = new ListNode(0, head2);
        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1->val < curr2->val) {
                curr->next = curr1;
                curr1 = curr1->next;
            } else {
                curr->next = curr2;
                curr2 = curr2->next;
            }
            curr = curr->next;
        }
        if (curr1 != nullptr) curr->next = curr1;
        if (curr2 != nullptr) curr->next = curr2;
        ListNode *ret = dummyHead->next;
        delete curr1;
        delete curr2;
        delete curr;
        delete dummyHead;
        return ret;
    }

    ListNode *sortListNode(ListNode *head, ListNode *tail) {
        if (head == nullptr) return head;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        while (fast != tail) {
            fast = fast->next;
            slow = slow->next;
            if (fast != tail) fast = fast->next;
        }
        ListNode *list1 = sortListNode(head, slow);
        ListNode *list2 = sortListNode(slow, tail);
        ListNode *list = merge(list1, list2);
        return list;
    }

public:
    ListNode *sortList(ListNode *head) {
        // 归并排序
        sortListNode(head, nullptr);
    }
};