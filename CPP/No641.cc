/**
 * Created by Xiaozhong on 2020/11/1.
 * Copyright (c) 2020/11/1 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MyCircularDeque {
private:
    vector<int> data;
    int front = 0, rear = 0;
    int capacity;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : capacity(k + 1) {
        data.resize(capacity);
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        data[front] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;;
        data[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return data[front];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return data[(rear - 1 + capacity) % capacity];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return rear == front;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};