/**
 * Created by Xiaozhong on 2020/9/2.
 * Copyright (c) 2020/9/2 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "unordered_map"
#include "unordered_set"

using namespace std;

class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> mapper;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        // 记录最初状态，如果里面存在该数，则记为 false
        bool res = mapper.count(val) == 0;
        // 在 val 的映射集和中，添加索引
        mapper[val].insert(nums.size());
        // 将 val 添加到数据列中
        nums.push_back(val);
        return res;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        // 如果这个 val 不存在，那么就直接返回 false
        if (mapper.count(val) == 0) return false;
        // 记录最后一个数据
        int last = nums.back();
        if (last == val) {
            // 如果最后一个数正好等于 val ，那么就将它从数据映射表中抹掉，然后从数据列中也抹掉
            mapper[val].erase(nums.size() - 1); // 之所以是 nums.size() - 1, 是因为它出现在数据列最后
            nums.pop_back();
        } else {
            int index = *mapper[val].begin();   // 记录 val 出现在数据列中的第一个索引，准备删掉它
            nums[index] = last;                 // 首先记录数据列中最后一个元素的值，准备将它交换到 index 的位置，然后删除最后一个元素
            mapper[last].erase(nums.size() - 1); // 擦除掉最后一个元素的映射
            mapper[last].insert(index);             // 在最后一个元素值的映射表中，加入一个待更换的 index
            mapper[val].erase(index);               // 将原来的 index 移除掉
            nums.pop_back();    // 弹掉最后一个元素
        }
        if (mapper[val].empty()) {  // 如果 val 处的集和成空的了，那么就直接在映射表中擦除掉 val
            mapper.erase(val);
        }
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};