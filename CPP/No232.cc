/**
 * Created by Xiaozhong on 2020/8/23.
 * Copyright (c) 2020/8/23 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "stack"

using namespace std;

class MyQueue {
private:
    stack<int> s;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> buffer;
        while (!s.empty()) {
            buffer.push(s.top());
            s.pop();
        }
        int data = buffer.top();
        buffer.pop();
        while (!buffer.empty()) {
            s.push(buffer.top());
            buffer.pop();
        }
        return data;
    }

    /** Get the front element. */
    int peek() {
        stack<int> buffer;
        while (!s.empty()) {
            buffer.push(s.top());
            s.pop();
        }
        int data = buffer.top();
        while (!buffer.empty()) {
            s.push(buffer.top());
            buffer.pop();
        }
        return data;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};