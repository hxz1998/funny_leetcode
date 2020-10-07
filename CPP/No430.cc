/**
 * Created by Xiaozhong on 2020/9/19.
 * Copyright (c) 2020/9/19 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
private:
    Node *dfs(Node *prev, Node *curr) {
        if (!curr) return prev;
        // 首先将当前节点和前一个节点连接好
        curr->prev = prev;
        prev->next = curr;
        // 记录下当前节点的下一个节点，因为在递归操作中，会把 curr 的 next 修改掉，所以先暂存，下面要进行使用
        Node *temp = curr->next;
        // 将分支进行处理
        Node *tail = dfs(curr, curr->child);
        // 断开分支
        curr->child = nullptr;
        // 从分支的尾部和 curr 原来的 next 进行处理
        return dfs(tail, temp);
    }

public:
    Node *flatten(Node *head) {
        if (!head) return head;
        // 建立一个虚拟头部节点，方便操作
        Node *pseudoHead = new Node();
        dfs(pseudoHead, head);
        // 将虚拟头部节点与主体断开连接
        pseudoHead->next->prev = nullptr;
        return pseudoHead->next;
    }
};