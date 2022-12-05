/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/25
 **/
package microsoft;

public class No88 {
    private final long MAX = 1000000000;

    public int solution(int[] nums) {
        long ans = 0;
        int n = nums.length;
        if (n == 0) return 0;
        long[] copy = new long[n];
        for (int idx = 0; idx < n; ++idx) copy[idx] = nums[idx];
        for (int idx = 0; idx < n; ++idx) {
            long count = 0;
            for (; idx + 2 < n && copy[idx + 1] - copy[idx] == copy[idx + 2] - copy[idx + 1]; ++idx) {
                count++;
                ans += count;
                if (ans >= MAX) return -1;
            }
        }
        return (int) ans;
    }

    public static void main(String[] args) {
        No88 no88 = new No88();
        System.out.println(no88.solution(new int[]{2000000000, -2000000000, -2000000000}));
//        System.out.println(Integer.MAX_VALUE);
//        System.out.println(2000000000);
//        System.out.println(2000000000 + 2000000000);
        int[] nums = new int[10000];
        for (int idx = 0; idx < 10000; ++idx) nums[idx] = 2;
        System.out.println(no88.solution(nums));
    }
}
