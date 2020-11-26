/**
 * Created by Xiaozhong on 2020/11/26.
 * Copyright (c) 2020/11/26 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool check(int num) {
        int copy = num;
        while (copy) {
            // 取出来最右边的一位数字
            int n = copy % 10;
            // 排除掉中间有 0 的情况以及不能除尽被除数的情况
            if (n == 0 || num % n) return false;
            else copy /= 10;
        }
        return true;
    }

public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        // 挨个检查并且放到返回值中
        for (int num = left; num <= right; ++num) {
            if (check(num)) ans.emplace_back(num);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> ans = s.selfDividingNumbers(1, 22);
    return 0;
}