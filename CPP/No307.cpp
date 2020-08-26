/**
 * Created by Xiaozhong on 2020/8/26.
 * Copyright (c) 2020/8/26 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class NumArray {
private:
    int n = 0;
    vector<int> tree;

    // 构建整个线段树
    void buildTree(vector<int> &nums) {
        // 填充后面的叶子节点
        for (int i = n, j = 0; i < 2 * n; i++, j++) tree[i] = nums[j];
        // 填充前面的求和结果
        for (int i = n - 1; i > 0; i--) tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

public:
    NumArray(vector<int> &nums) {
        if (nums.size() > 0) {
            n = nums.size();
            tree.resize(2 * n);
            buildTree(nums);
        }
    }

    void update(int position, int val) {
        // 首先定位叶子节点所在位置，然后自底向上更新运算
        position += n;
        tree[position] = val;
        while (position > 0) {
            int left = position, right = position;
            if (position & 1) { // 说明当前位置在偏向右侧（右子节点），需要把左下标向左调整
                left = left - 1;
            } else {            // 说明当前位置在偏向左侧（左子节点），需要把右下标向右调整
                right = right + 1;
            }
            position >>= 1;     // 将下标 / 2
            tree[position] = tree[left] + tree[right];  // 更新和值
        }
    }

    int sumRange(int left, int right) {
        left += n;
        right += n;
        int sum = 0;
        while (left <= right) { // 求总和
            if (left & 1) sum += tree[left++];
            if (!(right & 1)) sum += tree[right--];
            left >>= 1;
            right >>= 1;
        }
        return sum;
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray n(nums);
    cout << n.sumRange(0, 2) << endl;
    n.update(1, 2);
    cout << n.sumRange(0, 2);

}
