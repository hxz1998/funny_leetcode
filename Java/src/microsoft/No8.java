/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/13
 **/
package microsoft;

import java.util.HashMap;
import java.util.Map;

public class No8 {
    private static long MOD = 1000000007;

    public int solution(int[] X, int[] Y) {
        Map<Integer, Map<Integer, Integer>> mapper = new HashMap<>();
        int n = X.length;
        for (int idx = 0; idx < n; ++idx) {
            int a = X[idx]; // 分子
            int b = Y[idx]; // 分母
            int g = gcd(Math.max(a, b), Math.min(a, b));
            a /= g;
            b /= g;
            Map<Integer, Integer> count = mapper.getOrDefault(b, new HashMap<>());
            count.put(a, count.getOrDefault(a, 0) + 1);
            mapper.put(b, count);
        }
        long ans = 0;
        for (Map.Entry<Integer, Map<Integer, Integer>> entry : mapper.entrySet()) {
            // 分母 -> {分子 -> 分子个数}
            int denominator = entry.getKey();
            Map<Integer, Integer> counter = entry.getValue();
            for (Map.Entry<Integer, Integer> elem : counter.entrySet()) {
                if (denominator - elem.getKey() == elem.getKey()) {
                    if (elem.getValue() > 2) ans += C(elem.getValue(), 2);
                    else if (elem.getValue() == 2) ans += 1;
                } else {
                    if (counter.containsKey(denominator - elem.getKey()) && counter.get(denominator - elem.getKey()) > 0) {
                        ans += (long) counter.get(denominator - elem.getKey()) * elem.getValue();
                        counter.put(elem.getKey(), 0);
                        counter.put(denominator - elem.getKey(), 0);
                    }
                }
            }
            ans %= MOD;
        }
        return (int) (ans % MOD);
    }

    private long C(int a, int b) {
        long ret = 1;
        while (b-- > 0) {
            ret *= a;
            a -= 1;
        }
        return ret / 2;
    }

    private int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        int[] X = {1, 1, 1};
        int[] Y = {2, 2, 2};
        System.out.println(new No8().solution(X, Y));
    }
}
