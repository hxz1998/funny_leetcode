/*
 * Created by Xiaozhong on 12/3/2021.
 * Copyright (c) 12/3/2021 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
private:
    int mod = 1e9 + 7;
public:
    int cuttingRope(int n) {
        if (n < 2) return 0;
        else if (n == 2) return 1;
        else if (n == 3) return 2;
        else {
            auto remainder = [](const int x, int a, const int c) -> long long {
                long long ret = 1;
                while (a-- > 0) {
                    ret = ret * x % c;
                }
                return ret;
            };

            int a = n / 3, b = n % 3;
            if (b == 1) return (int) (remainder(3, a - 1, mod) * 4 % mod);
            else if (b == 2) return (int) remainder(3, a, mod) * 2 % mod;
            else return (int) remainder(3, a, mod);
        }
    }
};

int main() {
    Solution s;
    cout << s.cuttingRope(10) << " " << s.cuttingRope(2) << endl;
    double a = 1.123, b = 1.123;
    cout << (1.123 == 1.123) << endl;
    cout << (a == b) << endl;
}