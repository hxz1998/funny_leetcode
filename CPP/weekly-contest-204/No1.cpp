/**
 * Created by Xiaozhong on 2020/8/30.
 * Copyright (c) 2020/8/30 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    bool containsPattern(vector<int> &arr, int m, int k) {
        for (int i = 0; i < arr.size() - m; i++) {
            int count = 0;
            int j = i;
            for (int n = 0; n <= k; n++) {
                if (arr[j] == arr[m + j]) {
                    j++;
                    if (++count >= k) return true;
                    if (j - i >= m) continue;
                } else break;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 2, 4, 4, 4, 4};
    cout << s.containsPattern(arr, 1, 3) << endl;
    arr = {1, 2, 1, 2, 1, 1, 1, 3};
    cout << s.containsPattern(arr, 2, 2) << endl;
    arr = {1, 2, 1, 2, 1, 3};
    cout << s.containsPattern(arr, 2, 3) << endl;
}