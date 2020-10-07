/**
 * Created by Xiaozhong on 2020/9/11.
 * Copyright (c) 2020/9/11 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
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
};

int main() {
    Solution s;
    vector<int> data = {197, 130, 1};
    cout << s.validUtf8(data) << endl;
    data = {235, 140, 4};
    cout << s.validUtf8(data) << endl;
}