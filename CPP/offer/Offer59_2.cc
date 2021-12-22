/**
 * Created by Xiaozhong on 2021/12/21.
 * Copyright (c) 2021/12/21 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "queue"
#include "deque"
using namespace std;

class MaxQueue {
private:
    queue<int> data;
    deque<int> maxQueue;
public:
    MaxQueue() {

    }

    int max_value() {
        if (maxQueue.empty()) return -1;
        return maxQueue.front();
    }

    void push_back(int value) {
        while (!maxQueue.empty() && maxQueue.back() < value) maxQueue.pop_back();
        maxQueue.push_back(value);
        data.push(value);
    }

    int pop_front() {
        if (data.empty()) return -1;
        int val = data.front();
        data.pop();
        if (maxQueue.front() == val) maxQueue.pop_front();
        return val;
    }
};