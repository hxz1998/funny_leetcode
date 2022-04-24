/**
 * Created by Xiaozhong on 2022/4/7.
 * Copyright (c) 2022/4/7 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

//class Solution {
//    int mod = 1e6;
//public:
//    int numsOfStrings(int n, int k) {
//        unsigned long long ans = 0;
//        int length = 2;
//        while (n / length >= k) {
//            ans += static_cast<unsigned long long>(pow(25, n / length - 1)) * 26 % mod;
//            length++;
//        }
//        return static_cast<int>(ans) % mod;
//    }
//};

class Solution {
    int mod = 1e6;
    unsigned long long types = 0;

    void helper(int remain, int remainK, unsigned long long buffer) {
        if (remainK == 1) {
            types += buffer;
            return;
        }
        for (int len = 2; len <= remain - 2 * (remainK - 1); ++len) {
            helper(remain - len, remainK - 1, buffer + 1);
        }
    }

public:
    int numsOfStrings(int n, int k) {
        unsigned long long ans = 0;
        types = 0;
        int length = 2;
        // 枚举出来每一个长度组合方案
        helper(n, k, 1);
        ans = 26 * static_cast<unsigned long long>(pow(25, k - 1));
        ans = ans % mod * types;
        return static_cast<int>(ans) % mod / k;
    }
};

//class Solution {
//    int mod = 1e6;
//public:
//    int numsOfStrings(int n, int k) {
//        unsigned long long ans = 0;
//        int types = k * (n - 2 * (k - 1) - 2 + 1);
//        if (k % 2 == 0) types /= 2;
//        ans = 26 * (static_cast<unsigned long long>(pow(25, k - 1)) % mod);
//        ans = ans % mod * types;
//        return static_cast<int>(ans) % mod;
//    }
//};

int main() {
    Solution s;
//    cout << s.numsOfStrings(10, 2) << endl;
//    cout << 7 * 650 << endl;
    cout << s.numsOfStrings(2, 1) << endl;  // 26
    cout << s.numsOfStrings(4, 2) << endl;  // 650
    cout << s.numsOfStrings(10, 2) << endl; // 4550
    cout << s.numsOfStrings(10, 3) << endl;
    cout << 15 * 26 * 25 * 25 << endl;
    cout << s.numsOfStrings(10, 4) << endl;
    cout << s.numsOfStrings(1000, 500) << endl;
}

