/**
 * Created by Xiaozhong on 2020/8/27.
 * Copyright (c) 2020/8/27 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "string"

using namespace std;

class Solution {
private:
    // 求数组长度为 k 的最长子序列
    vector<int> kMaxSequence(vector<int> &nums, int k) {
        int n = nums.size();
        if (n < k) return nums;
        vector<int> data;   // 数据域
        int remain = n - k; // 剩余可读入数
        for (int i = 0; i < n; i++) {
            /**
             * 如果数据域不为空，
             * 而且当前读入的数字要比数据域最后一个数字要大，并且剩余可读入数不为 0，
             * 那么就弹出来数据域最后一个数，填充较大的 nums[i]
             */
            while (!data.empty() && nums[i] > data.back() && remain-- > 0) data.pop_back();
            data.push_back(nums[i]);
        }
        data.resize(k);
        return data;
    }

public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> ans(k, 0);
        int n = nums1.size(), m = nums2.size();
        // s 个字符来自 nums1 ， k - s 个字符来自 nums2
        for (int s = max(0, k - m); s <= min(k, n); s++) {
            vector<int> temp;
            vector<int> temp1 = kMaxSequence(nums1, s);
            vector<int> temp2 = kMaxSequence(nums2, k - s);
            auto iter1 = temp1.begin(), iter2 = temp2.begin();
            while (iter1 != temp1.end() || iter2 != temp2.end()) {
                // lexicographical_compare(begin1, end1, begin2, end2)，
                // 如果 [begin1, end1] 字典序大于 [begin2, end2]，那么就返回 true， 否则就返回 false
                temp.push_back(lexicographical_compare(iter1, temp1.end(), iter2, temp2.end()) ? *iter2++ : *iter1++);
            }
            ans = lexicographical_compare(ans.begin(), ans.end(), temp.begin(), temp.end()) ? temp : ans;
        }
        return ans;
    }
};