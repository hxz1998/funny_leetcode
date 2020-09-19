/**
 * Created by Xiaozhong on 2020/9/19.
 * Copyright (c) 2020/9/19 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
private:
    int count(int i, int j, int n) {   // 根据行数 i 和列数 j 来确定染了多少个块
        int sum = 0;
        sum += n * i;
        sum += n * j;
        sum -= i * j;
        return sum;
    }

    int cmn(int m, int n) {     // C_m^n
        if (n == 0) return 0;
        int ans = 1;
        for (int i = m; i >= n + 1; --i) {
            ans *= i;
        }
        for (int i = 1; i <= n; ++i) {
            ans /= i;
        }
        return ans;
    }

public:
    int paintingPlan(int n, int k) {
        if (k == 0) return 0;
        if (k < n) return 0;
        if (n * n == k) return 1;
        int ans = 0;
        for (int i = 0; i <= n; ++i) {       // 选择多少行
            for (int j = 0; j <= n; ++j) {   // 选择多少列
                if (k == count(i, j, n)) {
//                    cout << "可以的组合有： " << i << " " << j << " - " << cmn(n, i) << " - " << cmn(n, j) << endl;
                    if (i == 0) {
                        ans += cmn(n, j);
                    } else if (j == 0) {
                        ans += cmn(n, i);
                    } else {
                        ans += cmn(n, i) * cmn(n, j);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.paintingPlan(2, 4) << endl;
    cout << s.paintingPlan(2, 1) << endl;
    cout << s.paintingPlan(2, 2) << endl;
    cout << s.paintingPlan(4, 8) << endl;
    cout << s.paintingPlan(4, 0) << endl;
}