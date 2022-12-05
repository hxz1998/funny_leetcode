/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/16
 **/
package org.example;

import java.util.Arrays;

public class LCP28 {

    public int purchasePlans(int[] nums, int target) {
        int mod = 1000000007;
        int n = nums.length;
        int left = 0, right = n - 1;
        Arrays.sort(nums);
        int ans = 0;
        while (left < right) {
            while (left < right && nums[left] + nums[right] > target) right--;
            if (left < right) ans += right - left;
            left++;
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println(new LCP28().purchasePlans(new int[]{3, 1, 2}, 5));
        System.out.println(new LCP28().purchasePlans(new int[]{2, 5, 3, 5}, 6));
        System.out.println(new LCP28().purchasePlans(new int[]{2, 2, 1, 9}, 10));
    }
}
