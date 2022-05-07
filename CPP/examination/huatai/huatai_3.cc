/**
 * Created by Xiaozhong on 2022/4/28.
 * Copyright (c) 2022/4/28 Xiaozhong. All rights reserved.
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
     * 首先记录每一个数的出现与否，放在哈希表中，方便查找
     * 然后对于每一个 num ，都往后递增着找，找到所有的后续 num + i
     * 那么在这个递增过程中，所记录的最长递增次数就是最长序列长度
     */
    int MLS(vector<int> &arr) {
        unordered_set<int> numbers(arr.begin(), arr.end());
        int n = static_cast<int>(arr.size());
        int ans = 0;
        for (int idx = 0; idx < n; ++idx) {
            if (numbers.find(arr[idx] - 1) != numbers.end()) continue;
            int num = arr[idx];
            int length = 0;
            while (numbers.find(num) != numbers.end()) {
                length++;
                num++;
            }
            ans = max(ans, length);
        }
        return ans;
    }
};