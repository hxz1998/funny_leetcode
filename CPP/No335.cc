/**
 * Created by Xiaozhong on 2020/8/28.
 * Copyright (c) 2020/8/28 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int> &x) {
        for (int i = 3; i < x.size(); i++) {
            if (i >= 3 && x.at(i - 1) <= x.at(i - 3) && x.at(i) >= x.at(i - 2)) return true;
            if (i >= 4 && x.at(i - 3) == x.at(i - 1) && x.at(i) + x.at(i - 4) >= x.at(i - 2)) return true;
            if (i >= 5 && x.at(i) + x.at(i - 4) >= x.at(i - 2) && x.at(i - 1) + x.at(i - 5) >= x.at(i - 3) &&
                x.at(i - 2) > x.at(i - 4) && x.at(i - 3) > x.at(i - 1))
                return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> x = {1, 2, 3, 4};
    cout << s.isSelfCrossing(x) << endl;
    vector<int> x1 = {2, 1, 1, 2};
    cout << s.isSelfCrossing(x1) << endl;

}