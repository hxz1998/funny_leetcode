/**
 * Created by Xiaozhong on 2021/12/5.
 * Copyright (c) 2021/12/5 Xiaozhong. All rights reserved.
 */
#include "stack"
#include "vector"
#include "iostream"

using namespace std;

class MinStack {
private:
    stack<int> data;
    stack<int> ms;
public:

    MinStack() {

    }

    void push(int x) {
        data.push(x);
        if (ms.empty() || ms.top() >= x) ms.push(x);
    }

    void pop() {
        int top = data.top();
        data.pop();
        if (top == ms.top()) ms.pop();
    }

    int top() {
        return data.top();
    }

    int min() {
        return ms.top();
    }
};