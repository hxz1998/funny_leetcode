/**
 * Created by Xiaozhong on 2020/9/12.
 * Copyright (c) 2020/9/12 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
    int minimumOperations(string leaves) {
        int left = 0, right = leaves.size() - 1, ans = 0;
        bool leftToggle = true, rightToggle = true;
        while (left < right) {
            while (leaves[left] == 'r') ++left;
            while (leaves[left] == 'y') ++left;
            while (leaves[right] == 'r') --right;
            while (left < right && leaves[left] == 'r' && leaves[right] == 'y') {
                swap(leaves[left], leaves[right]);
                ++left;
                --right;
                ++ans;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.minimumOperations("rrryyyrryyyrr") << endl;
    cout << s.minimumOperations("ryr");
}