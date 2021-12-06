/**
 * Created by Xiaozhong on 2020/8/31.
 * Copyright (c) 2020/8/31 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

/*class Solution {
private:
    // 快速幂算法加速计算，但是每一个发生乘法的地方仍要 mod 1337
    int qpow(int x, int n) {
        int res = 1;
        while (n) {
            if (n & 1) {
                res = (res * x) % 1337;
            }
            x %= 1337;
            x = (x * x) % 1337;
            n >>= 1;
        }
        return res;
    }

public:
    int superPow(int a, vector<int> &b) {
        int ans = 1, size = b.size();
        for (int i = size - 1; i >= 0; --i) {
            ans = (ans * qpow(a, b[i]) % 1337); // 相乘值
            a = qpow(a, 10) % 1337; // 倍增底数
        }
        return ans;
    }
};*/
class Solution {
private:
    int mod = 1337;
public:
    int superPow(int a, vector<int> &b) {
        int n = b.size();
        int ans = 1;
        a %= mod;
        while (n) {
            ans *= quickPow(a, b[n - 1]) % mod;
            a = quickPow(a, 10) % mod;
            n--;
        }
        return ans;
    }

private:
    // 快速幂算法，计算 x^y 的结果
    int quickPow(int x, int y) {
        int ret = 1;
        while (y > 0) {
            if (y & 1) ret = (ret * x) % mod;
            y >>= 1;
            x = x * x % mod;
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> b = {1, 0};
    cout << s.superPow(2, b) << endl;
}