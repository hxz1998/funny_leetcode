/**
 * Created by Xiaozhong on 2020/12/15.
 * Copyright (c) 2020/12/15 Xiaozhong. All rights reserved.
 */
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        // 建立字符映射表，table[index] = priority，其中
        // index：表示字符，priority：表示出现的次序（优先级）
        vector<int> table(26, 0);
        // 对 S 中每一个字符的优先级进行指定
        for (int priority = 0, idx = 0; idx < S.length(); ++idx)
            table[S[idx] - 'a'] = priority++;
        // 根据优先级进行排序
        sort(T.begin(), T.end(), [&](char lhs, char rhs) {
            return table[lhs - 'a'] < table[rhs - 'a'];
        });
        return T;
    }
};

int main() {
    Solution s;
    cout << s.customSortString("cba", "abcd") << endl;
}