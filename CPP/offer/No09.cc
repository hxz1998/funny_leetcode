/**
 * Created by Xiaozhong on 2021/11/14.
 * Copyright (c) 2021/11/14 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "queue"
#include "vector"
#include "algorithm"
#include "stack"

using namespace std;


class CQueue {
private:
    stack<int> buffer;
    stack<int> data;
public:
    CQueue() {

    }

    void appendTail(int value) {
        data.push(value);
    }

    int deleteHead() {
        if (data.empty()) return -1;
        int sz = data.size();
        for (int idx = 0; idx < sz - 1; ++idx) {
            buffer.push(data.top());
            data.pop();
        }
        int ret = data.top();
        data.pop();
        while (!buffer.empty()) {
            data.push(buffer.top());
            buffer.pop();
        }
        return ret;
    }
};

int main() {
    CQueue cQueue;
    cQueue.appendTail(5);
    cQueue.appendTail(2);
    cout << cQueue.deleteHead() << endl;
    cout << cQueue.deleteHead() << endl;
}