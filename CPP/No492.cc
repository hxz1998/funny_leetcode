/**
 * Created by Xiaozhong on 2020/10/2.
 * Copyright (c) 2020/10/2 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int sideLength = sqrt(area);
        if (sideLength * sideLength == area) return {sideLength, sideLength};
        for (int i = sideLength; i >= 1; --i) {
            if (area % i == 0) {
                return {area / i, i};
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    cout << s.constructRectangle(10)[0] << " - " << s.constructRectangle(10)[1] << endl;
}
