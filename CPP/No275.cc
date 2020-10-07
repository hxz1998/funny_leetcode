/**
 * Created by Xiaozhong on 2020/8/24.
 * Copyright (c) 2020/8/24 Xiaozhong. All rights reserved.
 */

#include "vector"

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i = 0;
        while (i < citations.size() && citations[citations.size() - 1 - i] > i) i++;
        return i;
    }
};
