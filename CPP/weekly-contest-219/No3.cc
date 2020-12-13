/**
 * Created by Xiaozhong on 2020/12/13.
 * Copyright (c) 2020/12/13 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void helper(vector<int> &stones, int left, int right, int &alice, int &bob, int sum) {
        if (left >= right) return;
        if (stones[left] < stones[right]) {
            alice += (sum -= stones[left++]);
        } else {
            alice += (sum -= stones[right--]);
        }

    }

public:
    int stoneGameVII(vector<int> &stones) {
        int sum = 0;
        for (auto i : stones) sum += i;
        int alice = 0, bob = 0, left = 0, right = stones.size() - 1;
        helper(stones, left, right, alice, bob, sum);
        return alice - bob;
    }
};

int main() {
    Solution s;
    vector<int> stones = {5, 3, 1, 4, 2};
    cout << s.stoneGameVII(stones);
}