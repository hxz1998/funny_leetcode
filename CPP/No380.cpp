/**
 * Created by Xiaozhong on 2020/9/2.
 * Copyright (c) 2020/9/2 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "unordered_map"

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> mapper;
    vector<int> nums;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        // 如果内部存在这个数据，直接返回 false
        if (mapper.count(val)) return false;
        // 否则，就建立映射，并且插入到列表尾部
        mapper[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // 如果不存在这个数，那么就直接返回 false
        if (!mapper.count(val)) return false;
        // 否则就把这个数放到列表尾部，然后删掉它
        int lastElement = nums[nums.size() - 1];
        int index = mapper[val];
        nums[index] = lastElement;
        nums.pop_back();
        // 而且更新原来列表尾部元素在哈希表中的映射
        mapper[lastElement] = index;
        // 擦除原来的元素
        mapper.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};