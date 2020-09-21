/**
 * Created by Xiaozhong on 2020/9/21.
 * Copyright (c) 2020/9/21 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "string"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int left = 0, right = 0;    // 滑动窗口，left 指向窗口左边界，right 指向窗口右边界
        vector<int> needs(26, 0), window(26, 0);    // needs：用来统计 p 中所需要的字符个数，window：用来统计当前窗口中的字符
        for (char c : p) ++needs[c - 'a']; // 对每一个需要的字符个数进行统计
        while (right < s.size()) {
            int curr_right = s[right++] - 'a'; // 新读入的字符，更新窗口统计
            ++window[curr_right]; // 把读进来的字符映射表 + 1，并且向右移动 right 指针
            while (window[curr_right] > needs[curr_right]) --window[s[left++] - 'a'];
            if (right - left == p.size()) ans.push_back(left);  // 如果窗口长度符合要求了，那么就添加进来
        }
        return ans;
    }
};

int main() {
    Solution s;
    for (int item : s.findAnagrams("cbaebabacd", "abc"))
        cout << item << endl;
}
