//
// Created by Monkey on 2020/5/5.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v = {2, 7, 11, 15};
    vector<int> result = s.twoSum(v, 9);
    for (int i : result) {
        cout << i << " ";
    }
}
