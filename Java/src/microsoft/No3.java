/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/6
 **/
package microsoft;

import java.util.ArrayList;
import java.util.List;

public class No3 {
    public boolean solution(int[] a, int[] b, int s) {
        int n = a.length;
        if (n > s) return false;
        // 1 1 1
        // 2 2 3
        // 1 2 1 6 8 7 8
        // 2 3 4 7 7 8 7
        int[][] graph = new int[s + 1][s + 1];
        for (int idx = 0; idx < n; ++idx) {
            int ax = a[idx], bx = b[idx];
            graph[ax][bx]++;
            graph[bx][ax]++;
            if (graph[ax][bx] >= 3 || graph[bx][ax] >= 3) return false;
        }
        boolean[] visited = new boolean[s + 1];
        for (int start = 1; start <= s; ++start) {
            if (visited[start]) continue;
            List<Integer> points = new ArrayList<>();
            dfs(graph, start, visited, points);
            int edges = 0;
            for (int point : points) {
                for (int i = 0; i < graph.length; ++i) {
                    edges += graph[point][i];
                }
            }
            edges /= 2;
            if (edges > points.size()) return false;
        }
        return true;
    }

    private void dfs(int[][] graph, int start, boolean[] visited, List<Integer> points) {
        for (int idx = 0; idx < graph.length; ++idx) {
            if (graph[start][idx] > 0 && !visited[idx]) {
                points.add(idx);
                visited[idx] = true;
                dfs(graph, idx, visited, points);
            }
        }
    }

    public static void main(String[] args) {
        System.out.println(new No3().solution(new int[]{2, 6, 2, 5, 4, 3},
                new int[]{6, 2, 5, 2, 5, 5}, 8));
    }
}
