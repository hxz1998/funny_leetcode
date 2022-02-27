/**
 * Created by Xiaozhong on 2020/10/17.
 * Copyright (c) 2020/10/17 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*class Solution {
public:
    string optimalDivision(vector<int> &nums) {
        // 只要保证除数最小，被除数最大就好
        string res = "";

        if (nums.size() == 1) return to_string(nums.front());
        if (nums.size() == 2) return to_string(nums.front()) + "/" + to_string(nums.back());
        for (int i = 0; i < nums.size(); ++i) {
            res += to_string(nums[i]);
            if (i != nums.size() - 1) res += "/";
            if (i == 0) res += "(";
        }
        return res += ")";
    }
};*/

class Solution {
public:
    string optimalDivision(vector<int> &nums) {
        // 只要保证除数最小，被除数最大就好
        string ret = "";
        if (nums.size() == 0) return ret;
        else if (nums.size() == 1) return to_string(nums[0]);
        else if (nums.size() == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            ret.append(to_string(nums[idx]));
            if (idx != nums.size() - 1) ret.push_back('/');
            if (idx == 0) ret.push_back('(');
        }
        ret.push_back(')');
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1000, 100, 10, 2};
    cout << s.optimalDivision(nums) << endl;
}