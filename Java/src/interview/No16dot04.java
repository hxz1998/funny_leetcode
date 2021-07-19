/*
 * Copyright (c) 7/18/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

public class No16dot04 {
    public String tictactoe(String[] board) {
        int m = board.length, n = board[0].length();
        boolean hasBlank = false;
        for (int i = 0; i < m; ++i) {
            int rowX = 0, rowO = 0, columnX = 0, columnO = 0;
            for (int j = 0; j < n; ++j) {
                if (board[i].charAt(j) == ' ') hasBlank = true;
                if (board[i].charAt(j) == 'X') rowX++;
                else if (board[i].charAt(j) == 'O') rowO++;
                if (board[j].charAt(i) == 'X') columnX++;
                else if (board[j].charAt(i) == 'O') columnO++;
            }
            if (rowX == m || columnX == n) return "X";
            if (rowO == m || columnO == n) return "O";
        }
        int leftTopToRightBottomX = 0, leftTopToRightBottomO = 0, rightTopToLeftBottomX = 0, rightTopToLeftBottomO = 0;
        for (int i = 0; i < m; ++i) {
            if (board[i].charAt(i) == 'X') leftTopToRightBottomX++;
            else if (board[i].charAt(i) == 'O') leftTopToRightBottomO++;
            if (board[i].charAt(n - i - 1) == 'X') rightTopToLeftBottomX++;
            else if (board[i].charAt(n - i - 1) == 'O') rightTopToLeftBottomO++;
        }
        if (leftTopToRightBottomX == m || rightTopToLeftBottomX == n) return "X";
        else if (leftTopToRightBottomO == m || rightTopToLeftBottomO == n) return "O";
        return hasBlank ? "Pending" : "Draw";
    }

    public static void main(String[] args) {
        String[] boards = {
                "                             ",
                "                     O       ",
                "         X           X       ",
                "                             ",
                "                             ",
                "                             ",
                "                             ",
                "                             ",
                "                             ",
                "                             ",
                "                             ",
                "                             ",
                "                             ",
                "                             ",
                "                             ",
                "                             ",
                "                      O      ",
                "                             ",
                "                             ",
                "                             ",
                "                             ",
                "                             ",
                "                             ",
                "      X                      ",
                "                             ",
                "                             ",
                "      O                      ",
                "                             ",
                "                             "};
        No16dot04 no16dot04 = new No16dot04();
        System.out.println(no16dot04.tictactoe(boards));
    }
}
