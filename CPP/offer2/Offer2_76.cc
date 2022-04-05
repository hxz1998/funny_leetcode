/**
 * Created by Xiaozhong on 2022/4/3.
 * Copyright (c) 2022/4/3 Xiaozhong. All rights reserved.
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

class Solution {
    bool flag = false;
    int ans = 0;

    int partition(vector<int> &nums, int left, int right, int target) {
        int pivot = nums[left];
        int low = left, high = right + 1;
        while (true) {
            while (nums[++low] >= pivot) if (low == right) break;
            while (nums[--high] <= pivot) if (high == left) break;
            if (low >= high) break;
            swap(nums[low], nums[high]);
        }
        swap(nums[left], nums[high]);
        return high;
    }

    void quickSort(vector<int> &nums, int left, int right, int target) {
        if (left >= right) return;
        int mid = partition(nums, left, right, target);
        quickSort(nums, left, mid - 1, target);
        if (mid > target) return;
        quickSort(nums, mid + 1, right, target);
    }

public:
    int findKthLargest(vector<int> &nums, int k) {
        quickSort(nums, 0, nums.size() - 1, k);
        return nums[k - 1];
    }
};

int main() {
    vector<int> nums = {-1, 2, 0};
    Solution s;
    cout << s.findKthLargest(nums, 2) << endl;
}