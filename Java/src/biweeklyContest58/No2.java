/*
 * Copyright (c) 8/7/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package biweeklyContest58;

public class No2 {
    public boolean checkMove(char[][] board, int rMove, int cMove, char color) {
        board[rMove][cMove] = color;
        int n = 8;
        // 检查上下左右以及两条斜线是否构成好线段
        // 上下左右
        char between = color == 'W' ? 'B' : 'W';
        int cnt = 0;
        for (int r = rMove - 1; r >= 0; --r) {
            if (board[r][cMove] == between) cnt++;
            if (board[r][cMove] == '.') break;
            if (board[r][cMove] == color) {
                if (cnt > 0) return true;
                break;
            }
        }
        cnt = 0;
        for (int r = rMove + 1; r < n; ++r) {
            if (board[r][cMove] == between) cnt++;
            if (board[r][cMove] == '.') break;
            if (board[r][cMove] == color) {
                if (cnt > 0) return true;
                break;
            }
        }
        cnt = 0;
        for (int c = cMove + 1; c < n; ++c) {
            if (board[rMove][c] == between) cnt++;
            if (board[rMove][c] == '.') break;
            if (board[rMove][c] == color) {
                if (cnt > 0) return true;
                break;
            }
        }
        cnt = 0;
        for (int c = cMove - 1; c >= 0; --c) {
            if (board[rMove][c] == between) cnt++;
            if (board[rMove][c] == '.') break;
            if (board[rMove][c] == color) {
                if (cnt > 0) return true;
                break;
            }
        }
        // 检查对角线
        cnt = 0;
        for (int c = cMove - 1, r = rMove - 1; r >= 0 && c >= 0; --r, --c) {
            if (board[r][c] == between) cnt++;
            if (board[r][c] == '.') break;
            if (board[r][c] == color) {
                if (cnt > 0) return true;
                break;
            }
        }
        cnt = 0;
        for (int c = cMove + 1, r = rMove + 1; r < n && c < n; ++r, ++c) {
            if (board[r][c] == between) cnt++;
            if (board[r][c] == '.') break;
            if (board[r][c] == color) {
                if (cnt > 0) return true;
                break;
            }
        }
        cnt = 0;
        for (int c = cMove + 1, r = rMove - 1; r >= 0 && c < n; ++c, --r) {
            if (board[r][c] == between) cnt++;
            if (board[r][c] == '.') break;
            if (board[r][c] == color) {
                if (cnt > 0) return true;
                break;
            }
        }
        cnt = 0;
        for (int c = cMove - 1, r = rMove + 1; r < n && c >= 0; ++r, --c) {
            if (board[r][c] == between) cnt++;
            if (board[r][c] == '.') break;
            if (board[r][c] == color) {
                if (cnt > 0) return true;
                break;
            }
        }
        return false;
    }

    private boolean checkIsBoard(char[][] board, int x, int y) {
        if (x == 0 || y == 0 || x == board.length - 1 || y == board.length - 1) return true;
        int[][] dirs = {{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};
        int cnt = 0;
        for (int i = 0; i < 8; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (board[nx][ny] != '.') cnt++;
        }
        return cnt == 1;
    }

    public static void main(String[] args) {
        char[][] grid = {{'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', 'B', '.', '.', 'W', '.', '.', '.'}, {'.', '.', 'W', '.', '.', '.', '.', '.'}, {'.', '.', '.', 'W', 'B', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', 'B', 'W', '.', '.'}, {'.', '.', '.', '.', '.', '.', 'W', '.'}, {'.', '.', '.', '.', '.', '.', '.', 'B'}};
        No2 no2 = new No2();
        System.out.println(no2.checkMove(grid, 4, 4, 'W'));
        grid = new char[][]{{'B', 'B', '.', '.', 'B', 'W', 'W', '.'}, {'.', 'W', 'W', '.', 'B', 'W', 'B', 'B'}, {'.', 'W', 'B', 'B', 'W', '.', 'W', '.'}, {'B', '.', '.', 'B', 'W', 'W', 'W', '.'}, {'W', 'W', 'W', 'B', 'W', '.', 'B', 'W'}, {'.', '.', '.', 'W', '.', 'W', '.', 'B'}, {'B', 'B', 'W', 'B', 'B', 'W', 'W', 'B'}, {'W', '.', 'W', 'W', '.', 'B', '.', 'W'}};
        System.out.println(no2.checkMove(grid, 2, 5, 'W'));
        grid = new char[][]{{'.', '.', 'W', '.', 'B', 'W', 'W', 'B'}, {'B', 'W', '.', 'W', '.', 'W', 'B', 'B'}, {'.', 'W', 'B', 'W', 'W', '.', 'W', 'W'}, {'W', 'W', '.', 'W', '.', '.', 'B', 'B'}, {'B', 'W', 'B', 'B', 'W', 'W', 'B', '.'}, {'W', '.', 'W', '.', '.', 'B', 'W', 'W'}, {'B', '.', 'B', 'B', '.', '.', 'B', 'B'}, {'.', 'W', '.', 'W', '.', 'W', '.', 'W'}};
        System.out.println(no2.checkMove(grid, 5, 4, 'W'));
        grid = new char[][]{{'B', 'B', 'B', '.', 'W', 'W', 'B', 'W'}, {'B', 'B', '.', 'B', '.', 'B', 'B', 'B'}, {'.', 'W', '.', '.', 'B', '.', 'B', 'W'}, {'B', 'W', '.', 'W', 'B', '.', 'B', '.'}, {'B', 'W', 'W', 'B', 'W', '.', 'B', 'B'}, {'.', '.', 'W', '.', '.', 'W', '.', '.'}, {'W', '.', 'W', 'B', '.', 'W', 'W', 'B'}, {'B', 'B', 'W', 'W', 'B', 'W', '.', '.'}};
        System.out.println(no2.checkMove(grid, 5, 6, 'B'));
    }
}
