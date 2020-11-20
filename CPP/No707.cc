/**
 * Created by Xiaozhong on 2020/11/20.
 * Copyright (c) 2020/11/20 Xiaozhong. All rights reserved.
 */
#include <iostream>

using namespace std;

class MyLinkedList {
    struct Node {
        int val = -1;
        Node *next = nullptr;

        Node(int v) : val(v), next(nullptr) {}
    };

    Node *dummy_head = nullptr; // 指向第一个伪头部节点
    Node *tail = nullptr;       // 指向最后一个元素
    int sz;                     // 容器元素多少，[0, sz]
public:
    /** Initialize your data structure here. */
    MyLinkedList() : dummy_head(nullptr), tail(nullptr) {
        dummy_head = new Node(-1);
        tail = dummy_head;
        sz = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= sz) return -1;
        Node *ptr = dummy_head->next;
        while (index--) ptr = ptr->next;
        return ptr->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *node = new Node(val);
        node->next = dummy_head->next;
        dummy_head->next = node;
        // 如果容器是空的，那么记得把 tail 指针更新到新添加的元素上来
        if (sz == 0) tail = node;
        sz++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        tail->next = new Node(val);
        tail = tail->next;
        ++sz;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == sz) addAtTail(val);
        else if (index < 0) addAtHead(val);
        else if (index > sz) return;
        else {
            Node *ptr = dummy_head;
            while (index--) ptr = ptr->next;
            Node *node = new Node(val);
            node->next = ptr->next;
            ptr->next = node;
            ++sz;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int copy_index = index;
        if (index < 0 || index >= sz) return;
        Node *ptr = dummy_head;
        while (index--) ptr = ptr->next;
        Node *tmp = ptr->next;
        ptr->next = ptr->next->next;
        delete tmp;
        // 如果删除的是最后一个节点，需要把 tail 指针指向倒数第 2 个节点
        if (sz - 1 == copy_index) tail = ptr;
        --sz;
    }
};

int main() {
    MyLinkedList list;
    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2);
    cout << list.get(1) << endl;
    list.deleteAtIndex(1);
    cout << list.get(1) << endl;

    MyLinkedList list2;
    list2.addAtHead(1);
    list2.deleteAtIndex(0);
    //["MyLinkedList",
    // "addAtHead","addAtIndex","addAtTail",
    // "addAtHead","addAtIndex","addAtTail",
    // "addAtTail","addAtIndex","deleteAtIndex",
    // "deleteAtIndex","addAtTail"]
    //[[],[0],[1,4],[8],[5],[4,3],[0],[5],[6,3],[7],[5],[4]]
    MyLinkedList list3;
    list3.addAtHead(0);
    list3.addAtIndex(1, 4);
    list3.addAtTail(8);
    list3.addAtHead(5);
    list3.addAtIndex(4, 3);
    list3.addAtTail(0);
    list3.addAtTail(5);
    list3.addAtIndex(6, 3);
    list3.deleteAtIndex(7);
    list3.deleteAtIndex(5);
    list3.addAtTail(4);
}