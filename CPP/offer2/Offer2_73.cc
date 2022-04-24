/**
 * Created by Xiaozhong on 2022/4/20.
 * Copyright (c) 2022/4/20 Xiaozhong. All rights reserved.
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
#include <list>
#include <random>

using namespace std;

class Solution {
private:
    int helper(const vector<int> &piles, int speed) {
        int ret = 0;
        for (int pile: piles) {
            ret += ((pile + speed - 1) / speed);
        }
        return ret;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int mx = *max_element(piles.begin(), piles.end());
        int left = 1, right = mx;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int hours = helper(piles, mid);
            if (hours > h) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

int main() {

}