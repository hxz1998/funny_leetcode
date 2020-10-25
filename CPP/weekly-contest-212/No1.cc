/**
 * Created by Xiaozhong on 2020/10/25.
 * Copyright (c) 2020/10/25 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed) {
        if (keysPressed.length() == 1) return keysPressed.front();
        char ans = keysPressed.front();
        long long last = releaseTimes.front();
        for (int i = 1; i < releaseTimes.size(); ++i) {
            if (releaseTimes[i] - releaseTimes[i - 1] > last) {
                last = releaseTimes[i] - releaseTimes[i - 1];
                ans = keysPressed[i];
            } else if (releaseTimes[i] - releaseTimes[i - 1] == last) {
                ans = ans > keysPressed[i] ? ans : keysPressed[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> releaseTimes = {9, 29, 49, 50};
    string keysPressed = "cbcd";
    cout << s.slowestKey(releaseTimes, keysPressed) << endl;
    assert(s.slowestKey(releaseTimes, keysPressed) == 'c');
    releaseTimes = {12, 23, 36, 46, 62};
    keysPressed = "spuda";
    cout << s.slowestKey(releaseTimes, keysPressed) << endl;
}