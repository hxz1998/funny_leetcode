/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest52;

import java.util.Arrays;

public class No3 {
    public char[][] rotateTheBox(char[][] box) {
        int m = box.length, n = box[0].length;
        char[][] ans = new char[n][m];  // 用来构建返回值的二维数组
        // 首先逐行处理，把石头挪到该放的地方去
        for (int i = 0; i < m; ++i) {
            // 首先假设当前 i 行可放的位置是 pos
            int pos = n - 1;
            // 然后从右往左遍历，逐个更新石头的位置
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '#') {
                    // 遇到了石头，先把它放到该放的位置去
                    box[i][pos--] = '#';
                    // 确保没有覆盖掉起始位置的石头，然后把挪动前的位置置为 空（.）
                    if (pos != j - 1) box[i][j] = '.';
                }
                // 如果遇到了障碍物，那么就更新可放的位置为障碍物的下一个位置（左边）
                else if (box[i][j] == '*') pos = j - 1;

            }
        }
        // 然后把更新后的位置映射到返回值中
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][m - 1 - i] = box[i][j];
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        char[][] cs = {{'#', '.', '#'}};
        No3 no3 = new No3();
//        System.out.println(Arrays.toString(no3.rotateTheBox(cs)));
        cs = new char[][]{{'#', '.', '*', '.'}, {'#', '#', '*', '.'}};
        no3.rotateTheBox(cs);
    }
}
