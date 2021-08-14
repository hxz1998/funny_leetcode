/*
 * Copyright (c) 8/9/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No348 {
    static class TicTacToe {
        private int[][] grid;
        private int n;

        public TicTacToe(int n) {
            grid = new int[n][n];
            this.n = n;
        }

        /**
         * Player {player} makes a move at ({row}, {col}).
         *
         * @param row    The row of the board.
         * @param col    The column of the board.
         * @param player The player, can be either 1 or 2.
         * @return The current winning condition, can be either:
         * 0: No one wins.
         * 1: Player 1 wins.
         * 2: Player 2 wins.
         */
        public int move(int row, int col, int player) {
            grid[row][col] = player;
            // 需要检查对角线
            // 左上到右下
            int cnt = 0;
            for (int i = 0; i < n; ++i) if (grid[i][i] == player) cnt++;
            if (cnt == n) return player;
            // 右上到左下
            cnt = 0;
            for (int i = 0; i < n; ++i) if (grid[i][n - i - 1] == player) cnt++;
            if (cnt == n) return player;
            // 需要检查从上到下
            cnt = 0;
            for (int i = 0; i < n; ++i) if (grid[i][col] == player) cnt++;
            if (cnt == n) return player;
            cnt = 0;
            for (int i = 0; i < n; ++i) if (grid[row][i] == player) cnt++;
            if (cnt == n) return player;
            return 0;
        }
    }

    public static void main(String[] args) {
        TicTacToe ticTacToe = new TicTacToe(2);
        System.out.println(ticTacToe.move(0, 1, 1));
        System.out.println(ticTacToe.move(1, 1, 2));
        System.out.println(ticTacToe.move(1, 0, 1));
    }
}
