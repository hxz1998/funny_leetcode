import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Properties;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/9/11
 **/

public class No857 {
    public double mincostToHireWorkers(int[] quality, int[] wage, int k) {
        int n = quality.length;
        Integer[] h = new Integer[n];
        for (int idx = 0; idx < n; ++idx) {
            h[idx] = idx;
        }
        Arrays.sort(h, (a, b) -> quality[b] * wage[a] - quality[a] * wage[b]);
        double ans = Double.MAX_VALUE;
        double totalQ = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 0; i < k - 1; ++i) {
            totalQ += quality[h[i]];
            pq.add(quality[h[i]]);
        }
        for (int i = k - 1; i < n; ++i) {
            totalQ += quality[h[i]];
            pq.add(quality[h[i]]);
            double totalC = ((double) wage[h[i]] / quality[h[i]] * totalQ);
            ans = Math.min(ans, totalC);
            assert !pq.isEmpty();
            totalQ -= pq.poll();
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("hello");
        Properties properties = System.getProperties();
        properties.list(System.out);
    }
}
