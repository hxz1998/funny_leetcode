/**
 * Created by Xiaozhong on 2020/9/21.
 * Copyright (c) 2020/9/21 Xiaozhong. All rights reserved.
 */
#include "iostream"

using namespace std;

/*class Solution {
public:
    int findKthNumber(int n, int k) {
        auto getCount = [](int prefix, int n) {
            int count = 0;
            for (long long i = prefix, i_next = prefix + 1; i <= n; i *= 10, i_next *= 10)
                count += min(i_next, (long long) n + 1) - i;
            return count;
        };

        int p = 1, prefix = 1;
        while (p < k) {
            int count = getCount(prefix, n);
            if (p + count > k) {
                prefix *= 10;
                ++p;
            } else if (p + count <= k) {
                ++prefix;
                p += count;
            }
        }
        return prefix;
    }
};*/

class Solution {
    long long getSteps(long long curr, long long n) {
        long long steps = 0, first = curr, last = curr;
        while (first <= n) {
            steps += min(last, n) - first + 1;
            first *= 10;
            last = first + 9;
        }
        return steps;
    }

public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            long long steps = getSteps(curr, n);
            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr = curr * 10;
                k--;
            }
        }
        return curr;
    }
};

int main() {
    Solution s;
    cout << s.findKthNumber(681692778, 351251360) << endl;
}