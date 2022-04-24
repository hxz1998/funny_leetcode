/**
 * Created by Xiaozhong on 2022/4/24.
 * Copyright (c) 2022/4/24 Xiaozhong. All rights reserved.
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
#include <list>
#include <random>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param a int整型vector
     * @return int整型
     */
    list<int> nums;

    bool isPrime(int num) {
        if (num == 1) return false;
        int end = sqrt(num);
        for (int idx = 2; idx <= end; ++idx) {
            if (num % idx == 0) return false;
        }
        return true;
    }

    int getNumber(vector<int> &a) {
        int n = static_cast<int>(a.size());
        vector<bool> visited(n);
        int remain = n;
        while (remain > 1) {
            int index = 1;
            for (int idx = 0; idx < n; ++idx) {
                if (visited[idx]) continue;
                if (!isPrime(index)) {
                    visited[idx] = true;
                    remain--;
                }
                index++;
            }
        }
        for (int idx = 0; idx < n; ++idx) if (!visited[idx]) return a[idx];
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 2, 3, 4};
    cout << s.getNumber(nums) << endl;
}