/**
 * Created by Xiaozhong on 2022/3/29.
 * Copyright (c) 2022/3/29 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <random>

using namespace std;

class Solution {
private:
    int helper(const string &str, int k, char target) {
        int n = static_cast<int>(str.size());
        int left = 0, right = 0, cnt = 0;
        int ret = 0;
        while (right < n) {
            while (right < n && cnt <= k) {
                if (str[right] == target) cnt++;
                right++;
            }
            if (right == n && cnt <= k) ret = max(ret, right - left);
            else ret = max(ret, right - left - 1);
            while (left < n && cnt > k) {
                if (str[left] == target) cnt--;
                left++;
            }
        }
        return ret;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(helper(answerKey, k, 'T'), helper(answerKey, k, 'F'));
    }
};

int main() {
    Solution s;
    cout << s.maxConsecutiveAnswers("TTFF", 2) << endl;
    cout << s.maxConsecutiveAnswers("TTFTTFTT", 1) << endl;
    cout << s.maxConsecutiveAnswers("TTFTTFTT", 2) << endl;
}