import java.util.ArrayDeque;
import java.util.Deque;
import java.util.List;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/7
 **/

public class No636 {
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] ans = new int[n];
        Deque<int[]> stack = new ArrayDeque<>();
        for (String log : logs) {
            int idx = Integer.parseInt(log.substring(0, log.indexOf(":")));
            String type = log.substring(log.indexOf(":") + 1, log.lastIndexOf(":"));
            int timeStamp = Integer.parseInt(log.substring(log.lastIndexOf(":") + 1));
            if (type.equals("start")) {
                if (!stack.isEmpty()) {
                    ans[stack.peek()[0]] += timeStamp - stack.peek()[1];
                    stack.peek()[1] = timeStamp;
                }
                stack.push(new int[]{idx, timeStamp});
            } else {
                assert !stack.isEmpty();
                int[] top = stack.pop();
                ans[top[0]] += timeStamp - top[1] + 1;
                if (!stack.isEmpty()) stack.peek()[1] = timeStamp + 1;
            }
        }
        return ans;
    }
}
