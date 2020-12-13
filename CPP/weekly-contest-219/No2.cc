/**
 * Created by Xiaozhong on 2020/12/13.
 * Copyright (c) 2020/12/13 Xiaozhong. All rights reserved.
 */
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        vector<int> bit;
        for (char c : n) bit.emplace_back(c - '0');
        return *max_element(bit.begin(), bit.end());
    }
};

int main() {
    Solution s;
    cout << s.minPartitions("27346209830709182346") << endl;
}