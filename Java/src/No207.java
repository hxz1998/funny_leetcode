import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/6
 **/

public class No207 implements AutoCloseable {
    private static final int S1 = 0, S2 = 1, S3 = 2;
    private boolean valid = true;

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] visited = new int[numCourses];
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < numCourses; ++i) graph.add(new ArrayList<>());
        // [a, b]: b->a
        for (int[] prerequisite : prerequisites) {
            graph.get(prerequisite[1]).add(prerequisite[0]);
        }
        for (int course = 0; course < numCourses; ++course) {
            if (visited[course] == S1) {
                dfs(graph, visited, course);
            }
        }
        return valid;
    }

    private void dfs(List<List<Integer>> graph, int[] visited, int u) {
        visited[u] = S2;
        for (int next : graph.get(u)) {
            if (visited[next] == S2) {
                valid = false;
                return;
            }
            dfs(graph, visited, next);
        }
        visited[u] = S3;
    }

    private void add(int... num) {
        AtomicInteger integer = new AtomicInteger();
    }

    private static void add(int num) {

    }

    public static void main(String[] args) {
        No207.add(1);
        new No207().add(1, 2);
    }

    @Override
    public void close() throws Exception {

    }
}
