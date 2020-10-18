/**
 * Created by Xiaozhong on 2020/10/17.
 * Copyright (c) 2020/10/17 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> mapper;
        // 记录每一行每一个元素带来的和值，每多一个相同的和值，
        // 说明从这个和值上面穿过的话，会多一个砖块
        for (const vector<int> &item : wall) {
            int sum = 0;
            for (int i = 0; i < item.size() - 1; ++i) {
                sum += item[i];
                if (mapper.count(sum) != 0) ++mapper[sum];
                else mapper[sum] = 1;
            }
        }
        int res = wall.size();
        // 挨个检查怎样穿过会比较少
        for (unordered_map<int, int>::iterator iter = mapper.begin(); iter != mapper.end(); ++iter)
            res = min(res, (int) wall.size() - iter->second);
        return res;
    }
};