//
// Created by cherry on 2020/7/13.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int length = nums.size();
        if (length == 0) return -1;
        if (length == 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = length - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && nums[mid] > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && nums[length - 1] >= target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char *args[]) {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    Solution s;
    cout << s.search(nums, 0) << endl;
    return 0;
}