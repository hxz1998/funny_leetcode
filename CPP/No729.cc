/**
 * Created by Xiaozhong on 2020/11/26.
 * Copyright (c) 2020/11/26 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class MyCalendar {
    vector<pair<int, int>> calendar;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        for (auto item : calendar) {
            if (item.first < end && item.second > start) return false;
        }
        calendar.emplace_back(make_pair(start, end));
        return true;
    }
};