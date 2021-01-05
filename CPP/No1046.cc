/**
 * Created by Xiaozhong on 2020/12/30.
 * Copyright (c) 2020/12/30 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> pq;
        for (int i : stones) pq.push(i);
        while (pq.size() > 1) {
            int top = pq.top();
            pq.pop();
            int next = pq.top();
            pq.pop();
            pq.push(top - next);
        }
        if (pq.empty()) return 0;
        else return pq.top();
    }
};

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    Solution s;

    cout << s.lastStoneWeight(stones) << endl;
}