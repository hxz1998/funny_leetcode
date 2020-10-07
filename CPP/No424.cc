/**
 * Created by Xiaozhong on 2020/9/18.
 * Copyright (c) 2020/9/18 Xiaozhong. All rights reserved.
 */
#include "string"
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.length() == 0) return 0;
        vector<int> count(26, 0);
        int left = 0, right = 0, ans = 1;
        while (right < s.length() && left <= right) {
            count[s[right] - 65]++;
            int max_res = MAX(count);   // 记录窗口中出现次数最多的次数
            if (right - left + 1 - max_res <= k) {
                // 检查当前需要替换的元素是否大于 k，如果不大于 k 的话，那么就：
                ans = max(ans, right - left + 1);
                right++;
            } else {
                // 说明现在是已经超出了 k，那么就调整左边界，让它往右边挪挪
                count[s[left] - 65]--;  // 首先把最左边的字符个数 --
                left++;
                count[s[right] - 65]--; // 然后把最右边的字符个数也复原了
            }
        }
        return ans;
    }

private:
    int MAX(vector<int> count) {
        int res = count[0];
        for (int i = 1; i < count.size(); ++i) {
            if (count[i] > res) {
                res = count[i];
            }
        }
        return res;
    }
};