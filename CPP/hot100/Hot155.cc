/*
 * Created by Xiaozhong on 2/25/2022.
 * Copyright (c) 2/25/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "stack"

using namespace std;

class MinStack {
private:
    stack<int> data;
    stack<int> minData;
public:
    MinStack() {

    }

    void push(int val) {
        if (minData.empty()) minData.push(val);
        else if (minData.top() >= val) minData.push(val);
        data.push(val);
    }

    void pop() {
        int val = data.top();
        data.pop();
        if (val == minData.top()) minData.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minData.top();
    }
};