/**
 * Created by Xiaozhong on 2020/7/17.
 * Copyright (c) 2020/7/17 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        int len = nums.size();
        vector<vector<int>> ans;

        // 边界条件
        if (len == 0) {
            return ans;
        }

        // 剪枝的前提：要先排序
        sort(nums.begin(), nums.end());
        //用来记录使用过的元素
        vector<bool> visited(nums.size());
        // 记录下来整个访问路径，单次使用，完成一个结果后就要清空了
        vector<int> path;

        // 开始更新生成
        dfs(nums, len, 0, visited, path, ans);
        return ans;
    }

private:
    /*
     * 深度优先搜索算法，其中
     * nums 是原来的数组，
     * len 是 num 的长度
     * depath 是当前的深度
     * visited 是用来记录已经访问过的元素
     * path 用来记录临时的路径
     * ans 最终的结果
     */
    void dfs(vector<int> &nums, int len, int depath, vector<bool> visited, vector<int> &path,
             vector<vector<int>> &ans) {
        // 如果已经检查完所有的元素了，那么就把当前的合法路径记录在返回值中
        if (depath == len) {
            ans.push_back(path);
            return;
        }

        // 开始从 0 检查元素，看看哪个没用过呢
        for (int i = 0; i < len; ++i) {
            // 用过了就跳过去
            if (visited[i]) continue;
            // 剪枝操作
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
            // 把当前元素放到临时路径中，并标记使用过了
            path.push_back(nums[i]);
            visited[i] = true;
            // 检查下一个深度
            dfs(nums, len, depath + 1, visited, path, ans);
            // 把当前元素吐出来，然后取消标记
            visited[i] = false;
            path.pop_back();
        }
    }
};

int main(int argc, char *args[]) {
    Solution s;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> ans = s.permuteUnique(nums);
    for (vector<int> item : ans) {
        for (int i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
}