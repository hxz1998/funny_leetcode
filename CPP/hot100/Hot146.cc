/*
 * Created by Xiaozhong on 2/25/2022.
 * Copyright (c) 2/25/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "queue"
#include "unordered_map"

using namespace std;

class LRUCache {
private:
    struct Node {
        Node *prev, *next;
        int key, val;

        Node() = default;

        Node(int k, int v) : key(k), val(v) {}

        Node(int k, int v, Node *p, Node *n) : key(k), val(v), prev(p), next(n) {
        }
    };

    int cap = 0, sz = 0;
    unordered_map<int, Node *> mapper;
    Node *dummyHead, *dummyTail;
public:
    LRUCache(int capacity) : cap(capacity) {
        dummyHead = new Node();
        dummyTail = new Node();
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    int get(int key) {
        if (mapper.find(key) != mapper.end()) {
            Node *node = mapper[key];
            moveToFirst(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mapper.find(key) == mapper.end() && sz >= cap) {
            // 先删除末尾节点
            int ret = deleteLast();
            mapper.erase(ret);
            Node *node = new Node(key, value);
            mapper[key] = node;
            addFirst(node);
        } else if (mapper.find(key) == mapper.end()) {
            Node *node = new Node(key, value);
            mapper[key] = node;
            addFirst(node);
            sz++;
        } else {
            Node *node = mapper[key];
            node->val = value;
            moveToFirst(node);
        }
    }

private:
    void addFirst(Node *node) {
        Node *next = dummyHead->next;
        node->next = next;
        next->prev = node;
        dummyHead->next = node;
        node->prev = dummyHead;
    }

    void moveToFirst(Node *node) {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
        node->next = dummyHead->next;
        dummyHead->next->prev = node;
        dummyHead->next = node;
        node->prev = dummyHead;
    }

    int deleteLast() {
        if (dummyTail->prev == dummyHead) return -1;
        Node *prev = dummyTail->prev->prev;
        Node *node = prev->next;
        prev->next = dummyTail;
        dummyTail->prev = prev;
        int ret = node->key;
        delete node;
        return ret;
    }

    void connect(Node *lhs, Node *rhs) {
        Node *prev = lhs->prev;
        Node *next = rhs->next;
        prev->next = rhs;
        lhs->next = next;
        lhs->prev = rhs;
        rhs->next = lhs;
        rhs->prev = prev;
        next->prev = lhs;
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    cout << " --------------- " << endl;
    LRUCache c(2);
    c.put(1, 0);
    c.put(2, 2);
    cout << c.get(1) << endl;
    c.put(3, 3);
    cout << c.get(2) << endl;
    c.put(4, 4);
    cout << c.get(1) << endl;
    cout << c.get(3) << endl;
    cout << c.get(4) << endl;
}