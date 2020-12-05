/**
 * Created by Xiaozhong on 2020/12/5.
 * Copyright (c) 2020/12/5 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        stack<int> stk;
        for (int num : arr) {
            if (!stk.empty() && num < stk.top()) {
                int head = stk.top();
                while (!stk.empty() && stk.top() > num) stk.pop();
                stk.push(head);
            }else {
                stk.push(num);
            }
        }
        return stk.size();
    }
};