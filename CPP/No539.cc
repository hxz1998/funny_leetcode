/**
 * Created by Xiaozhong on 2020/10/14.
 * Copyright (c) 2020/10/14 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minute(const string &time) {
        int ans = 0;
        string buf;
        bool flag = true;
        // 对小时进行处理，转换成分钟
        for (const char &c : time) {
            if (c != ':') {
                buf.push_back(c);
            } else {
                ans += stoi(buf) * 60;
                buf = "";
            }
        }
        // 把分钟也加上来
        ans += stoi(buf);
        buf = "";
        return ans;
    }

    int findMinDifference(vector<string> &timePoints) {
        if (timePoints.empty()) return 0;
        vector<int> minutes;
        // 对每一个数据都进行转换，例如 23:59 -> 1439
        for (const string &time : timePoints) minutes.push_back(minute(time));
        // 从小到大对分钟数进行排序
        sort(minutes.begin(), minutes.end());
        int ans = INT32_MAX;
        // 两两检查，看看哪一对之间是最小值
        for (int i = 0; i < minutes.size() - 1; ++i) {
            ans = min(minutes[i + 1] - minutes[i], ans);
        }
        // 检查首尾元素
        ans = min(minutes.front() + 24 * 60 - minutes.back(), ans);
        return ans;
    }
};

int main() {
    vector<string> timePoints = {"23:59", "00:00"};
    Solution s;
    cout << s.findMinDifference(timePoints) << endl;
}