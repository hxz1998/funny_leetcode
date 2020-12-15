/**
 * Created by Xiaozhong on 2020/12/15.
 * Copyright (c) 2020/12/15 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        for (int i = 0; i < s.length();) {
            // 首先记录下来当前要检查的字符
            char curr = s[i];
            // 记录下来开始位置，结束位置 end 在遍历过程中进行更新
            int start = i, end = i;
            // 更新结束位置
            while (s[end] == curr) ++end;
            // 如果结束位置和开始位置之间相差 3 个及以上，那么就把结果放到返回值中
            if ((end - start) >= 3) ans.push_back({start, end - 1});
            // 然后直接更新下一个开始的位置
            i = end;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> ans = s.largeGroupPositions("abcdddeeeeaabbbcd");
    return 0;
}

