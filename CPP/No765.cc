/**
 * Created by Xiaozhong on 2020/12/5.
 * Copyright (c) 2020/12/5 Xiaozhong. All rights reserved.
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        int ans = 0;
        // 第 i 个位置的编号情侣编号一定是 row[i] ^ 1，在处理的时候，需要一次加两个
        for (int i = 0; i < row.size(); i += 2) {
            int x = row[i];
            // 如果人家已经组成了情侣，那么就跳过去
            if (row[i + 1] == (x ^ 1)) continue;
            // 否则记录一次调整次数
            ans++;
            // 找到后面与当前位置 row[i] 配对的情侣，调到它的位置前面 i + 1
            for (int j = i + 1; j < row.size(); ++j) {
                if (row[j] == (x ^ 1)) {
                    row[j] = row[i + 1];
                    row[i + 1] = x ^ 1;
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> row = {0, 2, 1, 3};
    cout << s.minSwapsCouples(row) << endl;
}