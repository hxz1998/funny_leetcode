/**
 * Created by Xiaozhong on 2020/8/31.
 * Copyright (c) 2020/8/31 Xiaozhong. All rights reserved.
 */
#include "iostream"

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;
        long left = 2, right = num / 2, suspect;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            suspect = mid * mid;
            if (suspect == num) return true;
            if (suspect > num) right = mid - 1;
            if (suspect < num) left = mid + 1;
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isPerfectSquare(16) << endl;
    cout << s.isPerfectSquare(14) << endl;
}
