/**
 * Created by Xiaozhong on 2020/10/20.
 * Copyright (c) 2020/10/20 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_set>
#include <list>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int> &nums) {
        int ans = 0;
        vector<bool> visited(nums.size(), false);
        for (int i = 0; i < nums.size(); ++i) {
            int path = 0;
            while (!visited[i]) {
                visited[i] = true;
                ++path;
                i = nums[i];
            }
            ans = max(ans, path);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 4, 0, 3, 1, 6, 2};
    cout << s.arrayNesting(nums) << endl;
}