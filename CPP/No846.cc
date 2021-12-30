/*
 * Created by Xiaozhong on 12/30/2021.
 * Copyright (c) 12/30/2021 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        map<int, int> mapper;
        for (int num: hand) mapper[num]++;
        while (!mapper.empty()) {
            int first = mapper.begin()->first;
            for (int i = first; i < first + groupSize; ++i) {
                if (mapper.find(i) == mapper.end()) return false;
                if (mapper[i] == 1) mapper.erase(i);
                else mapper[i]--;
            }
        }
        return true;
    }
};

int main() {
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    Solution s;
    cout << s.isNStraightHand(hand, 3) << endl;
}