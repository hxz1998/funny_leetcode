/**
 * Created by Xiaozhong on 2022/2/7.
 * Copyright (c) 2022/2/7 Xiaozhong. All rights reserved.
 */

#include "string"
#include "vector"
#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> arr = {{a, 'a'},
                                       {b, 'b'},
                                       {c, 'c'}};
        string ans;
        while (true) {
            bool hasNext = false;
            sort(arr.begin(), arr.end(), [](const pair<int, char> &lhs, const pair<int, char> &rhs) {
                return lhs.first > rhs.first;
            });
            for (pair<int, char> &item: arr) {
                if (item.first <= 0) break;
                if (ans.size() >= 2 && ans[ans.size() - 1] == item.second &&
                    ans[ans.size() - 2] == item.second)
                    continue;
                hasNext = true;
                ans.push_back(item.second);
                item.first--;
                break;
            }
            if (!hasNext) break;
        }
        return ans;
    }
};