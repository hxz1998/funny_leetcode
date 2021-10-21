#include <iostream>

using namespace std;

/**
 * 下面这种情况没有考虑 结果越界 的问题
 */
/*******************************************
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int symbol = 0;
        if (dividend == 0)
            return 0;
        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
            symbol = 1;
        else 
            symbol = -1;
        int i = 0;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while (dividend >= divisor)
        {
            dividend -= divisor;
            i++;
        }
        i *= symbol;
        return i;
    }
};
********************************************/

/*class Solution {
public:
    int divide(int dividend, int divisor) {
        // 特殊情况处理
        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1) {
            if (dividend > INT32_MIN)
                return -dividend; // 只要不是最小的那个整数，都是直接返回相反数就好啦
            return INT32_MAX;     // 是最小的那个，那就返回最大的整数啦
        }
        // 数值转换，方便后面使用
        long a = dividend;
        long b = divisor;
        // 符号存储
        int sign = 1;
        if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
            sign = -1;
        }
        // 转换成绝对值
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        // 获取到结果
        long res = div(a, b);
        //根据符号来确定最后返回值
        if (sign > 0)
            return res > INT32_MAX ? INT32_MAX : (int) res;
        return -(int) res;
    }

    //
    long div(long a, long b) {
        if (a < b)
            return 0;
        long count = 1;
        long tb = b; // 在后面的代码中不更新b
        while ((tb + tb) <= a) {
            count = count + count; // 最小解翻倍
            tb = tb + tb;          // 当前测试的值也翻倍
        }
        return count + div(a - tb, b);
    }
};*/

/**
 * 2021年10月12日 重新来做一下
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend == INT32_MIN ? INT32_MAX : -dividend;
        int sign = 1;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) sign = -1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        long ret = div(dividend, divisor);
        if (sign == -1) return -ret;
        else return ret > INT32_MAX ? INT32_MAX : ret;
    }

private:
    long div(long a, long b) {
        if (a < b) return 0;
        long tb = b;
        long count = 1;
        while (tb + tb <= a) {
            count *= 2;
            tb *= 2;
        }
        return count + div(a - tb, b);
    }
};


int main(int argc, char *args[]) {
    Solution s;
    printf("%d\n", s.divide(10, 3));
}