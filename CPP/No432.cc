/**
 * Created by Xiaozhong on 2022/3/16.
 * Copyright (c) 2022/3/16 Xiaozhong. All rights reserved.
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

class AllOne {
private:
    struct Node {
        int cnt = 0;
        string word;
        Node *prev = nullptr;
        Node *next = nullptr;

        Node(const string &w, int c = 0) : word(w), cnt(c) {}
    };

    Node *head;
    Node *tail;
    unordered_map<string, Node *> mapper;

    void connect(Node *lhs, Node *rhs) {
        lhs->next = rhs;
        rhs->prev = lhs;
    }

    void adjust(Node *node) {
        while (node->cnt > node->prev->cnt) {
            Node *next = node->next;
            Node *prev = node->prev;
            prev->prev->next = node;
            node->prev = prev->prev;
            prev->next = next;
            next->prev = prev;
            node->next = prev;
            prev->prev = node;
        }
        while (node->cnt < node->next->cnt) {
            Node *prev = node->prev;
            Node *next = node->next;
            node->next = next->next;
            next->next->prev = node;
            next->prev = prev;
            next->next = node;
            prev->next = next;
            node->prev = next;
        }
    }

public:
    AllOne() {
        head = new Node("", INT32_MAX);
        tail = new Node("", INT32_MIN);
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (mapper.find(key) == mapper.end()) {
            Node *node = new Node(key, 1);
            mapper[key] = node;
            node->prev = tail->prev;
            tail->prev->next = node;
            tail->prev = node;
            node->next = tail;
        } else {
            Node *node = mapper[key];
            node->cnt++;
            adjust(node);
        }
    }

    void dec(string key) {
        Node *node = mapper[key];
        node->cnt--;
        if (node->cnt == 0) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            mapper.erase(key);
            delete node;
        } else {
            adjust(node);
        }
    }

    string getMaxKey() {
        if (head->next == tail) return "";
        else return head->next->word;
    }

    string getMinKey() {
        if (head->next == tail) return "";
        else return tail->prev->word;
    }

};

int main() {
    AllOne allOne;
    allOne.inc("a");
    allOne.inc("b");
    allOne.inc("b");
    allOne.inc("c");
    allOne.inc("c");
    allOne.inc("c");
    allOne.dec("b");
    allOne.dec("b");
    cout << allOne.getMinKey() << endl;
    allOne.dec("a");
    cout << allOne.getMaxKey() << endl;
    cout << allOne.getMinKey() << endl;
}