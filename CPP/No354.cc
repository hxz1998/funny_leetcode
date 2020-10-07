/**
 * Created by Xiaozhong on 2020/8/29.
 * Copyright (c) 2020/8/29 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        // 把数据按照 w 升序， h 降序排列
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        vector<int> ans;
        for (const auto &e:envelopes) {
            // 二分查找第一个大于等于的地方
            auto p = lower_bound(ans.begin(), ans.end(), e[1]);
            if (p == ans.end()) ans.push_back(e[1]);
            else *p = e[1];
        }
        return ans.size();
    }
};

int main() {
    Solution s;
}