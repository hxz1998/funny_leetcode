import java.util.Arrays;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/10/18
 **/

public class No902 {
    private String[] digits;
    private char[] s;
    private int[] dp;


    public int atMostNGivenDigitSet(String[] digits, int n) {
        this.digits = digits;
        this.s = Integer.toString(n).toCharArray();
        dp = new int[s.length];
        Arrays.fill(dp, -1);
        return f(0, true, false);
    }

    private int f(int idx, boolean limited, boolean valid) {
        if (idx == s.length) return valid ? 1 : 0;
        if (!limited && valid && dp[idx] > 0) return dp[idx];
        int ret = 0;
        if (!valid) {
            ret = f(idx + 1, false, false);
        }
        char up = limited ? s[idx] : '9';
        for (String c : digits) {
            if (c.charAt(0) > up) break;
            ret += f(idx + 1, limited && c.charAt(0) == up, true);
        }
        if (!limited && valid) dp[idx] = ret;
        return ret;
    }

    public static void main(String[] args) {
    }
}
