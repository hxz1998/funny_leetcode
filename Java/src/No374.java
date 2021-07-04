/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No374 {
    public int guessNumber(int n) {
        int left = 1, right = n;
        while (true) {
            int mid = left + (right - left) / 2;
            int ret = guess(mid);
            if (ret == 0) return mid;
            else if (ret > 0) left = mid + 1;
            else right = mid;
        }
    }

    private int guess(int num) {
        return 0;
    }
}
