/**
 * Created by Xiaozhong on 2020/10/28.
 * Copyright (c) 2020/10/28 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int> &arr) {
        if (arr.empty()) return true;
        unordered_map<int, int> counter;
        for (auto &i : arr) counter[i]++;
        unordered_set<int> times;
        for (auto &item : counter) times.insert(item.second);
        return times.size() == counter.size();
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    assert(s.uniqueOccurrences(arr) == 1);
}