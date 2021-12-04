/**
 * Created by Xiaozhong on 2020/8/25.
 * Copyright (c) 2020/8/25 Xiaozhong. All rights reserved.
 */
#include "string"
#include "iostream"
#include "vector"

using namespace std;

//class Solution {
//public:
//    string getHint(string secret, string guess) {
//        /*
//         * bulls：公牛，cows：母牛，nums[]：索引是数字，值是该数字出现的次数
//         */
//        int bulls = 0, cows = 0, num[10] = {0};
//        for (int i = 0; i < secret.length(); i++) {
//            if (secret[i] == guess[i]) bulls++;         // 说明对上了号，公牛+1
//            else {
//                if (num[secret[i] - '0']++ < 0) cows++; // 没对上号
//                if (num[guess[i] - '0']-- > 0) cows++;
//            }
//        }
//        // 拼接结果，然后返回
//        return to_string(bulls).append("A").append(to_string(cows)).append("B");
//    }
//};

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> cnt(10);
        for (int idx = 0; idx < secret.length(); ++idx) {
            if (secret[idx] == guess[idx]) bulls++;
            else {
                if (cnt[secret[idx] - '0']++ < 0) cows++;
                if (cnt[guess[idx] - '0']-- > 0) cows++;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main() {
    Solution s;
    cout << s.getHint("1807", "7810");
}