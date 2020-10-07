/**
 * Created by Xiaozhong on 2020/8/22.
 * Copyright (c) 2020/8/22 Xiaozhong. All rights reserved.
 */
#include "deque"
#include "iostream"

using namespace std;

class MyStack {
private:
    deque<int> data;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        data.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ans = data.back();
        data.pop_back();
        return ans;
    }

    /** Get the top element. */
    int top() {
        return data.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
};

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}