/**
 * Created by Xiaozhong on 2022/3/19.
 * Copyright (c) 2022/3/19 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = static_cast<int>(numbers.size());
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) return {left, right};
            else if (sum < target) left++;
            else right--;
        }
        return {-1, -1};
    }
};