/**
 * Created by Xiaozhong on 2020/9/12.
 * Copyright (c) 2020/9/12 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
private:
public:
    int breakfastNumber(vector<int> &staple, vector<int> &drinks, int x) {
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        int ans = 0;
        for (int i = 0; i < staple.size(); ++i) {
            if (staple[i] >= x) break;
            int index = upper_bound(drinks.begin(), drinks.end(), x - staple[i]) - drinks.begin();
            ans %= 1000000007;
            ans += index;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> staple = {10, 20, 5};
    vector<int> drinks = {5, 5, 2};
    cout << s.breakfastNumber(staple, drinks, 15) << endl;
    staple = {2, 1, 1};
    drinks = {9, 8, 5, 1};
    cout << s.breakfastNumber(staple, drinks, 9) << endl;
}