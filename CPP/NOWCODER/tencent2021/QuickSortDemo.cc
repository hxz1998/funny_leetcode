/**
 * Created by Xiaozhong on 2022/3/24.
 * Copyright (c) 2022/3/24 Xiaozhong. All rights reserved.
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

//int partition(vector<int> &nums, int low, int high) {
//    int left = low, right = high + 1;
//    int v = nums[low];
//    while (true) {
//        while (nums[++left] <= v) if (left == high) break;
//        while (nums[--right] >= v) if (right == low) break;
//        if (left >= right) break;
//        swap(nums[left], nums[right]);
//    }
//    swap(nums[low], nums[right]);
//    return right;
//}
//
//void quickSort(vector<int> &nums, int low, int high) {
//    if (low >= high) return;
//    int index = partition(nums, low, high);
//    quickSort(nums, low, index - 1);
//    quickSort(nums, index + 1, high);
//}

int partition(vector<int> &nums, int left, int right) {
    int low = left, high = right + 1;
    int v = nums[left];
    while (true) {
        while (nums[++low] <= v) if (low == right) break;
        while (nums[--high] >= v) if (high == left) break;
        if (low >= high) break;
        swap(nums[low], nums[high]);
    }
    swap(nums[left], nums[high]);
    return high;
}

void quickSort(vector<int> &nums, int left, int right) {
    if (left >= right) return;
    int index = partition(nums, left, right);
    quickSort(nums, left, index - 1);
    quickSort(nums, index + 1, right);
}

int main() {
    vector<int> nums = {1, 3, 5, 2, 2, 6, -1, 3};
    quickSort(nums, 0, nums.size() - 1);
    for (int num: nums) cout << num << " ";
}