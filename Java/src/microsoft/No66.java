/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/25
 **/
package microsoft;

import java.util.PriorityQueue;

public class No66 {
    public int solution(int num) {
        String str = Integer.toString(num);
        if (str.length() == 1) return 0;
        if (str.length() == 2 && str.charAt(0) == '-') return 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> o2 - o1);
        for (int idx = 0; idx < str.length(); ++idx) {
            if (str.charAt(idx) == '5') {
                pq.add(Integer.parseInt(str.substring(0, idx) + str.substring(idx + 1)));
            }
        }
        assert !pq.isEmpty();
        return pq.poll();
    }

    public static void main(String[] args) {
        No66 no66 = new No66();
        System.out.println(no66.solution(15958));
        System.out.println(no66.solution(-5000));
        System.out.println(no66.solution(-9599995));
        System.out.println(no66.solution(-50));
        System.out.println(no66.solution(05));
        System.out.println(no66.solution(-05));
        System.out.println(-959999 > -999995);
    }
}
