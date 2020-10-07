/**
 * Created by Xiaozhong on 2020/8/27.
 * Copyright (c) 2020/8/27 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "string"
#include "deque"
#include "iostream"

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int size = s.length();
        if (size <= 1) return s;
        // 用来标记每一个字符是否在前面已经用过了
        vector<bool> used(26, false);

        // 记下每一个字符在字符串中最后出现的位置
        int last_appear_index[26];
        for (int i = 0; i < size; i++) last_appear_index[s[i] - 'a'] = i;

        // 使用双端队列，来存储结果
        deque<char> dq;
        for (int i = 0; i < size; i++) {
            if (used[s[i] - 'a']) continue; // 如果在前面已经出现过了，那么就跳过
            /**
             * 如果队列最后一个符号 dq.back() 小于当前读入的符号 s[i]，也就说明是降序，
             * 那么就要判断是否在后面又出现了 dp.back()
             * 如果后面还有，那么就把当前的 dp.back() 给弹出来，然后把 s[i] 入队，
             * 否则就继续入队，忽略这个降序
             */
            while (!dq.empty() && dq.back() > s[i] && last_appear_index[dq.back() - 'a'] >= i) {
                char c = dq.back();         // 把符号弹出来，然后取消它的出现
                dq.pop_back();
                used[c - 'a'] = false;
            }
            dq.push_back(s[i]);             // 将符号入队
            used[s[i] - 'a'] = true;        // 标记出现过了
        }
        // 拼最后的结果
        string ans;
        while (!dq.empty()) {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.removeDuplicateLetters("cbacdcbc");
}