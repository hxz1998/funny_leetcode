/**
 * Created by Xiaozhong on 2020/10/9.
 * Copyright (c) 2020/10/9 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int> &machines) {
        int sum = 0;
        for (int &item : machines) sum += item;

        int size = machines.size();
        if (sum % size) return -1;

        int average = sum / size;
        int flux = 0, mx = 0, res = 0;
        for (int &i : machines) {
            flux += i - average;
            mx = max(i - average, abs(flux));
            res = max(res, mx);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> machines = {1, 0, 5};
    cout << s.findMinMoves(machines) << endl;
}