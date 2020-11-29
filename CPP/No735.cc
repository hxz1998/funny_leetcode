/**
 * Created by Xiaozhong on 2020/11/28.
 * Copyright (c) 2020/11/28 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        stack<int> stk; stk.push(INT32_MIN);
        for (auto ast: asteroids) {
            // 行星向左走
            if (ast < 0) {
                // 新来的行星往左走，而且一直比向右的行星大
                while (stk.top() < -ast && stk.top() > 0) stk.pop();
                // 现在的行星都是向左走，来了另一个向左走的，那么自然放进来就好了
                if (stk.top() < 0) stk.push(ast);
                else if (stk.top() == -ast) stk.pop();
            } else stk.push(ast);
        }
        vector<int> res;
        while (stk.size() != 1) {
            res.push_back(stk.top());
            stk.pop();
        }

        return {res.rbegin(), res.rend()};
    }
};

int main() {
    Solution s;
    vector<int> asteroids = {8, -8};
    vector<int> ans = s.asteroidCollision(asteroids);
    return 0;
}