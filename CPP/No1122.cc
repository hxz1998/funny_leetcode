/**
 * Created by Xiaozhong on 2020/11/14.
 * Copyright (c) 2020/11/14 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        map<int, int> mapper;
        for (auto &i : arr1) { ++mapper[i]; }
        arr1.clear();
        for (auto &i : arr2) {
            if (mapper.count(i)) {
                for (int j = 0; j < mapper[i]; ++j) arr1.emplace_back(i);
                mapper.erase(i);
            }
        }
        for (auto iter = mapper.begin(); iter != mapper.end(); ++iter) {
            for (int j = 0; j < iter->second; ++j) {
                arr1.emplace_back(iter->first);
            }
        }
        return arr1;
    }
};

int main() {
    Solution s;
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    vector<int> ans = s.relativeSortArray(arr1, arr2);
    return 0;
}