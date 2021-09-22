/*
 * Copyright (c) 9/17/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No36 {
    public boolean isValidSudoku(char[][] board) {
        int[][] rowValue = new int[9][9];
        int[][] columnValue = new int[9][9];
        int[][] boxValue = new int[9][9];
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;
                int boxIdx = r / 3 + c / 3;
                int value = board[r][c] - '1';

                if (rowValue[r][value] != 0 || columnValue[c][value] != 0 || boxValue[boxIdx][value] != 0) return false;
                rowValue[r][value] = 1;
                columnValue[c][value] = 1;
                boxValue[boxIdx][value] = 1;
            }
        }
        return true;
    }
}
