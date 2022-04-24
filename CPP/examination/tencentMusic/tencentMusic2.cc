/**
 * Created by Xiaozhong on 2022/4/7.
 * Copyright (c) 2022/4/7 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

class Solution {
public:
    int minMax(vector<int> &a, int k, int x) {
        priority_queue<int, vector<int>, greater<>> pq;
        for (int num: a) pq.push(num);
        while (k-- > 0) {
            int top = pq.top();
            top -= x;
            pq.push(top);
        }
        return pq.top();
    }
};