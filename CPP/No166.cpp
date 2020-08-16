/**
 * Created by Xiaozhong on 2020/8/16.
 * Copyright (c) 2020/8/16 Xiaozhong. All rights reserved.
 */
#include "string"
#include "unordered_map"

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0 || denominator == 0) return "0";
        string ans;
        long long num = (long long) numerator, denom = (long long) denominator;
        if ((num > 0) ^ (denom > 0)) ans.push_back('-');
        num = llabs(num), denom = llabs(denom);

        ans.append(to_string(num / denom));
        num %= denom;               // 取到余数
        if (num == 0) return ans;   // 如果余数为 0 ，那么就直接返回结果
        ans.push_back('.');         // 是一个有余数的结果，那么就在末尾补上一个小数点
        int index = ans.size() - 1; //用来记录每个余数在结果集中的下标，方便填充括号
        unordered_map<int, int> mapper;
        while (num && mapper.count(num) == 0) { // 余数不为 0 ，而且余数出现次数没有重复
            mapper[num] = ++index;
            num *= 10;                          // 一般除法计算过程，先扩大十倍，然后求余数
            ans.append(to_string(num / denom));
            num %= denom;
        }
        if (mapper.count(num)) {                // 看看是否需要添加括号
            ans.insert(mapper[num], "(");
            ans.push_back(')');
        }
        return ans;
    }
};