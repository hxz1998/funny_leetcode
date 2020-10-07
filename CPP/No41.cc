/**
 * Created by Xiaozhong on 2020/7/16.
 * Copyright (c) 2020/7/16 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        // 首先，对数组进行遍历，并且将所有元素放到它应该放的地方
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // 如果某一位置上放置的元素不是本该放置的，那么就返回该节点的位置
        for (int j = 0; j < n; ++j) {
            if (nums[j] != j + 1) {
                return j + 1;
            }
        }
        return n + 1;
    }
};


int main(int argc, char *args[]) {
    Solution s;
    vector<int> nums = {3, 4, -1, 1};
    cout << s.firstMissingPositive(nums) << endl;
}

/**
 * 下面的方法会报错，错误信息为：
 * Line 923: Char 34: runtime error: addition of unsigned offset to 0x602000000030 overflowed to 0x60200000002c (stl_vector.h)
 * SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/8/../../../../include/c++/8/bits/stl_vector.h:933:34
 * 原因目前未知
 */
//class Solution {
//public:
//    int firstMissingPositive(vector<int> &nums) {
//        int n = nums.size();
//        // 首先对数组中所有的数据取正处理，让 <= 0 的数据修改为 N + 1
//        for (int i = 0; i < n; i++) {
//            if (nums[i] < 0) {
//                nums[i] = INT32_MAX;
//            }
//        }
//
//        // 然后对出现过的数据打上标记，标记为 -1 ，即：原来为 1 时，打上标记就成了 -1
//        for (int i = 0; i < n; i++) {
//            int num = abs(nums[i]);
//            if (num <= n) {
//                nums[num - 1] = -abs(nums[num - 1]);
//            }
//        }
//
//        // 最后检查，碰到第一个大于 0 的数，就是所要求的数
//        for (int i = 0; i < n; i++) {
//            if (nums[i] > 0) {
//                return i + 1;
//            }
//        }
//        // 否则返回 n + 1
//        return n + 1;
//    }
//};