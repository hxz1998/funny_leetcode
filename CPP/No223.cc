/**
 * Created by Xiaozhong on 2020/8/22.
 * Copyright (c) 2020/8/22 Xiaozhong. All rights reserved.
 */
#include "iostream"

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area_1 = (C - A) * (D - B);
        int area_2 = (G - E) * (H - F);
        int x1 = max(A, E), y1 = max(B, F); // 求两个子区域的左下角
        int x2 = min(C, G), y2 = min(D, H); // 求两个子区域的右上角
        if (x1 <= x2 && y1 <= y2) {
            return area_1 - (x2 - x1) * (y2 - y1) + area_2; // 防止溢出，先减再加
        }
        return area_1 + area_2;
    }
};

int main() {
    Solution s;
    cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
}