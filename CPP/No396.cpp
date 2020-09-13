/**
 * Created by Xiaozhong on 2020/9/12.
 * Copyright (c) 2020/9/12 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int> &A) {
        int n = A.size();
        long s = 0;
        long f = 0;
        for (int i = 0; i < n; ++i) {
            s += A[i];
            f += i * A[i]; // F[k]
        }
        long ans = f;
        for (int i = n - 1; i >= 0; --i) {
            // F[k + 1] = F[k] + Sum[B] - n * B[n - 1]
            f += s - n * (long) A[i];
            ans = max(ans, f);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> A = {4, 3, 2, 6};
    cout << s.maxRotateFunction(A) << endl;
}