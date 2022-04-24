/**
 * Created by Xiaozhong on 2022/4/8.
 * Copyright (c) 2022/4/8 Xiaozhong. All rights reserved.
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

class MyCalendar {
    vector<pair<int, int>> clt;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        if (clt.empty()) clt.emplace_back(start, end);
        else {
            int left = 0, right = static_cast<int>(clt.size());
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (clt[mid].second <= start) left = mid + 1;
                else right = mid;
            }
            if (left < clt.size() && clt[left].first < end) return false;
            clt.insert(clt.begin() + left, {start, end});
        }
        return true;
    }
};