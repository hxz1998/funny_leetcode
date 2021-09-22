/*
 * Copyright (c) 8/22/2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No789 {
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int[] source = {0, 0};
        int dist = manhattanDistance(source, target);
        for (int[] ghost : ghosts) if (manhattanDistance(ghost, target) <= dist) return false;
        return true;
    }

    private int manhattanDistance(int[] source, int[] destination) {
        return Math.abs(source[0] - destination[0]) + Math.abs(source[1] - destination[1]);
    }

}
