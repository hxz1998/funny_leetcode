/*
 * Copyright (c) 9/16/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class No212 {
    // 切换四个方向
    private static final int[][] dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    public List<String> findWords(char[][] board, String[] words) {
        // 记录表格中每一个字符出现的位置
        Map<Character, List<int[]>> mapper = new HashMap<>();
        int n = board.length, m = board[0].length;
        // 对位置进行记录
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; ++c) {
                char v = board[r][c];
                if (mapper.containsKey(v)) {
                    List<int[]> list = mapper.get(v);
                    list.add(new int[]{r, c});
                    mapper.put(v, list);
                } else {
                    List<int[]> list = new ArrayList<>();
                    list.add(new int[]{r, c});
                    mapper.put(v, list);
                }
            }
        }
        // 返回值
        List<String> ans = new ArrayList<>();
        // 对每一个单词进行深度优先搜索
        for (String word : words) {
            // 如果哈希表中没有记录当前单词第一个字母出现的位置，说明整个表中都没有这个字符，此时直接跳过就好了，没必要搜索了
            if (!mapper.containsKey(word.charAt(0))) continue;
            // 对所有出现的位置进行一次深度优先搜索
            for (int[] start : mapper.get(word.charAt(0))) {
                boolean[][] visited = new boolean[n][m];
                // 先把起始点标记成已访问
                visited[start[0]][start[1]] = true;
                if (dfs(board, visited, word, 1, start[0], start[1])) {
                    ans.add(word);
                    // 只要找到了，就进行下一个单词的查找
                    break;
                }
            }
        }
        return ans;
    }

    private boolean dfs(char[][] board, boolean[][] visited, String word, int pos, int x, int y) {
        // 如果位置来到了单词的末尾，说明已经查找完毕，直接返回 true
        if (pos >= word.length()) return true;
        // 否则就对四个方向进行深度优先搜索
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            // 确保新的坐标合法，而且没有访问过
            if (nx >= 0 && nx < board.length && ny >= 0 && ny < board[0].length && !visited[nx][ny] && board[nx][ny] == word.charAt(pos)) {
                // 先标记成访问过
                visited[nx][ny] = true;
                // 递归
                if (dfs(board, visited, word, pos + 1, nx, ny)) return true;
                // 回溯，再标记成没访问过
                visited[nx][ny] = false;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        char[][] board = {{'a', 'a'}};
        String[] words = {"aaa"};
        No212 no212 = new No212();
        System.out.println(no212.findWords(board, words));
    }
}
