/**
 * Created by Xiaozhong on 2020/11/10.
 * Copyright (c) 2020/11/10 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int sz = str.length();
        for (int i = 0; i < sz - 1; ++i) {
            char maxBit = str[i];
            int idx = 0;
            for (int j = i + 1; j < sz; ++j) {
                if (maxBit <= str[j]) {
                    maxBit = str[j];
                    idx = j;
                }
            }
            if (maxBit != str[i]) {
                swap(str[i], str[idx]);
                return stoi(str);
            }
        }
        return num;
    }
};

int main() {
    Solution s;
    cout << s.maximumSwap(9973) << endl;
    cout << s.maximumSwap(2736) << endl;
}