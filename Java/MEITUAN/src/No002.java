/*
 * Copyright (c) 8/13/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.io.*;
import java.util.Scanner;

public class No002 {

    static int[] p, val;

    static int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(reader.readLine());
        String[] w = reader.readLine().split(" ");
        String[] f = reader.readLine().split(" ");

        // 用于判断相邻节点是否已经插入了
        boolean[] v = new boolean[n + 1];
        // 存储每个节点的数据和(只有当当前节点为根节点时才有意义)
        val = new int[n + 1];
        for (int i = 1; i <= n; i++) val[i] = Integer.parseInt(w[i - 1]);
        p = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }

        int max = 0;
        int[] res = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            int cur = Integer.parseInt(f[i]);
            v[cur] = true;
            max = Math.max(max, val[cur]);
            if (cur - 1 >= 1 && v[cur - 1]) {
                int pa = find(cur - 1);
                p[pa] = cur;
                val[cur] += val[pa];
                max = Math.max(max, val[cur]);
            }
            if (cur + 1 <= n && v[cur + 1]) {
                int pa = find(cur + 1);
                p[pa] = cur;
                val[cur] += val[pa];
                max = Math.max(max, val[cur]);
            }
            res[i] = max;
        }

        for (int i = 1; i < n; i++) {
            writer.write(res[i] + "\n");
        }
        writer.write(0 + "\n");

        writer.close();
        reader.close();
    }
}
