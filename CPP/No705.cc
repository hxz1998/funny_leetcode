/**
 * Created by Xiaozhong on 2020/11/21.
 * Copyright (c) 2020/11/21 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class MyHashSet {
    vector<unsigned> hash_set;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        hash_set = vector<unsigned>(1000000 / 32, 0);
    }

    void add(int key) {
        hash_set[key >> 5] |= 1 << (key & 31);
    }

    void remove(int key) {
        hash_set[key >> 5] &= ~(1 << (key & 31));
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash_set[key >> 5] & (1 << (key & 31));
    }
};