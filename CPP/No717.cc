/**
 * Created by Xiaozhong on 2020/11/23.
 * Copyright (c) 2020/11/23 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        for (int i = 0; i < bits.size(); ++i) {
            // 如果到了倒数第二个字符，而且还等于 1 ，
            // 那么就说明最后一个 0 要和这个 1 附在一起解码了
            if (bits[i] == 1 && i == bits.size() - 2) return false;
            // 遇到 1 ，就可以直接跳过去下面一个字符了
            else if (bits[i] == 1) i++;
            // 遇到 0 ，只能跳过当前这个字符
            else if (bits[i] == 0) continue;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> bits = {1, 0, 0};
    cout << s.isOneBitCharacter(bits) << endl;
    bits = {1, 1, 1, 0};
    cout << s.isOneBitCharacter(bits) << endl;
}