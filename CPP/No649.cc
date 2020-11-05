/**
 * Created by Xiaozhong on 2020/11/4.
 * Copyright (c) 2020/11/4 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        bool R = true, D = true;    // 标记参议院中是否还有 R 和 D
        int person = 0;             // person > 0 则 R 可以淘汰 D，否则 D 可以淘汰 R
        while (R && D) {
            R = false, D = false;
            for (int i = 0; i < senate.size(); ++i) {
                if (senate[i] == 'R') {
                    R = true;
                    if (person < 0) senate[i] = '0';
                    ++person;   // 因为来了一个 R 所以 person 一定要加一个
                } else if (senate[i] == 'D') {
                    D = true;
                    if (person > 0) senate[i] = '0';
                    --person;   // 来了一个 D 所以 person 一定要减去一个
                }
            }
        }
        return person > 0 ? "Radiant" : "Dire";
    }
};

int main() {
    Solution s;
    cout << s.predictPartyVictory("RDD") << endl;
}