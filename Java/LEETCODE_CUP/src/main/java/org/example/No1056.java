/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/16
 **/
package org.example;


import java.util.Map;
import java.util.Set;

public class No1056 {
    private static class Solution {
        public boolean confusingNumber(int n) {
            Set<Integer> set = Set.of(2, 3, 4, 5, 7);
            Map<Integer, Integer> mapper = Map.of(0, 0, 1, 1, 6, 9, 9, 6, 8, 8);
            int copy = n;
            int reverse = 0;
            while (n > 0) {
                int num = n % 10;
                if (set.contains(num)) return false;
                reverse = reverse * 10 + mapper.get(num);
                n /= 10;
            }
            return reverse != copy;
        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution().confusingNumber(906));
        System.out.println(new Solution().confusingNumber(11));
        System.out.println(new Solution().confusingNumber(6));
    }

}
