/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashMap;
import java.util.Map;


class Trie {
    private static class Node {
        Node[] data = new Node[26];
        boolean isEnd = false;
    }

    private Node root;

    public Trie() {
        root = new Node();
    }

    public void insert(String word) {
        Node curr = root;
        for (int i = 0; i < word.length(); ++i) {
            int idx = word.charAt(i) - 'a';
            if (curr.data[idx] == null) {
                curr.data[idx] = new Node();
            }
            curr = curr.data[idx];
        }
        curr.isEnd = true;
    }

    public boolean search(String word) {
        Node node = searchPrefix(word);
        return node != null && node.isEnd;
    }

    public boolean startsWith(String prefix) {
        return searchPrefix(prefix) != null;
    }

    private Node searchPrefix(String prefix) {
        Node curr = root;
        for (int i = 0; i < prefix.length(); ++i) {
            int idx = prefix.charAt(i) - 'a';
            if (curr.data[idx] == null) return null;
            else curr = curr.data[idx];
        }
        return curr;
    }
}

public class No208 {

}
