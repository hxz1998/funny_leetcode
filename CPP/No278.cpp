/**
 * Created by Xiaozhong on 2020/8/25.
 * Copyright (c) 2020/8/25 Xiaozhong. All rights reserved.
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int version) {
    if (version <= 3) return false;
    else return true;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n, ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return ans;
    }
};