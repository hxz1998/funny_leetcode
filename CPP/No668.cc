/**
 * Created by Xiaozhong on 2020/11/9.
 * Copyright (c) 2020/11/9 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (kThCount(m, n, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    int kThCount(int m, int n, int mid) {
        int res = 0, row = 1, col = m;
        while (col > 0 && row <= n) {
            if (col * row <= mid) {
                res += col;
                row++;
            } else col--;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.findKthNumber(3, 3, 5) << endl;
}