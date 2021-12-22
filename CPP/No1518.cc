/*
 * Created by Xiaozhong on 12/17/2021.
 * Copyright (c) 12/17/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            int n = empty % numExchange;
            ans += empty / numExchange;
            empty = n + empty / numExchange;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.numWaterBottles(9, 3) << endl;
    cout << s.numWaterBottles(15, 4) << endl;
}