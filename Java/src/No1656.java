import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/8/16
 **/

public class No1656 {
    private static class OrderedStream {
        private TreeMap<Integer, String> treeMap;
        private int ptr = 0;

        public OrderedStream(int n) {
            treeMap = new TreeMap<>();
            ptr = 0;
        }

        public List<String> insert(int idKey, String value) {
            treeMap.put(idKey, value);
            List<String> ans = new ArrayList<>();
            while (treeMap.containsKey(ptr)) {
                ans.add(treeMap.get(ptr));
                ptr++;
            }
            return ans;
        }
    }
}
