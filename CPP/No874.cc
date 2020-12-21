/**
 * Created by Xiaozhong on 2020/12/21.
 * Copyright (c) 2020/12/21 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
        set<pair<int, int>> obstacle_set;
        for (const vector<int> &obstacle : obstacles) {
            obstacle_set.insert(make_pair(obstacle.front(), obstacle.back()));
        }
        int ans = 0;
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;
        for (int command : commands) {
            if (command == -1) di = (di + 1) % 4;
            else if (command == -2) di = (di + 3) % 4;
            else {
                for (int k = 0; k < command; ++k) {
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if (obstacle_set.find(make_pair(nx, ny)) == obstacle_set.end()) {
                        x = nx;
                        y = ny;
                        ans = max(ans, x * x + y * y);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
}