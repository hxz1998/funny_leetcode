import java.util.HashSet;

/**
 * Created by Xiaozhong on 2021/2/1.
 * Copyright (c) 2021/2/1 Xiaozhong. All rights reserved.
 */

public class No888 {
    public int[] fairCandySwap(int[] A, int[] B) {
        int sumA = 0, sumB = 0;
        for (int i : A) sumA += i;
        for (int i : B) sumB += i;
        int delta = (sumA - sumB) / 2;
        HashSet<Integer> set = new HashSet<>();
        for (int i : A) set.add(i);
        for (int i : B) {
            if (set.contains(i + delta)) return new int[]{i + delta, i};
        }
        return null;
    }
}
