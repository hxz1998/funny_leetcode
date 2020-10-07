/**
 * Created by Xiaozhong on 2020/8/30.
 * Copyright (c) 2020/8/30 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    bool containsPattern(vector<int> &arr, int m, int k) {
        /**
         * 这道题直接暴力遍历就好了，因为题目中说了 arr.length < 100，不算特别大
         * 弄一个宽度为 m 的窗进行遍历
         */
        int n = arr.size();
        if (n < m * k) return false;
        for (int i = 0; i <= n - m * k; i++) {
            int j = i + m;
            for (; j < i + m * k; j++) {
                // 判断当前元素和前面的元素是否相同，如果不同则开始检查下一个起始位置
                if (arr[j] != arr[j - m]) break;
            }
            if (j == i + m * k) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 2, 4, 4, 4, 4};
    cout << s.containsPattern(arr, 1, 3) << endl;
    arr = {1, 2, 1, 2, 1, 1, 1, 3};
    cout << s.containsPattern(arr, 2, 2) << endl;
    arr = {1, 2, 1, 2, 1, 3};
    cout << s.containsPattern(arr, 2, 3) << endl;
}