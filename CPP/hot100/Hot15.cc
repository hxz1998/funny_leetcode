/**
 * Created by Xiaozhong on 2022/2/8.
 * Copyright (c) 2022/2/8 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "unordered_set"

using namespace std;

// 下面这种插入排序去重的方法不可取，太慢了
/*class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        unordered_map<int, int> cnt;
        class hash_vector {
        public:
            size_t operator()(const vector<int> &data) const {
                int ans = 0;
                for (int num: data) ans += num % 7;
                return ans;
            }
        };
        class equal_to_vector {
        public:
            bool operator()(const vector<int> &lhs, const vector<int> &rhs) const {
                for (int idx = 0; idx < lhs.size(); ++idx) if (lhs[idx] != rhs[idx]) return false;
                return true;
            }
        };
        unordered_set<vector<int>, hash_vector, equal_to_vector> container;
        vector<vector<int>> ans;
        for (int num: nums) cnt[num]++;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < nums.size(); ++first) {
            for (int second = first + 1; second < nums.size(); ++second) {
                cnt[nums[first]]--;
                cnt[nums[second]]--;
                if (cnt[0 - nums[first] - nums[second]] > 0) {
                    vector<int> buf = {nums[first], nums[second], 0 - nums[first] - nums[second]};
                    sort(buf.begin(), buf.end());
                    container.insert(buf);
                }
                cnt[nums[first]]++;
                cnt[nums[second]]++;
            }
        }
        for (vector<int> num: container) ans.emplace_back(num);

        return ans;
    }
};
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int first = 0; first < n; ++first) {
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            int third = n - 1;
            int target = -nums[first];
            for (int second = first + 1; second < n; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1]) continue;
                while (second < third && nums[second] + nums[third] > target) --third;
                if (second == third) break;
                if (nums[second] + nums[third] == target) ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
        return ans;
    }
};

ostream &operator<<(ostream &os, const vector<vector<int>> &data) {
    for (const vector<int> &item: data) {
        for (int num: item) os << num << ", ";
        os << endl << flush;
    }
    return os;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution s;
    cout << s.threeSum(nums) << endl;
}