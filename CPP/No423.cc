/**
 * Created by Xiaozhong on 2020/9/18.
 * Copyright (c) 2020/9/18 Xiaozhong. All rights reserved.
 */

#include "iostream"
#include "string"
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26 + (int) 'a');
        for (char letter : s) {
            count[letter]++;
        }
        vector<int> out(10, 0);
        out[0] = count['z'];
        out[2] = count['w'];
        out[4] = count['u'];
        out[6] = count['x'];
        out[8] = count['g'];
        out[3] = count['h'] - out[8];
        out[5] = count['f'] - out[4];
        out[7] = count['s'] - out[6];
        out[9] = count['i'] - out[5] - out[6] - out[8];
        out[1] = count['n'] - 2 * out[9] - out[7];

        string output;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < out[i]; ++j) {
                output.append(to_string(i));
            }
        }
        return output;
    }
};

int main() {
    Solution s;
    cout << s.originalDigits("owoztneoer") << endl;
}