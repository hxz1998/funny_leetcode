/**
 * Created by Xiaozhong on 2020/8/16.
 * Copyright (c) 2020/8/16 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // 巨慢无比的哈希映射法
        /*unordered_map<int, int> mapper;
        vector<int> ans;
        for (int i = 1; i <= numbers.size(); i++) mapper[numbers[i - 1]] = i;
        for (int i = 1; i <= numbers.size(); i++) {
            if (mapper.count(target - numbers[i - 1])) {
                ans.push_back(i);
                ans.push_back(mapper[target - numbers[i - 1]]);
                return ans;
            }
        }
        return ans;*/
        // 正常点的双指针法
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) return {left + 1, right + 1};
            else if (sum < target) left++;
            else right--;
        }
        return {-1, -1};
    }
};