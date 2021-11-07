/*
 * Created by Xiaozhong on 10/28/2021.
 * Copyright (c) 10/28/2021 Xiaozhong. All rights reserved.
 */
#include "libs.hh"

class Solution {

public:
    bool reorderedPowerOf2(int n) {
        int num = 1;
        unordered_set<int> uSet;
        int times = 1;
        while (times++ <= 31) {
            uSet.insert(sorted(num));
            num <<= 1;
        }
        if (uSet.count(sorted(n))) return true;
        return false;
    }

private:
    long sorted(int num) {
        vector<int> vec;
        while (num > 0) {
            vec.push_back(num % 10);
            num /= 10;
        }
        sort(vec.rbegin(), vec.rend());
        long ret = 0;
        for (const int &item: vec) {
            ret *= 10;
            ret += item;
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.reorderedPowerOf2(46) << endl;
    cout << s.reorderedPowerOf2(1) << endl << s.reorderedPowerOf2(10) << endl << s.reorderedPowerOf2(16) << endl;
    cout << s.reorderedPowerOf2(24) << endl << s.reorderedPowerOf2(46) << endl;
    cout << "8774432110" << endl << INT32_MAX;
}