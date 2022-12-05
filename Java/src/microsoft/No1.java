/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/6
 **/
package microsoft;

import java.util.PriorityQueue;

public class No1 {
    public int solution(String s, int budget) {
//        int n = s.length();
//        if (n == 0 || budget == 0) return 0;
//        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
//        for (int idx = 0; idx < n; ) {
//            if (s.charAt(idx) == 'x') {
//                int len = 0;
//                while (idx < n && s.charAt(idx) == 'x') {
//                    idx++;
//                    len++;
//                }
//                pq.add(len);
//            } else idx++;
//        }
//        if (pq.isEmpty()) return 0;
//        int ans = 0;
//        while (budget > 0) {
//            if (pq.isEmpty()) {
//                return ans;
//            } else if (pq.peek() + 1 <= budget) {
//                budget -= (pq.peek() + 1);
//                ans += pq.peek();
//                pq.poll();
//            } else {
//                ans += (budget - 1);
//                budget = 0;
//            }
//        }
//        return ans;

        int n = s.length();
        int cnt = 0;
        for (int idx = 0; idx < n; ++idx) {
            if (s.charAt(idx) == 'x') {
                cnt++;
                idx = idx + 2;
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        System.out.println(new No1().solution("...xxx..x....xxx.", 7));
        System.out.println(new No1().solution("..xxxxx", 4));
        System.out.println(new No1().solution("x.x.xxx...x", 14));
        System.out.println(new No1().solution("..", 5));
    }
}
