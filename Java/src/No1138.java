/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1138 {
    public String alphabetBoardPath(String target) {
        int x = 0, y = 0;
        StringBuilder builder = new StringBuilder();
        for (char c : target.toCharArray()) {
            int nx = (c - 'a') / 5, ny = (c - 'a') % 5;
            if (nx < x) builder.append("U".repeat(x - nx));
            if (ny > y) builder.append("R".repeat(ny - y));
            if (ny < y) builder.append("L".repeat(y - ny));
            if (nx > x) builder.append("D".repeat(nx - x));
            builder.append("!");
            x = nx;
            y = ny;
        }
        return builder.toString();
    }

    public static void main(String[] args) {
        No1138 no1138 = new No1138();
        System.out.println(no1138.alphabetBoardPath("leet"));
    }
}
