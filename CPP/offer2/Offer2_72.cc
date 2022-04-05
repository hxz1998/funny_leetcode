/**
 * Created by Xiaozhong on 2022/3/15.
 * Copyright (c) 2022/3/15 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x / 2;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid * mid < x && (mid + 1) * (mid + 1) > x) return mid;
            else if (mid * mid == x) return mid;
            else if ((mid + 1) * (mid + 1) == x) return mid + 1;
            else if (mid * mid > x) right = mid;
            else if ((mid + 1) * (mid + 1) < x) left = mid + 1;
        }
        return 0;
    }
};

int main() {
    Solution s;
    cout << s.mySqrt(4) << endl;
}