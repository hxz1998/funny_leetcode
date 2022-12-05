import java.util.ArrayList;
import java.util.List;

/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/14
 **/

public class No745 {
    private static class WordFilter {
        private static class Trie {
            Trie[] next = new Trie[26];
            List<Integer> indexes = new ArrayList<>();
        }

        private Trie order = new Trie();
        private Trie reverseOrder = new Trie();

        private void add(Trie node, String s, int idx, boolean flip) {
            int n = s.length();
            node.indexes.add(idx);
            for (int i = flip ? n - 1 : 0; i >= 0 && i < n; i += flip ? -1 : 1) {
                int u = s.charAt(i) - 'a';
                if (node.next[u] == null) node.next[u] = new Trie();
                node = node.next[u];
                node.indexes.add(idx);
            }
        }

        public WordFilter(String[] words) {
            for (int idx = 0; idx < words.length; ++idx) {
                add(order, words[idx], idx, false);
                add(reverseOrder, words[idx], idx, true);
            }
        }

        public int f(String prefix, String suffix) {
            int n = prefix.length(), m = suffix.length();
            Trie node = order;
            for (int idx = 0; idx < n; ++idx) {
                if (node.next[prefix.charAt(idx) - 'a'] == null) return -1;
                node = node.next[prefix.charAt(idx) - 'a'];
            }
            List<Integer> l1 = node.indexes;
            node = reverseOrder;
            for (int idx = 0; idx < m; ++idx) {
                if (node.next[prefix.charAt(idx) - 'a'] == null) return -1;
                node = node.next[prefix.charAt(idx) - 'a'];
            }
            List<Integer> l2 = node.indexes;
            for (int idx1 = l1.size() - 1, idx2 = l2.size() - 1; idx1 >= 0 && idx2 >= 0; ) {
                if (l1.get(idx1) > l2.get(idx2)) idx1--;
                else if (l1.get(idx1) < l2.get(idx2)) idx2--;
                else return l1.get(idx1);
            }
            return -1;
        }
    }
}
