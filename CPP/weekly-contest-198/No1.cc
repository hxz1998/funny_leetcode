/**
 * Created by Xiaozhong on 2020/7/19.
 * Copyright (c) 2020/7/19 Xiaozhong. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = 0;
        sum += rev(sum, numBottles, numExchange, 0);
        return sum;
    }

    int rev(int &sum, int numBottles, int numExchange, int empty) {
        if (numBottles < numExchange && empty < numExchange) {
            return numBottles;
        }
        sum += numBottles;
        return rev(sum, (numBottles + empty) / numExchange, numExchange,
                   (numBottles + empty) / numExchange + (numBottles + empty) % numExchange);
    }
};

int main(int argc, char *args[]) {
    Solution s;
    cout << s.numWaterBottles(15, 4) << endl;
}