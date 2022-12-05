/**
 * Java
 *
 * @Description: TODO
 * @Author: cherry
 * @Create on: 2022/7/11
 **/

public class No676 {
    private static class MagicDictionary {

        public MagicDictionary() {

        }

        public void buildDict(String[] dictionary) {
            for (String word : dictionary) insert(word);
        }

        public boolean search(String searchWord) {
            return dfs(root, searchWord, 0, false);
        }

        private boolean dfs(Node curr, String word, int index, boolean flag) {
            if (index == word.length()) return flag && curr.isEnd;
            if (curr.children[word.charAt(index) - 'a'] != null) {
                if (dfs(curr.children[word.charAt(index) - 'a'], word, index + 1, flag)) return true;
            }
            if (!flag) {
                for (int idx = 0; idx < 26; ++idx) {
                    if (idx != (word.charAt(index) - 'a') && curr.children[idx] != null) {
                        if (dfs(curr.children[idx], word, index + 1, true)) return true;
                    }
                }
            }
            return false;
        }

        private void insert(String word) {
            Node curr = root;
            for (char ch : word.toCharArray()) {
                if (curr.children[ch - 'a'] == null) curr.children[ch - 'a'] = new Node();
                curr = curr.children[ch - 'a'];
            }
            curr.isEnd = true;
        }

        private Node root = new Node();

        private static class Node {
            boolean isEnd = false;
            Node[] children = new Node[26];
        }
    }

    public static void main(String[] args) {
        MagicDictionary dictionary = new MagicDictionary();
        dictionary.buildDict(new String[]{"hello", "hallo", "leetcode"});
        System.out.println(dictionary.search("hhllo"));
    }
}
