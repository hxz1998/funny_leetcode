/*
 * Created by Xiaozhong on 12/2/2021.
 * Copyright (c) 12/2/2021 Xiaozhong. All rights reserved.
 */

#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] < numbers[right]) right = mid;
            else if (numbers[mid] > numbers[right]) left = mid + 1;
            else right--;
        }
        return numbers[left];
    }
};

int main() {

}