/**
 * Created by Xiaozhong on 2021/10/31.
 * Copyright (c) 2021/10/31 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"

using namespace std;

int main() {
    int t;
    int mod = 425;
    cin >> t;
    t /= 60;
    if (t == 0) cout << 0;
    else if (t >= 1 && t <= 3) cout << 1;
    else {
        int first = 1, second = 1, third = 1;
        for (int i = 4; i <= t; ++i) {
            int tmp = third;
            third = (first + second + third) % mod;
            first = second;
            second = tmp;
        }
        cout << third % mod;
    }
}