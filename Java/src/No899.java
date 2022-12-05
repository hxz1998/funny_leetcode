import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/3
 **/

public class No899 {
    public String orderlyQueue(String s, int k) {
        if (k == 1) {
            String ans = s;
            StringBuilder builder = new StringBuilder(s);
            for (int idx = 0; idx < s.length() - 1; ++idx) {
                builder.append(builder.charAt(0));
                builder.deleteCharAt(0);
                if (builder.toString().compareTo(ans) < 0) ans = builder.toString();
            }
            return ans;
        } else {
            char[] res = s.toCharArray();
            Arrays.sort(res);
            return new String(res);
        }
    }

    // 找到第一个只出现一次的数字
    public int solution(int[] nums) {
        Map<Integer, Integer> counter = new HashMap<>();
        for (int num : nums) counter.put(num, counter.getOrDefault(num, 0) + 1);
        int ans = -1;
        for (int idx = 0; idx < nums.length; ++idx) {
            if (counter.get(nums[idx]) == 1) {
                ans = idx;
                break;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println(new No899().solution(new int[]{1, 4, 3, 3, 1, 2}));
        int[][] matrix = {{}};
        System.out.println(matrix.length + ":" + matrix[0].length);
    }
}
