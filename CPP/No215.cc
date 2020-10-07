/**
 * Created by Xiaozhong on 2020/8/21.
 * Copyright (c) 2020/8/21 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"
#include "cstdlib"
#include "time.h"

using namespace std;

class Solution {
private:
    void swap(vector<int> &nums, int i, int j) {
        // 交换两个元素
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    int partition(vector<int> &nums, int lo, int hi) {
        // 将随机选出的中间节点两侧元素排序好，并且返回排好元素的下标以供检查
        if (lo < hi) {
            int index = rand() % (hi - lo) + lo + 1;
            swap(nums, index, lo);
        }
        int pivot = nums[lo], j = lo;
        for (int i = lo + 1; i <= hi; i++) {
            if (pivot > nums[i]) {      // 本来该出现在左侧的元素，出现在了右侧
                swap(nums, ++j, i);
            }
        }
        swap(nums, j, lo);              // 将 pivot 调整到正确的位置
        return j;
    }

public:
    int findKthLargest(vector<int> &nums, int k) {
        // 最简单的方法，直接排序后返回倒数第 k 个元素，当然~该方法不会让人满意
        /*
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
        */
        srand(time(0));                 // 设置随机数种子
        int lo = 0, hi = nums.size() - 1, target = nums.size() - k;
        while (true) {
            int index = partition(nums, lo, hi);        // 改进后的快速排序算法，只要获取到目标 target 就可以结束了，不用排序完
            if (index < target) lo = index + 1;         // 目标在右边，调整左下标
            else if (index > target)hi = index - 1;     // 目标在左边，调整右下标
            else return nums[index];
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << s.findKthLargest(nums, 2) << endl;
}