package interview;

import java.util.Map;
import java.util.TreeMap;

public class No10dot10 {
    static class StreamRank {
        private TreeMap<Integer, Integer> mapper;
        public StreamRank() {
            mapper = new TreeMap<>();
        }

        public void track(int x) {
            mapper.put(x, mapper.getOrDefault(x, 0) + 1);
        }

        public int getRankOfNumber(int x) {
            int ans = 0;
            for (Map.Entry<Integer, Integer> entry : mapper.entrySet()) {
                if (entry.getKey() > x) return ans;
                else ans += entry.getValue();
            }
            return ans;
        }
    }
}
