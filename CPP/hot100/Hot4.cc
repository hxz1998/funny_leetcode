/*
 * Created by Xiaozhong on 3/7/2022.
 * Copyright (c) 3/7/2022 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "set"
#include "map"
#include "queue"
#include "functional"
#include "stack"

#define mp make_pair

using namespace std;

// 又臭又长的方法
/*class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = (int) nums1.size(), n = (int) nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        int leftSize = (m + n + 1) / 2;
        int left = 0, right = m;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int idx = leftSize - mid;
            if (nums2[idx - 1] > nums1[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int nums1LeftMax = left == 0 ? INT32_MIN : nums1[left - 1];
        int nums1RightMin = left == m ? INT32_MAX : nums1[left];
        int nums2LeftMax = leftSize - left == 0 ? INT32_MIN : nums2[leftSize - left - 1];
        int nums2RightMin = leftSize - left == n ? INT32_MAX : nums2[leftSize - left];

        if ((n + m) % 2 == 0) {
            return (1.0 * max(nums1LeftMax, nums2LeftMax) + 1.0 * max(nums2RightMin, nums1RightMin)) / 2;
        } else {
            return max(nums1LeftMax, nums2LeftMax);
        }
    }
};*/
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = (int) nums1.size();
        int m = (int) nums2.size();
        int left = (n + m + 1) / 2;
        int right = (n + m + 2) / 2;
        return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) +
                getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5;
    }

private:
    double getKth(const vector<int> &nums1, const int &start1, const int &end1,
                  const vector<int> &nums2, const int &start2, const int &end2, const int &k) {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        if (len1 == 0) return nums2[start2 + k - 1];
        else if (len2 == 0) return nums1[start1 + k - 1];
        else {
            if (k == 1) return min(nums1[start1], nums2[start2]);
            int i = start1 + min(len1, k / 2) - 1;
            int j = start2 + min(len2, k / 2) - 1;
            if (nums1[i] > nums2[j]) return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
            else return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (j - start1 + 1));
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 6};
    vector<int> nums2 = {1, 3, 4, 5, 9, 10};
//    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    nums1 = {0, 0};
    nums2 = {0, 0};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}