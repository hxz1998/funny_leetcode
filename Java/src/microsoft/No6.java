/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/13
 **/
package microsoft;

import java.util.Comparator;
import java.util.PriorityQueue;

public class No6 {
    public int solution(int[] nums) {
        int sum = 0;
        PriorityQueue<Double> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int num : nums) {
            sum += num;
            pq.add((double) num);
        }
        double target = 1.0 * sum / 2.0;
        int ans = 0;
        while (sum > target) {
            ans++;
            double elem = pq.poll();
            double remain = elem / 2.0;
            sum -= remain;
            pq.add(remain);
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {5, 19, 8, 1};
        System.out.println(new No6().solution(nums));
    }
}
