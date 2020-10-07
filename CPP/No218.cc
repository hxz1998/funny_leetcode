/**
 * Created by Xiaozhong on 2020/8/22.
 * Copyright (c) 2020/8/22 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "set"

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        multiset<pair<int, int>> all;
        vector<vector<int>> ans;

        for (auto &item : buildings) {
            all.insert(make_pair(item[0], -item[2]));
            all.insert(make_pair(item[1], item[2]));
        }

        vector<int> last = {0, 0};
        multiset<int> heights({0});

        for (auto &item : all) {
            if (item.second < 0) heights.insert(-item.second);
            else heights.erase(heights.find(item.second));

            auto max_height = *heights.rbegin();

            if (last[1] != max_height) {
                last[0] = item.first;
                last[1] = max_height;
                ans.push_back(last);
            }
        }
        return ans;
    }
};