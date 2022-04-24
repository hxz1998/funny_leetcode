/**
 * Created by Xiaozhong on 2022/4/7.
 * Copyright (c) 2022/4/7 Xiaozhong. All rights reserved.
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
    int minCnt(string s) {
        int num = 0;
        for (char c: s) if (c == '1') num++;
        return num - 1;
    }
};