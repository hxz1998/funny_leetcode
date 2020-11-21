/**
 * Created by Xiaozhong on 2020/11/21.
 * Copyright (c) 2020/11/21 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class MyHashMap {
    vector<int> bucket;
    const int len = 1e6;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        bucket = vector<int>(len, -1);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        bucket[key % len] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return bucket[key % len];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        bucket[key % len] = -1;
    }
};