/**
 * Created by Xiaozhong on 2021/10/31.
 * Copyright (c) 2021/10/31 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

struct Node {
    int value = 0;
    Node *prev;
    int id = -1;
    int maxValue = 0;
    vector<Node *> children;

    Node(int i, int val, Node *pre) : id(i), value(val), prev(pre) {}

    Node(int val) : value(val) {}

    Node() {}
};


int dfsUpdate(Node *root, int value, int& maxValue) {
    if (!root) return 0;
    root->value += value;
    maxValue = max(maxValue, root->value);
    int mValue = root->value;
    for (Node *next : root->children) {
        root->maxValue = dfsUpdate(next, value, maxValue);
        mValue = max(mValue, next->maxValue);
    }
    root->maxValue = mValue;
    return mValue;
}

void dfsQuery(Node *root, int &ans) {
    if (!root) return;
    ans = max(ans, root->value);
    for (Node *next : root->children) dfsQuery(next, ans);
}

int main() {
    unordered_map<int, Node *> mapper;
    Node *root = nullptr;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int prevValue = 0, nextValue = 0;
        cin >> prevValue >> nextValue;
        Node *prev = nullptr, *next = nullptr;
        if (mapper.count(prevValue)) prev = mapper[prevValue];
        if (mapper.count(nextValue)) next = mapper[nextValue];
        if (prevValue == 1 && root == nullptr) {
            root = new Node(prevValue, 0, nullptr);
            next = new Node(nextValue, 0, root);
            root->children.emplace_back(next);
            mapper[prevValue] = root;
            mapper[nextValue] = next;
        } else {
            if (prev != nullptr) next = new Node(nextValue, 0, prev);
            else if (next != nullptr) {
                prev = new Node(prevValue, 0, nullptr);
                next->prev = prev;
            } else {
                prev = new Node(prevValue, 0, nullptr);
                next = new Node(nextValue, 0, prev);
            }
            prev->children.emplace_back(next);
            mapper[prevValue] = prev;
            mapper[nextValue] = next;
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1) {
            int k;
            cin >> k;
            int maxValue = 0;
            Node* curr = mapper[x];
            dfsUpdate(curr, k, maxValue);
            while (curr != root) {
                curr->maxValue = max(maxValue, curr->maxValue);
                curr = curr->prev;
            }
            root->maxValue = max(root->maxValue, maxValue);
        } else {
            Node *curr = mapper[x];
            cout << max(curr->value, curr->maxValue) << endl;
        }
    }
}
