import java.util.ArrayList;
import java.util.List;

public class No241 {
    private static class Solution {
        private static final Integer ADD = -1;
        private static final Integer SUB = -2;
        private static final Integer MUT = -3;

        public List<Integer> diffWaysToCompute(String expression) {
            List<Integer> operations = new ArrayList<>();
            for (int idx = 0; idx < expression.length(); ) {
                char c = expression.charAt(idx);
                if (Character.isDigit(c)) {
                    int num = 0;
                    while (idx < expression.length() && Character.isDigit(expression.charAt(idx))) {
                        num = num * 10 + (expression.charAt(idx) - '0');
                        idx++;
                    }
                    operations.add(num);
                } else {
                    if (c == '+') operations.add(ADD);
                    else if (c == '-') operations.add(SUB);
                    else if (c == '*') operations.add(MUT);
                    idx++;
                }
            }
            List<Integer>[][] dp = new List[operations.size()][operations.size()];
            for (int x = 0; x < operations.size(); ++x) {
                for (int y = 0; y < operations.size(); ++y) {
                    dp[x][y] = new ArrayList<>();
                }
            }
            return dfs(operations, 0, operations.size() - 1, dp);
        }

        private List<Integer> dfs(List<Integer> operations, int low, int high, List<Integer>[][] dp) {
            if (dp[low][high].isEmpty()) {
                if (low == high) {
                    dp[low][high].add(operations.get(low));
                } else {
                    for (int idx = low; idx < high; idx += 2) {
                        List<Integer> left = dfs(operations, low, idx, dp);
                        List<Integer> right = dfs(operations, idx + 2, high, dp);
                        for (int lv : left) {
                            for (int rv : right) {
                                if (operations.get(idx + 1).equals(ADD)) {
                                    dp[low][high].add(lv + rv);
                                } else if (operations.get(idx + 1).equals(SUB)) {
                                    dp[low][high].add(lv - rv);
                                } else {
                                    dp[low][high].add(lv * rv);
                                }
                            }
                        }
                    }
                }
            }
            return dp[low][high];
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.diffWaysToCompute("2-1-1"));

        int[] numbers = {1, 2, 3, 4, 5};
        for (int i = 0; i < numbers.length; ++i) {
            System.out.printf(",%d" + (i == 0 ? 1 : 0), numbers[i]);
        }
    }
}
