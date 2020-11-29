/**
 * Created by Xiaozhong on 2020/11/28.
 * Copyright (c) 2020/11/28 Xiaozhong. All rights reserved.
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        ListNode *head = list1, *ptr1 = list1, *ptr2 = list2;
        int count = 0;
        while (count++ < b) ptr1 = ptr1->next;
        while (ptr2->next) { ptr2 = ptr2->next; }
        ptr2->next = ptr1->next;

        count = 0;
        ptr1 = list1, ptr2 = list2;
        while (count++ < a - 1) ptr1 = ptr1->next;
        ptr1->next = ptr2;
        return head;
    }
};

int main() {

}