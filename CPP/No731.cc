/**
 * Created by Xiaozhong on 2020/11/27.
 * Copyright (c) 2020/11/27 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class MyCalendarTwo {
private:
    vector<pair<int, int>> calendar;
    vector<pair<int, int>> overlaps;

public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        for (pair<int, int> &item : overlaps) {
            if (item.first < end && item.second > start) return false;
        }
        for (pair<int, int> &item : calendar) {
            if (item.first < end && item.second > start) {
                overlaps.emplace_back(make_pair(max(start, item.first), min(end, item.second)));
            }
        }
        calendar.emplace_back(make_pair(start, end));
        return true;
    }
};