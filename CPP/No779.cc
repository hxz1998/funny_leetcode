/**
 * Created by Xiaozhong on 2020/12/9.
 * Copyright (c) 2020/12/9 Xiaozhong. All rights reserved.
 */
#include <iostream>

using namespace std;

class Solution {
    int helper(int N, int K, int flag) {
        if (N == 0 || N == 1) return flag;
        int idx = (1 << (N - 2));
        if (K <= idx) {
            return helper(N - 1, K, flag);
        } else {
            return helper(N - 1, K - idx, 1 - flag);
        }
    }

public:
    /**
     * 第 K 个数字是上一行第 (K+1) / 2 个数字生成的。
     * 如果上一行的数字为 0，被生成的数字为 1 - (K%2)，
     * 如果上一行的数字为 1，被生成的数字为 K%2
     */
    int kthGrammar(int N, int K) {
        return helper(N, K, 0);
    }
};

int main() {
    Solution s;
    cout << s.kthGrammar(4, 5) << endl;
}