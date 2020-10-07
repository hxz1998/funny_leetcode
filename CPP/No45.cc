/**
 * Created by Xiaozhong on 2020/7/17.
 * Copyright (c) 2020/7/17 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        /*
         * max_position 记录了当前已经处理过的节点可以到达的最远处
         * end 记录了边界条件
         * step 记录了已经走过的步数，也就是经历过的边界条件
         */
        int max_position = 0, end = 0, step = 0, n = nums.size();
        // 从头到尾，遍历数组，但是不用处理最后一个元素，因为最后的结果一定是大于等于末尾的
        for (int i = 0; i < n - 1; ++i) {
            // 如果当前的位置不满足可到达的最远位置，那么就继续
            if (max_position >= i) {
                // 更新一下可以到达的最远位置，nums[i] + i 是因为更新时要加上去的时它跳过的布数
                max_position = max(max_position, nums[i] + i);
                // 如果到了边界，那么就更新边界而且增加一个步数
                if (i == end) {
                    step++;
                    end = max_position;
                }
            }
        }
        return step;
    }
};

int main(int argc, char *args[]) {
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << s.jump(nums) << endl;
}