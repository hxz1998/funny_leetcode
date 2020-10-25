/**
 * Created by Xiaozhong on 2020/10/26.
 * Copyright (c) 2020/10/26 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        if (flowerbed.size() == 1) return flowerbed.front() == 0 && n == 1 || n == 0;
        int count = 0;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                ++count;
                flowerbed[i] = 1;
            }
        }
        return count >= n;
    }
};

int main() {
    Solution s;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    cout << s.canPlaceFlowers(flowerbed, 1) << endl;
    flowerbed = {0};
    cout << s.canPlaceFlowers(flowerbed, 1) << endl;
}