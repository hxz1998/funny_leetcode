/**
 * Created by Xiaozhong on 2022/4/28.
 * Copyright (c) 2022/4/28 Xiaozhong. All rights reserved.
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
    /**
     * 如果 A 节点和 B 的长度就不一样，那么就不需要比较了，直接返回 false就好了。
     * 否则的话，先把 A 拼接一个 A 连成一个长条，然后检查是否存在 B 作为 A 的子串
     */
    bool solve(string A, string B) {
        if (A.size() != B.size()) return false;
        if (A == B) return true;
        A = A + A;
        return A.find(B) != A.npos;
    }
};