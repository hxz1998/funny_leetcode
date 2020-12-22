/**
 * Created by Xiaozhong on 2020/12/22.
 * Copyright (c) 2020/12/22 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
        int sumA = 0, sumB = 0;
        for (int i : A) sumA += i;
        for (int i : B) sumB += i;
        int delta = (sumA - sumB) / 2;
        unordered_set<int> set;
        for (int i : A) set.insert(i);
        for (int i : B) {
            if (set.find(i + delta) != set.end()) {
                return {i + delta, i};
            }
        }
        return {};
    }
};