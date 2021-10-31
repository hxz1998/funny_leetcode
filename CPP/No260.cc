/**
 * Created by Xiaozhong on 2020/8/24.
 * Copyright (c) 2020/8/24 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

/*class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int bitmask = 0;
        vector<int> ans;
        for (int num : nums) bitmask ^= num;

        int diff = bitmask & (-bitmask); // 找到 x 和 y 第一次不同的地方，然后标记 1（整个diff中只有一个1）
        int x = 0;
        // 过滤出 x，因为其他出现两次的数都被 ^ 运算抵消掉了，而出现一次的数被上面的diff给过滤掉了
        for (int num :nums) if ((num & diff) != 0) x ^= num;
        return vector<int>({x, bitmask ^ x});
    }
};*/
class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        vector<int> ans;
        int xorValue = 0;
        sort(nums.begin(), nums.end());

        for (int idx = 0; idx < nums.size(); idx += 2) {
            if (nums[idx] != nums[idx + 1] && ans.empty()) ans.emplace_back(nums[idx]);
            xorValue ^= nums[idx];
            xorValue ^= nums[idx + 1];
        }
        ans.emplace_back(xorValue ^ ans[0]);
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 1, 2, 3, 4, 1};
    Solution s;
    vector<int> ans = s.singleNumber(nums);
    for (int i : ans) cout << i << " ";
    cout << endl << -(3 ^ 5) << endl;
}