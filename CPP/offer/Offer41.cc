/*
 * Created by Xiaozhong on 12/30/2021.
 * Copyright (c) 12/30/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "queue"

using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, less<>> left;
    priority_queue<int, vector<int>, greater<>> right;

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (left.empty() || num <= left.top()) left.push(num);
        else right.push(num);
        if (left.size() < right.size()) {
            int n = right.top();
            right.pop();
            left.push(n);
        }
        if (left.size() > right.size() + 1) {
            int n = left.top();
            left.pop();
            right.push(n);
        }
    }

    double findMedian() {
        if (left.empty()) return 0;
        else if (left.size() == right.size()) return (1.0 * left.top() + 1.0 * right.top()) / 2.0;
        else if (left.size() > right.size()) return left.top();
        else return right.top();
    }
};

int main() {
    vector<int> nums = {2, 4, 3};
    priority_queue<int, vector<int>, greater<>> pq;
    for (int num: nums)
        pq.push(num);
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}