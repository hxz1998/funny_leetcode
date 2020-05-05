//
// Created by Monkey on 2020/5/5.
//
#include "iostream"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

/*
 * 原来的小破方法
    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* tl = new ListNode(0);
            ListNode* head = tl;
            int temp = 0;
            while(true) {
                if(l1 == NULL && l2 != NULL) {
                    temp = 0 + l2->val + temp;
                    tl->val = temp % 10;
                    temp /= 10;
                    l1 = NULL;
                    l2 = l2->next;
                } else if(l1 != NULL && l2 == NULL) {
                    temp = l1->val + 0 + temp;
                    tl->val = temp % 10;
                    temp /= 10;
                    l2 = NULL;
                    l1 = l1->next;
                } else if(l1 != NULL && l2 != NULL) {
                    temp = l1->val + l2->val + temp;
                    tl->val = temp % 10;
                    temp /= 10;
                    l2 = l2->next;
                    l1 = l1->next;
                }
                if (l1 == NULL && l2 == NULL) {
                    if (temp > 0) {
                        tl->next = new ListNode(0);
                        tl = tl->next;
                        tl->val = temp;
                    }
                    break;
                }
                tl->next = new ListNode(0);
                tl = tl->next;
            }
            return head;
        }
    };
 */
// 改进后的方法
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *cursor = head;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int l1Val = l1 != nullptr ? l1->val : 0;
            int l2Val = l2 != nullptr ? l2->val : 0;
            int sum = l1Val + l2Val + carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            cursor->next = node;
            cursor = node;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;

        }
        return head->next;
    }
};

int main() {
    ListNode l1(2);
    ListNode l2(4);
    ListNode l3(3);
    l1.next = &l2;
    l2.next = &l3;

    ListNode l4(5);
    ListNode l5(6);
    ListNode l6(4);
    l4.next = &l5;
    l5.next = &l6;

    Solution s;
    ListNode *result = s.addTwoNumbers(&l1, &l4);
    while (result != nullptr) {
        cout << (*result).val << " ";
        result = result->next;
    }

}

