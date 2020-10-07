/**
 * Created by Xiaozhong on 2020/7/16.
 * Copyright (c) 2020/7/16 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        // 边界情况
        if (height.size() == 0) return 0;
        int ans = 0;
        int size = height.size();
        // left_max 用来记录从左边往右边走的过程中遇到的最大值
        // right_max 用来记录从右边往左边走的过程中遇到的最大值
        vector<int> left_max(size), right_max(size);
        // 对最左边的值进行更新，第一个元素直接取下标为 0 的元素，其余的开始更新
        left_max[0] = height[0];
        for (int i = 1; i < size; ++i) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        // 同上，对最左边的值进行更新，第一个元素取最末尾的元素，其余的开始更新
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        // 把答案进行更新，更新算法为：
        // 对于某一个下标 i ，在（左端看到的最大值，右端看到的最大值）中取一个最小值，然后减去当前容器的高度，然后加到最后的结果上
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        // 返回回来
        return ans;
    }
};

int main(int argc, char *args[]) {
    Solution s;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(height) << endl;
}