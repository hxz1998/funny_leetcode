/**
 * Created by Xiaozhong on 2020/12/18.
 * Copyright (c) 2020/12/18 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int left = 1, right = arr.size() - 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    Solution s;
    vector<int> arr = {18, 29, 38, 59, 98, 100, 99, 98, 90};
    cout << s.peakIndexInMountainArray(arr) << endl;
}
// 这种方法太笨了
/*
class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int ans = 0, max_ele = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > max_ele) {
                ans = i;
                max_ele = arr[i];
            }
        }
        return ans;
    }
};*/
