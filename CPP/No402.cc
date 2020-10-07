/**
 * Created by Xiaozhong on 2020/9/14.
 * Copyright (c) 2020/9/14 Xiaozhong. All rights reserved.
 */
#include "string"
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        // 首先对num中每一个出现的字符遍历，并使用栈对其辅助处理
        // 如果栈顶元素 大于 当前元素，那么弹出栈顶元素（代表删掉了它），记得 k--
        for (char c : num) {
            // 这里一定要用 while 因为需要把不符合要求的元素 统统 删掉
            while (stk.size() > 0 && k > 0 && stk.back() > c) {
                stk.pop_back();
                --k;
            }
            stk.push_back(c);
        }
        // 补充删除，从尾部删除
        for (int i = 0; i < k; ++i) stk.pop_back();
        // 拼接最后答案
        string ans;
        bool leadingZero = true;    // 负责去除前导 0
        for (char c : stk) {
            if (leadingZero && c == '0') continue;
            leadingZero = false;
            ans.push_back(c);
        }
        // 如果字符串里面没东西，不能返回空字符串而是 "0"
        if (ans.length() == 0) return "0";
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.removeKdigits("10200", 1) << endl;
    cout << s.removeKdigits("1432219", 3) << endl;
    cout << s.removeKdigits("1234567890", 9) << endl;
}