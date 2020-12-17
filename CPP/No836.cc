/**
 * Created by Xiaozhong on 2020/12/17.
 * Copyright (c) 2020/12/17 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
        return !(rec1[2] <= rec2[0] ||   // 左
                 rec1[1] >= rec2[3] ||   // 上
                 rec1[3] <= rec2[1] ||   // 下
                 rec1[0] >= rec2[2] ||   // 右
                 rec1[0] == rec1[2] ||   // 检查矩形是不是一条线
                 rec1[1] == rec1[3] ||
                 rec2[0] == rec2[2] ||
                 rec2[1] == rec2[3]
        );
    }
};