/**
 * Created by Xiaozhong on 2022/3/13.
 * Copyright (c) 2022/3/13 Xiaozhong. All rights reserved.
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

// 很笨的做法，一点一点移动窗口
/*class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = static_cast<int>(s.size());
        unordered_map<char, int> cnt;
        auto check = [&]() {
            for (auto item: cnt) if (item.second > 1) return false;
            return true;
        };
        int left = 0, right = 0;
        int ans = 0;
        while (right < n) {
            while (right < n && check()) cnt[s[right++]]++;
            ans = max(ans, right - left - 1);
            while (left <= right && !check()) cnt[s[left++]]--;
        }
        return ans;
    }
};*/

// 比较好的做法，直接移动一个区域
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = static_cast<int>(s.size());
        if (n <= 1) return n;
        // 记录下来上次出现的位置
        unordered_map<char, int> mapper;
        int left = -1, ans = 0;
        for (int idx = 0; idx < n; ++idx) {
            if (mapper.find(s[idx]) != mapper.end()) {
                left = max(left, mapper[s[idx]]);
            }
            ans = max(ans, idx - left);
            mapper[s[idx]] = idx;
        }
        return max(ans, n - left - 1);
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("cdd") << endl;
}