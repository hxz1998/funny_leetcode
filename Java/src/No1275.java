/*
 * Copyright (c) 8/17/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1275 {
    public String tictactoe(int[][] moves) {
        int[][] grid = new int[3][3];
        int player = 1;
        for (int[] move : moves) {
            int ret = check(grid, move, player);
            player = player == 1 ? 2 : 1;
            if (ret != 0) return ret == 1 ? "A" : "B";
        }
        return moves.length == 9 ? "Draw" : "Pending";
    }

    private int check(int[][] grid, int[] move, int player) {
        int x = move[0], y = move[1];
        grid[x][y] = player;
        // 横纵检查
        int cnt = 0;
        for (int row = 0; row < 3; ++row) {
            if (grid[row][y] == player) cnt++;
        }
        if (cnt == 3) return player;
        cnt = 0;
        for (int column = 0; column < 3; ++column) {
            if (grid[x][column] == player) cnt++;
        }
        if (cnt == 3) return player;
        // 如果在对角线，则再检查对角线
        if (x == y || x + y == 2) {
            cnt = 0;
            for (int row = 0; row < 3; ++row) if (grid[row][row] == player) cnt++;
            if (cnt == 3) return player;
            cnt = 0;
            for (int row = 0; row < 3; ++row) if (grid[row][2 - row] == player) cnt++;
            if (cnt == 3) return player;
        }
        return 0;
    }
}
