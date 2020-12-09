/**
 * Created by Xiaozhong on 2020/12/9.
 * Copyright (c) 2020/12/9 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int> &answers) {
        unordered_map<int, int> mapper;
        int ans = 0;
        for (int i : answers) {
            if (i == 0) ++ans;
            else if (mapper.count(i)) {
                mapper[i]--;
                if (mapper[i] == 0) mapper.erase(i);
            } else {
                ans += (1 + i);
                mapper[i] = i;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> answers = {1, 1, 2};
    cout << s.numRabbits(answers) << endl;
    answers = {0, 0, 1, 1, 1};
    cout << s.numRabbits(answers) << endl;
    answers = {1, 0, 1, 0, 0};
    cout << s.numRabbits(answers) << endl;
}