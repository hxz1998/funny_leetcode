/**
 * Created by Xiaozhong on 2020/8/12.
 * Copyright (c) 2020/8/12 Xiaozhong. All rights reserved.
 */
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> left(ratings.size(), 1);
        vector<int> right(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
            if (ratings[i] > ratings[i - 1]) left[i] = left[i - 1] + 1;
        int count = left[ratings.size() - 1];
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) right[i] = right[i + 1] + 1;
            count += max(left[i], right[i]);
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> ratings = {1, 0, 2};
    cout << s.candy(ratings) << endl;
}