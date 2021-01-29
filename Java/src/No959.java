/**
 * Created by Xiaozhong on 2021/1/25.
 * Copyright (c) 2021/1/25 Xiaozhong. All rights reserved.
 */

class No959 {
    private class UnionFind {
        private int[] parent;
        private int count;

        public int getCount() {
            return count;
        }

        public UnionFind(int n) {
            this.count = n;
            this.parent = new int[n];
            for (int i = 0; i < n; ++i) parent[i] = i;
        }

        public int find(int idx) {
            while (idx != parent[idx]) {
                parent[idx] = parent[parent[idx]];
                idx = parent[idx];
            }
            return idx;
        }

        public void union(int x, int y) {
            int rootx = find(x);
            int rooty = find(y);
            if (rootx == rooty) return;
            else {
                parent[rootx] = rooty;
                count--;
            }
        }
    }

    public int regionsBySlashes(String[] grid) {
        int N = grid.length;
        int size = 4 * N * N;

        UnionFind uf = new UnionFind(size);
        for (int i = 0; i < N; ++i) {
            char[] row = grid[i].toCharArray();
            for (int j = 0; j < N; ++j) {
                // 二维网格转换为一维的表格
                int idx = 4 * (i * N + j);
                char c = row[j];
                // 单元格内合并
                if (c == '/') {
                    uf.union(idx, idx + 3);
                    uf.union(idx + 1, idx + 2);
                } else if (c == '\\') {
                    uf.union(idx, idx + 1);
                    uf.union(idx + 2, idx + 3);
                } else {
                    uf.union(idx, idx + 1);
                    uf.union(idx + 1, idx + 2);
                    uf.union(idx + 2, idx + 3);
                }
                // 单元格间合并
                // 向右方合并，1（当前），3（右边一列）
                if (j + 1 < N) {
                    uf.union(idx + 1, 4 * (i * N + j + 1) + 3);
                }
                // 向下合并，2（当前），0（下一行）
                if (i + 1 < N) {
                    uf.union(idx + 2, 4 * ((i + 1) * N + j));
                }
            }
        }
        return uf.getCount();
    }
}
