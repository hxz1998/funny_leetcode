/**
 * Created by Xiaozhong on 2020/10/27.
 * Copyright (c) 2020/10/27 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int front = 0, rear = 0;
    int sz = 0;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : sz(k + 1) {
        data.resize(k + 1);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        data[rear] = value;
        rear = (rear + 1) % sz;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % sz;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return data[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        return data[(rear - 1 + sz) % sz];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == rear;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (rear + 1) % sz == front;
    }
};

int main() {
    MyCircularQueue queue(3);
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    cout << queue.isEmpty() << endl;
}