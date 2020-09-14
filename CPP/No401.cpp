/**
 * Created by Xiaozhong on 2020/9/14.
 * Copyright (c) 2020/9/14 Xiaozhong. All rights reserved.
 */
#include "string"
#include "vector"
#include "iostream"

using namespace std;

class Solution {
private:
    int count(int n) {
        /*
         * 对 n 进行检查，检查有几位 1
         */
        int num = 0;
        while (n != 0) {
            n = n & (n - 1);
            ++num;
        }
        return num;
    }

public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        /*
         * 从 0:00 - 11:59，挨个检查是否符合要求
         */
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (count(h) + count(m) == num) {
                    ans.push_back(to_string(h) + ":" +
                                  (m < 10 ? "0" + to_string(m) : to_string(m)));
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    for (string item : s.readBinaryWatch(1)) {
        cout << item << endl;
    }
}