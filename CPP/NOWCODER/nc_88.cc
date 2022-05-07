/**
 * Created by Xiaozhong on 2022/4/28.
 * Copyright (c) 2022/4/28 Xiaozhong. All rights reserved.
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
    int partition(vector<int> &nums, int left, int right) {
        int v = nums[left];
        int low = left, high = right + 1;
        while (true) {
            while (nums[++low] >= v) if (low == right) break;
            while (nums[--high] <= v) if (high == left) break;
            if (low >= high) break;
            swap(nums[low], nums[high]);
        }
        swap(nums[left], nums[high]);
        return high;
    }

    void quickSort(vector<int> &nums, int left, int right, int K) {
        if (left >= right) return;
        int index = partition(nums, left, right);
        quickSort(nums, left, index - 1, K);
        if (index < K - 1) quickSort(nums, index + 1, right, K);
    }

public:
    int findKth(vector<int> nums, int n, int K) {
        quickSort(nums, 0, n - 1, K);
        return nums[K - 1];
    }
};

int main() {
    vector<int> nums = {9, 9, 12, 5, 10, 6};
    Solution s;
    s.findKth(nums, 6, 3);
}