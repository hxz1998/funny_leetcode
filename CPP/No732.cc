/**
 * Created by Xiaozhong on 2020/11/27.
 * Copyright (c) 2020/11/27 Xiaozhong. All rights reserved.
 */
#include <map>

using namespace std;

class MyCalendarThree {
    map<int, int> delta;
public:
    MyCalendarThree() {

    }

    int book(int start, int end) {
        delta[start]++;
        delta[end]--;
        int active = 0, ans = 0;
        for (auto iter = delta.begin(); iter != delta.end(); ++iter) {
            active += iter->second;
            ans = max(ans, active);
        }
        return ans;
    }
};