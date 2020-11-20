/**
 * Created by Xiaozhong on 2020/11/20.
 * Copyright (c) 2020/11/20 Xiaozhong. All rights reserved.
 */

#include <queue>
#include <iostream>

using namespace std;

class KthLargest {
private:
    struct cmp {
        bool operator()(const int &rhs, const int &lhs) {
            return rhs > lhs;
        }
    };

    int _k;
    priority_queue<int, vector<int>, cmp> pq;

public:

    KthLargest(int k, vector<int> &nums) : _k(k) {
        for (int i : nums) {
            pq.push(i);
            if (pq.size() > _k) pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > _k) pq.pop();
        return pq.top();
    }
};


int main() {
    // 验证优先级队列
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < 10; ++i) {
        pq.push(i);
    }
    pq.pop();
    return 0;
}