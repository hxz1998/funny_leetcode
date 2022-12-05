import java.util.LinkedList;
import java.util.PriorityQueue;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/2
 **/

public class No871 {
    class Solution {
        public int minRefuelStops(int target, int startFuel, int[][] stations) {
            PriorityQueue<Integer> pq = new PriorityQueue<>((lhs, rhs) -> rhs - lhs);
            int n = stations.length, ans = 0, prev = 0, fuel = startFuel;
            for (int idx = 0; idx <= n; ++idx) {
                int curr = idx == n ? target : stations[idx][0];
                fuel -= curr - prev;
                while (fuel < 0 && !pq.isEmpty()) {
                    fuel += pq.poll();
                    ans++;
                }
                if (fuel < 0) return -1;
                if (idx < n) {
                    pq.add(stations[idx][1]);
                    prev = curr;
                }
            }
            return ans;
        }
    }

    public static void main(String[] args) {
    }
}
