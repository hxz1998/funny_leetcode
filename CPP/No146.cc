/**
 * Created by Xiaozhong on 2020/8/14.
 * Copyright (c) 2020/8/14 Xiaozhong. All rights reserved.
 */
#include "unordered_map"

using namespace std;

// 双向链表的结构体
struct LRUDLinkedList {
    int key, val;
    LRUDLinkedList *next;
    LRUDLinkedList *prev;

    LRUDLinkedList() : key(0), val(0), next(nullptr), prev(nullptr) {}

    LRUDLinkedList(int _key, int _val) : key(_key), val(_val) {}
};

class LRUCache {
private:
    unordered_map<int, LRUDLinkedList *> cache; // 存储数据的 map 映射
    LRUDLinkedList *head;                       // 双向链表的头部
    LRUDLinkedList *tail;                       // 双向链表尾部
    int size;
    int capacity;

    // 将元素移动到头部（更新使用操作）
    void move_to_head(LRUDLinkedList *node) {
        remove_node(node);
        add_to_head(node);
    }

    // 删除元素（实际上并不会 delete 内存）
    void remove_node(LRUDLinkedList *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 将元素添加到双向链表头部
    void add_to_head(LRUDLinkedList *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // 删除尾部元素（并不会 delete 元素的内存）
    LRUDLinkedList *remove_tail() {
        LRUDLinkedList *node = tail->prev;
        remove_node(node);
        return node;
    }

public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        // 使用伪头部以及伪尾部作为辅助节点
        head = new LRUDLinkedList();
        tail = new LRUDLinkedList();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        // 如果不存在，那么直接返回去一个 -1
        if (!cache.count(key)) return -1;
        // 如果存在，那么将其放到链表的头部，并且返回其值
        LRUDLinkedList *node = cache[key];
        // 然后将其移动到双向链表的头部
        move_to_head(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.count(key)) {// 如果存在该元素，那么将其值更新，然后移动到链表头部
            LRUDLinkedList *node = cache[key];
            // 更新值
            node->val = value;
            // 更新访问
            move_to_head(node);
        } else {                // 否则添加该元素
            LRUDLinkedList *node = new LRUDLinkedList(key, value);
            cache[key] = node;
            add_to_head(node);
            size++;
            if (size > capacity) {  // 如果容量已经满了，那么就删除尾部节点，并且释放申请的空间
                LRUDLinkedList *remove_node = remove_tail();
                cache.erase(remove_node->key);
                delete remove_node;
                size--;
            }
        }
    }
};
