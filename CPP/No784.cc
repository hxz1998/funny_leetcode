/**
 * Created by Xiaozhong on 2020/12/10.
 * Copyright (c) 2020/12/10 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
private:
    // 用来存放生成的字符串
    vector<string> container;

    // 回溯算法，从 start 往后挨个检查是否是字母，如果是就替换，否则就跳过
    void backtrack(string s, int start) {
        for (int i = start; i < s.length(); ++i) {
            if ((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A')) {
                // 大小转小写，小写转大写，都用 ^= 32 即可
                s[i] ^= 32;
                container.emplace_back(s);
                backtrack(s, i + 1);
                // 回溯
                s[i] ^= 32;
            } else {
                continue;
            }
        }
    }

public:
    vector<string> letterCasePermutation(string S) {
        container.emplace_back(S);
        backtrack(S, 0);
        return container;
    }
};

int main() {
    Solution s;
    vector<string> ans = s.letterCasePermutation("a1b2");
    return 0;
}