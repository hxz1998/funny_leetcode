/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/13
 **/
package microsoft;

public class No68 {
    public int solution(int[] A, int X, int Y) {
        int n = A.length;
        int ans = Integer.MAX_VALUE;
        for (int idx = 0; idx < n - Y; ++idx) {
            ans = Math.min(ans, dfs(A, 0, idx));
        }
        return ans;
    }

    private int dfs(int[] nums, int sum, int start) {
        return 0;
    }

    public static void main(String[] args) {
        int[] A = {4, 2, 3, 7};
        System.out.println(new No68().solution(A, 2, 2));
        A = new int[]{10, 3, 4, 7};
        System.out.println(new No68().solution(A, 2, 3));
        A = new int[]{4, 2, 5, 4, 3, 5, 1, 4, 2, 7};
        System.out.println(new No68().solution(A, 3, 2));
    }
}
