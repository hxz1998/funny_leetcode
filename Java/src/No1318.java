/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

public class No1318 {
    public int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int bitA = (a >> i) & 1, bitB = (b >> i) & 1, bitC = (c >> i) & 1;
            int sum = bitA + bitB;
            if (bitC == 1 && sum == 0) ans++;
            else if (bitC == 0 && sum != 0) ans += sum == 2 ? 2 : 1;
        }
        return ans;
    }

    public static void main(String[] args) {
        No1318 no1318 = new No1318();
        System.out.println(no1318.minFlips(2, 6, 5));
    }
}
