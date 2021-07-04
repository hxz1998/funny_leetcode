/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

public class No08dot02 {
    public List<List<Integer>> pathWithObstacles(int[][] obstacleGrid) {
        List<List<Integer>> ans = new ArrayList<>();
        getPath(obstacleGrid, obstacleGrid.length - 1, obstacleGrid[0].length - 1, ans);
        return ans;
    }

    private boolean getPath(int[][] obstacleGrid, int row, int col, List<List<Integer>> path) {
        if (row < 0 || col < 0 || obstacleGrid[row][col] == 1) return false;
        if ((row == 0 && col == 0) || (getPath(obstacleGrid, row - 1, col, path))
                || (getPath(obstacleGrid, row, col - 1, path))) {
            ArrayList<Integer> point = new ArrayList<>();
            point.add(row);
            point.add(col);
            path.add(point);
            return true;
        }
        return false;
    }
}
