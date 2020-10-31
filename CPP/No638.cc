/**
 * Created by Xiaozhong on 2020/10/31.
 * Copyright (c) 2020/10/31 Xiaozhong. All rights reserved.
 */
#include <vector>
#include <iostream>

using namespace std;

// 直接计算单买价格之和
int operator*(const vector<int> &lhs, const vector<int> &rhs) {
    int sum = 0;
    for (int i = 0; i < lhs.size(); ++i) sum += lhs[i] * rhs[i];
    return sum;
}

class Solution {
    int shopping(const vector<int> &price,
                 const vector<vector<int>> &special,
                 vector<int> &needs) {
        // 首先计算单买价格，保存下来（相当于是保存了一个最大值）
        // j 是用来挨个检查商品的
        int j = 0, res = needs * price;
        for (const vector<int> &item : special) {
            // 然后对礼包进行检查，挨个匹配
            vector<int> clone = vector<int>(needs);
            for (j = 0; j < needs.size(); ++j) {
                // 计算当前需要的东西，和礼包内包含的物品数量差
                int diff = clone[j] - item[j];
                // 如果礼包内包含的物品数量都大于了需要的，那么就放掉这个礼包
                if (diff < 0) break;
                // 否则就买下来，记录下来差值
                clone[j] = diff;
            }
            // 如果检查完了礼包，没有不合适的，那么就计算当前花费最小值
            if (j == needs.size())
                res = min(res, item[j] + shopping(price, special, clone));
        }
        return res;
    }

public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        return shopping(price, special, needs);
    }
};

int main() {
    Solution s;
    vector<int> price = {2, 5};
    vector<vector<int>> specials = {
            {3, 0, 5},
            {1, 2, 10}
    };
    vector<int> needs = {3, 2};
    cout << s.shoppingOffers(price, specials, needs) << endl;
}