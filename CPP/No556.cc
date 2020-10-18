/**
 * Created by Xiaozhong on 2020/10/18.
 * Copyright (c) 2020/10/18 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        // 转换成字符序列
        string num = to_string(n);
        // i 确定的是从右到左，第一个降序的位置
        int i = num.size() - 2;
        while (i >= 0 && num[i] >= num[i + 1]) --i;
        if (i < 0) return -1;

        // j 确定的是，从右向左，第一个大于 num[i] 的数
        int j = num.size() - 1;
        while (j >= 0 && num[j] <= num[i]) --j;

        // 交换 i 和 j 位置的元素
        char t = num[i];
        num[i] = num[j];
        num[j] = t;

        // 把 i 右侧 逆序 过来
        int left = i + 1, right = num.size() - 1;
        while (left < right) {
            t = num[left];
            num[left] = num[right];
            num[right] = t;
            ++left;
            --right;
        }
        try {
            return stoi(num);
        } catch (std::out_of_range) {
            return -1;
        }
    }
};

int main() {
    Solution s;
    cout << s.nextGreaterElement(12) << endl;
    cout << s.nextGreaterElement(21) << endl;
    cout << s.nextGreaterElement(1999999999) << endl;
}