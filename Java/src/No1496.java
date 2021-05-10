/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class No1496 {

    public boolean isPathCrossing(String path) {
        int y = 0, x = 0;
        Set<int[]> set = new TreeSet<>(((o1, o2) -> o1[0] * 100000 + o1[1] - o2[0] * 100000 + o2[1]));
        set.add(new int[]{x, y});
        for (char c : path.toCharArray()) {
            switch (c) {
                case 'N':
                    y++;
                    break;
                case 'E':
                    x++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'W':
                    x--;
                    break;
            }
            if (!set.add(new int[]{x, y})) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        No1496 no1496 = new No1496();
        System.out.println(no1496.isPathCrossing("NNSWWEWSSESSWENNW"));
    }
}
