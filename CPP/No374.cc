/**
 * Created by Xiaozhong on 2020/8/31.
 * Copyright (c) 2020/8/31 Xiaozhong. All rights reserved.
 */

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
#include "iostream"

using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 0, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int ans = guess(mid);
            if (ans == 1) left = mid + 1;
            else if (ans == -1) right = mid - 1;
            else return mid;
        }
        return -1;
    }
};
