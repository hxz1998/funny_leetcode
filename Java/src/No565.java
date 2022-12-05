/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/17
 **/

public class No565 {
    public int arrayNesting(int[] nums) {
        int ans = 0;
        int n = nums.length;
        boolean[] visited = new boolean[n];
        for (int idx = 0; idx < n; ++idx) {
            if (visited[idx]) continue;
            int curr = nums[idx];
            int len = 0;
            while (!visited[curr]) {
                len++;
                visited[curr] = true;
                curr = nums[curr];
            }
            ans = Math.max(ans, len);
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {5, 4, 0, 3, 1, 6, 2};
        System.out.println(new No565().arrayNesting(nums));
    }
}
