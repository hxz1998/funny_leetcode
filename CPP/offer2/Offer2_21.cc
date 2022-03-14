/**
 * Created by Xiaozhong on 2022/3/14.
 * Copyright (c) 2022/3/14 Xiaozhong. All rights reserved.
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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummyHead;
        dummyHead.next = head;
        ListNode *target = &dummyHead, *fast = head;
        while (fast != nullptr && n-- > 0) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            target = target->next;
        }
        target->next = target->next->next;
        return dummyHead.next;
    }
};

int main() {
    Solution s;
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    s.removeNthFromEnd(root, 2);
}