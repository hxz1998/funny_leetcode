/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No990 {
    static class UnionFind {
        int[] id = new int[26];

        UnionFind() {
            for (int i = 0; i < 26; ++i) {
                id[i] = i;
            }
        }

        private void union(char v, char w) {
            int identifier = find(v);
            for (int i = 0; i < 26; i++) {
                if (id[i] == identifier) id[i] = id[w - 'a'];
            }
        }

        private boolean connected(char v, char w) {
            return find(v) == find(w);
        }

        private int find(char c) {
            return id[c - 'a'];
        }
    }

    public boolean equationsPossible(String[] equations) {
        UnionFind uf = new UnionFind();
        for (String equation : equations) {
            if (equation.startsWith("==", 1)) {
                uf.union(equation.charAt(0), equation.charAt(3));
            }
        }
        for (String equation : equations) {
            if (equation.startsWith("!=", 1)) {
                char from = equation.charAt(0);
                char to = equation.charAt(3);

                if (uf.connected(from, to)) return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String[] equations = {"a==b", "b!=a"};
        No990 no990 = new No990();
        System.out.println(no990.equationsPossible(equations));
    }
}
