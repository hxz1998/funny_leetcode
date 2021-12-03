/*
 * Created by Xiaozhong on 12/2/2021.
 * Copyright (c) 12/2/2021 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2) return 0;
        else if (n == 2) return 1;
        else if (n == 3) return 2;
        else {
            vector<int> products(n + 1, 0);
            products[0] = 0;
            products[1] = 1;
            products[2] = 2;
            products[3] = 3;
            for (int totalLength = 4; totalLength <= n; ++totalLength) {
                int mx = 0;
                for (int leftLength = 1; leftLength <= totalLength / 2; ++leftLength) {
                    mx = max(mx, products[leftLength] * products[totalLength - leftLength]);
                }
                products[totalLength] = mx;
            }
            return products[n];
        }
    }
};

int main() {
    Solution s;
    cout << s.cuttingRope(2) << " " << s.cuttingRope(10) << endl;
}