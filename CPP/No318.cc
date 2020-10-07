/**
 * Created by Xiaozhong on 2020/8/27.
 * Copyright (c) 2020/8/27 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    int maxProduct(vector<string> &words) {
        int size = words.size();
        vector<int> bits(size, 0);
        for (int i = 0; i < size; i++) {
            // 挨个对字符转换后的结果进行 或 运算，记录在 bits[i] 的每一位中
            for (char c : words[i]) bits[i] |= 1 << (c - 'a');
        }
        int ans = 0;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                // 判断是否两个字符串有交集，如果没有的话，那么就计算最大长度乘积
                if ((bits[i] & bits[j]) == 0) ans = max(ans, (int) (words[i].length() * words[j].length()));
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> words = {"a", "aa", "aaa", "aaaa"};
    cout << s.maxProduct(words);
}
