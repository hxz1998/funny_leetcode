/**
 * Created by Xiaozhong on 2020/11/7.
 * Copyright (c) 2020/11/7 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        if (x <= arr.front()) return vector<int>(arr.begin(), arr.begin() + k);
        if (x >= arr.back()) return vector<int>(arr.end() - k, arr.end());
        int left = 0, right = arr.size() - 1;
        while (right - left + 1 > k) {
            if (x - arr[left] <= arr[right] - x) {
                --right;
            } else {
                ++left;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};

int main() {
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> ans = s.findClosestElements(arr, 4, 3);
    for (int i : ans) cout << i << " ";
    cout << endl;
    ans = s.findClosestElements(arr, 4, -1);
    for (int i : ans) cout << i << " ";
    cout << endl;
    arr = {1, 1, 1, 10, 10, 10};
    ans = s.findClosestElements(arr, 1, 9);
    for (int i : ans) cout << i << " ";
}