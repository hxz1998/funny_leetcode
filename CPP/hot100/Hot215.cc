/*
 * Created by Xiaozhong on 2/28/2022.
 * Copyright (c) 2/28/2022 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int> pq;
        for (int num: nums) pq.push(num);
        for (int idx = 0; idx < k - 1; ++idx) pq.pop();
        return pq.top();
    }
};

int main() {
    Solution *s = nullptr;
    vector<int> num = {1, 2, 3};
    cout << s->findKthLargest(num, 1) << endl;
}