/*
 * Copyright (c) 7/31/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No261 {
    static class UnionFind {
        private int[] id;
        private int count = 0;

        public UnionFind(int n) {
            this.id = new int[n];
            count = n;
            for (int i = 0; i < n; ++i) id[i] = i;
        }

        public int find(int v) {
            return id[v];
        }

        public void union(int v, int w) {
            if (find(v) == find(w)) return;
            int identifier = find(v);
            for (int i = 0; i < id.length; ++i) if (identifier == id[i]) id[i] = find(w);
            count--;
        }

        public boolean connected(int v, int w) {
            return find(v) == find(w);
        }

        public int count() {
            return count;
        }
    }

    public boolean validTree(int n, int[][] edges) {
        if (n - 1 != edges.length) return false;
        UnionFind uf = new UnionFind(n);
        for (int[] edge : edges) {
            if (uf.connected(edge[0], edge[1])) return false;
            uf.union(edge[0], edge[1]);
        }
        return uf.count() == 1;
    }

    public static void main(String[] args) {
        No261 no261 = new No261();
        int[][] edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
        System.out.println(no261.validTree(5, edges));
    }
}
