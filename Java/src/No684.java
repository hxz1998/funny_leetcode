public class No684 {
    // 准备返回值
    private int[] ans = new int[2];
    // 用来标记连通 identifier 的数组
    private int[] id;
    // 题目提供的接口，给我们一个 edges 数组，用来表示边。
    public int[] findRedundantConnection(int[][] edges) {
        // 为什么是 n + 1？还不是因为题目没有从 0 开始计数😑
        id = new int[edges.length + 1];
        // 初始化各个边
        for (int i = 1; i < id.length; ++i) id[i] = i;
        // 把各个边都添加进连通分量中去
        for (int[] edge : edges) union(edge[0], edge[1]);
        return ans;
    }

    private void union(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        // p 和 q 并没有连通，那么就让他们连通
        if (pRoot != qRoot) id[pRoot] = qRoot;
        // 说明 p 和 q 已经连通了呀，那么就直接把它们记录下来
        else {
            ans[0] = p;
            ans[1] = q;
        }
    }

    private int find(int p) {
        // 向上回查根节点编号
        while (id[p] != p) p = id[p];
        return p;
    }

    public static void main(String[] args) {

    }
}
