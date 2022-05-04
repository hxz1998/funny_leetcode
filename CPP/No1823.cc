/**
 * Created by Xiaozhong on 2022/5/4.
 * Copyright (c) 2022/5/4 Xiaozhong. All rights reserved.
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
public:
    int findTheWinner(int n, int k) {
        if (n <= 1) return n;
        // 前后两次开始的位置不同，所以有一个 k 的偏移差。
        int ans = (findTheWinner(n - 1, k) + k) % n;
        return ans == 0 ? n : ans;
    }
};