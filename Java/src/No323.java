/*
 * Copyright (c) 8/3/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No323 {
    static class UnionFind {
        private int[] id;
        private int count = 0;

        public UnionFind(int n) {
            id = new int[n];
            count = n;
            for (int i = 0; i < n; ++i) id[i] = i;
        }

        private int find(int v) {
            return id[v];
        }

        public boolean connected(int v, int w) {
            return find(v) == find(w);
        }

        public void union(int v, int w) {
            int idv = find(v);
            int idw = find(w);
            if (idv == idw) return;
            for (int i = 0; i < id.length; ++i) if (id[i] == idv) id[i] = idw;
            count--;
        }

        public int count() {
            return count;
        }
    }

    public int countComponents(int n, int[][] edges) {
        UnionFind uf = new UnionFind(n);
        for (int[] edge : edges) uf.union(edge[0], edge[1]);
        return uf.count();
    }
}
