/*
 * Created by Xiaozhong on 12/11/2021.
 * Copyright (c) 12/11/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 这种哈希表映射的方法，使用了很多额外的空间，不是很好
/*
class Solution {
private:
    // 映射源节点-新节点
    unordered_map<Node *, Node *> mapper;
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) return nullptr;
        if (!mapper.count(head)) {
            Node *node = new Node(head->val);
            mapper[head] = node;
            node->next = copyRandomList(head->next);
            node->random = copyRandomList(head->random);
        }
        return mapper[head];
    }
};*/

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) return nullptr;
        Node *curr = head;
        // 先复制整个链表的 next 连接关系
        while (curr != nullptr) {
            Node *tmp = new Node(curr->val);
            tmp->next = curr->next;
            curr->next = tmp;
            curr = tmp->next;
        }
        curr = head;
        // 链接新链表的 random
        while (curr != nullptr) {
            Node *randomNext = curr->random == nullptr ? nullptr : curr->random->next;
            curr->next->random = randomNext;
            curr = curr->next->next;
        }
        // 拆分
        Node *dummy = new Node(-1);
        Node *currHead = head;
        dummy->next = head->next;
        curr = head->next;

        while (curr != nullptr && curr->next != nullptr && currHead != nullptr && currHead->next != nullptr) {
            currHead->next = currHead->next->next;
            currHead = currHead->next;
            curr->next = curr->next->next;
            curr = curr->next;
        }
        currHead->next = nullptr;
        return dummy->next;
    }
};