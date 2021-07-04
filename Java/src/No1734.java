/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

import java.util.Arrays;

public class No1734 {

    public int[] decode(int[] encoded) {
        int n = encoded.length;
        int[] ans = new int[n + 1];
        int total = 0;
        for (int i = 1; i <= n + 1; ++i) total ^= i;

        int odd = 0;
        for (int i = 1; i < n; i += 2) odd ^= encoded[i];

        ans[0] = odd ^ total;
        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[i - 1] ^ encoded[i - 1];
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] encoded = {6, 5, 4, 6};
        No1734 no1734 = new No1734();
        System.out.println(Arrays.toString(no1734.decode(encoded)));
    }
}
