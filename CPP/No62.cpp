/**
 * Created by Xiaozhong on 2020/7/22.
 * Copyright (c) 2020/7/22 Xiaozhong. All rights reserved.
 */

#include <iostream>

using namespace std;

class Solution {
private:
    // 记录下来访问过的次数，也就是到达这点的次数
    int a[101][101] = {0};
public:
    int uniquePaths(int m, int n) {
        // 特例以及返回条件
        if (m == 0 || n == 0) return 0;
        if (m == 1 || n == 1) return 1;
        // 如果a[m][n] > 0 那么说明已经访问过了
        if (a[m][n] > 0) return a[m][n];
        // a[m - 1][n] 点记录的是到这点可走的路径个数
        a[m - 1][n] = uniquePaths(m - 1, n);
        // 同上
        a[m][n - 1] = uniquePaths(m, n - 1);
        // 记录下来最终的次数
        a[m][n] = a[m - 1][n] + a[m][n - 1];
        return a[m][n];
    }
};

int main() {
    Solution s;
    cout << s.uniquePaths(51, 9);
}