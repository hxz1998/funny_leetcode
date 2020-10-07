/**
 * Created by Xiaozhong on 2020/7/21.
 * Copyright (c) 2020/7/21 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        // 首先排序，排序先按照第一个元素排序，然后按照第二个排序
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        // 遍历整个数组
        for (int i = 0; i < intervals.size();) {
            // 记录当前范围可到达的最远距离
            int max_scope = intervals[i][1];
            int j = i + 1;
            // 更新可达最远处，如果当前的最大距离都小于了 当前元素的最小值 那么就需要跳出来
            while (j < intervals.size() && intervals[j][0] <= max_scope) {
                max_scope = max(max_scope, intervals[j][1]);
                j++;
            }
            // 把子范围添加进来
            ans.push_back({intervals[i][0], max_scope});
            i = j;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals = {
            {1,  3},
            {2,  6},
            {8,  10},
            {15, 18}
    };
    for (vector<int> item : s.merge(intervals)) {
        for (int i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
}