/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

class WordDictionary {

    static class Node {
        Node[] data = new Node[26];
        boolean isEnd = false;
    }

    private Node root;

    public WordDictionary() {
        root = new Node();
    }

    public void addWord(String word) {
        Node curr = root;
        for (int i = 0; i < word.length(); ++i) {
            int idx = word.charAt(i) - 'a';
            if (curr.data[idx] == null) curr.data[idx] = new Node();
            curr = curr.data[idx];
        }
        curr.isEnd = true;
    }

    public boolean search(String word) {
        return backtrace(root, word, 0);
    }

    private boolean backtrace(Node root, String s, int start) {
        if (start == s.length() && root.isEnd) return true;
        if (s.charAt(start) == '.') {
            for (int i = 0; i < 26; ++i)
                if (root.data[i] != null && backtrace(root.data[i], s, start + 1))
                    return true;
            return false;
        } else {
            int idx = s.charAt(start) - 'a';
            if (root.data[idx] == null) return false;
            else return backtrace(root.data[idx], s, start + 1);
        }
    }
}

public class No211 {
}
