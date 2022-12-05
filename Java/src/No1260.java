import java.util.ArrayList;
import java.util.List;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/20
 **/

public class No1260 {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        List<List<Integer>> data = new ArrayList<>();
        int n = grid.length, m = grid[0].length;
        for (int x = 0; x < n; ++x) {
            List<Integer> row = new ArrayList<>();
            for (int y = 0; y < m; ++y) row.add(0);
            data.add(row);
        }
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                int idx = (x * m + y + k) % (m * n);
                data.get(idx / m).set(idx % m, grid[x][y]);
            }
        }
        return data;
    }
}
