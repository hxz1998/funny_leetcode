/**
 * Created by Xiaozhong on 2020/11/1.
 * Copyright (c) 2020/11/1 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
private:
    bool compare(const vector<int> &lhs, const vector<int> &rhs) {
        if (lhs.size() != rhs.size()) return false;
        for (int i = 0; i < rhs.size(); ++i) if (lhs[i] != rhs[i]) return false;
        return true;
    }

public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
        unordered_map<int, vector<int>> mapper;
        for (auto iter : pieces)
            mapper[iter.front()].assign(iter.begin() + 1, iter.end());
        for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
            if (mapper.count(*iter)) {
                if (mapper[*iter].empty()) continue;
                vector<int> lhs = vector<int>(iter + 1, iter + mapper[*iter].size() + 1);
                vector<int> rhs = vector<int>(mapper[*iter]);
                if (!compare(lhs, rhs)) return false;
                iter += mapper[*iter].size();
            } else return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> arr = {91, 4, 64, 78};
    vector<vector<int>> pieces = {
            {78},
            {4, 64},
            {91}
    };
    cout << s.canFormArray(arr, pieces) << endl;
}