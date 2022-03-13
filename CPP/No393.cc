/**
 * Created by Xiaozhong on 2020/9/11.
 * Copyright (c) 2020/9/11 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

// 原始方法
/*class Solution {
public:
    bool validUtf8(vector<int> &data) {
        int num = 0;
        int mask1 = 1 << 7, mask2 = 1 << 8;
        for (int i = 0; i < data.size(); ++i) {
            if (num == 0) {
                int mask = 1 << 7;
                while ((mask & data[i]) != 0) {
                    num += 1;
                    mask >>= 1;
                }
                if (num == 0) continue;
                if (num > 4 || num == 1) return false;
            } else {
                if (!((data[i] & mask1) != 0 && (mask2 & data[i]) == 0)) return false;
            }
            num -= 1;
        }
        return num == 0;
    }
};*/

class Solution {
public:
    bool validUtf8(vector<int> &data) {
        int n = static_cast<int>(data.size());
        if (n > 4) return false;
        for (int idx = 0; idx < n; ++idx) {
            bool isSingleSign = (data[idx] & (1 << 7)) == 0;
            if (isSingleSign) {
                continue;
            } else {
                int tmp = data[idx];
                int cnt = 0;
                while ((tmp & (1 << 7)) != 0) {
                    tmp <<= 1;
                    cnt++;
                }
                if (idx == n || cnt > n - idx || cnt == 1) return false;
                while (--cnt > 0 && idx++ < n) {
                    if ((data[idx] & (1 << 7)) != (1 << 7)) return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> data = {240, 162, 138, 147, 145};
    cout << s.validUtf8(data) << endl;
    data = {145};
    cout << s.validUtf8(data) << endl;
    data = {230, 136, 145};
    cout << s.validUtf8(data) << endl;
    data = {197, 130, 1};
    cout << s.validUtf8(data) << endl;
    data = {235, 140, 4};
    cout << s.validUtf8(data) << endl;
}