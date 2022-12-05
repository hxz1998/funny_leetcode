/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/25
 **/
package microsoft;

import java.util.HashMap;
import java.util.Map;

public class No86 {
    private final long MAX = 1000000000;

    public int solution(int[] nums) {
        long ans = 0;
        int n = nums.length;
        if (n == 0) return 0;
        Map<Long, Long> mapper = new HashMap<>();
        mapper.put(0L, 1L);
        long preSum = 0;
        for (int idx = 0; idx < n; ++idx) {
            preSum += nums[idx];
            if (mapper.containsKey(preSum)) {
                ans += mapper.get(preSum);
                if (ans >= MAX) return -1;
            }
            mapper.put(preSum, mapper.getOrDefault(preSum, 0L) + 1);
        }
        return (int) ans;
    }

    public static void main(String[] args) {
        int[] nums = {2, -2, 3, 0, 4, -7};
        No86 no86 = new No86();
        System.out.println(no86.solution(nums));
    }
}
