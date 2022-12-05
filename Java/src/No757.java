import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/22
 **/

public class No757 {
    public int intersectionSizeTwo(int[][] intervals) {
        int n = intervals.length;
        int res = 0;
        int m = 2;
        Arrays.sort(intervals, (lhs, rhs) -> {
            if (lhs[0] == rhs[0]) return rhs[1] - lhs[1];
            return lhs[0] - rhs[0];
        });

        List<List<Integer>> temp = new ArrayList<>();
        for (int idx = 0; idx < n; ++idx) temp.add(new ArrayList<>());
        for (int idx = n - 1; idx >= 0; --idx) {
            for (int num = intervals[idx][0], size = temp.get(idx).size(); size < m; ++size, ++num) {
                res++;
                help(intervals, temp, idx - 1, num);
            }
        }
        return res;
    }

    private void help(int[][] intervals, List<List<Integer>> temp, int pos, int num) {
        for (int idx = pos; idx >= 0; --idx) {
            if (intervals[idx][1] < num) break;
            temp.get(idx).add(num);
        }
    }
}
