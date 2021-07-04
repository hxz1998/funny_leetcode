/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Comparator;
import java.util.PriorityQueue;

public class No1738 {
    public int kthLargestValue(int[][] matrix, int k) {
        PriorityQueue<Integer> queue = new PriorityQueue<>((o1, o2) -> o2 - o1);
        int m = matrix.length, n = matrix[0].length;
        int[][] mirror = new int[m][n];
        for (int i = 0; i < m; ++i) {
            mirror[i][0] = matrix[i][0];
            for (int j = 1; j < n; ++j) {
                mirror[i][j] = mirror[i][j - 1] ^ matrix[i][j];
            }
        }
        for (int j = 0; j < n; ++j) {
            int curr = 0;
            for (int i = 0; i < m; ++i) {
                curr = curr ^ mirror[i][j];
                queue.offer(curr);
            }
        }
        int ans = 0;
        while (--k > 0) queue.poll();
        ans = queue.poll();
        return ans;
    }

    public static void main(String[] args) {
        int[][] matrix = {{5, 2}, {1, 6}};
        No1738 no1738 = new No1738();
        System.out.println(no1738.kthLargestValue(matrix, 1));
    }
}
