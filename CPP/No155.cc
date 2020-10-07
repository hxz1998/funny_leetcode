/**
 * Created by Xiaozhong on 2020/8/15.
 * Copyright (c) 2020/8/15 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "stack"

using namespace std;

class MinStack {
private:
    stack<int> data;
    stack<int> min_data;
public:
    /** initialize your data structure here. */
    MinStack() {
        min_data.push(INT32_MAX);
    }

    void push(int x) {
        min_data.push(min(min_data.top(), x));
        data.push(x);
    }

    void pop() {
        min_data.pop();
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min_data.top();
    }
};