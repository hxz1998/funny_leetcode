/**
 * Created by Xiaozhong on 2020/11/14.
 * Copyright (c) 2020/11/14 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int> &code, int k) {
        vector<int> ans;
        int n = code.size();
        if (k < 0) {
            for (int i = 0; i < code.size(); ++i) {
                int num = 0;
                for (int j = 0, index = i; j < -k; ++j) {
                    num += code[(--index + n) % n];
                }
                ans.push_back(num);
            }
        } else {
            for (int i = 0; i < code.size(); ++i) {
                int num = 0;
                for (int j = 0, index = i; j < k; ++j) {
                    num += code[(++index) % n];
                }
                ans.push_back(num);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> codes = {5, 7, 1, 4};
    vector<int> ans = s.decrypt(codes, 3);
    codes = {2, 4, 9, 3};
    ans = s.decrypt(codes, -2);
    return 0;
}