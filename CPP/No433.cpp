/**
 * Created by Xiaozhong on 2020/9/19.
 * Copyright (c) 2020/9/19 Xiaozhong. All rights reserved.
 */
#include "string"
#include "vector"

using namespace std;

class Solution {
private:
    void dfs(string start, string end, vector<string> &bank, int change) {
        if (start == end) {
            ans = min(ans, change);
            return;
        }
        for (int j = 0; j < bank.size(); ++j) {
            string item = bank[j];  // 记录当前的数据，下面用来回溯
            if (item.length() == 0) continue;   // 如果为 0 ，说明已经用过了，因此跳过
            int diff = 0;   // 用来记录两个基因序列的不同
            for (int i = 0; i < start.length(); ++i) {
                if (start[i] != item[i]) diff++;
            }
            if (diff == 1) {    // 如果 有一个位 是不同的，那么说明找到了！
                bank[j] = "";   // 先进行处理，防止下次再用
                dfs(item, end, bank, change + 1); // 递归~不过这个起点是和上一个有一位不同的序列
                bank[j] = item; // 回溯
            }
        }
    }

    int ans = INT32_MAX;
public:
    int minMutation(string start, string end, vector<string> &bank) {
        dfs(start, end, bank, 0);
        return ans == INT32_MAX ? -1 : ans;
    }
};