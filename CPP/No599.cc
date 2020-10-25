/**
 * Created by Xiaozhong on 2020/10/25.
 * Copyright (c) 2020/10/25 Xiaozhong. All rights reserved.
 */
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        unordered_map<string, int> mapper;
        for (int i = 0; i < list1.size(); ++i) mapper[list1[i]] = i;
        int sum = INT32_MAX;
        vector<string> ans;
        for (int i = 0; i < list2.size(); ++i) {
            if (mapper.count(list2[i])) {
                if (mapper[list2[i]] + i < sum) {
                    ans.clear();
                    ans.emplace_back(list2[i]);
                    sum = mapper[list2[i]] + i;
                } else if (mapper[list2[i]] + i == sum) {
                    ans.emplace_back(list2[i]);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"},
            list2 = {"KFC", "Shogun", "Burger King"};
    vector<string> ans = s.findRestaurant(list1, list2);
    for (string item : ans) {
        cout << item << " " << endl;
    }
}