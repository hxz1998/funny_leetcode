/**
 * Created by Xiaozhong on 2022/3/18.
 * Copyright (c) 2022/3/18 Xiaozhong. All rights reserved.
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

using namespace std;

class MovingAverage {
private:
    int size;
    queue<int> pq;
    int sum = 0;
public:
    MovingAverage(int _size) : size(_size) {

    }

    double next(int val) {
        if (pq.size() == size) {
            sum -= pq.front();
            pq.pop();
        }
        sum += val;
        pq.push(val);
        return 1.0 * sum / pq.size();
    }
};