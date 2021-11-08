/**
 * Created by Xiaozhong on 2020/10/21.
 * Copyright (c) 2020/10/21 Xiaozhong. All rights reserved.
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*class Solution {
public:
    int distributeCandies(vector<int> &candies) {
        int ans = 1;
        sort(candies.begin(), candies.end());
        for (int i = 1; i < candies.size() && ans < candies.size() / 2; ++i) {
            if (candies[i] != candies[i - 1]) ++ans;
        }
        return ans;
    }
};*/
class Solution {
public:
    int distributeCandies(vector<int> &candyType) {
        unordered_set<int> count;
        for (int type: candyType) count.insert(type);
        size_t n = candyType.size();
        if (n / 2 >= count.size()) return count.size();
        else return n / 2;
    }
};

int main() {
    Solution s;
    vector<int> candies = {1, 1, 2, 2, 3, 3};
    cout << s.distributeCandies(candies) << endl;
    candies = {1, 1, 2, 3};
    cout << s.distributeCandies(candies) << endl;
}